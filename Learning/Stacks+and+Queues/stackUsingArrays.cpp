//implement stack using arrays

#include<iostream>
using namespace std;

class stack{
private:
    int capacity;
    int Top;
    int *arr;
public:
    stack(int capacity){
        Top = -1;
        this->capacity = capacity;
        arr = new int[capacity];
    }
    void push(int x);
    int pop();
    int top();
    int size();
    bool isEmpty();
    bool isFull();
};

void stack::push(int x){
    if(Top==capacity-1){
        cout<<"Cannot be inserted!--> Stack Overflow"<<endl;
    }else{
        Top++;
        arr[Top] = x;
    }
}

int stack::pop(){
    if(Top==-1){
        cout<<"Stack Underflow!!! No elements to pop"<<endl;
        return -1;
    }
    else{
        int x = arr[Top];
        arr[Top] = 0;
        Top--;
        return x;
    }
}

int stack::top(){
    if(Top==-1){
        cout<<"Stack is empty!!!"<<endl;
        return -1;
    }else{
        return arr[Top];
    }
}

int stack::size(){
    return Top+1;
}

bool stack::isEmpty(){
    return Top==-1? true:false;
}

bool stack::isFull(){
    return Top==(capacity-1) ? true: false;
}
int main(){
    stack s(10);
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    s.push(5);
    s.push(6);
    s.push(1);
    cout<<"size: "<<s.size();
    return 0;
}