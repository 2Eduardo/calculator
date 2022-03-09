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
