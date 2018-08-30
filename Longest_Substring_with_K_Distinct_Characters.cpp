/*
Solved program: https://ide.geeksforgeeks.org/1FcdJRjR19
Given a string you need to print longest possible substring that has exactly M unique characters. If there are more than one substring of longest possible length, then print any one of them.

Examples:

"aabbcc", k = 1
Max substring can be any one from {"aa" , "bb" , "cc"}.

"aabbcc", k = 2
Max substring can be any one from {"aabb" , "bbcc"}.

"aabbcc", k = 3
There are substrings with exactly 3 unique characters
{"aabbcc" , "abbcc" , "aabbc" , "abbc" }
Max is "aabbcc" with length 6.

"aaabbb", k = 3
There are only two unique characters, thus show error message.
*/
// C++ program to find the longest substring with k unique
// characters in a given string
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int counter = 0;
    int start = 0, head = 0, maxLen = 0, i;

    vector<int> remaining(128, 0);
    for(i = 0; i<s.length(); i++){
        if(remaining[s[i]]++ == 0){
            counter++;
        }

        while(counter > k && start<i){
            if(maxLen < i-start){
                maxLen = i-start;
                head = start;
            }

            remaining[s[start]]--;
            if(remaining[s[start]] == 0){
                counter--;
                start++;
                break;
            }
            start++;
        }
    }

    if(counter<k){
        cout << "Not Enought characters." << endl;
        return;
    }

    if(maxLen < i-start){
        maxLen = i-start;
        head = start;
    }
    cout << s.substr(head, maxLen) << endl;
}

// Driver function
int main()
{
	string s = "aabb";
	int k = 3;
	kUniques(s, k);
	return 0;
}
