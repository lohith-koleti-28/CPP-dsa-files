#include<simplecpp>
main_program{
	turtleSim();
	cout<<"Enter the number\n";
	int n;
	double k = 400;
	cin >> n;
	penUp();left(180);
	forward(200);left(90);
	forward(100);left(90);
	penDown();
	repeat(n){
	repeat(4){
	forward(k);left(90);
	}
        forward(k/2);left(45);
        k /= 1.414;	
	}
	wait(5);
}
