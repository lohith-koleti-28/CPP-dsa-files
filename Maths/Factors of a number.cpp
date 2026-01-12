#include<simplecpp>
void primeFactor(int n){
for(int i=1;i<=n;i++){
    if(n%i ==0){
        cout<<i<<" ";
    }
}
cout<<endl;
}

main_program{
    int a; cin >>a;
    primeFactor(a);
}

