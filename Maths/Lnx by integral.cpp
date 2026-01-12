#include<simplecpp>
double lnx(unsigned long int n , double x){
	double ans=0;double w , x1=1,x2;
	w = (x-1)/n;
	for(unsigned int i =1;i<=n;i++){
		x2 = x1 + w;
		ans += ((1.0/x1) + (1.0/x2))/2 * (w);
		x1 = x2;
	}
	return ans;
}
main_program{
	unsigned long int n = 10000000;
	double x;
	cout<<"Enter x: ";
	cin >>x;
	cout<<"Calculated: "<<lnx(n,x)<<endl;
	cout<<"Library: "<<log(x)<<endl;

}