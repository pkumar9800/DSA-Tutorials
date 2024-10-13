//converting prefix to infix 
#include<iostream>
#include<stack>
using namespace std;

void prefixToInfix(string &str){
    int n=str.length();
    int i=n-1;
    stack<string> s;
    while(i>=0){
        if((str[i]>='0' && str[i]<='9') || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            s.push(string(1,str[i]));
        }else{
            string t1 = s.top();
            s.pop();
            string t2 = s.top();
            s.pop();
            string temp = "("+t1+str[i]+t2+")";
            s.push(temp);
        }
        i--;
    }
    str=s.top();
    s.pop();
}

int main(){
    string str;
    cin>>str;
    prefixToInfix(str);
    cout<<str;
    return 0;
}