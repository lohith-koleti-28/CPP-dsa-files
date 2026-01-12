#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void print(vector<vector<bool>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> v = {5,3,7,1,4,6};
    int n = v.size();
    int sum = accumulate(v.begin(),v.end(),0);

    vector<vector<bool>> dp(n,vector<bool>(sum+1,0));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }
    dp[0][v[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            bool notTake = dp[i-1][j];
            bool take = 0;
            if(v[i] <= j){
                take = dp[i-1][j-v[i]];
            }
            dp[i][j] = take || notTake;
        }
    }

    //Last row contains those column indices which are possible for s1
    int ans = INT32_MAX;
    for(int i=0;i<dp[0].size();i++){
        if(dp[n-1][i] == 1){
            // This is potential s1
            ans = min(ans, abs(sum - 2 * i));
        }
        // cout<<"(i,j) = "<<"("<<i<<","<<j<<")\n";
            print(dp);
            cout<<"\n\n";
    }
    cout<< ans << endl;
}