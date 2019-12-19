/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file   BuildFormula.cpp
 * @author Sebastien Fourey
 */
#include "BuildFormula.h"
#include <cctype>  // For isalpha(int)
#include <cstdlib> // For exit(int)
#include <iostream>

Formula * buildFormula(const char * str, const char ** end)
{
  if (!str || !*str) {
    return nullptr;
  }
  switch (*str) {
  case '(':
  case ')':
  case ' ':
    return buildFormula(str + 1, end);
  case '~':
    return new Negation(buildFormula(str + 1, end));
  case '&': {
    const char * endLeft;
    Formula * left = buildFormula(str + 1, &endLeft);
    Formula * right = buildFormula(endLeft, end);
    return new Conjunction(left, right);
  }
  case '|': {
    const char * endLeft;
    Formula * left = buildFormula(str + 1, &endLeft);
    Formula * right = buildFormula(endLeft, end);
    return new Disjunction(left, right);
  }
  default: // It must be a variable...
  {
    if (!isalpha(*str)) {
      std::cerr << "\nFatal error: unrecognized symbol (" << (*str) << ")\n";
      exit(-1);
    }
    if (end) {
      *end = str + 1;
    }
    return new Variable(*str);
  }
  }
}
