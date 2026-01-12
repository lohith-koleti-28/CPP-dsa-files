#include<iostream>
#include<vector>
using namespace std;

long long tabulation(int n){
    long long ans = 1;
    if(!(n == 1 || n == 2)){
        long long a1 = 1;
        long long a2 = 1;
        for(int i=0;i<n-2;i++){
            ans = a1 + a2;
            a1 = a2;
            a2 = ans;
        }
    }
    // cout<<"The "<<n<<"th Fibonacci Number is: "<< ans << "\n";
    return ans;
}

long long recursive(int n, vector<long long>& dp){
    if(n == 1 || n == 2){
        return 1;
    }
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursive(n-2,dp) + recursive(n-1,dp);
}

int main(){
    int n;
    cin >> n;
    vector<long long> dp(n+1,-1);
    cout << tabulation(n)<<endl;
    cout<< recursive(n,dp);
}