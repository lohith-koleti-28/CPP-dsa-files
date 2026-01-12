#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
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

int recursive(vector<int> &v,int start,int end , int x){
    //Binary Search modified
    if(start > end) return -1;
    int mid = start  + (end - start)/2;
    if(v[mid] == x){
        if(mid == 0) return 0;
        if(v[mid-1] == x){
           return recursive(v,start,end-1,x);
        }
        else{
            return mid;
        }
    }
    if(v[mid] > x){
        return recursive(v,start,mid-1,x);
    }
    else{
        return recursive(v,mid+1,end,x);
    }
}

int iterative(vector<int> &v,int x){
    int l = 0,h = v.size() - 1;
    while(l <= h){
        int mid = l + (h-l)/2;
        if(v[mid] == x){
            if(mid ==0) return 0;
            else if(v[mid-1] == x){
                h--;
            }
            else{
                return mid;
            }
        }
        else if(v[mid] > x){
            h = mid-1;
        }
        else{
            l = mid+1;  
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter array length: ";
    cin >> n;

    vector<int> v(n);
    cout<<"Enter elements: ";
    for(int &i : v) cin >> i;
    // random(v);
    // print(v);
    // bubbleSort(v);
    // print(v);
    int x;
    cout<<"Target is: ";
    cin >> x;
    cout<<"Recursive: "<<recursive(v,0,n-1,x)<<endl;
    cout<<"Iterative: "<<iterative(v,x)<<endl;
}