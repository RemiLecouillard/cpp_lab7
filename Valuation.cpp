#include "Valuation.h"
#include <cmath>

std::ostream &operator<<(std::ostream & out,const Valuation & other) {
    out << "[";

    for (Valuation::const_iterator it = other.begin(); it != other.end(); it++) {
        Valuation::const_iterator tmp = it;
        tmp++;
        if (tmp != other.end()) {
            out << it->first << "=" << it->second << ",";
        } else {
            out << it->first << "=" << it->second;
        }
    }
    out << "]";
    return out;
}

ValuationList::ValuationList(std::set<char> & setVariables) {
    std::set<char>::iterator it;
    char *tmp;

    _variables = new char[setVariables.size()];
    tmp = _variables;
    _nbVariables = setVariables.size();

    for (it = setVariables.begin(); it != setVariables.end(); it++) {
        *tmp = *it;
        tmp++;
    }

}


ValuationList::Iterator ValuationList::begin() const{
    return ValuationList::Iterator(*this, 0);
}

ValuationList::Iterator ValuationList::end() const{
    return ValuationList::Iterator(*this, std::pow(2,_nbVariables));
}

ValuationList::Iterator& ValuationList::Iterator::operator++() {
    _position++;
    return *this;
}

ValuationList::Iterator ValuationList::Iterator::operator++(int) {
    ValuationList::Iterator tmp(*this);
    operator++(); 
    return tmp;
}

bool ValuationList::Iterator::operator==(Iterator const & other) const {
    return _position == other._position;
}

bool ValuationList::Iterator::operator!=(Iterator const & other) const {
    return _position != other._position;
}

bool bit(int x, int i) {
    return (x>>(i)) & 1;
}

Valuation ValuationList::Iterator::operator*() const{
    Valuation v;

    for (int i = 0; i < _list._nbVariables; i ++) {
        v[_list._variables[i]] = bit(_position, i);
    }

    return v;
}
