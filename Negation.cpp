#include "Negation.h"

Negation::Negation(Formula * formula) : _operation(formula) {

}


std::ostream &Negation::display(std::ostream & out) const {
    out << "~";
    out << *_operation;
    return out;
}

void Negation::getVariables(std::set<char> & setVariables) const {
    (*_operation).getVariables(setVariables);
}


bool Negation::operator()(const Valuation & v) const {
    return !(*_operation)(v);
}


Negation::~Negation() {
    delete _operation;
}

ValuationList Negation::valuations() const {
    return _operation->valuations();
}
