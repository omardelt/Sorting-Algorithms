#pragma once

#include <iostream>
#include <vector>
using namespace std;


/*
Time Complexity:
Best case: O(n) if list already sorted
Average case: O(n^2) if the list is randomly ordered
Worst case: O(n^2) if the list is in reverse order

Auxiliary Space: O(1)

Stable, but inefficient for large lists 
*/
template <typename T>
void insertionSort(vector<T> arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Insertion Sorted array: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}