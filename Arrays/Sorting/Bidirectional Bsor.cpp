#include<iostream>
#include<ctime>
using namespace std;
void swap(int *a,int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bbS(int *a,int n){
    int c=0,b=n-2;
    int i;
    for(i=0;i<n/2;i++){
        bool done = false;
        for(int j=c;j<=b;j++){
            if(a[j]> a[j+1]){
                swap(a,j,j+1);
                done = true;
            }
        }
        b--;
        // print(a,n);
        if(!done)break;
        for(int k=b+1;k>=c;k--){
            if(a[k]>a[k+1]){
                swap(a,k,k+1);
                done = true;
            }
        }
        // print(a,n);
        c++;
    }
    cout<<"Number of iterations: "<<i<<endl;
}
void random(int *a,int n){
    srand(time(0));
    for(int i=0;i<n;i++)a[i] = 1+40.0*rand()/RAND_MAX;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    random(a,n);
    print(a,n);
    bbS(a,n);
    print(a,n);
}