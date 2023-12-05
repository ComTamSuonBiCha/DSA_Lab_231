#include<iostream>
using namespace std;
int findMax(int* arr, int length){
    if (length == 1) return arr[0];
    else {
        int temp = findMax(arr+1, length-1);
        return (arr[0] > temp) ? arr[0] : temp;
    }
}