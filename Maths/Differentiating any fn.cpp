#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return log(x+pow(1+x*x , 0.5));
}
double fdash(double f(double) , double x){
    return (f(x+1.0e-8) - f(x))/1.0e-8;
}

int main(){
    double x; cin >> x;
    cout<<"Calculated: "<<fdash(f , x)<<endl;
    cout<<"Actual: "<<pow(1+x*x,-0.5)<<endl;
}
