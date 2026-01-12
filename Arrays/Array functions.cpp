#include<simplecpp>

void doubleArray(int arr [] , int k){
    for(int i=0;i<k;i++){
        arr[i] *= 2;
    }
}

void printArray(int arr1 [] ,int p){
    for(int i=0;i<p;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
}

main_program{
    int n; cin >>n;
    int arr2 [n];
    for(int i=0;i<n;i++){
        cin >>arr2[i];
    }
    printArray(arr2,n);
    doubleArray(arr2 , n);
    printArray(arr2 ,n);
}

