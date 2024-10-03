#include<iostream>
using namespace std;

int binaryToDecimal(string num){
    int res = 0;
    for(int i=0; i<num.length(); i++){
        res = res * 2 + (num[i]-48);
    }
    return res;
}
int main(){
    string num;

    //Enter a number
    cin>>num;
    cout<<"Decimal: "<<binaryToDecimal(num)<<endl;
    return 0;
}