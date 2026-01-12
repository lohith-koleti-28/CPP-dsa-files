#include<iostream>
#include<cstdlib>
using namespace std;
void print(float * a , int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
bool removeFirst(float arr[], int &n , float x){
    int found =-1;
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            found = i;
            break;
        }
    }
    if (found != -1){
        for(int i=found;i<(n-1);i++){
            arr[i] = arr[i+1];
        }
        arr[n] = 0;
        n--;
        return 1;
    }
    return 0;
}

int main(){
    float a [] = {1,2,3,4,5,6,7,8,8,8,8,3,4,56,7,8};
    int n = sizeof(a)/sizeof(a[0]);
    print(a,n);
    cout<<endl;
    for(int i=0;i<8;i++)
    removeFirst(a,n,8);
    print(a,n); cout<<endl;
}
