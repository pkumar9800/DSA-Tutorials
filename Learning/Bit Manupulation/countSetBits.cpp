//count number of set Bits in a number using various methods

#include<iostream>
using namespace std;

//count using loops
int countBitsLoop(int num){
    int count=0;
    while(num!=0){
        if(num&1){
            count++;
        }
        num=num>>1;
    }
    return count;
}

//Brian Kernighan’s Algorithm
int countBKA(int num){
    int count =0;
    while(num!=0){
        num = num & (num-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    //using built in function
    cout<<__builtin_popcount(n)<<endl;
    cout<<countBitsLoop(n)<<endl;
    cout<<countBKA(n)<<endl;
    return 0;
}