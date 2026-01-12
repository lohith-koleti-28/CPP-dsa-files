#include<iostream>
#include<cmath>
using namespace std;

double f(double x){
    return x*x*x*sin(x*x);
}

double integral(double f(double) , double x1 , double xf ){
    double w =(xf-x1)/10000000 , ans = 0, x2;
    for(long long int i=0;i<=10000000;i++){
        x2 = x1+w;
        ans += f((x1+x2)/2.0) * w;
        x1 = x2;
    }
    return ans;
}

int main(){
    double x1,x2;
    cin >> x1>>x2;
    cout<<"Caclucated: "<<integral(f , x1,x2)<<endl;
}
