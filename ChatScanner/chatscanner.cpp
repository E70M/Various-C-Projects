#include <iostream>
#include <fstream>
int lineCount(std::ifstream file) {
	int foo;
	return foo;
}
int main() {
	std::ifstream chatlog("chatlog.txt"), blacklist("blacklist.txt"); 
	int cl_length = lineCount(chatlog), bl_length = lineCount(blacklist);
}