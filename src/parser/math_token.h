/**
 * @file math_token.h
 * @author Eduardo Luis
 *
 * @brief This header has the declarations for a math token, that is a unit
 * from the math language point of view. A math token can be a number, an infix
 * which is an operator in the middle of two expressions or a parentheses in
 * which the expression inside it takes precedence over what is outside it.
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MATH_TOKEN_H
#define MATH_TOKEN_H

typedef enum
{
  TOK_NULL,
  TOK_ERROR,
  TOK_END,
  TOK_NUMBER,
  TOK_INFIX,
  TOK_OPEN,
  TOK_CLOSE
} TokenType;

typedef struct
{
  const char *start, *next;
  TokenType type;
  union
  {
    double value;
    const void *op;
  };
} Token;

/* Store the next token into TOKEN. The TOKEN must be initializated, so we can
 * continue through him to the next token. */
void next_token (Token *token);

#endif /* MATH_TOKEN_H */
