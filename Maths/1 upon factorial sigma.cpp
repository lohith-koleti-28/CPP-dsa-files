#include<simplecpp>
main_program{
	cout<<"Enter n\n";
	int n;
	cin >> n;
	double a =1,b=1;
	for(int i=1; i<=n;i++){
		b = b/i;
		a += b;
	}
	cout<<a<<endl;
}


