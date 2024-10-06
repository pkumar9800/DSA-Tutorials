//implement stack using queue
#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q;
public:
    void Push(int x){
        int S= q.size();
        q.push(x);
        for(int i=0; i<S; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int Pop(){
        int popped = q.front();
        q.pop();
        return popped;
    }

    int Top(){
        return q.front();
    }
    int Size(){
        return q.size();
    }
};
int main(){
    stack s;
    s.Push(5);
    s.Push(10);
    s.Push(15);
    cout<<s.Top()<<endl;
    s.Pop();
    cout<<s.Top()<<endl;
    cout<<"Size: "<<s.Size()<<endl;
    return 0;
}