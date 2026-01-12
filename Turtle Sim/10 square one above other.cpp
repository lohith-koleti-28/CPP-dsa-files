#include<simplecpp>
main_program{
	turtleSim();
	penUp();
	right(90);
	forward(200);
	left(90);
	penDown();
	int l= 25 , a= 90;
	for(int i =1;i<=2;i++){
	repeat(10){
		repeat(2){
		forward(l);
		left(a);
		}
		a= -a;
	}
	a =-a;
	}
	penUp();forward(500);
	wait(4);
}



