/*
Source: GeeksforGeeks - Solution Runtime: 0.04s
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two integers N & K and the second line contains N space separated array elements.

Output:
For each test case, print the count of required subarrays in new line.

Constraints:
1<=T<=200
1<=N<=105
1<=K<=1015
1<=A[i]<=105

Example:
Input:
2
4 10
1 2 3 4
7 100
1 9 2 8 6 4 3

Output:
7
16

Explanation:

Input : A[]={1, 2,3,4}
        K = 10
Output : 7
The contiguous subarrays are {1}, {2}, {3}, {4}
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.

*/
#include <iostream>
#define ll long long
using namespace std;


ll countSubArray(ll int arr[], int N, ll int K){
    ll int res = 0;
    int i = 0, s = 0;
    ll int prod = 1;
    while(i<N){
        prod *= arr[i];

        if(prod < K){
            res += i - s + 1;
        }
        else{
            while(prod>K && s<i){
                prod/=arr[s++];
            }
            if(prod < K){
                res += i - s + 1;
            }
        }

        ++i;
    }
    return res;
}

int main() {

	int T;
	cin>> T;

	while(T--){
	 int N;
	 ll int K;
	 ll int count = 0;
	 cin>>N >> K;
	 ll int arr[N];
	 for(int i = 0; i<N; i++){
	     cin>>arr[i];
	 }


	 cout << countSubArray(arr, N, K) << endl;
	}
	return 0;
}
