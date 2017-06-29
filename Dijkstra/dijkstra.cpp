#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
class coordinate {
	int x, y;
	bool visited;
public:
	void setX(int x) {this->x = x;}
	void setY(int y) {this->y = y;}
	void setVisited(bool v) {this->visited = v;}
	int getX() {return x;}
	int getY() {return y;}
	bool isVisited() {return visited;}
	coordinate(int x, int y) {
		setX(x);
		setY(y);
		setVisited(false);
	}
};
void displayGrid(int l, int w, std::vector<coordinate> coords, std::vector<coordinate> path) {
	for(int i=0; i<l; i++) {
		for(int j=0; j<w; j++) {
			for(int k=0; k<coords.size(); k++) {
				if(i == coords[k].getX() && j == coords[k].getY()) {std::cout << "[]\t";}
				else {std::cout << "*\t";}
			}
		}
		std::cout << "\n";
	}
}
void dijkstra() {
	//Note: if there are multiple paths of equal length, use a PRNG to pick a path
}
int main() {
	int length = 0, width = 0, foo, bar, temp; std::vector<coordinate> coords, path;
	std::cout << "\nDijkstra's Algorithm 1.0\nEnter the x-position of the starting point:\n"; std::cin >> foo;
	std::cout << "Enter the y-position of the starting point:\n"; std::cin >> bar;
	coordinate *c = new coordinate(foo, bar); coords.push_back(*c); delete c;
	std::cout << "Enter the x-position of the end point:\n"; std::cin >> foo;
	std::cout << "Enter the y-position of the end point:\n"; std::cin >> bar;
	c = new coordinate(foo, bar); coords.push_back(*c); delete c;
	std::cout << "How many other points would you like? Please enter here:\n"; std::cin >> temp;;
	for(int i=0; i<temp; i++) {
		std::cout << "Enter the x-position of a point:\n"; std::cin >> foo;
		std::cout << "Enter the y-position of a point:\n"; std::cin >> bar;
		c = new coordinate(foo, bar); coords.push_back(*c); delete c;
	}
	for(int i=0; i<coords.size(); i++) {
		if(coords[i].getX() > length) {length = coords[i].getX();}
		if(coords[i].getY() > width) {width = coords[i].getY();}
	}
	displayGrid(length, width, coords, path); //tests grid for now
}