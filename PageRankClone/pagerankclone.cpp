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
	double weights[nodeCount][nodeCount];
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			if(i == j) {
				weights[i][j] = 0;
			} else if(j < i) {
				weights[i][j] = weights[j][i];
			} else {
				std::cout << "Enter weight of path from node " << i + 1 << " to node " << j + 1 << ":\n";
				std::cin >> weights[i][j];
				if(weights[i][j] < 0) {
					weights[i][j] *= -1;
				}
			}
		}
	}
	/*
	for(int i = 0; i < nodeCount; i++) {
		for(int j = 0; j < nodeCount; j++) {
			std::cout << weights[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/ //for test purposes only, displays adjacency matrix
}