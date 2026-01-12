#include<iostream>
#include<ctime>
using namespace std;
void print(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void Bsort(int *a , int n){
    for(int i=(n-1);i>=0;i--){//i goes from 0 to n-1
        for(int j = 0;j<i;j++){//j goes from 0 to i-1
            if(a[j] > a[j+1]){
                swap(a,j,j+1);
            }
        }
    }
}
void random(int a[] , int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i] = 1+ 20.0*rand()/RAND_MAX;
    }
}

int main(){
    int size;
    cin >> size;
    int a [size];
    random(a,size);
    print(a,size); cout<<endl;
    Bsort(a,size);
    print(a,size);
    cout<<endl;
}