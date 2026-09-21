#pragma once

#include <iostream>
#include <vector>
using namespace  std;


/*
Time Complexity: O(n^2)

Auxiliary Space: O(1)

Not stable and slow, but it requires less number of swaps 
compared to many other standard algorithms
*/
template <typename T>
void selectionSort(vector<T> arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            swap(arr[i], arr[min]);
        }
    }
    cout << "Selection Sorted array: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
} 
