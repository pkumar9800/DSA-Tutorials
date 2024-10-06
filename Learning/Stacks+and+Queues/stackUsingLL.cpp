//implement stack using linked list

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
class stack{
    Node* top;
    int size;
public:
    stack(){
        size=0;
        top=nullptr;
    }
    void push(int x){
        Node* ele = new Node(x);
        ele->next = top;
        top = ele;
        size++;
    }
    int pop(){
        if(top==NULL){
            return -1;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        temp->next=NULL;
        delete temp;
        size--;
        return popped;
    }
    int Size(){
        return size;
    }
    int Top(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    bool empty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
    void print() {
    Node * current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.Size() << "\n";
    cout <<"Stack empty or not? "<<s.empty()<<"\n";
    cout << "stack's top element: " << s.Top() << "\n";
    s.print();
    return 0;
}