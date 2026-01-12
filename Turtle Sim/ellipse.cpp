#include<simplecpp>
int main(){
    turtleSim();
    double theta = 0;
    Circle c(10,10,10);
    for(int i=1;i<=361;i++){
        // Text t(100 + 20*cosine(theta),150+  60*sine(theta) , ".");
        c.moveTo(100 + 20*cosine(theta),150+  60*sine(theta) );
        c.penDown();
        theta += 1;
    }
    getClick();
}