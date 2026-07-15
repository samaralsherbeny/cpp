#include<iostream>
#include<vector>
#include <algorithm>

int main() {
	std::vector<int> v = { 2,1 };
	std::sort(v.begin(), v.end());
	std::cout << "Sorted: ";
	for (int num : v)
		std::cout << num << "  ";
	std::cout << '\n';
	v.push_back(3);
	std::cout << "first push back:  ";
	for (int num : v)
		std::cout << num << "  ";
	std::cout << '\n';
	std::cout << "Element at index 2 has value " << v.at(2) << '\n';
	v.push_back(4);
	std::cout << "second push back:  ";
	for (int num : v)
		std::cout << num << "  ";
    std::cout << '\n';
    std::cout << "after erasing an element:  ";
        v.erase(v.begin() + 2);
        for (int num : v) 
            std::cout << num << " ";
            std::cout << '\n';
    std::vector<int> arr1 = { 100, 200, 300, 400, 500 };
    std::vector<int> arr2 = { 10, 20, 30, 40, 50 };
    std::cout << " Array 2 Before : ";
    for (const auto& num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    arr1.swap(arr2);

    std::cout << " Array 1 After : ";
    for (const auto& num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << " Array 2 After : ";
    for (const auto& num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::vector<int> vect;
    std::cout << "before resize : ";

    for (int num : vect )
        std::cout << num << "  ";
    std::cout << '\n';
    vect.resize(3);       
    vect[0] = 5;          
    vect[1] = 10;          
    vect[2] = 15;    
    std::cout << "after resize : ";

    for (int num : vect)
        std::cout << num << "  ";
    std::cout << '\n';
}
