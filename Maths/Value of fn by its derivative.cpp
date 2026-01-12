#include<iostream>
#include<cmath>
using namespace std;
double fd(double x){
    return atan2(x,1);
}
double integral(double fd(double), double f0,double t){
    //Needs to know the value of the function at atleast 1 pt
    //In this case f(0) = f0
    double x1=0,w = t/(10000000),x2 = x1+w,ans=0;
    // cout<<"x2 :"<<x2<<endl<<"w: "<<w<<endl;
    for(long long int i=1;i<=10000000;i++){
        ans += fd((x1 + x2)/2.0) * w;
        x1 = x2;
        x2 = x2 + w;
    }
    // cout<<"ans: "<<ans<<endl;
    ans += f0;
    return ans;
}
int main(){
    double t;
    cin >> t;
    cout<<"Calculated Integral: "<<integral(fd,0,t)<<endl;
    cout<<"Actual: "<<t*atan2(t,1)-0.5*log(1 + t*t)<<endl;
}