#include<simplecpp>
main_program{
	int n; cin >>n;
	int open =0 , close=0;
	bool check;
	char arr[n];//Using array to store input;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i] =='('){
			open++;
		}
		else if(arr[i] ==')'){
			close++;
		}
		if(i ==(n-1)) break;
		if(open >= close){//Initial open should be more than close;
			check = true;
		}
		else{
			check = false;
		}
	}
	if((open ==close)  && check){//Finally both open close should be same;
		cout<<"Correct\n";
	}
	else{
		cout<<"Incorrect\n";
	}
}