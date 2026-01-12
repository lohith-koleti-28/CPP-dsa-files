#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;
void print(const vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void random(vector<int> &v){
    srand(time(0));
    for(int i=0;i<v.size();i++){
        v[i] = 1 + (double)v.size()*rand()/RAND_MAX;
    }
    return;
}

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        bool found = false;
        for(int j = 0;j<n-1;j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                found = true;
            }
        }
        if(!found) break;
    }
    return;
}

bool binarySearch(vector<int> &v,int first,int L , int x){
    if(L == 1) return v[first] == x;
    if(v[first + L/2] == x) return 1;
    if(v[first + L/2] < x){
        return binarySearch(v,first + L/2,L - L/2,x);
    } 
    if(v[first + L/2] > x){
        return binarySearch(v,first,L/2,x);
    }
    return 0;
}

int b(vector<int> &v,int start,int end,int x){
    while(start <= end){
        int mid = start + (end - start)/2;
        if(v[mid] == x) return mid;
        else if(v[mid] > x){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int idx(vector<int> &v){
    int l = 0,h = v.size()-1;
    int ans = 0;
    while(l <= h){
        int m = l + (h-l)/2;
        if(v[0] > v[m]){
            ans = m;
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}

int find(vector<int> &v , int x){
    int pivot = idx(v);
    if(v[0] <= x && x <= v[pivot-1]){
        return b(v,0,pivot-1,x);
    }
    else {
        return b(v,pivot,v.size()-1,x);
    }
}

int findF(vector<int> &v,int x){
    int l = 0,h = v.size()-1;
    while(l <= h){
        int m = l + (h-l)/2;
        if(v[m] == x) return m;
        if(v[l] <= v[m]){
            if(v[l] <=x && x < v[m]){
                h = m -1;
            }
            else{
                l = m + 1;
            }
        }
        else{
            if(v[m] < x && x <=v[h]){
                l = m+1;
            }
            else{
                h = m - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    int x;
    cin >> x;
    cout<<find(v,x)<<"\n";
    cout<<findF(v,x)<<"\n";
}