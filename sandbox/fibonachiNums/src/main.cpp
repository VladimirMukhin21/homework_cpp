#include <iostream>
#include "fibonachiNums.hpp"

int main() {
    int n;
    std::cout<<"Enter n ";
    std::cin>>n;

    int *arr = new int[n];
    FibonachiNums(arr, n);

    for (int i=0;i<n;i++){
        std::cout<<arr[i];
    }
    delete[] arr;
    return 0;
}
