//convert infix expresion to postfix expression
//T.C : O(N) +O(N)
//S.C : O(N)+ O(N)

#include<iostream>
#include<stack>
using namespace std;

int priority(char c){
        if (c == '^') return 3;  
        else if (c == '/' || c == '*') return 2;  
        else if (c == '+' || c == '-') return 1;
        else return -1;
}

string infix2Postfix(string str){
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
            while(!s.empty() && priority(s.top())>=priority(str[i])){
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
    return ans;
}
int main(){
    string str;
    cin>>str;
    cout<<infix2Postfix(str);
    return 0;
}