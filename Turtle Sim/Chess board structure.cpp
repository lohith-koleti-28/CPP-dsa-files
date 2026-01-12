#include<simplecpp>
main_program{
	turtleSim();
	penUp();
	right(90);
	forward(200);
	left(90);
	penDown();
	int l= 10 , a= 90;
	for(int j = 1;j<=8;j++){
	for(int i =1;i<=2;i++){
	repeat(8){
		repeat(2){
		forward(l);
		left(a);
		}
		a= -a;
	}
	a =-a;
	}
	forward(l);
	}
	wait(4);
}



