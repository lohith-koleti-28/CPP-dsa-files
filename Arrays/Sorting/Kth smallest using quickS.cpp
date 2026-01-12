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

int partition(vector<int> &v,int s,int e){
    int pivot = v[e];
    int i = s;
    for(int j=s;j<=e;j++){
        if(v[j] < pivot){
            if(i != j){
                swap(v[i],v[j]);
            }
            i++;
        }
    }
    swap(v[i],v[e]);
    return i;
}

void quickSort(vector<int> &v,int s,int e){
    if(s >= e) return;
    int pi = partition(v,s,e);
    quickSort(v,s,pi-1);
    quickSort(v,pi+1,e);
}

void random(vector<int> &v){
    srand(time(0));
    for(int i=0;i<v.size();i++){
        v[i] = 1 + 50.0*rand()/RAND_MAX;
    }
    return;
}
int kthSmallest(vector<int> &v,int k){
    for(int i=1;i<v.size();i++){
        if(v[i-1] != v[i]){
            k--;
            if(k ==0) return v[i-1];
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    int k;
    cin >> k;
    // random(v);
    vector<int> b = v;
    quickSort(v,0,n-1);
    cout<<k<<"th Smallest Element is: "<<kthSmallest(v,k)<<"\n";
}