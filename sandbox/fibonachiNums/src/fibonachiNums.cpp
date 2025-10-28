#include "fibonachiNums.hpp"

void FibonachiNums(int *arr, int n) {
    for (int i=1; i<n; i++){
        arr[i]=arr[i-1] + arr[i-2];
    }
};