#include <iostream>
#include <fstream>
#include <string>
#include "Negation.h"
#include "Variable.h"
#include "BuildFormula.h"
#include "Disjunction.h"
#include <algorithm>

using namespace std;


int main(int argc, char ** argv) {
	if (argc != 2)
	{
		cerr << "Missing parameters" << endl;
		return EXIT_FAILURE;
	}
	char space = ' ';
	char character;
	string formula1_str;
	string formula2_str;
	ifstream file(argv[1]);

	if(file) {
		while (file.good())
			{
			file >> formula1_str;		
			file.get(character);
			if(character != space) {
				cerr << "Wrong file format" << endl;
				return EXIT_FAILURE;
			}
			file >> formula2_str;
			const char *formula1_chars = formula1_str.c_str();
			const char *formula2_chars = formula2_str.c_str();

			Formula *formula1 = buildFormula(formula1_chars);
			Formula *formula2 = buildFormula(formula2_chars);
			if (*formula1 == *formula2) {
				cout << *formula1 << " and " << *formula2 << " are equivalent."<< endl;
			} else {
				cout << *formula1 << " and "  << *formula2 << " are not equivalent."  << endl;
			}
		}
	} else {
		cerr << "Can not open this file!" << endl;
		return EXIT_FAILURE;
	}
	file.close();

	return EXIT_SUCCESS;
}