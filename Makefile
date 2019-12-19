CXX = g++
CC=g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -fno-elide-constructors
SRC = main.cpp Formula.h Formula.cpp Variable.h Variable.cpp Negation.h Negation.cpp Conjunction.h Conjunction.cpp Disjunction.h Disjunction.cpp Valuation.h Valuation.cpp BuildFormula.h BuildFormula.cpp 
FILES = README.txt Makefile $(SRC)
EXEC = main
OBJ = $(SRC:.cpp=.o)

.PHONY: clean all tar files

all: $(EXEC)

main: $(OBJ)

clean:
	rm -f *.o *~  $(EXEC)

files: $(SRC)
	if [ -f "./files.txt" ]; then rm files.txt; fi
	for file in $(FILES); do \
		echo $$file >> files.txt; \
	done

tar: clean files
	mkdir Lecouillard_Weber
	cp $(FILES) files.txt ./Lecouillard_Weber
	tar -cf Lecouillard_Weber.tar Lecouillard_Weber; rm -rf Lecouillard_Weber 
	/home/public/CPlusPlus/cppcheck.sh  Lecouillard_Weber.tar
	

	
