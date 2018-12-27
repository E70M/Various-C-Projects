#include <iostream>
#include <vector>
#include <utility>

int partition(std::vector<int> &arr, int startIndex, int endIndex) {
	int pivot = arr[endIndex];
	int i = startIndex - 1;
	for(int j = startIndex; j < endIndex; j++) {
		if(arr[j] <= pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[endIndex]);
	return i + 1;
}

void quickSort(std::vector<int> &arr, int startIndex, int endIndex) {
	if(startIndex < endIndex) {
		int pivot = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pivot - 1);
		quickSort(arr, pivot + 1, endIndex);
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
	quickSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}