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

int max(vector<int> &v){
    int m = v[0];
    for(int i=1;i<v.size();i++){
        if(m < v[i]){
            m = v[i];
        }
    }
    return m;
}

void countSort(vector<int> &v){
    vector<int> freq(max(v) + 1);
    int n = v.size();
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }
    for(int i=1;i<freq.size();i++){
        freq[i] += freq[i-1];   
    }
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
        ans[--freq[v[i]]] = v[i];
    }
    v = ans;
    return;
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
    countSort(v);
    sort(b.begin(),b.end());
    bool found  = 0;
    for(int i=0;i<n;i++){
        if(v[i] != b[i]){
            found = 1;
        }
    }
    cout<<"Found: "<<found<<endl;
}