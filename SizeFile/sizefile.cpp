#include <iostream>
#include <fstream>
int main() {
	std::string filename, filepath; std::streampos begin, end;
	std::cout << "SizeFile 1.0\nEnter the file path:\n"; std::cin >> filepath;
	std::cout << "Enter the name of the file:\n"; std::cin >> filename;
	std::ifstream myfile(filepath+filename, std::ios::binary);
	begin = myfile.tellg(); myfile.seekg(0, std::ios::end);
	end = myfile.tellg(); myfile.close();
	std::cout << "\n" << filename << " is " << (end-begin) << " bytes.\n\n";
	return 0;
}