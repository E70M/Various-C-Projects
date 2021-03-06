#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr) {
	for(int i = 0; i < arr.size(); i++) {
		for(int j = i + 1; j < arr.size(); j++) {
			if(arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main() {
	int n;
	std::vector<int> arr;
	std::cout << "Enter length of set of integers:" << std::endl;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		std::cout << "Enter a value:" << std::endl;
		std::cin >> x;
		arr.push_back(x);
	}
	std::cout << "Unordered set: ";
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\nOrdered set (in ascending order): ";
	bubbleSort(arr);
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}