#include "SortLib.h"

template <typename T>
T max(T arr[], int size){  //This function finds the largest value
    T max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}


template <typename T>
T min(T arr[], int size){   //This function finds the smallest value
    T min = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

template <typename T>
void SortLib::CountingSort(T arr[], int size){  //This function implements counting sort
    T maximum = max(arr,size);                  //Gets the max in the array
    T minimum = min(arr,size);                  //Gets the min in the array
    T* countArr = new T[maximum-minimum+1]{};   //Creates the count array. Uses a range instead of 0 to max (so smaller array)
    T newArr[size] = {};                        //Temporary array to hold sorted values

    for(int i = 0; i < size; i++)               //Creates the count array (how many 1s, 2s, for instance)
        countArr[arr[i] - minimum]++;


    for(int i = 1; i < maximum-minimum+1; i++)  //Adds the count to get indexes at each position
        countArr[i] += countArr[i-1];


    for(int i = size-1; i >= 0; i--){           //Fills newArr (the temp array) with the sorted values, decrements in countArr (to
        newArr[countArr[arr[i]-minimum]-1] = arr[i]; //preserve correct index)
        countArr[arr[i]-minimum]--;
    }

    delete[] countArr;                          //Deallocates countArr (was allocated so could handle exceeding large ranges)

    for(int i = 0; i < size; i++)               //Puts the sorted list into arr, which is given to user, since passed as a pointer
        arr[i] = newArr[i]; 
}




template void SortLib::CountingSort(int*, int); //Tells compiler what types to prepare for