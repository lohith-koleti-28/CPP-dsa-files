#include<iostream>
#include<cmath>
using namespace std;   

string to_str(int n){
    int d=0;
    int temp = n;
    while(temp > 0){
        d++;
        temp /= 10;
    }
    char a[d+1];
    a[d] = '\0';
    for(int i=d-1;i>=0;i--){
        a[i] = n%10 + '0';
        n /= 10;
    }
    return (string)a;
}

int main(){
    int n;
    cin >> n;
    cout<<to_str(n)<<endl;
    cout<<to_string(n)<<endl;
}