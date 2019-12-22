#ifndef VARIABLE_H
#define VARIABLE_H

#include "Formula.h"

class Variable : public Formula {

	public:
		Variable(char character);
		Variable(const Variable & other);
		std::ostream &display(std::ostream & out) const override;
		void getVariables(std::set<char> & setVariables) const override;
		Formula* clone() const override;
		ValuationList valuations() const override;

		bool operator()(const Valuation & v) const override;

	private:
		char _character;

};

#endif