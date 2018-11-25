/*
 *	Author: Eitan Myron
 *	Date: 11/24/18
 *	Project: API Call Builder
 *	Description: Reads in fields and values from a csv file and writes them to a text 
 *	file as formatted JSON strings.
 *	Distributed with a free-will license. (Insert all the legal jargon)
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main() {
	std::ifstream input("index.csv");
	std::ofstream output("json.txt");
	std::vector<std::string> vals;
	std::string fields;
	while(input.good()) {
		if(fields.empty()) {
			std::getline(input, fields);
			while(fields.find(",", 0) != std::string::npos) {
				fields = fields.replace(fields.find(",", 0), 1, ":");
			}
		}
		std::string val;
		std::getline(input, val);
		vals.push_back(val);
	}
	for(int i = 0; i < vals.size(); i++) {
		std::string line = "{", temp = fields;
		while(temp.find(":") != std::string::npos) {
			line += temp.substr(0, temp.find(":")) + ":\"" + vals.at(i).substr(0, vals.at(i).find(",")) + "\",";
			temp = temp.substr(temp.find(":") + 1);
			vals.at(i) = vals.at(i).substr(vals.at(i).find(",") + 1);
		}
		line += temp.substr(0, temp.find("\r")) + ":\"" + vals.at(i).substr(0, vals.at(i).find("\r")) + "\"}\n";
		std::cout << line;
		output << line;
	}
	output.close();
}