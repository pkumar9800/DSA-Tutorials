#include<iostream>
using namespace std;

void singleNumberIII(int arr[], int size, int ans[]){
    int xorr = 0;
    int b1=0, b2=0;
    for(int i=0; i<size; i++){
        xorr = xorr ^ arr[i];
    }
    int rightmost = (xorr & (xorr-1))^xorr;
    for(int i=0; i<size; i++){
        if(arr[i]&rightmost){
            b1 = b1^arr[i];
        }else{
            b2 = b2^arr[i];
        }
    }
    ans[0] = b1;
    ans[1] = b2;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    int ans[2] = {0};
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    singleNumberIII(arr,size,ans);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}