#ifndef VALUATION_H
#define VALUATION_H

#include <map>
#include <set>
#include <iostream>

typedef std::map<char,bool> Valuation;

std::ostream &operator<<(std::ostream & out,const Valuation & other);

class ValuationList {
	public:
		ValuationList(std::set<char> & setVariables);

	class Iterator {   
		public:
			Iterator(const ValuationList &list, int nb): _list(list), _position(nb){};

			Iterator& operator++();
			Iterator operator++(int);
			
			Valuation operator*() const;
			bool operator==(const Iterator & other) const;
			bool operator!=(const Iterator & other) const;

		private:
            const ValuationList & _list;
			int _position;
	};

	Iterator begin() const;
	Iterator end() const;

    char* getVariables() const { return _variables;}
    int getNbVariables() const { return _nbVariables;}
		
	private:
		char* _variables;
		int _nbVariables;
};


#endif 