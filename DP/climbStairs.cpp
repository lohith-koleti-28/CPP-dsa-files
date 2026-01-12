#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int tabulation(int n){
    vector<int> dp(n,-1);
    if(n == 1 || n == 2) return 1;
    dp[0] = 1;
    dp[1] = 1;
    print(dp);
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        print(dp);
    }
    return dp.back();
}

int main(){
    int n;
    cin >> n;

    cout<<tabulation(n);
}