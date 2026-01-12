#include<simplecpp>
main_program{
	cout<<"Enter the number of enteries to be processed\n";
	int n;
	cin >> n;
        double  p = 0;
	repeat(n){
		cout<<"Give the entry\n";
		double a;
		cin >> a;
		p = p +a;
	}
	double k = p/n;
	cout<<"The average of the entries is: \n";
	cout<< k;
	cout<<"\n";
}
