#include "SortLib.h"
#include <algorithm>
#include <iostream>

template <typename T>
T median3(T arr[], int left, int right){
    int center = (left + right) / 2;

    if(arr[center] < arr[left])
        std::swap(arr[left], arr[center]);
    if(arr[right] < arr[left])
        std::swap(arr[left], arr[right]);
    if(arr[right] < arr[center])
        std::swap(arr[center], arr[right]);

    std::swap(arr[center], arr[right-1]);
    return arr[right-1];
}

template <typename T>
void quicksort(T arr[], int left, int right){    
    if(right-left < 2) return;

    T pivot = median3(arr, left, right);

    int i = left;
    int j = right-1;

    for(;;){
        while(arr[++i] < pivot) { }
        while(pivot < arr[--j]) { }
        if(i < j)
            std::swap(arr[i], arr[j]);
        else 
            break;
    }

    std::swap(arr[i], arr[right-1]);

    quicksort(arr, left, i-1);
    quicksort(arr, i+1, right-1);
}

template <typename T>
void SortLib::QuickSort(T arr[], int size){
    quicksort(arr, 0, size);
}

template void SortLib::QuickSort(int*, int);