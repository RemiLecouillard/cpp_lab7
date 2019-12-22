#include "Disjunction.h"


Disjunction::Disjunction(Formula * formula1,Formula * formula2) : _leftOp(formula1), _rightOp(formula2) {

}


std::ostream &Disjunction::display(std::ostream & out) const {
    out << "(";
    out << *_leftOp;
    out << "|";
    out << *_rightOp;
    out << ")";
    return out;
}

bool Disjunction::operator()(const Valuation & v) const {
    return (*_leftOp)(v) || (*_rightOp)(v);
}

Disjunction::~Disjunction() {
    delete _leftOp;
    delete _rightOp;
}

void Disjunction::getVariables(std::set<char> & setVariables) const {
    (*_leftOp).getVariables(setVariables);
    (*_rightOp).getVariables(setVariables);
}

ValuationList Disjunction::valuations() const {
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

Formula* Disjunction::clone() const {
    return new Disjunction(_rightOp->clone(), _leftOp->clone());
}

Disjunction::Disjunction(const Disjunction & other) {
    _leftOp = other._leftOp->clone();
    _rightOp = other._rightOp->clone();
}

Disjunction Disjunction::operator=(const Disjunction & other) {
    if (_leftOp) {
        delete _leftOp;
    }
    if (_rightOp) {
        delete _rightOp;
    }

    if (other._leftOp) {
        _leftOp = other._leftOp->clone();
    } else {
        _leftOp = nullptr;
    }

    if (other._rightOp) {
        _rightOp = other._rightOp->clone();
    } else {
        _rightOp = nullptr;
    }

    return *this;
}