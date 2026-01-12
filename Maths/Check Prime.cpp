#include<simplecpp>
main_program{
	//ut<<"Hello World\n";
	int a;cin >> a;
	bool ans = false;
	for(int i=2;i<=a-2;i++){
		if(a%i==0){
			ans = true;
		}
	}
	if(ans){
		cout<<"Composite\n";
	}
	else{
		cout<<"Prime\n";
	}


}
