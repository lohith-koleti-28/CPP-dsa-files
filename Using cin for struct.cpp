#include<iostream>
#include<cmath>
using namespace std;
struct V{
    double x,y,z;
    double mod(){
        return sqrt(x*x+y*y+z*z);
    }
};
void operator>>(istream &ist, V &v){
    cin>>v.x>>v.y>>v.z;
}
void operator<<(ostream &ost ,const V &v){
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
}
int main(){
    V v;
    cin >> v;
    cout<<v.mod()<<endl;
    cout<<v;
}