//converting infix to prefix expression

#include<iostream>
#include<stack>
#include <string>
#include <algorithm>
using namespace std;

//reverses infix expression
void rev(string &str){
    int i=0;
    int j=str.length()-1;
    while(i<j){
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
        if(str[j]=='(') str[j]=')';
        else if(str[j]==')') str[j]='(';
        swap(str[i],str[j]);
        i++;
        j--;
    }
    if(i==j && str[i]=='(') str[i]=')';
    else if(i==j && str[i]==')') str[i]='(';
}

//infix to postfix conversion
int priority(char c){
        if (c == '^') return 3;  
        else if (c == '/' || c == '*') return 2;  
        else if (c == '+' || c == '-') return 1;
        else return -1;
}

void infix2Postfix(string &str){
    string ans;
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
            ans=ans+str[i];
        }
        else if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(s.top()!='('){
                ans = ans + s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && priority(s.top())>priority(str[i])){
                ans = ans+s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans=ans+s.top();
        s.pop();
    }
    str=ans;
}

int main(){
    string str;
    cin>>str;
    //reverse the expression

    rev(str);
    //convert the result to postfix
    infix2Postfix(str);

    //again reverse the result.
    //result obtained is prefix expression
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}