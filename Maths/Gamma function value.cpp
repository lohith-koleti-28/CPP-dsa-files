// Example program
#include <iostream>
#include <string>
#include<cmath>
using namespace std;
//Gives the integral of gamma function
double f(double a,double x){
    return exp(-x) * pow(x,a-1);
}

double integral(double gamma){
    double ans = 0;
    double a = 0 , b = pow(10,5);//Change as per time and accuracy requirement
    long long w = pow(10,7);//10^8
    double n = (b-a)/w;
    if(gamma<1) a += n;
    for(long long i=0;i<=w;i++){ 
        ans += (n)*(f(gamma,a) + f(gamma,a+n))/2;   
        a += n;    
    }
    return ans;
}

int main()
{
  double g;
  cout<<"Enter Argument of Gamma Function\n";
  cin >>g;
  cout<<"Value of Gamma function at: "<<g<<" is : ";
  cout<<integral(g)<<endl;
}