#include "reverse.hpp"

void Reverse(int *arr, size_t len) {
    int k;
    for (int i=len-1; i>len/2; i--){
        k=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=k;
    }
}