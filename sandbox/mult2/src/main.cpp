#include <iostream>
#include "mult2.hpp"

int main() {
    int n;
    std::cout<<"Enter n";
    std::cin>>n;

    int *arr = new int[n];
    for (int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    Mult2(arr, n);
    for (int i=0;i<n;i++){
        std::cout<<arr[i]<<' ';
    }
    
    delete[] arr;
    return 0;
}
