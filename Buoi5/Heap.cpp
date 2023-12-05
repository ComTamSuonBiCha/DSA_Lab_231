#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int getItem(T item);
    void remove(T item);
    void clear();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
//Your code goes here

template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return this->count==0;
}

template<class T>
T Heap<T>::peek(){
    if (isEmpty())
        return -1;
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i=0;i<count;i++) {
        if (elements[i] == item)
            return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (isEmpty())
        return false;
    elements[0]=elements[count-1];
    count--;
    reheapDown(0);
    return true;
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count+1);
    elements[count] = item;
    count++;
    reheapUp(count-1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity) {
        capacity*=2;
        T* newElements = new T[capacity];
        memcpy(newElements, elements, count*sizeof(T));
        delete elements;
        elements = newElements;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    int parent = (position-1)/2;
    T newItem = elements[position];
    while(position > 0 && newItem > elements[parent]) {
        elements[position] = elements[parent];
        position = parent;
        parent = (position-1)/2;
    }
    elements[position] = newItem;
}

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i=0;i<count;i++)
        if (elements[i]==item)
            return i;

    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1)
        return;
    elements[index] = elements[count-1];
    if (index < count-1) {
        reheapDown(index);
    }
    if (index > 0) {
        reheapUp(index);
    }
    count--;
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    count = 0;
    delete[] elements;
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int largerChild;
    int temp = maxHeap[index];
    while(index<numberOfElements/2) {
        int leftChild = 2*index+1;
        int rightChild = 2*index+2;
        if (rightChild < numberOfElements && maxHeap[leftChild] < maxHeap[rightChild]) {
            largerChild = rightChild;
        } else {
            largerChild = leftChild;
        } if (temp >= maxHeap[largerChild]) {
            break;
        } 
        maxHeap[index] = maxHeap[largerChild];
        index = largerChild;
        } 
    maxHeap[index] = temp;    
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    int parent = (index-1)/2;
    int temp = maxHeap[index];
    while(index>0 && temp>maxHeap[parent]){
        maxHeap[index] = maxHeap[parent];
        index = parent;
        parent = (index-1)/2;
    }
    maxHeap[index] = temp;
}

template<class T>
static void heapify(T* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
template<class T>
static void heapSort(T* start, T* end){
//TODO
    long size = end - start;
    for (long i = size / 2 - 1; i >= 0; i--)
        heapify(start, size, i);
    for (long i = size - 1; i > 0; i--) {
    // Move current root to end
        swap(start[0], start[i]);
        heapify(start, i, 0);
    } 
    Sorting<T>::printArray(start, end);
}

#include<queue>
#include<string>
#include<iostream>
using namespace std;
class PrinterQueue
{
private:
    struct Compare{
        bool operator()(const pair<int, pair<int,string>> &lhs, const pair<int, pair<int,string>> &rhs )
        {
            if (lhs.second.first != rhs.second.first) return lhs.second.first < rhs.second.first;
            return lhs.first>rhs.first;
        }
    };
    priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, Compare> pq;
    int timestamp;
    // your attributes
public:
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        // your code here
        pq.push(make_pair(timestamp++, make_pair(priority, fileName)));
    }

    void print()
    {
        if (pq.empty())
        {
            cout << "No file to print" << endl;
            return;
        }
        cout << pq.top().second.second << endl;
        pq.pop();
        // your code here
        // After some logic code, you have to print fileName with endline 
    }
};

int leastAfter(vector<int>& nums, int k) {
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> pq (nums.begin(), nums.end());
    while(k>0){
        int smallest = pq.top();
        pq.pop();
        pq.push(smallest*2);
        k--;
    }
    return pq.top();
}