#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Different types of derivation

// We should first be able to detect what kind of derivation
// is required for a given equation.


/*
  Power Rule derivation
  We are only given polynomials

  Steps:
    1. Split the Polynomial into it's
        terms. E.g. x^2 + 2 -> {"x^2", "2"}
    2. Apply the power rule to each
        individual term
    3. String all of them back together
*/

void splitPolynomial(char *polynomial, int polyStringLen, char **polynomialTerms) {
  int termNumber = 0;
  int termIndex = 0;
  char *term = malloc(sizeof(char) * 255);
  for (int i = 0; i < polyStringLen; i++) {
    if (polynomial[i] != ' ') {
      if ((polynomial[i] == '+') || (polynomial[i] == '-')) {
        polynomialTerms[termNumber++] = strdup(term);
        polynomialTerms[termNumber++][0] = polynomial[i];
        termIndex = 0;
        memset(term, 0, 255);
      } else {
        term[termIndex++] = polynomial[i];
      }
    }
  }
  polynomialTerms[termNumber++] = strdup(term);
  free(term);
}

void deriveTerm(char *term) {

}

int main(int argc, char **argv) {
  char **myPoly = malloc(sizeof(char*) * 255);
  for (int i = 0; i < 256; i++) {
    myPoly[i] = malloc(sizeof(char) * 255);
  }

  splitPolynomial(argv[1], strlen(argv[1]), myPoly);
  for (int i = 0; i < 10; i++) {
    printf("%s ", myPoly[i]);
  }
  printf("\n");
}
