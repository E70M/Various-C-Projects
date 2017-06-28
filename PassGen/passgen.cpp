#include <iostream>
#include <cstdlib>
#include <ctime>
char genChar(int i) {
	if(i < 35 || (i >= 39 && i <= 47) || (i >= 58 && i <= 63) || (i >= 91 && i <= 96)) {return genChar(rand() % 123);}
	else {return static_cast<char>(i);}
}
int main() {
	srand(static_cast<unsigned int>(time(0))); int length; std::string pass = ""; 
	std::cout << "\nPassGen 1.0\nEnter the length of the password:\n"; std::cin >> length;
	for(int i=0; i<length; i++) {pass += genChar(rand() % 123);}
	std::cout << "\nGenerated: " << pass << "\n\n"; return 0;
}