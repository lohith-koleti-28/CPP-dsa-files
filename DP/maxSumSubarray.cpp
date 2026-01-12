#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int tabulation(vector<int> &v){
    vector<int> dp(v.size(),-1);
    dp[0] = v[0];
    print(dp);
    for(int i=1;i<v.size();i++){
        dp[i] = max(v[i],dp[i-1] + v[i]);
        print(dp);
    }
    return dp.back();
}

int main(){
    int n;
    cout<<"Enter n\n";
    cin >> n;
    vector<int> v(n);
    cout<<"Enter entries of the vector\n";
    for(int &i : v) cin >> i;
    cout<< tabulation(v)<<endl;
} 
