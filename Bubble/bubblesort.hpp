#pragma once

#include <iostream>
#include <vector>
using namespace std;


/*
Time Complexity: O(n^2)

Auxiliary Space: O(1)

Stable, but not practical as it is slow with huge amount of data
*/
template <typename T> 
void bubbleSort (vector<T> arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Bubble Sorted array: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}