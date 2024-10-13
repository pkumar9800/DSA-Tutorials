//conversion of postfix expression to infix expression
#include<iostream>
#include<stack>
using namespace std;

void postfixToInfix(string &str){
    stack<string> s;
    int i=0;
    int n=str.length();
    while(i<n){
        if((str[i]>='0' && str[i]<='9') || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            s.push(string(1,str[i]));
        }
        else{
            string t1 = s.top();
            s.pop();
            string t2 = s.top();
            s.pop();
            string temp = "("+t2+str[i]+t1+")";
            s.push(temp);
        }
        i++;
    }
    str=s.top();
    s.pop();
}


int main(){
    string str;
    cin>>str;
    postfixToInfix(str);
    cout<<str;
    return 0;
}