#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    map <string, int> strsMap;
	    int maxCount = 1;
	    string maxStr;

	    int N;
	    cin>>N;
	    N--;
	    string firstInput;
	    cin>>firstInput;
	    maxStr = firstInput;
	    strsMap.insert(pair<string, int > (firstInput, 1));

	    while(N--){
	        string input;
	        cin>>input;
	        map <string, int>::iterator it = strsMap.find(input);
	        if(it == strsMap.end()){
	            strsMap.insert(pair<string, int > (input, 1));
	        }
	        else{
	           // cout << it->second << endl;
	            it->second = it->second + 1;
	            if(maxCount < it->second++){
	                maxCount = it->second;
	                maxStr = input;
	            }
	        }

	    }

	    cout << maxStr << endl;

	}
	return 0;
}
