//set ith Bit

#include<iostream>
using namespace std;

void setBits(int &num, int i){
    num = num|(1<<i);
}
int main(){
    int num,i;
    cin>>num>>i;
    setBits(num, i);
    cout<<num<<endl;
    return 0;
}