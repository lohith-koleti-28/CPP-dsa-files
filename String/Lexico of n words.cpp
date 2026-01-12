#include<iostream>
using namespace std;
char check(char*a , char*b){
    for(int i=0; ; i++){
        if(a[i] == '\0' && b[i] == '\0') return '=';
        if(a[i] == '\0') return '<';
        if(b[i] == '\0') return '>';
        if(a[i]>b[i]) return '>';
        if(a[i]<b[i]) return '<';
    }
}
void swap(char*a , char*b,int n){
    char temp;
    //Swaps two strings of equal length n
    for(int i=0;i<n;i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
void sort(char a[][8] , int n){
    //Bubble sort
    for(int i=0;i<(n-1);i++){
        for(int j=(i+1);j<n;j++){
            if(check(a[i] , a[j]) == '>'){
                swap(a[i],a[j],8);
            }
        }
    }
}
void print(char a[][8],int n){
    for(int i =0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of words: ";
    cin >> n;
    char a[n][8];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,n);
    print(a,n);
}