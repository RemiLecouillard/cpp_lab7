#ifndef CONJUNCTION_H
#define CONJUNCTION_H
#include <iostream>
#include <cstdlib>
#include "Formula.h"

class Conjunction : public Formula {
public:

    Conjunction(Formula * formula1,Formula * formula2);

    std::ostream &display(std::ostream & out) const override;
    bool operator()(const Valuation & v) const override;
    void getVariables(std::set<char> & setVariables) const override;
    Formula* clone() const override;
    ValuationList valuations() const override;

    ~Conjunction();

private:

    Formula * _leftOp;
    Formula * _rightOp;
};

#endif