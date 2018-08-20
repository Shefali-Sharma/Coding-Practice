/*
Source: GeeksforGeeks - Solution Runtime: 0.02s
Implement a Queue using Array.

Input (To be used for Expected Output):

The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries .
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop element from queue and print the poped element)

The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the queue is empty else the element poped out from the queue .
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the quee  and pop which returns a integer poped out from othe queue.

Constraints:
1<=T<=100
1<=Q<=100
1<=x<=100

Example:
Input
1
5
1 2 1 3 2 1 4 2

Output
2 3

Explanation:

In the first test case for query
1 2    the quee will be {2}
1 3    the queue will be {2 3}
2       poped element will be 2 the queue will be {3}
1 4    the queue will be {3 4}
2       poped element will be 3
*/

{
#include<bits/stdc++.h>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
};
class Queue {
private:
    int arr[10001];
    int front;
    int rear;
public :
    Queue(){front=0;rear=0;}
    void push(int);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue *sq = new Queue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
    }

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is
class Queue {
private:
    int arr[10001];
    int front;
    int rear;
public :
    Queue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue */

Queue *myQueue = new Queue();
void Queue :: push(int x)
{
        // if(myQueue->front == 0 && myQueue->rear==0){
        if(rear != front-1){
            if(rear == 10000){
                rear = 0;
                myQueue->arr[rear++] = x;
            }
            else{
                myQueue->arr[rear++] = x;
            }
        }



}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
        if(front == rear){
            return -1;
        }
        if(front == 1000){
            front = 0;
            return myQueue->arr[1000];
        }
        return myQueue->arr[front++];
}
