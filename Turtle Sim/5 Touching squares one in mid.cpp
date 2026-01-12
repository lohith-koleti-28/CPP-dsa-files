#include<simplecpp>
main_program{
	turtleSim();
	int l =70;
	repeat(4){
		repeat(4){
			forward(l);
			left(90);
			wait(0.1);
		}
		forward(l);
		right(90);
		wait(0.1);
	}
	wait(5);
}

