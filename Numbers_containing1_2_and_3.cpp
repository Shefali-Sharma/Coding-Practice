/*
Source: GeeksforGeeks - Solution Runtime: 0.07s
Given an array of numbers, the task is to print only those numbers which have only 1, 2 and 3 as their digits.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an integer N and the second line contains N space separated array elements.

Output:
For each test case, In new line print the required elements in increasing order. if there is no such element present in the array print "-1".

Constraints:
1<=T<=100
1<=N<=106
1<=A[i]<=106

Example:
Input:
2
3
4 6 7
4
1 2 3 4

Output:

-1
1 2 3
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--){
	    int N;
	    cin>>N;
	    int flag = 0;
	    int arr[N];
	    int k = 0;
	   // while(N--){
	   for(int i =0; i<N; i++){
	        int x;
	        cin>>x;
	        int num = x;

	        while(num){
	            int check = num%10;
	           // cout << check << " ";
	            if(check>=1 && check<=3){
	                num/=10;
	            }
	            else
	                break;
	        }

	        if(num == 0){
	            flag = 1;
	           arr[k++] = x;
	           // cout<< x << " ";   // Printing here instead of storing and later printing everythong together - caused the program to take more than 0.192s
	        }
	    }
	    sort(arr, arr+k);
	    for(int i = 0; i<k; i++)
	        cout<<arr[i] << " ";
	    if(flag == 0)
	        cout << -1;
	    cout<<endl;
	}



	return 0;
}
