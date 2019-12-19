/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file   BuildFormula.h
 * @author Sebastien Fourey
 */
#ifndef BUILD_FORMULA_H
#define BUILD_FORMULA_H

#include "Formula.h"
#include "Conjunction.h"
#include "Disjunction.h"
#include "Negation.h"
#include "Valuation.h"
#include "Variable.h"

Formula * buildFormula(const char * str, const char ** end = nullptr);

#endif // !defined(BUILD_FORMULA_H)
