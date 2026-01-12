#include<iostream>
#include<cmath>
using namespace std;
double f (double x){
    return x*x*x+4*x*x-8*x-7;
}
double fd(double x){
    return 3*x*x+8*x-8;
}
double root(double g(double x),double gd(double x), double x0,int &i){
    for(i=1;abs(f(x0))>=0.0000001;i++){
        x0 = x0 - g(x0)/gd(x0);
    }
    return x0;
}
int main(){
    double x0;
    int i;
    cout<<"Enter a guess: ";
    cin >>x0;
    cout<<"Root is: "<<root(f,fd,x0,i)<<endl;
    cout<<"Number of iterations: "<<i<<endl;
}