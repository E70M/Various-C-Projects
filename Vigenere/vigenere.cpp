#include <iostream>
#include <fstream>
#include <cstdlib>
#include "encrypt.h"

class TreeNode {
private:
	
};

class Tree {

};

int main() {
	string phrase, key;
	int counter = 0;
	std::cout << "Vigenere v1.0\n\n" << std::endl;
	std::cout << "Please enter a phrase to be encrypted: ";
	std::cin >> phrase;
	std::cout << "Please enter a key to encrypt with: ";
	std::cin >> key;
	string phrasekey = getPhraseKey(key, phrase.length());
}