//lemove last bit from left side

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    n = n & (n-1);
    cout<<n<<endl;
    return 0;
}