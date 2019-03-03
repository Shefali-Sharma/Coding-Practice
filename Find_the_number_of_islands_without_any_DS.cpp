/*
Source: GeeksforGeeks - Solution Runtime: 0.03s

A group of connected 1s forms an island now your task is to complete the method findIslands which returns the no of islands present. The function  takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size of the matrix A .

Input:
The first line of input will be the no of test cases T then T test cases follow. The first line of each test case contains Two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
The output in the expected output will be the total no of islands present.

Constraints:
1<=T<=100
1<=N,M<=50
0<=A[][]<=1

Example(To be used only for expected output) :
Input
1
3 3
1 1 0 0 0 1 1 0 1
Output
2

Explanation
The graph will look like
1 1 0
0 0 1
1 0 1
Here  two islands will be formed
First island will be formed by elements { A[0][0] ,  A[0][1], A[1][2], A[2][2] }
Sec island will be formed by  { A[2][0] }
*/


{
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
/*you are required to complete this method*/
void displayMatrix(int A[MAX][MAX], int N, int M){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout << A[i][j] << " ";
        }
        cout<<endl;
    }
}

void markIsland(int A[MAX][MAX], int N, int M, int i, int j){
    
    A[i][j] = -1;
    if(i>0 && A[i-1][j]==1){
        markIsland(A, N, M, i-1, j);
    }
    if(j>0 && A[i][j-1]==1){
        markIsland(A, N, M, i, j-1);
    }
    if(i>0 && j>0 && A[i-1][j-1]==1){
        markIsland(A, N, M, i-1, j-1);
    }
    if(i<N-1 && A[i+1][j]==1){
        markIsland(A, N, M, i+1, j);
    }
    if(j<M-1 && A[i][j+1]==1){
        markIsland(A, N, M, i, j+1);
    }
    if(i<N-1 && j<M-1 && A[i+1][j+1]==1){
        markIsland(A, N, M, i+1, j+1);
    }
    if(i>0 && j<M-1 && A[i-1][j+1]==1){
        markIsland(A, N, M, i-1, j+1);
    }
    if(i<N-1 && j>0 && A[i+1][j-1]==1){
        markIsland(A, N, M, i+1, j-1);
    }
}

int findIslands(int A[MAX][MAX], int N, int M)
{
    // int visited[MAX][MAX];
    // memset(visited, 0, sizeof(int)*N*M);
    // displayMatrix(A, N, M);
    int count = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 1){
                count++;
                markIsland(A, N, M, i, j);
                // displayMatrix(A, N, M);
            }
        }
    }
    
    return count;
}