#include <iostream>
#include <string>
#include <limits.h>
class node {
	int m_id;
	std::string path;
public:
	node(int id) {
		m_id = id;
		path = ""; //temporary
	}
	int getID() { return m_id; }
	std::string getPath(int destination) {
		return path; //temporary, will call dijkstra function
	}
};
int main() {
	int nodeCount, source = 0;
	std::cout << "Enter number of nodes:" << std::endl;
	std::cin >> nodeCount;
	while(source < 1 || source > nodeCount) {
		std::cout << "Which node is the source? Please enter an integer from 1 to " << nodeCount << ".\n";
		std::cin >> source;
		if(source < 1 || source > nodeCount) {
			std::cout << "Out of range." << std::endl;
		}
	}
	double weights[nodeCount][nodeCount];
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			weights[i][j] = 0;
		}
	}
	for(int i = 0; i < nodeCount; i++) {
		int edges;
		std::cout << "How many nodes is node " << i + 1 << " connected to?" << std::endl;
		std::cin >> edges;
		for(int j = 0; j < edges; j++) {
			int pos;
			std::cout << "Enter a node that node " << i + 1 << " is connected to:" << std::endl;
			std::cin >> pos;
			if(i == pos - 1) {
				weights[i][pos - 1] = 0;
			} else if(pos - 1 < i) {
				weights[i][pos - 1] = weights[pos - 1][i];
			} else {
				std::cout << "Enter the distance between the two nodes:" << std::endl;
				std::cin >> weights[i][pos - 1];
			}
		}
	}
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			printf("%f\t", weights[i][j]);
		}
		std::cout << "\n";
	} // for testing purposes only
	node nodes[] = { NULL };
	for(int i = 0; i < nodeCount; i++) {
		nodes[i] = node(i + 1);
		std::cout << "node " << nodes[i].getID() << "\tpath from source: " << nodes[i].getPath(source) << std::endl;
	}
}