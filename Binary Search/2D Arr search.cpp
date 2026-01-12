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

bool search(vector<int> &v , int x){
    int low = 0 , high = v.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] == x) return 1;
        if(v[low] <= v[mid]){
            if(v[low] <= x && x < v[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(v[mid] <x && x <= v[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return 0;
}
int check(vector<vector<int> > &v , int x){
    //for 2 d array search
    int n = v.size();
    bool found = false;
    int i;
    for(i=0;i<=(n-2);i++){
        if(v[i][0] <= x && v[i+1][0] >= x){
            if(v[i][0] == x || v[i+1][0] == x) return 1;
            found  = true;
            break;
        }
    }
    int lo = 0, hi = v[0].size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(v[i][mid] == x) return 1;
        else if(v[i][mid] > x){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return 0;
}

int check2(vector<vector<int> >&v , int x){
    // i and j are r and c
    //1 is low 2 is high
    int i1=0,j1=0,i2 = v.size()-1,j2 = v[0].size() -1;
    while(i1 <= i2 && j1 <= j2){
        // m1 is row and m2 is column
        int m1 = i1 + (i2-i1)/2;
        int m2 = j1 + (j2-j1)/2;
        if(v[m1][m2] == x) return 1;
        else if(v[m1][m2] > x){
            j2 = m2 - 1;
        }
        else{
            j1 = m2 + 1;
        }
        if(j1 == v[0].size()){
            j1 = 0;
            i1++;
        }
        if(j2 == -1){
            j2 = v[0].size()-1;
            i2--;
        }
    }
    return 0;
}

int check3(vector<vector<int> >&v , int x){
    int l = 0,h = v.size() * v[0].size() - 1;
    while(l<= h){
        int m = l + (h-l)/2;
        //m = row * i + j for v[i][j]
        int i = m/v[0].size(),j = m%v[0].size();
        if(v[i][j] == x) return 1;
        else if(v[i][j] > x){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return 0;
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int> > v(m , vector<int> (n,0));
    for(int i=0;i<v.size();i++){
        for(int j = 0;j<v[0].size();j++){
            cin >> v[i][j];
        }
    }
    int x;
    cin >> x;
    cout<<check(v,x)<<"\n";
    cout<<check2(v,x)<<"\n";
}