#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <set>
#include "Valuation.h"

class Formula {
	public:
		virtual ~Formula();
		
		virtual std::ostream &display(std::ostream & out) const = 0;
		virtual void getVariables(std::set<char> & setVariables) const = 0;
		virtual ValuationList valuations() const = 0;
		virtual Formula* clone() const = 0;
		bool isValid() const;
		bool isSatisfiable() const;

		virtual bool operator()(const Valuation & v) const = 0;
		friend std::ostream &operator<<(std::ostream & out, const Formula & other);
		bool operator==(const Formula & other2);

};
#endif 