#include<simplecpp>
int rev(int n){
	int ans=0 , t;
	while(n>0){
		t = n%10;
		ans = ans*10 + t;
		n /= 10;
	}
	return ans;
}
main_program{
	int a ;
	cout<<"Enter a: ";
	cin >>a;
	for(int i = (a+1);i>0;i++){
		if(i ==rev(i)){
			cout<<i<<endl;
			break;
		}
	}
}