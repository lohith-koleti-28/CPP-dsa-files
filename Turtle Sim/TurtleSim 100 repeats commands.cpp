#include<simplecpp>
main_program{
	turtleSim();
	cout<<"Type f for forward , l for left and r for right"<<endl;
	char com;
	repeat(100){
		cin >> com;
		switch(com){
			case 'f' : 
				forward(50);
				break;
			case 'l' :
				left(90);
				break;
			case 'r' :
				right(90);
				break;
		}
	}
	wait(5);
}



