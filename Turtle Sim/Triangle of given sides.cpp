#include<simplecpp>
main_program{
	cout<<"Enter the sides of triangle"<<endl;
	double a,b,c;
	cin >> a>> b>>c;
	turtleSim();
	if((c>a+b) || (a>b+c) || (b>c+a)){
		cout<<"Invalid Triangle"<<endl;
	}else{
	forward(b*50);
	double angle_1 = (b*b + c*c -a*a)/(2*b*c);
	left(180.0 - arccosine(angle_1));
	forward(c*50);
	double angle_2 = (a*a+c*c-b*b)/(2*a*c);
	left(180.0 -arccosine(angle_2));
	forward(a*50);
	}
	wait(4);
}

