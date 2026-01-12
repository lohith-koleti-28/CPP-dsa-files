#include<simplecpp>
main_program{
	int n; cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){//first stars 
			cout<<"*";
		}
		for(int j=1;j<=(2*n-2*i);j++){//spaces
			cout<<" ";
		}
		for(int j=1;j<=i;j++){//final stars
			cout<<"*";
		}
		cout<<endl;
	}
	
}