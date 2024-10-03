#include<iostream>
using namespace std;

string decimalToBin(int num){
    string res ="";
    while(num!=0){
        if(num&1){
            res = '1' + res;
        }else{
            res = '0' + res;
        }
        num = num/2;
    }
    return res;
}
int main(){
    int num;

    //Enter a number
    cin>>num;
    cout<<"Binary: "<<decimalToBin(num)<<endl;
    return 0;
}