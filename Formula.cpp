#include <algorithm>
#include "Formula.h"


std::ostream &operator<<(std::ostream & out, const Formula & other) {
	return other.display(out);
}

bool Formula::operator==(const Formula & other) {
	ValuationList list = valuations();
	ValuationList otherList = other.valuations();
	bool isEquivalent = true;
   
	if (list.getNbVariables() != otherList.getNbVariables()) {
		return false;
	}

	for (int i = 0; i < list.getNbVariables(); i ++) {
		if (list.getVariables()[i] != otherList.getVariables()[i]) {
			return false;
		}
	}
	
	std::for_each(list.begin(), list.end(), [this, &other, &isEquivalent](const Valuation & v) {
		if ((*this)(v) != other(v)) {
			isEquivalent = false;
		}});

	return isEquivalent;
}


bool Formula::isValid() const {
	ValuationList list = valuations();
	bool isValid = true;
	
	std::for_each(list.begin(), list.end(), [this, &isValid](const Valuation & v) {
		if (!(*this)(v)) {
			isValid = false;
		}});
	return isValid;
}

bool Formula::isSatisfiable() const {
	ValuationList list = valuations();
	bool isSatisfiable = false;
	
	std::for_each(list.begin(), list.end(), [this, &isSatisfiable](const Valuation & v) {
		if ((*this)(v)) {
			isSatisfiable = true;
		}});
	return isSatisfiable;
}


Formula::~Formula() {}

