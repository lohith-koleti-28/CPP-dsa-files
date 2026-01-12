#include<simplecpp>
main_program{
	turtleSim();
	int l = 70;
	cout<<"Enter the number of sides"<<endl;
	int n ;
	cin >> n;
	repeat(n){
		repeat(n){
			forward(l);
			left(360.0/n);
		}
		forward(l);
		right(360.0/n);
	}
	wait(3);
}


