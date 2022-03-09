#include "math_token.h"

#include <stdlib.h> /* for strtod() */
#include <ctype.h>  /* for isspace() and isdigit() */

#include "math_operations.h"

#define skip_whitespace(str)                                                  \
  do                                                                          \
    {                                                                         \
      if (isspace (*str))                                                     \
        str++;                                                                \
    }                                                                         \
  while (0)

void
next_token (Token *token)
{
  token->type = TOK_NULL;

  do
    {
      skip_whitespace (token->next);

      if (!token->next[0])
        {
          token->type = TOK_END;
          return;
        }

      if (isdigit (token->next[0]) || token->next[0] == '.')
        {
          token->value = strtod (token->next, (char **)&token->next);
          token->type = TOK_NUMBER;
        }
      else
        {
          switch (token->next++[0])
            {
            case '+':
              token->op = add;
              token->type = TOK_INFIX;
              break;
            case '-':
              token->op = sub;
              token->type = TOK_INFIX;
              break;
            case '*':
              token->op = mul;
              token->type = TOK_INFIX;
              break;
            case '/':
              token->op = divide;
              token->type = TOK_INFIX;
              break;
            case '^':
              token->op = pow;
              token->type = TOK_INFIX;
              break;
            case '(':
              token->type = TOK_OPEN;
              break;
            case ')':
              token->type = TOK_CLOSE;
              break;

            default:
              token->type = TOK_ERROR;
              break;
            }
        }
    }
  while (token->type == TOK_NULL);
}
