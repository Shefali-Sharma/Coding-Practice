/*
Source: GeeksforGeeks - Solution Runtime: 0.01s
Given a string - "str", find the repeated character present first in the string.

Example :
Input  :  geeksforgeeks
Output :  g
          (mind that it will be g, not e.)

Input :
The first line of input contains an integer T denoting the Test cases. Then T test cases follow.
Second line contains the string - "str"

Output :
repeated character present first in the string, if present
otherwise print "-1"


Input :
3
hello
fg
geeksforgeeks

Output :
l
-1
g
*/
#include <iostream>
#include <map>
using namespace std;

int main() {

	int T;
	cin>> T;

	while(T--){
	    int map[257] = {0};
	    string str;
	    cin>>str;
	    int i;
	    for(i = 0; i<str.length(); i++){
	        ++map[int(str[i])];
	    }
	    for(i = 0; i<str.length(); i++){
	       if(map[int(str[i])]>1){
	           cout << str[i] << endl;
	           break;
	       }
	    }
	    if(i==str.length()){
	        cout << -1 << endl;
	    }
	}

	return 0;
}
