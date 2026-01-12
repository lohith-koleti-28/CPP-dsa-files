#include<iostream>
using namespace std;
int main(){
    int r1,c1;
    cout<<"Enter order of 1st Matrix: ";
    cin >>r1>>c1;
    int a[r1][c1];
    cout<<"Enter entries: ";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> a[i][j];
        }
    }
    int r2,c2;
    cout<<"Enter order of 2nd Matrix: ";
    cin >>r2>>c2;
    int b[r2][c2];
    cout<<"Enter entries: ";
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> b[i][j];
        }
    }
    int c[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            c[i][j] = 0;
        }
    }
    if(c1 == r2){
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                for(int t=0;t<r2;t++){
                    c[i][j] += a[i][t]*b[t][j];
                }
            }
        }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"Invalid Matrices for Multiplication\n";
}