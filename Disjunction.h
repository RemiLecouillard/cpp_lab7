#ifndef DISJUNCTION_H
#define DISJUNCTION_H
#include <iostream>
#include "Formula.h"

class Disjunction : public Formula {
public:
    Disjunction(Formula * formula1,Formula * formula2);

    std::ostream &display(std::ostream & out) const override;
    void getVariables(std::set<char> & setVariables) const override;
    ValuationList valuations() const;

    bool operator()(const Valuation & v) const override;
    ~Disjunction();

private:

    Formula * _leftOp;
    Formula * _rightOp;

};

#endif