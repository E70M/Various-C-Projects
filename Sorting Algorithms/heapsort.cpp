#include <iostream>
#include <vector>
#include <utility>

void heapify(std::vector<int> &arr, int width, int index) {
	int largest = index, left = 2 * index + 1, right = 2 * index + 2;
	if(left < width && arr[left] > arr[largest]) {
		largest = left;
	}
	if(right < width && arr[right] > arr[largest]) {
		largest = right;
	}
	if(largest != index) {
		std::swap(arr[index], arr[largest]);
		heapify(arr, width, largest);
	}
}

void heapSort(std::vector<int> &arr, int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for(int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
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
	heapSort(arr, n);
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}