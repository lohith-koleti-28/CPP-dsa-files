#include<iostream>
#include<cmath>
using namespace std;

int main(){
    struct V{
        double x,y,z;
        V(double a=0 ,double b=0 , double c=0){
            x = a;
            y = b;
            z = c;
        }
        double mod(){
            return sqrt(x*x+y*y + z*z);
        }
        V operator*(V b){
            V ans( y*b.z - z*b.y,b.x*z - x*b.z,x*b.y - y*b.x);
            return ans;
        }
    };
    V a(1,2,3) , b(4,5,6);
    cout<<(a*b).x<<" "<<(a*b).y<<" "<<(a*b).z<<endl;
}