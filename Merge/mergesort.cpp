#include "mergesort.hpp"

int main(){
    vector<int> arr = {64,34,25,12,22,11,90};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "Merge Sorted array: ";
    for (const auto& num : arr){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}