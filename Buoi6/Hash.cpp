#include<math.h>
#include<map>
using namespace std;
long int midSquare(long int seed)
{
    int square=seed*seed;
    return (square/100)%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    int add=0;
	int e=0;
    int t_seed=seed;
    int s_size=0;
    while(t_seed>0){
        t_seed/=10;
        s_size++;
    }
    for(int i=0; i<size; i++){
		int modi= pow(10, s_size - extractDigits[i]);
        e= ((seed%modi)-(seed%(modi/10)))/(modi/10);
		e*=pow(10, size-i-1);
		add+=e;
    }
	return add;
}

int foldShift(long long key, int addressSize) { 
	long long tmp = key; 
	int A[100] = {}; 
	int n = 0;
	while (tmp != 0) { 
        A[n] = tmp % 10; 
        tmp = tmp / 10; 
        n++; 
	} 
	long long sum = 0; 
	while (n>0) { 
		long long s = 0; 
		for (int i = 0; i<addressSize; i++) { 
			if (n - i - 1 >= 0) { 
				s = s * 10 + A[n - i - 1]; 
			} 
		} 
		n -= addressSize; 
		sum += s; 
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t; 
}


int rotation(long long key, int addressSize){ 
	long long tmp = key; 
	int A[100] = {};
	int n = 0; 
	while (tmp != 0){
		A[n] = tmp % 10; 
		tmp = tmp / 10; n++; 
	} 
	tmp = A[0]; 
	for (int i = 0; i<n - 1; i++) A[i] = A[i + 1]; 
	A[n - 1] = tmp; 
	long long sum = 0; 
	while (n>0){ 
		long long s = 0; 
    	for (int i = 0; i<addressSize; i++) { 
    		if (n - i - 1 >= 0) {
    		    s = s * 10 + A[n - i - 1]; 
    		} 
    	} 
    	n -= addressSize; sum += s;
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t;
};

bool findPairs(int arr[], int n, pair<int, int>& pair1, pair<int, int>& pair2)
{
	map<int, pair<int, int>> Hash;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int sum = arr[i] + arr[j];
			if (Hash.find(sum) == Hash.end())
				Hash[sum] = make_pair(i, j);

			else 
			{
				pair<int,int>temp = Hash[sum];
				pair1.first = arr[temp.first];
				pair1.second = arr[temp.second];
				pair2 = make_pair(arr[i],arr[j]);
				return true;
			}
		}
	}
	return false;
}