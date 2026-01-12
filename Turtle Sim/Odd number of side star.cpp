#include<simplecpp>
main_program{
	turtleSim();
	cout<<"Enter side length of star" << endl;
	int l;
	cin >> l;
	cout<<"Number of sides of star"<< endl;
	int n;
	cin >> n;
	repeat(n){
		forward(l);
		right(720.0/n);
	}
	wait(5);
}


