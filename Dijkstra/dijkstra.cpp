#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class node {
	double weight;
public:
	void setWeight(double weight) { this->weight = weight; }
};
int main() {
	int nodeCount;
	std::cout << "Enter number of nodes:" << std::endl;
	std::cin >> nodeCount;
	double distances[nodeCount][nodeCount];
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			distances[i][j] = 0;
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
				distances[i][pos - 1] = 0;
			} else if(pos - 1 < i) {
				distances[i][pos - 1] = distances[pos - 1][i];
			} else {
				std::cout << "Enter the distance between the two nodes:" << std::endl;
				std::cin >> distances[i][pos - 1];
			}
		}
	}
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			std::cout << distances[i][j] << " ";
		}
		std::cout << "\n";
	} // for testing purposes only
}