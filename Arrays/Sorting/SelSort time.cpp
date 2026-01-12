#include<iostream>
#include<ctime>
using namespace std;
void print(int *a , int n){//Prints array
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
void swap(int *a , int i , int j){//Swaps array elements
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void random(int *a , int n){//Puts random values in array
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i] = 20.0*rand()/RAND_MAX; 
    }
}

int maxdex(int a[] , int n){//Finds index of max of array
    int index = 0;
    for(int i=1;i<n;i++){
        if(a[index] < a[i]){
            index = i;
        }
    }
    return index;
}

void selSort(int a[] , int n){//Selection sort
    for(int i=(n-1);i>=0;i--){
        swap(a,i,maxdex(a,i+1));
    }
}

int main(){
    int k;
    cin >> k;
    int a[k];
    random(a,k);
    // print(a,k);cout<<endl;
    clock_t start ,end;
    start = clock();
    selSort(a,k);    
    end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << cout.precision(5);
    cout << " sec " << endl;
    // print(a,k);cout<<endl;
}