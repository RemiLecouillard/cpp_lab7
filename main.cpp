#include <iostream>

#include "Negation.h"
#include "Variable.h"
#include "BuildFormula.h"
#include "Disjunction.h"
#include <algorithm>

using namespace std;


int main(int argc, char ** argv) {

	Formula *f = buildFormula("(&(&(|pq)(|pr))(&~pt))");
	Formula *f2 = buildFormula("(&(&(|pq)(|pr))(&~pt))");
	Valuation v;
	ValuationList list = f->valuations();
	cout << list.getVariables() << " " << list.getNbVariables() << endl;
	
	std::cout << *f << endl;
	std::for_each(list.begin(), list.end(), [](const Valuation & v) {cout << v << endl;});

	cout << "is Valid ? ";
	cout << f->isValid() << endl;
	cout << "is satisfiable ? ";
	cout << f->isSatisfiable() << endl;    
	cout << "is equal ? ";
	cout << (*f==*f2) << endl;
}