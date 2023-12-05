#include<iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x)
{
    if (right < left) {
        return -1;
    }
    int mid = left + (right - left)/2;
    cout << "We traverse on index: "<<mid << endl;
    if (arr[mid] == x){
        return mid;
    }
    if (arr[mid] < x)
        return binarySearch(arr, mid+1, right, x);
    else
        return binarySearch(arr, left, mid-1, x);
}

int interpolationSearch(int arr[], int left, int right, int x) {
    if (left <= right && x >= arr[left] && x <= arr[right]) {
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
        cout << "We traverse on index: " << pos << endl;
        if (arr[pos] == x) {
            return pos;
        }
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, right, x);
        } if (arr[pos] > x) {
            return interpolationSearch(arr, left, pos - 1, x);
        }
    }
    return -1;
}

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, other
    int step = sqrt (n);
    int prev = 0;
    int i = 0;
    for (; i < n; i += step) {
        cout << i << " ";
        if (arr[i] == x)
        return i;
        if (arr[i] > x)
        break;
        prev = i;
    } 
    if (arr[prev] > x) 
        return -1;
    for (int m = prev + 1; m < min (i + step, n) + 1; m++) {
        if (arr[m] > x)
            return -1;
        cout << m << " ";
        if (arr[m] == x)
            return m;
    } 
    return -1;
}
#include<map>
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2){
    map<int, pair<int, int>> sumPairs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sumPairs.find(sum) != sumPairs.end()) {
                pair1 = sumPairs[sum];
                pair2 = make_pair(arr[i], arr[j]);
                return true;
            } 
            else {
                sumPairs[sum] = make_pair(arr[i], arr[j]);
            }
        }
    } 
    return false;
}