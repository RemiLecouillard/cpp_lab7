#include "Variable.h"

Variable::Variable(char character) : _character(character) {

}

std::ostream &Variable::display(std::ostream & out) const {
    out << _character;
    return out;
}

bool Variable::operator()(const Valuation & v) const {
    return v.at(_character);
}

void Variable::getVariables(std::set<char> & setVariables) const {
    setVariables.insert(_character);
}

ValuationList Variable::valuations() const {
    std::set<char> character;
    character.insert(_character);
    return ValuationList(character);
}


Formula* Variable::clone() const {
    return new Variable(_character);
}

Variable::Variable(const Variable & other) : _character(other._character) {
}