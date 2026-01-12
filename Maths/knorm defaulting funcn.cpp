#include<simplecpp>
double knorm(double x , double y , double z ,int k=2){
    double ans = pow( pow(x,k) + pow(y,k) + pow(z,k), 1.0/k);
    return ans;
}
main_program{
    double x,y,z;
    cin>>x>>y>>z;
    bool check;
    int k;
    cin >>check;
    if(check){
        cin>>k;
        cout<<knorm(x,y,z,k);
    }
    else{
    cout<<knorm(x,y,z);
    }
    cout<<endl;
    
}
