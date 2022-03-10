/**
 * @file math_parse.c
 * @author Eduardo Luis
 * 
 * @brief TODO
 * 
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "math_parse.h"

#include <stdlib.h>
#include <math.h> /* for NAN */

#include "math_operations.h"
#include "math_token.h"

/* The FN_MASK macro is used when we need to know how much parameters the
 * function accepts. */
#define FN_MASK 0x7

/* Convenient macro for creating new nodes. */
#define NODE_NEW(type, ...)                                                   \
  parse_node_new (type, (const ParseNode *[]){ __VA_ARGS__ })

/* Prototypes. */

static ParseNode *parse_node_new (NodeType type, const ParseNode *params[]);
static void parse_free_params (ParseNode *node);

/* <expr>  ::= <expr0> "+" <expr> | <expr0> "-" <expr> | <expr0> */
static ParseNode *parse_expr (Token *token);
/* <expr0> ::= <expr1> "*" <expr0> | <expr1> "/" <expr0> | <expr1> */
static ParseNode *parse_expr0 (Token *token);
/* <expr1> ::= <expr2> "^" <expr1> | <expr2> */
static ParseNode *parse_expr1 (Token *token);
/* <expr2> ::= "+" <atom> | "-" <atom> | <atom> */
static ParseNode *parse_expr2 (Token *token);
/* <atom>  ::= "(" <expr> ")" | <NUMBER>  */
static ParseNode *parse_atom (Token *token);

/* Private functions. */

static ParseNode *
parse_node_new (NodeType type, const ParseNode *params[])
{
  ParseNode *ret;
  const size_t nparams = type & FN_MASK;
  const size_t params_size = nparams * sizeof (void *);
  const size_t total_size = sizeof (ParseNode) - sizeof (void *) + params_size;

  ret = (ParseNode *)malloc (total_size);
  if (params)
    memcpy (ret->params, params, params_size);
  ret->type = type;

  return ret;
}

static ParseNode *
parse_atom (Token *token)
{
  /* <atom> ::= "(" <expr> ")" | <NUMBER> */
  ParseNode *ret;

  if (token->type == TOK_NUMBER)
    {
      ret = NODE_NEW (NODE_CONSTANT, NULL);
      ret->value = token->value;
      next_token (token);
    }
  else if (token->type == TOK_OPEN)
    {
      next_token (token);
      ret = parse_expr (token);
      if (token->type != TOK_CLOSE)
        ret->type = TOK_ERROR;
      else
        next_token (token);
    }
  else
    {
      ret = NODE_NEW (TOK_ERROR, 0);
      ret->value = NAN;
    }

  return ret;
}

static ParseNode *
parse_expr2 (Token *token)
{
  ParseNode *ret;
  int sign = 1;

  while (token->type == TOK_INFIX && (token->op == add || token->op == sub))
    {
      if (token->op == sub)
        sign = -sign;
      next_token (token);
    }

  if (sign == 1)
    ret = parse_atom (token);
  else
    {
      ret = NODE_NEW (NODE_FUNCTION1, parse_atom (token));
      ret->op = negate;
    }

  return ret;
}

static ParseNode *
parse_expr1 (Token *token)
{
  ParseNode *ret = parse_expr2 (token);

  while (token->type == TOK_INFIX && (token->op == pow))
    {
      const void *op = token->op;

      next_token (token);
      ret = NODE_NEW (NODE_FUNCTION2, ret, parse_expr1 (token));
      ret->op = op;
    }

  return ret;
}

static ParseNode *
parse_expr0 (Token *token)
{
  ParseNode *ret = parse_expr1 (token);

  while (token->type == TOK_INFIX && (token->op == mul || token->op == divide))
    {
      const void *op = token->op;

      next_token (token);
      ret = NODE_NEW (NODE_FUNCTION2, ret, parse_expr0 (token));
      ret->op = op;
    }

  return ret;
}

static ParseNode *
parse_expr (Token *token)
{
  ParseNode *ret = parse_expr0 (token);

  while (token->type == TOK_INFIX && (token->op == add || token->op == sub))
    {
      const void *op = token->op;

      next_token (token);
      ret = NODE_NEW (NODE_FUNCTION2, ret, parse_expr (token));
      ret->op = op;
    }

  return ret;
}

static void
parse_free_params (ParseNode *node)
{
  switch (node->type)
    {
    case NODE_CONSTANT:
    case NODE_FUNCTION0:
      break;
    case NODE_FUNCTION2:
      math_parse_free (node->params[1]);
    case NODE_FUNCTION1:
      math_parse_free (node->params[0]);
    };
}

/* Public functions. */

void
math_parse_free (ParseNode *node)
{
  if (!node)
    return;
  parse_free_params (node);
  free (node);
}

ParseNode *
math_parse_str (const char *expression)
{
  ParseNode *ret;
  Token token;

  token.start = token.next = expression;

  next_token (&token);
  ret = parse_expr (&token);

  if (token.type != TOK_END)
    {
      /* TODO: error handler. */
      math_parse_free (ret);
      return NULL;
    }

  return ret;
}

double
math_parse_eval (const ParseNode *root)
{
  if (!root)
    return NAN;

  switch (root->type)
    {
    case NODE_CONSTANT:
      return root->value;
    case NODE_FUNCTION0:
    case NODE_FUNCTION1:
    case NODE_FUNCTION2:
      switch (root->type & FN_MASK)
        {
        case 1:
          return ((double (*) (double))root->op) (
              math_parse_eval (root->params[0]));
        case 2:
          return ((double (*) (double, double))root->op) (
              math_parse_eval (root->params[0]),
              math_parse_eval (root->params[1]));
        default:
          return NAN;
        }
    }

  return NAN;
}
