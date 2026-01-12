#include<simplecpp>
main_program{
	initCanvas("New" , 500 , 500);
	Turtle t1 , t2, t3;
	t3.left(-120);
	t2.left(120);
	repeat(3){
		t1.forward(100);
		t2.forward(100);
		t1.right(120);
		t2.right(120);
		t3.forward(100);
		t3.right(120);
	}
	wait(4);
}

