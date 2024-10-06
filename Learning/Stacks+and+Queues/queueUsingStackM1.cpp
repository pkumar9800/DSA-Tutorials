//implement queue using stack

//Approach 1
//T.C for Push operations: O(n) , n is the size of inputs to be push
//S.C : O(n), n is the size of dynamic space
#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s1,s2;
public:
    void Push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int Pop(){
        if(s1.empty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        int popped = s1.top();
        s1.pop();
        return popped;
    }

    int Top(){
        return s1.top();
    }
    int Size(){
        return s1.size();
    }
};

int main(){
    Queue q;
    q.Push(5);
    q.Push(10);
    q.Push(15);
    cout<<"Top: "<<q.Top()<<endl;
    cout<<"Popped: "<<q.Pop()<<endl;
    cout<<"Top: "<<q.Top()<<endl;
    q.Push(20);
    cout<<"Size: "<<q.Size()<<endl;
    return 0;
}