#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &v , int start , int end){
    //returns actual index of last element in sorted array
    //Partitions the actual array
    int pivot  = v[end];
    int i = start;
    for(int j = start;j<end;j++){
        if(v[j] < pivot){
            if(i != j)
            swap(v[i],v[j]);
            i++;
        }
    }
    int temp = i;
    i = end;
    for(int j = end-1;j>=temp;j--){
        if(v[j] > pivot){
            if(i !=j)
                swap(v[i],v[j]);
                i--;
        }
    }
    return i;
}

void quickSort(vector<int> &v , int start , int end){
    //start and end are indices
    if(start >= end) return;
    int pi = partition(v,start,end);
    quickSort(v,start,pi-1);
    quickSort(v,pi+1,end);
}

void random(vector<int> &v){
    srand(time(0));
    for(int i=0;i<v.size();i++){
        v[i] = 1 + 50.0*rand()/RAND_MAX;
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    // for(int &i : v) cin >> i;
    random(v);
    vector<int> b = v;
    quickSort(v,0,n-1);
    sort(b.begin(),b.end());
    bool found  = 0;
    for(int i=0;i<n;i++){
        if(v[i] != b[i]){
            found = 1;
        }
    }
    cout<<"Found: "<<found<<endl;
}