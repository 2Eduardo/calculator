#ifndef MATH_PARSE_H
#define MATH_PARSE_H

#include <math.h> /* for NAN */

#ifndef NAN
#define NAN 0.0 / 0.0
#endif /* NAN */

typedef enum
{
  NODE_CONSTANT,
  NODE_FUNCTION0 = 8,
  NODE_FUNCTION1, /* unary fn */
  NODE_FUNCTION2  /* binary fn */
} NodeType;

typedef struct ParseNode
{
  NodeType type;
  union
  {
    double value;
    const void *op;
  };
  struct ParseNode *params[1];
} ParseNode;

ParseNode *math_parse_str (const char *expression);

double math_parse_eval (const ParseNode *root);

void math_parse_free (ParseNode *node);

#endif /* MATH_PARSE_H */
