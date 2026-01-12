#include<simplecpp>
main_program{
	initCanvas("New",500,500);
	Line x (100,0,100,500);
	Line y (0,200,500,200);
	Line x1 (400,0,400,500);
	Line y1 (0,400,500,400);
	for(int i =1;i<11;i++){
	int pos = getClick();
	int x = pos/65536;
	int y = pos%65536;
	bool x_part = (x>=100) && (x<=400);
	bool y_part = (y>=200) && (y<=400);
	if((x_part) && (y_part)){
		cout<<"Inside Rectangle\n";
	}
	else{
		cout<<"Outside Rectangle\n";
	}
	}
	getClick();
}
