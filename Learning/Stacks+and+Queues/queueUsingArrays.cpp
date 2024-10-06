//implementation of Queue using array
#include<iostream>
using namespace std;

class Queue{
private:
    int Capacity;
    int start;
    int end;
    int *arr;
    int size;
public:
    Queue(int Capacity){
        this->Capacity=Capacity;
        arr = new int[Capacity];
        start = -1;
        end = -1;
        size=0;
    }

    void push(int x){
        if(size==Capacity){
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(end==-1){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1)%Capacity;
        }
        arr[end] = x;
        size = size+1;
    }
    int pop(){
        if(size==0){
            cout<<"Queue is empty!!!"<<endl;
            return -1;
        }
        int popped = arr[start];
        if(size==1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1)%Capacity;
        }
        size = size-1;
        return popped;
    }
    int top(){
        if(start==-1){
            cout<<"Queue is empty!!!"<<endl;
            return -1;
        }else{
            return arr[start];
        }
    }
    int Size(){
        cout<<"Size: ";
        return size;
    }
    int capacity(){
        return Capacity;
    }
    bool empty(){
        if(start==-1){
            return true;
        }else{
            return false;
        }
    }
    bool full(){
        return size==Capacity? true: false;
    }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Top element popped: "<<q.pop()<<endl;
    cout<<"Top element popped: "<<q.pop()<<endl;
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<"Top element popped: "<<q.pop()<<endl;
    cout<<"Top element: "<<q.top()<<endl;
    cout<<"Size: "<<q.Size()<<endl;
    cout<<"Capacity: "<<q.capacity()<<endl;
    cout<<"Empty: "<<q.empty()<<endl;
    cout<<"Full: "<<q.full()<<endl;
    return 0;
}