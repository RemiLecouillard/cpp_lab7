#include "Conjunction.h"
#include <set>


Conjunction::Conjunction( Formula * formula1,Formula * formula2) : _leftOp(formula1), _rightOp(formula2) {

}


std::ostream &Conjunction::display(std::ostream & out) const {
    out << "(";
    out << *_leftOp;
    out << "&";
    out << *_rightOp;
    out << ")";
    return out;
}

bool Conjunction::operator()(const Valuation & v) const {
    return (*_leftOp)(v) & (*_rightOp)(v);
}

void Conjunction::getVariables(std::set<char> & setVariables) const {
    (*_leftOp).getVariables(setVariables);
    (*_rightOp).getVariables(setVariables);
}

Conjunction::~Conjunction() {
    delete _leftOp;
    delete _rightOp;
}

ValuationList Conjunction::valuations() const {
    std::set<char> characters;
    
    ValuationList list = _leftOp->valuations();
    for (int i = 0; i < list.getNbVariables(); i ++) {
        characters.insert(list.getVariables()[i]);
    }

    list = _rightOp->valuations();
    for (int i = 0; i < list.getNbVariables(); i ++) {
        characters.insert(list.getVariables()[i]);
    }
    
    return ValuationList(characters);
}

Formula* Conjunction::clone() const {
    return new Conjunction(_rightOp->clone(), _leftOp->clone());
}

Conjunction::Conjunction(const Conjunction & other) {
    _leftOp = other._leftOp->clone();
    _rightOp = other._rightOp->clone();
}