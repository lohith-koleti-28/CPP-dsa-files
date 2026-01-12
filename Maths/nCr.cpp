#include<simplecpp>
	int fac(int k){
		int ans = 1;
		for(int i=1;i<=k;i++){
			ans *= i;
		}
		return ans;
	}

	int combi(int n , int r){
		int p = (fac(n))/(fac(r)*fac(n-r));
		return p;
	}
	main_program{
		cout<<"Enter n and r\n";
		int n,r;
		cin >>n>>r;
		cout<<combi(n,r)<<endl;
	}

