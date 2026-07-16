#include<iostream>
#include<vector>
#include <algorithm>
#include <map>
using namespace std;

void reverse_in_place(vector<int>& v) {
    int left = 0;
    int right = v.size() - 1;
    while (left < right) {
        swap(v[left], v[right]);
        left++;
        right--;
    }
}

void printVector(const vector<int>& v) {
    cout << "Vector: " << endl;
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}
void printFrequencies(const vector<int>& v) {
    map<int, int> freq_map;
    for (int num : v) {
        freq_map[num]++;
    }
    for (auto const& pair : freq_map) {
        cout << "  " << pair.first << " appears " << pair.second << " time(s)" << endl;
    }
}
int findSecondLargest(const vector<int>& v) {
    if (v.size() < 2) return -1; 

    int largest = -2147483648;      
    int second_largest = -2147483648;

    for (int num : v) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest && num != largest) {
            second_largest = num;
        }
    }
    return second_largest;
}
void removeDuplicates(vector<int>& v) {
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
}
int main()
{
    vector<int> v1 = { 1,2,3,6,8 };
    vector<int> v2 = { 100,250,35,420,50 };
    vector<int> v3 = { 10, 20, 10, 50, 30, 50, 40, 20, 50 };
    cout << " Initial Vectors" << endl;
    printVector(v1);
    printVector(v2);
    cout << endl;

    cout << " Sorting Checks " << endl;
    cout << boolalpha; 
    cout << "Is V1 Sorted: " << is_sorted(v1.begin(), v1.end()) << endl;
    cout << "Is V2 Sorted: " << is_sorted(v2.begin(), v2.end()) << endl;
    cout << endl;

    cout << "--- Reversing V1 In-Place ---" << endl;
    reverse_in_place(v1); 

    printVector(v1);
    cout << " Frequencies " << endl;
    printFrequencies(v3);
    cout << endl;

    cout << " Second Largest " << endl;
    int second = findSecondLargest(v3);
    cout << "Second largest value in v3: " << second << endl;
    cout << endl;

    cout << " Remove Duplicates" << endl;
    removeDuplicates(v3);
    printVector(v3);
    return 0;
}
