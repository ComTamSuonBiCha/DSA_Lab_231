#include<iostream>
using namespace std;
void printPattern(int n)
{
    cout << n ;
    if (n>0)
    {
        cout << " ";
        printPattern(n-5);
        cout << " "<< n;
    }
}