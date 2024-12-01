#include <stdio.h>

struct rational {
  int numerator;
  int denominator;
};

struct rational rationalAdd(struct rational a, struct rational b);
struct rational rationalSubtract(struct rational a, struct rational b);
struct rational rationalMultiply(struct rational a, struct rational b);
struct rational rationalDivide(struct rational a, struct rational b);
struct rational rationalSimplify(struct rational r);
int gcd(int a, int b);

