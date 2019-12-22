#ifndef NEGATION_H
#define NEGATION_H
#include "Formula.h"

class Negation : public Formula {
public:
    Negation(Formula * formula);
    Negation(const Negation & other);

    std::ostream &display(std::ostream & out) const override;
    void getVariables(std::set<char> & setVariables) const override;
    Formula* clone() const override;
    ValuationList valuations() const override;

    bool operator()(const Valuation & v) const override;

    ~Negation();
private:

    Formula * _operation;
};

#endif