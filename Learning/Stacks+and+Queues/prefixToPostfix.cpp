//converting prefix to postfix
#include<iostream>
#include<stack>
using namespace std;

void prefixToPostfix(string &str){
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
            string temp = t1+t2+str[i];
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
    prefixToPostfix(str);
    cout<<str;
    return 0;
}