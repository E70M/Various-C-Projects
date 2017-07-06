#include <iostream>
#include <fstream>
int lineCount(std::string filename) {
	std::ifstream file(filename.c_str()); file.unsetf(std::ios_base::skipws);
    return std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n') + 1;
}
std::string get_bl_keyword(int pos, std::string filename) {
	std::ifstream file(filename.c_str()); file.unsetf(std::ios_base::skipws); std::string line;
	for(int i=0; i<pos; i++) {std::getline(file, line);}
	return line;
}
void checkChat(std::string line, int blPos) {
	for(int k=0; k<line.length(); k++) {
		for(int j=line.length(); j>k; j--) {
			if(line.substr(j, k) == get_bl_keyword(blPos, "blacklist.txt")) {
				std::cout << "Flagged user: " << line.substr(0, line.find(":")) << ". Want to ban them?\n";
			}
		}
	}
}
int main() {
	std::ifstream chatlog("chatlog.txt"), blacklist("blacklist.txt"); std::string line;
	int bl_length = lineCount("blacklist.txt");
	for(int i=1; i<bl_length+1; i++) {
		std::cout << "Scanning chat for: " << get_bl_keyword(i, "blacklist.txt") << "\n";
		while(!chatlog.eof()) {std::getline(chatlog, line); checkChat(line, i);}
		std::getline(chatlog, line); checkChat(line, bl_length);
	}
	chatlog.close(); blacklist.close(); return 0;
}