#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
static int counter =0;
void random(int*a ,int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i] = 1+(pow(-1,i))*50.0*rand()/RAND_MAX;
    }
}
void print(int *a,int n){
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
bool bSearch(int *a , int x,int S ,int L){
    counter++;
    // print(a,8);
    // cout<<"Bsearch array: ";print(a,L);
    if(L == 1) return a[S] == x;
    int h = L/2;
    if(x>=a[S+h]){
        return bSearch(a,x,S+h,L -h);//Searches from s+h to last
    }
    else return bSearch(a,x,S,h);
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
int main(){
    cout<<"Enter size of array: ";
    int size;
    cin >> size;
    int a[size];
    random(a,size);
    Bsort(a,size);
    print(a,size);
    int n;
    cin >> n;
    cout<<bSearch(a,n,0,size)<<endl;
    cout<<"Number of searches: "<<counter<<endl;
}