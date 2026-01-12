#include<iostream>
#include<cmath>
using namespace std;
struct Matrix{
    private:
    double a,b,c,d;
    public:
    Matrix(double x=1,double y=0,double z=0,double w=1){
        a=x;b=y;c=z;d=w;//Makes an identity matrix
    }
    void print(){
        cout<<a<<" "<<b<<endl<<c<<" "<<d<<endl;
    }
    double det(){
        return a*d-b*c;
    }
    bool isSingular(){
        if(this->det() ==0) return 1;
        else return 0;
    }
    Matrix trans(){
        return Matrix(a,c,b,d);
    }
    Matrix operator*(double fac){
        return Matrix(fac*a,fac*b,fac*c,fac*d);
    }
    Matrix operator*(Matrix m){
        return Matrix(a*m.a+b*m.c,a*m.b+b*m.d,c*m.a+d*m.c,c*m.b+d*m.d);
    }
    Matrix operator+(Matrix m){
        return Matrix(a+m.a,b+m.b,c+m.c,d+m.d);
    }
    Matrix operator-(Matrix m){
        return Matrix(a-m.a,b-m.b,c-m.c,d-m.d);
    }
    Matrix inv(){
        //If singular returns same matrix
        if(!(this->isSingular())){
            Matrix ans(d,-b,-c,a);
            ans = ans*(1.0/this->det());
            return ans;
        }
        return *this;
    }
};
int main(){
    Matrix a(1,2,3,4) , b(5,6,7,8);
    cout<<"Matrices are:\n";
    a.print();
    b.print();
    cout<<"Determinants of matrices:\n";
    cout<<a.det()<<" "<<b.det()<<endl;
    cout<<"Sum of Matrices:\n";
    (a+b).print();
    cout<<"Inverses are:\n";
    if(a.det() !=0)
    a.inv().print();
    else cout<<"A is singular\n";
    if(b.det() !=0)
    b.inv().print();
    else cout<<"B is singular\n";
    cout<<"Product of Matrices:\n";
    (a*b).print();
    cout<<"Inverse of product:\n";
    if((a*b).det() !=0)
    (a*b).inv().print();
    else cout<<"A*B is singular\n";
}