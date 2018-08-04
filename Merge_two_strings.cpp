/*
Source: GeeksforGeeks - Solution Runtime: 0.01s
Given two strings S1 and S2 as input, the task is to merge them alternatively i.e. the first character of S1 then the first character of S2 and so on till the strings end.

NOTE: Add the whole string if other string is empty.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings S1 and S2.

Output:
For each test case, print the merged string in new line.

Constraints:
1<=T<=100
1<=|strings length|<=104

Example:
Input:
2
Hello Bye
abc def

Output:
HBeylelo
adbecf
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>> T;

	while(T--){
	    string str1, str2;
	    cin>>str1 >> str2;
	    string res = "";
	    int i = 0;

	    if(str1.length()<str2.length()){
	        while(i<str1.length()){
	            res.push_back(str1[i]);
	            res.push_back(str2[i]);
	           // cout << res << endl;
	            i++;
	        }
	        while(i<str2.length()){
	            res.push_back(str2[i]);
	            i++;
	        }
	    }
	    else{
	        while(i<str2.length()){
	            res.push_back(str1[i]);
	            res.push_back(str2[i]);
	           // cout<< res << endl;
	            i++;
	        }
	        while(i<str1.length()){
	            res.push_back(str1[i]);
	            i++;
	        }
	    }

	    cout << res << endl;
	}

	return 0;
}
