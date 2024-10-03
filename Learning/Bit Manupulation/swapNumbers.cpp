//swap two numbers using bitwise operators

#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Before: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"After: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    return 0;
}