/*
 * Solve.c
 *
 *  Created on: Sep 11, 2019
 *      Author: Artem
 */
//assertы разбить на функции (+лин ур-ие)
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Solve.h"

int main() {
	float a = NAN,
	      b = NAN,    //y = ax^2 + bx + c
		  c = NAN;
	float x1, x2;
	//Get and check values
	int cv = GetVal(&a, &b, &c); //Ret 1 if invalid enter
	if (cv) return -1;
	//Solution
	int cs = 0;
	if(a == 0) cs = SolveLinear(b, c, &x1); //When equation is linear
	cs = SolveSquare(a, b, c, &x1, &x2);

	switch (cs){
	case TwoSol:
		printf("Solution is: x1 = %g, x2 = %g\n", x1, x2);
		break;
	case OneSol:
		printf("Solution is: x = %g\n", x1);
		break;
	case Infinite:
		printf("Solution is: x is any number\n");
		break;
	case NoSol:
		printf("There is no solutions!\n");
		break;
	}
	return 0;
}

int GetVal(float *a, float *b, float *c) {
	assert(a != NULL);
	assert(b != NULL);
	assert(c != NULL);

	printf("Enter coefficients a, b, c (ax^2 + bx + c = 0):\n");
	scanf("%f", a);
	scanf("%f", b);
	scanf("%f", c);
	if(isnan(*a) || isnan(*b) || isnan(*c)) {
		printf("Invalid enter!\n");
		return 1;
	}

	printf("Your equation is:  (%gx^2) + (%gx) + (%g) = 0\n", *a, *b, *c);
	return 0;
}

int SolveSquare(float a, float b, float c, float* x1, float* x2) {
    assert(x1 != NULL);
    if(a == 0) return SolveLinear(b, c, x1);
    assert(x1 != NULL);
	//Calculate discriminant D
	float D = b*b - 4*a*c;
	if(D > 0) {
		*x1 = (-b - sqrtf(D)) / (2*a);
		*x2 = (-b + sqrtf(D)) / (2*a);
		return TwoSol;
	}
	if(D == 0) {
		*x1 = (-b) / (2*a);
		return OneSol;
	}
	if(D < 0) {
		return NoSol;
	}
	return 0;
}

int SolveLinear(float  b, float  c, float *x1) {
	if(b == 0) {
		if(c == 0) return Infinite;
		return NoSol;
	}
	*x1 = (-c) / b;
	return OneSol;
}
