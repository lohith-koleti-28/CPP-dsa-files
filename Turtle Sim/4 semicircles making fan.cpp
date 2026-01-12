#include<simplecpp>
main_program{
	turtleSim();
	repeat(4){
	forward(100);
	left(90);
	repeat(180){
		forward(0.87);left(1);
	wait(0.01);
	}wait(0.01);
	}
	wait(3);
}

