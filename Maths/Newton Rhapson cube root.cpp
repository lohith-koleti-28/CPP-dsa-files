#include<simplecpp>
double cubeRoot(int n ,double p){
	//f(x) = x*x*x -p;
	double x0;
	cout<<"Enter a guess which is greater than actual answer\n";
	cin >>x0;
	for(int i=1;i<=n;i++){
		x0 = x0 - ((x0*x0*x0 -p)/(3*x0*x0));
		cout<<"Iteration: "<<i<<" x0: "<<x0<<endl;
	}
	return x0;
}
main_program{
	int n; double ans;
	cout<<"Enter the number of iterations\n";
	cin>>n;
	double p;
	cout<<"Enter number for cube root\n";
	cin >>p;
	ans = cubeRoot(n,p);
	cout<<ans<<endl;
	cout<<pow(p,1.0/3)<<endl;
}