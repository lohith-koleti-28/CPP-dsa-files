#include<simplecpp>
main_program{
	initCanvas("Sine",600,600);
	//axes
	Line x (0,300,600,300);
	Line y (30,0,30,600);
	//points on x axis
	double a=70.6858;
	for(int i=1;i<9;i++){
		double x_val = i*PI/2.0;
		Text t (30+a ,310,x_val);
		//Text t1 (30+a+15,310,"Pi");
		t.imprint();
		//t1.imprint();
		a += 70.6858;

	}
	//Origin
	Text t2 (20,310,"0");

	
	//points on y axis
	double b = 70.0/4;
	for(int i=1;i<=4;i++){
		Text t3 (15,300-b , i/4.0);
		t3.imprint();
		b += 70.0/4;
	}
	b =70.0/4;
	for(int i=1;i<=4;i++){
		Text t6(15,300+b ,-i/4.0);
		t6.imprint();
		b += 70.0/4;
	}
	//graph
	for(int i=0;i<=283;i++){
	Text t4 (30+i,300-70*sin(i/45.0),".");	
	t4.imprint();
	}
	for(int i=0;i<=283;i++){
		Text t5 (313 +i,300 - 70*sin(i/45.0),".");
		t5.imprint();
	}
	//graph of cosine
	for(int i=0;i<=283;i++){
	Text t8 (30+i,300-70*cos(i/45.0),".");	
	t8.imprint();
	}
	for(int i=0;i<=283;i++){
		Text t9 (313 +i,300 - 70*cos(i/45.0),".");
		t9.imprint();
	}
	getClick();
}

