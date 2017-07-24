#include <iostream>
#include <fstream>
std::string get_bl_keyword(int pos, std::string filename) {
	std::ifstream file(filename.c_str()); file.unsetf(std::ios_base::skipws); std::string line;
	for(int i=0; i<pos; i++) {std::getline(file, line);}
	return line;
}
void checkChat(std::string line, int blPos) {
	int pos = line.find(get_bl_keyword(blPos, "blacklist.txt"));
	if(pos >= 0) {std::cout << "Flagged user: " << line.substr(0, line.find(":")) << ". Want to ban them?\n";}
}
int main() {
	std::ifstream chatlog("chatlog.txt"), blacklist("blacklist.txt"); std::string line; blacklist.unsetf(std::ios_base::skipws);
	int bl_length = std::count(std::istream_iterator<char>(blacklist), std::istream_iterator<char>(), '\n') + 1;
	for(int i=1; i<=bl_length; i++) {
		std::cout << "Scanning chat for: " << get_bl_keyword(i, "blacklist.txt") << "\n";
		while(!chatlog.eof()) {std::getline(chatlog, line); checkChat(line, i);}
		std::getline(chatlog, line); checkChat(line, bl_length);
	}
	chatlog.close(); blacklist.close(); return 0;
}