#include<iostream>
#include<cmath>
using namespace std;

double f(double x){
    return (x*x*x -8*x*x+12*x+14);
}

double root(double g(double x) ,double xl,double xr, int &x){
    double xm = (xl+xr)/2;
    int i;
    for(i=1;abs(g(xm)) >=0.00001;i++){
        xm = (xl+xr)/2;
        if( g(xl)*g(xm) <=0){
            xr = xm;
        }
        else{
            xl = xm;
        }
    }
    x = i;
    return xm;
}

int main(){
    double x1,x2;
    int i;
    cin>>x1>>x2;
    cout<<"Root is: "<<root(f ,x1,x2,i)<<endl;
    cout<<"Number of iterations: "<<i<<endl;
}   
