#include<iostream>
#include<cmath>
using namespace std;
void swap(char* arr , int i , int j){
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void revStr(char* arr , int n){
    for(int i=0;i<n/2;i++){
        swap(arr , i , n-i-1);
    }
}

int main(){
    char arr[20];
    cin.getline(arr,19);
    int i;
    for(i=0;i<20;i++){
        if(arr[i] =='\0'){
            break;
        }
    }
    cout<<"Before: "<<arr<<endl;
    revStr(arr,i);
    cout<<"After: "<<arr<<endl;

}
