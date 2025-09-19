#include "getMax.hpp"

int GetMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; ++i) {
        // max = max > arr[i] ? arr[i]:max; // True:False
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}