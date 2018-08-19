/*
Source: GeeksforGeeks - Solution Runtime: 0.03s
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings in a sequence and the second line contains N space separated strings.

Output:
For each test case, in a new line print the second most repeated string.

Constraints:
1<=T<=100
3<=N<=103
1<=|String length|<=100

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    map <string, int> strsMap;
	    int maxCount = 0;
	    int nextMaxCount = 0;
	    string secMaxStr = "", maxStr = "";

	    int N;
	    cin>>N;
	    N--;
	    string firstInput;
	    cin>>firstInput;
	    strsMap.insert(pair<string, int > (firstInput, 1));
	    map <string, int>::iterator it1;

	    while(N--){
	        string input;
	        cin>>input;
	        map <string, int>::iterator it = strsMap.find(input);
	        if(it == strsMap.end()){
	            strsMap.insert(pair<string, int > (input, 1));
	        }
	        else{
	            it->second = it->second + 1;
	        }
	    }

	    for(it1 = strsMap.begin(); it1 != strsMap.end(); it1++){
	            if(it1->second > maxCount){
	                nextMaxCount = maxCount;
	                maxCount = it1->second;
	                secMaxStr = maxStr;
	                maxStr = it1->first;
	            }
	            else if (it1->second > nextMaxCount){
	                secMaxStr = it1->first;
	                nextMaxCount = it1->second;
	            }
	        }
	    cout << secMaxStr << endl;

	}
	return 0;
}
