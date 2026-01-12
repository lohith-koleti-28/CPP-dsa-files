#include<simplecpp>
main_program{
	cout<<"Enter the angle of circles"<<endl;
	int a;
	cin >> a;//Take angle as input to separate the cirlces
	turtleSim();
	penUp();
	forward(-200);
	penDown();
	//int a = 45;
	right(a);//Intialising the circle orientation
	repeat(4){
		 repeat(360 + 2*a){
			 forward(1);
			 left(1);
			// wait(0.001);
		 }
	right(2*a);
	}
	wait(5);//a changes the distance b/w centres of circles.
}

	

