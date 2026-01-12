#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return x*x*x-x*x+4*x-8;
}
double fdash(double x){
    return 3*x*x-2*x+4;
}
double bisection(double f(double) , double fd(double) , double a , double b){
    double m  = (a+b)/2.0;
    double k = (f(b) - f(a))/(b-a);
    while(abs(fd(m) - k) >= 1.0e-7){
        m  = (a+b)/2.0;
        if((fd(a)-k)*(fd(m)-k)<=0){
            b = m;
        }
        else{
            a = m;
        }
    }
    return m;
}

int main(){
    double a,b;
    cin >>a>>b;
    cout<<"c: "<<bisection(f , fdash , a,b)<<endl;
    // cout<<"Actual: "<<(b+a)/2.0<<endl;
}
