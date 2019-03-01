/*
Source: GeeksforGeeks - Solution Runtime: 0.01s
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints:

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000


Example:

Input:
2
4
1 5 11 5
3
1 3 5

Output:

YES
NO
*/
#include <iostream>
#include <vector>
using namespace std;

bool findPartition(vector<int> arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum+= arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    bool res[arr.size()][sum/2 + 1];
    for(int i = 0; i<arr.size(); i++){
        res[i][0] = true;
    }

    for(int i = 0; i<arr.size(); i++){
        for(int j = 1; j<sum/2 + 1; j++){
            if(arr[i] == j){
                res[i][j] = true;
            }
            else if(i != 0 && (res[i-1][j - arr[i]] == true)){
                res[i][j] = true;
            }
            else{
                res[i][j] = false;
            }
        }
        if(res[i][sum] == true){ return true; }
    }

    return res[arr.size() - 1][sum];
}

int main() {
	int T;
	cin>>T;

	while(T--){
	    int n;
	    cin>>n;
	    vector<int> arr;

	    for(int i = 0; i<n; i++){
	        int item;
	        cin>>item;
	        arr.push_back(item);
	    }

	    if(findPartition(arr)){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }

	}
	return 0;
}
