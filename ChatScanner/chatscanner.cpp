#include <iostream>
#include <fstream>
int lineCount(std::string filename) {
	std::ifstream file(filename.c_str()); file.unsetf(std::ios_base::skipws);
    unsigned line_count = std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n');
    return line_count;
}
std::string get_bl_keyword(int pos, std::string filename) {
	std::ifstream file(filename.c_str()); file.unsetf(std::ios_base::skipws); std::string line, bar;
	for(int i=0; i<pos; i++) {std::getline(file, line);}
	bar = line;
	return bar;
}
int main() {
	std::ifstream chatlog("chatlog.txt"), blacklist("blacklist.txt");
	int cl_length = lineCount("chatlog.txt"), bl_length = lineCount("blacklist.txt");
	std::cout << "The chat log is " << cl_length << " lines long.\n"; //test length
	std::cout << "The blacklist is " << bl_length << " lines long.\n"; //test length
	std::cout << "Test keyword: " << get_bl_keyword(1, "blacklist.txt") << "\n"; //test keyword selection
	for(int i=1; i<bl_length+1; i++) {
		while(!chatlog.eof()) {
			std::string line; std::getline(chatlog, line);
			for(int k=0; k<line.length(); k++) {
				for(int j=line.length(); j>k; j--) {
					if(line.substr() == get_bl_keyword(i, "blacklist.txt")) {
						std::string user = line.substr(0, line.find(":"));
						std::cout << "Flagged user: " << user << ". Would you like to ban this player?\n";
					}
				}
			}
		}
	}
	chatlog.close(); blacklist.close(); return 0;
}