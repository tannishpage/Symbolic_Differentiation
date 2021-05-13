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

int splitPolynomial(char *polynomial, int polyStringLen, char **polynomialTerms) {
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
  return termNumber;
}

int getCoefficient(char *term, char *variable) {
  char *coefficient = strtok(strdup(term), variable);
  if (strcmp(coefficient, term) == 0) {
    return 0;
  }
  return strtol(coefficient, NULL, 10);
}

/*int getCoefficient(char *term, int length, char variable) {
	char *coefficient = malloc(sizeof(char) * length);
	for (int i = 0; i < length; i++) {
		if (term[i] == variable) {
			if (i == 0) {
				return 1;
			}
      break;
		} else {
      coefficient[i] = term[i];
    }
	}
  // Convert our coefficient string to an integer
  return strtol(coefficient, NULL, 10);
}*/

int getPower(char *term) {
  strtok(strdup(term), "^");
  char *power = strtok(NULL, "^");
  if (power == NULL){
    return 1;
  }
  return strtol(power, NULL, 10);
}

void deriveTerm(char *term, int length) {
	/* Steps:
	 			1. Find the coefficient of the term
				2. Find the power of the term
				3. Then multiply power and coefficient (new coefficient)
				4. Subtract 1 from power
				5. Put it all together.
	*/
}

int main(int argc, char **argv) {
  char **myPoly = malloc(sizeof(char*) * 255);
  for (int i = 0; i < 256; i++) {
    myPoly[i] = malloc(sizeof(char) * 255);
  }

  int numberOfTerms = splitPolynomial(argv[1], strlen(argv[1]), myPoly);
  for (int i = 0; i < numberOfTerms; i++) {
    if (strcmp(myPoly[i], "+") != 0 && strcmp(myPoly[i], "-") != 0){
        printf("Term: %s\t", myPoly[i]);
        printf("Coefficient: %d\t", getCoefficient(myPoly[i], "x"));
        printf("Power: %d\n", getPower(myPoly[i]));
    }
  }
  printf("\n");
}
