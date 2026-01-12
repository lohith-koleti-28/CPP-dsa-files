#include <simplecpp>
main_program{
	cout<<"Enter n and r\n";
	int n,r;
	cin >>n>>r;
	int Nr=1 , Dr=1;
	for(int i=1;i<=r;i++){
		Dr *= i;
	}
	for(int j =n;j>(n-r);j--){
		Nr *= j;
	}
	cout<<(Nr/Dr)<<endl;
}

