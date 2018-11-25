#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "sudokugen.h"

class Grid {
private:
	const static int m_rows = 9, m_columns = 9, subgrids = 9, squares = 81;
	std::string difficulty;
public:
	Grid(std::string difficulty) {
		this->difficulty = difficulty;
	}
};
int main() {
	int difficulty;
	std::string str, diff;
	std::cout << "Welcome to SudokuGen 1.0\n\n"
		<< "Enter a puzzle difficulty (easy, medium, hard):" << std::endl;
	std::cin >> str;
	for(int i = 0; i < diff.length(); i++) {
		diff = tolower(diff.at(i));
	}
	if(!(diff == "medium" || str == "hard")) {
		std::cout << "Default difficulty (easy) chosen." << std::endl;
		diff = "easy";
	}
	Grid *sudokuGrid = new Grid(diff);
	return 0;
}