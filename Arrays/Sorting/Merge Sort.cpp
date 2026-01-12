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

void merge(vector<int> &a , vector<int> &b , vector<int> &v){
    int x = a.size() , y = b.size();
    for(int i=0, af = 0,bf = 0;i<(x+y);i++){
        if(af < x && bf < y){
            if(a[af] <= b[bf]){
                v[i] = a[af];
                af++;
            }
            else if(b[bf] < a[af]){
                v[i] = b[bf];
                bf++;
            }
        }
        else if(bf < y){
            v[i] = b[bf];
            bf++;
        }
        else {
            v[i] = a[af];
            af++;
        }
    }
    return;
}

void mergeSort(vector<int> &v){
    int n = v.size();
    if(n == 1) return;
    vector<int> a(n/2) , b(n-n/2);  
    for(int i=0;i<n;i++){
        if(i < (n/2)){
            a[i] = v[i];
        }
        else{
            b[i - (n/2)] = v[i];
        }
    } 
    mergeSort(a);
    mergeSort(b);
    merge(a,b,v);
    
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
    for(int &i : v) cin >> i;
    // random(v);
    // print(v);
    mergeSort(v);
    print(v);
}