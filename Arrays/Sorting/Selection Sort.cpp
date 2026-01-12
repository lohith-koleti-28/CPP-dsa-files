#include<simplecpp>

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int index(int arr[] , int n){
    int maxIndex=0;
    for(int i=1;i<n;i++){
        if(arr[maxIndex]<arr[i]){
            maxIndex = i;
        }
    }
    return maxIndex;
}

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selSort(int arr[] , int n){
    for(int i = n-1;i>=0;i--){
        swap(arr,index(arr,i+1),i);
    }
}

int main(){
    int arr [] = {5,6,7,9,3,2,1,4,6,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    cout<<endl;
    selSort(arr,n);
    print(arr,n);
    cout<<endl;
}





