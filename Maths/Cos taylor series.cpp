#include<simplecpp>
long int fact ( int n){
  long int ans;
  for(int i=1;i<=n;i++){
    ans *= i;
  }
  return ans;
}
main_program{
  double s=1 ,t=1 ,x;
  cout<<"Enter x\n";
  cin >>x;
  for(int i=1;i<=15;i++){
    t *= (-1)*(x*x)/((2*i)*(2*i-1));
    s += t;
    cout<<"Number of iteration "<<i<<" the s is: "<<s<<" Error is: "<<t<<endl;
  }
  cout<<"Caluclated result: "<<s<<endl;
  cout<<"Library cos function "<<cos(x)<<endl;
}



