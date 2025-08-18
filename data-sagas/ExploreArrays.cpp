#include <iostream>
#include <vector>

void exploreArrays() {
    std::cout << "Running array experiments...\n";
    // TODO: implement Part 1 experiments
	// Run experiments on arrays to understand performance and behavior
	std::cout << "Running array experiments... \n";

	// Example: Create an array of integers and perform some operations
	int n = 5;
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		arr[i] = i * i; // Fill the array with squares of indices
	}

	// TODO : add timing experiments for growth and resizing
}
