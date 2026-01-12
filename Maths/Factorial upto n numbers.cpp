#include<simplecpp>
main_program{
	cout<<"Enter a number"<<endl;
	int n;
	cin >> n;
	int ans= 1;
	for(int i =1 ; i<=n;i++){
		for(int j =1 ; j<=i;j++){
			ans *= j;
		}
		cout <<ans<<endl;
		ans = 1;
	}
}


