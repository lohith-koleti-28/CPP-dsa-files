#include<simplecpp>
double fx(double x){
	double ans = 1.0/(sqrt(1-x*x)) ;
	return ans;
}

double sinInv( double x){
	unsigned long int n = 10000000;
	double ans=0;double w , x1=0,x2;
	w = (x)/n;
	for(unsigned int i =1;i<=n;i++){
		x2 = x1 + w;
		ans += ((fx(x1)) + fx(x2))/2 * (w);
		x1 = x2;
	}
	return ans * 180.0/PI;
}
main_program{
	double x;
	cout<<"Enter x: ";
	cin >>x;
	cout<<"Calculated: "<<sinInv(x)<<endl;
	cout<<"Library: "<<arcsine(x)<<endl;

}