//find xor or number from L to R

#include<iostream>
using namespace std;

int xor1toR(int n){
    if(n%4==0){
        return n;
    }
    else if(n%4==1){
        return 1;
    }
    else if(n%4==2){
        return n+1;
    }
    else if(n%4==3){
        return 0;
    }
    return 0;
}

int main(){
    int L,R;
    cin>>L>>R;
    int ans = xor1toR(L-1)^xor1toR(R);
    cout<<ans<<endl;
    return 0;
}