#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<vector<double> > v,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<double> > mul(vector<vector<double> > &a,vector<vector<double> > &b,int r1,int c2,int c1){
    vector<vector<double> > ans(r1,vector<double> (c2,0));
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int t=0;t<c1;t++)
            ans[i][j] += a[i][t]*b[t][j];
        }
    }
    return ans;
}
int main(){
    cout<<"Enter number of rows and columns of Matrix 1: ";
    int r1,c1;
    cin >> r1 >> c1;
    cout<<"Enter entries of Matrix 1: ";
    vector<vector<double> > m1(r1,vector<double> (c1));
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> m1[i][j];
        }
    }
    cout<<"Enter number of rows and columns of Matrix 2: ";
    int r2,c2;
    cin >> r2 >> c2;
    cout<<"Enter entries of Matrix 2: ";
    vector<vector<double> > m2(r2,vector<double> (c2));
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> m2[i][j];
        }
    }
    if(c1 == r2){
        print(mul(m1,m2,r1,c2,c1),r1,c2);
    }
    else{
        cout<<"Invalid for Multiplication\n";
    }
}
