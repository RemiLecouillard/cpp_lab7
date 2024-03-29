#ifndef DISJUNCTION_H
#define DISJUNCTION_H
#include <iostream>
#include "Formula.h"

class Disjunction : public Formula {
public:
    Disjunction(Formula * formula1,Formula * formula2);
    Disjunction(const Disjunction & other);
    Disjunction operator=(const Disjunction & other);

    std::ostream &display(std::ostream & out) const override;
    void getVariables(std::set<char> & setVariables) const override;
    Formula* clone() const override;
    ValuationList valuations() const override;

    bool operator()(const Valuation & v) const override;
    ~Disjunction();

private:

    Formula * _leftOp;
    Formula * _rightOp;

};

#endif