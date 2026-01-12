#include<simplecpp>
main_program{
   turtleSim();
   int i = 10;
   penUp();right(90);forward(100);left(90);
   forward(-200);penDown();
   for(i=10;i<=9000;i++){
    forward(0.5);
    left(i/5000.0);
   }
   penUp();forward(400);
    getClick();

}
