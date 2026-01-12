#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.141592;
int main(){
    struct com{
        double a,b;
        com(double x, double y){
            a=x;b=y;
        }
        com(bool polar , double r,double th){//th in radians
            a = r*cos(th);
            b = r*sin(th);
        }
        void print(){
            cout<<a<<" "<<b<<"i";
        }
    };
    com a(2,3);
    a.print();cout<<endl;
    com b(1,2,PI/4);
    b.print();cout<<endl;
}