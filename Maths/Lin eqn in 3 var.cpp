#include<iostream>
#include<cmath>
using namespace std;
bool singular;
void swap(double a[][3],double b[3], int i, int j){
    for(int k=0;k<3;k++){
        double temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
    double t = b[i];
    b[i] = b[j];
    b[j] = t;
}
double det(double a[][3]){
    return a[1][1]*a[2][2]-a[2][1]*a[1][2];
}

void print(double a[][3],double b[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<" : "<<b[i];
        cout<<endl;
    }
    cout<<endl;
}
void gauss(double a[][3],double b[3]){
    for(int t=0;t<3;t++){
        if(a[t][0] != 0){
            swap(a,b,t,0);
            // cout<<endl;
            // print(a,b);           
            double a1 = a[0][0]; 
            for(int i=0;i<3;i++){
                a[0][i] /= a1;
            }
                b[0] /= a1;

            // print(a,b);
                double a2 = a[1][0];
            for(int i=0;i<3;i++){
                a[1][i] -= a2*a[0][i];
            }
                b[1] = b[1] - a2*b[0];

            // print(a,b);
                double a3 = a[2][0];    
            for(int i=0;i<3;i++){
                a[2][i] -= a3*a[0][i];
            }
                b[2] -= a3*b[0];

            // print(a,b);
            if(abs(det(a))< 10e-5){
                cout<<"Invalid Equations\n";
                singular = true;
            }
            else{
                double c = a[2][1]/a[1][1];
            for(int i=0;i<3;i++){
                a[2][i] -= c*a[1][i];
            }
                b[2] -= c*b[1];

            // print(a,b);
            }
        }
    }
}
int main(){
    double a[3][3];
    double b[3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
        cin >> b[i];
    }
    gauss(a,b);
    if(singular){}
    else{
    double x,y,z;
    z = b[2]/a[2][2];
    y = (b[1] - z*a[1][2])/a[1][1];
    x = b[0] - a[0][1]*y - a[0][2]*z;
    cout<<"x: "<<x<<endl<<"y: "<<y<<endl<<"z: "<<z<<endl;
    }
}