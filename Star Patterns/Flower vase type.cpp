#include<simplecpp>
main_program{
	int n; cin >>n;
	for(int i=1;i<=n;i++){//First half increasing stars
		 for(int j=1;j<=n-i;j++){
			cout<<" ";
		 }
		 for(int j=1;j<=(n+2*i-2);j++){
			cout<<"*";
		 }
		 cout<<endl;
	}
		 for(int i =1;i<=n-1;i++){//Second half decreasing stars
			for(int j=1;j<=i;j++){
				cout<<" ";
			}
			for(int j=1;j<=(3*n-2-2*i);j++){
				cout<<"*";
			}
		 cout<<endl;
	}
}