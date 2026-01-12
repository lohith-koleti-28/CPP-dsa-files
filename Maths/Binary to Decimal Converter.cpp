#include<simplecpp>
main_program{
	cout<<"Enter Binary Number"<<endl;
	int a;
	cin >> a;
	int b=0;int ans =0;
	int m = 1;int k;
	while(a>0){
		b = a%10;
		k = b*m;
		ans += k;
		m *= 2;
		a /= 10;
	}
	cout<<"The Decimal Number is: "<<ans<<endl;
}




	

