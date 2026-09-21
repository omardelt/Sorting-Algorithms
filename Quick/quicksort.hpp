#pragma once

#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity:
Best case: Omega(n log n), when pivot element divides elements into
equal halves
Average case: Theta(n log n), when pivot divides array into two parts, but
not necessarily equal
Worst case: O(n^2), when smallest or largest element is always chosen as 
pivots (for example, in sorted arrays)

Auxiliary Space: 
Worst case: O(n) 
Best case: O(log n)

Not stable and no good for small data sets, but efficient on large data sets, 
requires small amount of memory to function, cache friendly and fast
*/
template <typename T>
int partition (vector<T>& arr, int low, int high){

    //Choose pivot
    int pivot = arr[high];

    //Undex of smaller element and indicates the right
    //position of the pivot found so far
    int i = low - 1;

    //Traverse arr[low..high] and move all smaller
    //elements on left side. Elements from low to i
    //are smaller after every iteration
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    } 

    //Move pivot after smaller elements and return its position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(vector<T>& arr, int low, int high){
    if (low < high){
        
        //pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        
        //recursion calls for smaller elements and greater or equal elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

