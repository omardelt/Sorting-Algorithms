#pragma once

#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity:
Best case: O(n log n), when the array is sorted or nearly sorted
Average case: O(n log n), when the array is randomly ordered
Worst case: O(n log n), when the array is sorted in reverse order

Auxiliary Space: O(n)

Stable, performs well on large datasets, but requires additional memory to
store the sorted data and slower than the Quick Sort
*/

/*
Merges two subarrays of arr[]
First subarray is arr[left..mid]
Second subarray is arr[mid+1..right]
*/
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //Temporal vectors
    vector<T> l(n1), r(n2);

    //Copy data to temporal vectors l and r
    for (int i = 0; i < n1; i++){
        l[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        r[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    //Merge temporal vectors back into arr[left..right]
    while (i < n1 && j < n2){
        if (l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements of l[], if any
    while (i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }

    //Copy remaining elements of r[], if any
    while (j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}


template <typename T>
void mergeSort(vector<T>& arr, int left, int right){
    if (left >= right){
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}