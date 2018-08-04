/*
Source: GeeksforGeeks - Solution Runtime: 0.01s
Given a string s, the task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of first occurrence is smallest.

Examples:

Input:  s = "geeksforgeeks"
Output: e
e is the first element that repeats

Input:  s = "hellogeeks"
Output: l
l is the first element that repeats

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the first repeating character in the string. If no such character exist print -1.

Constraints:
1<=T<=100
1<=Length of string <=1000

Example:
Input:
2
geeksforgeeks
hellogeeks
Output:
e
l
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	int T;
	cin>> T;
	while(T--){
	    string str;
	    cin>>str;
	    int map[257] = {0};
	    int i;
	    for(i = 0; i<str.length(); i++){
	        map[int(str[i])] += 1;
	        if(map[int(str[i])]>1){
	            cout << str[i] << endl;
	            break;
	        }
	    }
	    if(i == str.length()){
	        cout << -1 << endl;
	    }

	}

	return 0;
}
