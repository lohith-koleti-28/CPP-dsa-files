#include<simplecpp>
main_program{
	cout<<"Enter the degree of polynomial"<<endl;
	int n;
	cin >> n;
	int arr[n+1];//= new int [n];
	for(int i =0; i<n+1;i++){
		cout<<"Enter the value of coefficient at "<<i << " Index"<<endl;
		cin >> arr[i];
	}
	cout<<"Enter the value of Variable"<<endl;
	int x ;
	cin >> x;
	int p =1;
	int ans = 0;
	for(int j =0;j <n+1;j++){
		ans +=arr[j] * p;
		p *= x;
	}
	cout<<"The final value is: " << ans << endl;
}



