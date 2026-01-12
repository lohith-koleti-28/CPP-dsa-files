#include<simplecpp>
void drawI(int ht , int sp){
    //turtleSim();
    penDown();
    forward(sp); forward(-sp/2.0);
    right(90);forward(ht);left(90);forward(sp/2.0);
    forward(-sp);
    forward(sp/2.0);
    left(90);
    forward(ht);
    right(90);
    penUp();
    forward(sp*2);
    
}

void drawT(int ht , int sp){
    //turtleSim();
    penDown();
    forward(sp); forward(-sp/2.0);
    right(90);forward(ht);/*left(90);forward(sp/2.0);
    forward(-sp);
    forward(sp/2.0);
    left(90);
    forward(ht/2.0);
    right(90);penUp();
    forward(sp*2);*/
    penUp();
    
}

main_program{
    int a =50 , b=20;
    //cin >>a >>b;
    turtleSim();

    drawI(a,b);
    drawI(a,b);
    drawT(a,b);
    forward(500);
    getClick();
    
}
