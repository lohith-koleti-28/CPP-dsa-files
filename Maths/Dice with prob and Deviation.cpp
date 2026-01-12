#include<simplecpp>
void printArr(int arr [],int size,long long int n){
    for(int i=0;i<size;i++){
        cout<<i+1<<" : "<<arr[i]/(double)n
        <<" Deviation is: "<<abs((1.0/6 -arr[i]/(double)n)*100)<<" %"
        <<endl;
    }
}
int dice(){
    return 1+(6)* (double)rand()/RAND_MAX;
}
int main(){
    long long int n; cin>>n;
    int arr [] = {0,0,0,0,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    repeat(n){
        arr[dice()-1]++;
    }
    printArr(arr,size,n);
    cout<<"Probability: "<<1.0/6<<endl;
}




