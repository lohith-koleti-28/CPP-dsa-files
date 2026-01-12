#include<simplecpp>
int main(){
    turtleSim();
    double r = 10;
    left(90);
    repeat(20){
    repeat(180){
        forward(2*PI*r/360.0);
        left(1);
    }
    r +=10 ;
    }
    getClick();
}




