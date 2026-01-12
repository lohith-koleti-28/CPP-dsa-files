#include<simplecpp>
double f(double x){
  double ans = x*x-5;
  return ans;
}
main_program{
  double xl , xr , xm;
  cout<<"Enter the limits of interval\n";
  cin>>xl>>xr;
  int i;
  for( i=1;(xr -xl)>=0.000001;i++){
    xm = (xl + xr)/2;
    if((f(xl)*f(xm) ) <=0){
      xr = xm;
    }
    else{
      xl = xm;
    }
    cout<<"xl :"<<xl<<" xm: "<<xm<<" xr:"<<xr<<endl;
  }
  cout<<"Number of iterations: "<<i<<endl;
  cout<<"Calculated answer: "<<xr<<endl;
  cout<<"Library function: "<<sqrt(5)<<endl;
}




