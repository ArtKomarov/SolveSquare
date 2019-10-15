/*
 * Solve.h
 * With declaration
 *  Created on: Sep 11, 2019
 *      Author: Artem
 */

#ifndef SOLVE_H_
#define SOLVE_H_

/// Possible number of solutions of the square equation
enum{
	TwoSol = 0, ///< Two solutions
	OneSol = 1, ///< One solution
	Infinite = 2, ///< Infinite number of solutions
	NoSol = 3 ///< No solutions
};

/**
 * \brief Reads values ​​from the keyboard and check them
 *
 *
 * \param *a Coefficient before \f$x^2\f$
 * \param *b Coefficient before \f$x\f$
 * \param *c Free coefficient
 * \return - 0 if enter is OK; - 1 if enter is invalid;
 */
int GetVal (float *a, float *b, float *c);

/** \brief Solves square equation
 *
 * \param [in] a Coefficient before x^2
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \param [out] *x1 First solution
 * \param [out] *x2 Second solution
 */
int SolveSquare (float  a, float  b, float  c, float *x1, float *x2);

/** \brief Solves linear equation
 *
 * \param [in] b Coefficient before x
 * \param [in] c Free coefficient
 * \param [out] *x1 is the solution
 */
int SolveLinear (float  b, float  c, float *x1);

/**Print a result
 * \return - 0 if OK; - -1 if enter is invalid;
 */
int main();

#endif // SOLVE_H_
