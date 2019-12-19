#ifndef VARIABLE_H
#define VARIABLE_H

#include "Formula.h"

class Variable : public Formula {

	public:
		Variable(char character);
		std::ostream &display(std::ostream & out) const override;
		void getVariables(std::set<char> & setVariables) const override;
		ValuationList valuations() const;

		bool operator()(const Valuation & v) const override;

	private:
		char _character;

};

#endif