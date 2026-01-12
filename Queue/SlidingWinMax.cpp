#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> windowMax(vector<int> &nums , int k){

    vector<int> res;
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && nums[i] > nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    for(int i=k;i<nums.size();i++){
        if(dq.front() == (i-k)) dq.pop_front();
        while(!dq.empty() && nums[i] > nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(nums[dq.front()]);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v){
        cin >> i;
    }
    int k;
    cin >> k;
    vector<int> r = windowMax(v,k);
    for(auto i : r){
        cout<<i<<" ";
    }
    cout<<endl;
}