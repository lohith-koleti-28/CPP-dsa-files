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
vector<int> ind(vector<int> &v,int x){
    int l = 0,h = v.size()-1;
    vector<int> ans(2,-1);
    while(l <= h){
        int mid = l + (h-l)/2;
        if(v[mid] == x){
            int i = mid -1;
            int j = mid + 1;
            while(v[i] == x && i>=0){
                i--;
            }
            ans[0] = i+1;
            while(v[j] == x && j < v.size()){
                j++;
            }
            ans[1] = j-1;
            return ans;
        }
        else if(v[mid] > x){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    int x;
    cin >> x;
    print(ind(v,x));
}