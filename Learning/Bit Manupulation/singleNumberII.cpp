//Problem: Leetcode 137
//single number II

#include<iostream>
#include<unordered_map> 
#include<algorithm>
using namespace std;

//Bruteforce Method
//T.C : O(N)
//S.C : O(N/3 + 1)
int singleNumberIIM1(int arr[], int size){
    unordered_map<int,int> mpp;
    int ans;
    for(int i=0; i<size; i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            ans = it.first;
            break;
        }
    }
    return ans;
}

//Method 2
//Better Method
// T.C = O(32*N)
// S.C = O(1)
int singleNumberIIM2(int arr[], int size){
    int ans = 0;
    for(int indexBit = 0; indexBit<31; indexBit++){
        int count = 0;
        for(int i=0; i<size; i++){
            if(arr[i]&(1<<indexBit)){
                count++;
            }
        }
        if(count%3 == 1){
            ans = ans|(1<<indexBit);
        }
    }
    return ans;
}

//Method 3
//Better than method 2
//T.C = O(nlog n) because log n is very small in most of the cases
//S.C = O(1)
int singleNumberIIM3(int arr[], int size){
    sort(arr, arr+size);
    for(int i=1; i<size; i=i+3){
        if(arr[i]!=arr[i-1]){
            return arr[i-1];
        }
    }
    return arr[size-1];
}

//Method 4
//optimal Solution not so intuitive 
//you need to know this solution before hand
// T.C = O(n)
// S.C = O(1)
//This solution can ve viewed in BitManupulation Playlist 
// of take U forward channel 
// L6. Single Number II | Bit Manipulation
// Tme Stamp: 18:00

int singleNumberIIM4(int arr[], int size){
    int ones = 0;
    int twos =0;

    for(int i = 0; i<size; i++){
        ones = (ones^arr[i]) & (~twos);
        twos = (twos^arr[i]) & (~ones);
    }
    return ones;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<singleNumberIIM4(arr,size);
    return 0;
}