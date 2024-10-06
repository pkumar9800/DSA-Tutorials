//implement queue using linked list

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = nullptr;
    }
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
    Node(int x, Node* ptr){
        this->data=x;
        this->next = ptr;
    }
};

class queue{
public:
    Node* start;
    Node* end;
    int size;
    queue(){
        start=NULL;
        end = NULL;
        size = 0;
    }
    void push(int x){
        Node* ele = new Node(x);
        if(end==NULL){
            start = ele;
            end = ele;
        }
        else{
            start->next = ele;
            end = ele;
        }
        size++;
    }

    int pop(){
        if(start==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        Node* temp = start;
        start = start->next;
        int popped = temp->data;
        temp->next = nullptr;
        delete temp;
        size--;
        if(size==0){
            end = NULL;
        }
        return popped;
    }
    int top(){
        if(start==NULL){
            cout<<"Queue is empty!!!. Status: ";
            return -1;
        }
        return start->data;
    }
    int Size(){
        return size;
    }
    bool empty(){
        return size==0;
    }

    void print(){
        Node* current = start;
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
    }
};

int main(){
    queue q;
    cout<<"Empty ? : "<<q.empty()<<endl;;
    q.push(10);
    q.push(20);
    cout<<"Current status of queue"<<endl;
    q.print();
    cout<<endl;
    cout<<"popped: "<<q.pop()<<endl;
    cout<<"Current status of queue"<<endl;
    q.print();
    cout<<endl;
    q.push(40);
    q.push(30);
    cout<<"Top: "<<q.top()<<endl;
    cout<<"Size: "<<q.Size()<<endl;
    cout<<"Current status of queue"<<endl;
    q.print();
    cout<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"Empty? : "<<q.empty()<<endl;
    cout<<q.pop();
    return 0;
}