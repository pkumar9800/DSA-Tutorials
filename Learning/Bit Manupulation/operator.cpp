//Bitwise operators
#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"a & b: "<<(a&b)<<endl;
    cout<<"a | b: "<<(a|b)<<endl;
    cout<<"a ^ b: "<<(a^b)<<endl;
    cout<<"a << b: "<<(a<<b)<<endl;
    cout<<"a >> b: "<<(a>>b)<<endl;
    cout<<"~a: "<<(~a)<<endl;
    return 0;
}