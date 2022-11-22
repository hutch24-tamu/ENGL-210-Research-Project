#include "SortLib.h"

template <typename T>
T* merge(T arr1[], int size1, T arr2[], int size2){  //This function merges two sorted lists, so the result is sorted
    int i = 0;                        //This int is used to index arr1
    int j = 0;                        //This int is used to index arr2
    int k = 0;                        //This int is used to index merged, the merged sorted list
    
    if(size1 == 0)                    //Checks if easy answer (if arr1 is empty)
        return arr2;                    //If so, then return arr2
    else if(size2 == 0)               //Checks if easy answer (if arr2 is empty)
        return arr1;                    //If so, then return arr1

    T* merged = new T[size1+size2];   //Dynamically allocated array to hold merged sorted list
    bool done = false;                //Used to see when all elems put in merged or when one array is empty

    while(!done){                     //Main loop to fill merged
        if(arr1[i] < arr2[j]){        //First sees if arr1[i] is greater than arr2[j]
            merged[k] = arr1[i];        //If so, merged[k] should be the smaller (arr1[i])
            i++;                        //Increments arr1 indexs' value (so we know what else needs to be put in merged)
        }
        else{                         //Will execute if arr1[i] > arr2[j]
            merged[k] = arr2[j];        //If so, merges[k] should be the smaller or equal (arr2[j])
            j++;                        //Increments arr2 indexs' value (so we know what else needs to be put in merged)
        }

        done = (i == size1) || (j == size2);  //Checks if one or both of the lists are empty (if i == size1, or j == size2)
                                              //then no more elems to put in merged
        k++;                                  //Increments the sorted mnerged list's index (so that we know where to put new elems)
    }
    
    if(i != size1){                   //Will input remaining elems in arr1 into merged if there are any
        for(int x = i; x < size1; x++){
            merged[k] = arr1[x];
            k++;
        }
    }
    else if(j != size2){              //Will input remaining elems in arr2 into merged if there are any
        for(int y = j; y < size2; y++){
            merged[k] = arr2[y];
            k++;
        }
    }

    return merged;                    //Returns the sorted merged array
}

template <typename T>
T* mergeSort(T arr[], int size){            //Implements merge sort recursivley
    if(size > 2){                           //Checks if size greater than 2
        int firstSize = size / 2;             //If so, determine the size for the first half of arr
        T first[firstSize] = {};              //Creates new array to put first half of arr into
        for(int i = 0; i < firstSize; i++)    //Puts elements from first half of arr into first
            first[i] = arr[i];

        int secondSize = size - firstSize;    //Determines the size for the second half of arr
        T second[secondSize] = {};            //Creates new array to put the second half of arr
        for(int j = 0; j < secondSize; j++)   //Puts elements from second half of arr into second
            second[j] = arr[j+firstSize];

        //This line calls mergeSort (this function) on the first and second halves of arr. Once those
        //are resolved, the lists are merged. Note that mergeSort could call itself multiple times
        //and hence merge could be called multiple times. Because of implementation, this means memory leaks
        return merge( mergeSort(first, firstSize), firstSize, mergeSort(second, secondSize), secondSize);
    }
    else if(size == 2 && (arr[0] > arr[1])){//If size == 2 and the first value in arr is smaller than the second, swap them
        T temp = arr[0];                      //Temp var used to swap
        arr[0] = arr[1];                      //Setting lower index to higher indexed value
        arr[1] = temp;                        //Sets higher indexed value to lower indexed value (using temp)
        return arr;                           //Returns swapped array (so this two element array is sorted)
    }
    else                                    //If the size is two and sorted or if the size if one
        return arr;                           //Returns the array, since it's already sorted

}

template <typename T>
void SortLib::MergeSort(T arr[], int size){ //This function brings all these functions together to implement merge sort
    T* newArr = mergeSort(arr, size);       //Makes temp arr to hold values gotten from the recursive function
    for(int i = 0; i < size; i++)           //Puts all the sorted values into arr to complete the sort
        arr[i] = newArr[i];
}

template void SortLib::MergeSort(int*, int);  //Lets compiler knwo what to expect 