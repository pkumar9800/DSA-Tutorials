// check if ith bit is set or not using 

#include<iostream>
using namespace std;

bool checkUsingLeftShift(int n, int i){
    if((n&(1<<i))==0){
        return false;
    }else{
        return true;
    }
}

bool checkUsingRightShift(int n, int i){
    if(((n>>i)&1)==0){
        return false;
    }else{
        return true;
    }
}

int main(){
    int n,i;

    // Enter number and i
    //Binary representation of number follows 0-based index from LSB to MSB
    cin>>n>>i;
    cout<<checkUsingLeftShift(n,i)<<endl;
    cout<<checkUsingRightShift(n,i)<<endl;
    return 0;
}