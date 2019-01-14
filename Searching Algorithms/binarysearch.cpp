// This program assumes the set is not entered in sorted order and therefore sorts the set
// in ascending order with mergesort first.
#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int middle, int right) {
	int half1 = middle - left + 1, half2 = right - middle, pos = left;
	int leftArr[half1], rightArr[half2];
	for(int i = 0; i < half1; i++) {
		leftArr[i] = arr[left + i];
	}
	for(int j = 0; j < half2; j++) {
		rightArr[j] = arr[middle + 1 + j];
	}
	int leftPos = 0, rightPos = 0;
	while(leftPos < half1 && rightPos < half2) {
		if(leftArr[leftPos] <= rightArr[rightPos]) {
			arr[pos] = leftArr[leftPos];
			leftPos++;
		} else {
			arr[pos] = rightArr[rightPos];
			rightPos++;
		}
		pos++;
	}
	while(leftPos < half1) {
		arr[pos] = leftArr[leftPos];
		leftPos++;
		pos++;
	}
	while(rightPos < half2) {
		arr[pos] = rightArr[rightPos];
		rightPos++;
		pos++;
	}
}

void mergeSort(std::vector<int> &arr, int left, int right) {
	if(left < right) {
		int middle = left + (right - left) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

int binarySearch(std::vector<int> &arr, int left, int right, int target) {
	if(right >= 1) {
		int middle = left + (right - left) / 2;
		if(arr[middle] == target) {
			return middle;
		} else if(arr[middle] > target) {
			return binarySearch(arr, left, middle - 1, target);
		}
		return binarySearch(arr, middle + 1, right, target);
	}
	return -1;
}

int main() {
	int n, target, pos;
	std::vector<int> arr;
	std::cout << "Enter length of set of integers:" << std::endl;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		std::cout << "Enter a value:" << std::endl;
		std::cin >> x;
		arr.push_back(x);
	}
	mergeSort(arr, 0, n - 1);
	std::cout << "Set has been sorted. Enter target value:" << std::endl;
	std::cin >> target;
	pos = binarySearch(arr, 0, n - 1, target);
	std::cout << "Position of " << target << " (starting at i = 0): " << pos << std::endl;
	return 0;
}