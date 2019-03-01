/*
Source: GeeksforGeeks - Solution Runtime: 0.01s

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list which is list representation of addition of two input numbers.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of first linked list and next line contains N elements of the linked list. Again, next line contains M, and following line contains M elements of the linked list.

Output:
Output the resultant linked list.

User Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of new list.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7

Output:
0 9 3  
0 7

Explaination:
5->4 // linked link repsentation of 4 5.
5->4->3 // linked list representation of 3 4 5.
0->9 ->3 // linked list representation of 3 9 0 resultant linked list.
*/
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is */
#include <stack>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
/*You are required to complete this method */

int getLength(Node *head){
    Node* h = head;
    int count = 0;
    while(h){
        count++;
        h = h->next;
    }
    return count;
}
bool isPalindrome(Node *head)
{
    int len = getLength(head);
    stack<int> s;
    int i = 0;
    while(i<(len/2)){
        s.push(head->data);
        head= head->next;
        i++;
    }
    // cout << s.size() << " " << head->data << endl;
    if(len%2 != 0){
        head = head->next;
    }
    while(!s.empty() && head!=NULL){
        if(s.top() != head->data){
            return false;
        }
        s.pop();
        head = head->next;
    }
    
    return true;
}