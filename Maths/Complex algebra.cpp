#include<iostream>
#include<cmath>
using namespace std;

struct com{
    double a ,b;
};
com conju(com c){
    c.b = -c.b;
    return c;
}
com neg(com c){
    c.a = -c.a;
    c.b = -c.b;
    return c;
}
double mod(com c){
    return sqrt(pow(c.a,2) + pow(c.b,2));
}
com mul(com c1 , com c2){
    com ans ;
    ans.a = c1.a*c2.a - c1.b*c2.b;
    ans.b = c1.b*c2.a + c1.a*c2.b;
    return ans;
}
com div(com c1 , com c2){
    com ans;
    ans = mul(c1 , conju(c2));
    ans.a /= mod(c2)*mod(c2);
    ans.b /= mod(c2)*mod(c2);
    return ans;

}
com add(com c1, com c2){
    com ans;
    ans.a = c1.a + c2.a;
    ans.b = c1.b + c2.b;
    return ans;
}

int main(){
    com z1 , z2;
    cout<<"Enter Z1: ";
    cin>>z1.a>>z1.b;
    cout<<"Enter Z2: ";
    cin>>z2.a>>z2.b;
    cout<<"Mod Z1: "<<mod(z1)<<endl;
    cout<<"Mod Z2: "<<mod(z2)<<endl;
    cout<<"Multiplication is: "<<mul(z1,z2).a<<" "<<mul(z1,z2).b<<"i"<<endl;
    cout<<"Division is: "<<div(z1,z2).a<<" "<<div(z1,z2).b<<"i"<<endl;
    cout<<"Addition is: "<<add(z1,z2).a<<" "<<add(z1,z2).b<<"i"<<endl;
    cout<<"Subtraction is: "<<add(z1,neg(z2)).a<<" "<<add(z1,neg(z2)).b<<"i"<<endl;
}