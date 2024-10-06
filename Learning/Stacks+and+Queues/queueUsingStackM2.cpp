//implentation of queue using stack 
//This is Approach two
//where timecomplexity is optimised to ≈ O(N)
//Space complexity remains same i.e. 2

#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s1,s2;
public:
    void Push(int x){
        s1.push(x);
    }

    int Top(){
        if(!s2.empty()){
            return s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();   
    }

    int Pop(){
        if(!s2.empty()){
            int popped = s2.top();
            s2.pop();
            return popped;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int popped = s2.top();
        s2.pop();
        return popped;
    }

    int Size(){
        return s1.size()+s2.size();
    }

};

int main(){
    Queue q;
    q.Push(5);
    q.Push(10);
    q.Push(15);
    cout<<"Top: "<<q.Top()<<endl;
    cout<<"Popped: "<<q.Pop()<<endl;
    cout<<"Popped: "<<q.Pop()<<endl;
    cout<<"Popped: "<<q.Pop()<<endl;
    q.Push(20);
    cout<<"Top: "<<q.Top()<<endl;
    q.Push(21);
    q.Push(22);
    cout<<"Size: "<<q.Size()<<endl;
    return 0;
}