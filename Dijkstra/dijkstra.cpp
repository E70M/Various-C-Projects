#include <iostream>
class coordinate {
	int x, y;
public:
	void setX(int x) {this->x = x;}
	void setY(int y) {this->y = y;}
	int getX() {return x;}
	int getY() {return y;}
};
void displayGrid(int l, int w, coordinate coords[]) {
	for(int i=0; i<l; i++) {
		for(int j=0; j<w; j++) {
			if((i == coords[0].getX() && j == coords[0].getY()) || (i == coords[1].getX() && j == coords[1].getY())) {
				std::cout << "[]\t";
			}
			else {std::cout << "*\t";}
		}
		std::cout << "\n";
	}
}
void dijkstra() {

}
int main() {
	int length, width, temp; coordinate coords[2]; //coordinate path[]
	std::cout << "\nDijkstra's Algorithm 1.0\nEnter the length of the grid:\n"; std::cin >> length;
	std::cout << "Enter the width of the grid:\n"; std::cin >> width;
	std::cout << "Enter the x-position of the starting point:\n"; std::cin >> temp; coords[0].setX(temp);
	std::cout << "Enter the y-position of the starting point:\n"; std::cin >> temp; coords[0].setY(temp);
	std::cout << "Enter the x-position of the end point:\n"; std::cin >> temp; coords[1].setX(temp);
	std::cout << "Enter the y-position of the end point:\n"; std::cin >> temp; coords[1].setY(temp);
	displayGrid(length, width, coords); //tests grid for now
}