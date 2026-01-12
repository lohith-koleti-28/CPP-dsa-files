#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int call=0;
void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(vector<int> &a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int current = a[i];
        int j = i-1;
        while(j>=0 && a[j] > current){
            call++;
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
    return;
}

void random(vector<int> &a){
    srand(time(0));
    for(int i=0;i<a.size();i++){
        a[i] = 1 + ((double)a.size())*rand()/RAND_MAX;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    // for(int &i : v) cin >>i;
    // random(v);
    // print(v);
    insertionSort(v);
    print(v);
    cout<<"Number of calls: "<<call<<endl;
}