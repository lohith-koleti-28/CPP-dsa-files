#include<simplecpp>
main_program{
	turtleSim();
	left(180);
	penUp();
	forward(200);
	penDown();
	left(180);

	int r = 70;
	for(int a =1;a<4;a++){
	repeat(36){
		repeat(4){
			forward(r);
			right(90);
			//wait(0.09);
		}
		right(10);
	}
	penUp();
	forward(140);
	penDown();
	}
	penUp();
	forward(500);
	wait(5);
}


