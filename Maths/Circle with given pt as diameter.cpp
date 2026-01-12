#include<iostream>
#include<cmath>
using namespace std;
struct Point{
    double x,y;
};
void getPoint(Point &p){
    cin >> p.x >> p.y;
}
struct Circle{
    Point c;
    double r;
};

Circle fn(Point &p1 , Point &p2){
    Circle ans;
    ans.c.x = (p1.x + p2.x)/2;
    ans.c.y = (p1.y + p2.y)/2;
    ans.r = sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2))/2;
    return ans;
}

int main(){
    Point p1,p2;
    cout<<"Enter 1st point: ";
    getPoint(p1);
    cout<<"Enter 2nd point: ";
    getPoint(p2);
    Circle c1 = fn(p1,p2);
    cout<<"x: "<<c1.c.x<<" "<<"y: "<<c1.c.y
    <<"\n"<<"r: "<<c1.r<<endl;
}