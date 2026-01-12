#include<simplecpp>
int main(){
    int n,sq=0,sm=0,a;
    double ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        sm += a;
        sq += a*a;
    }
    ans = (double)sq/n - pow((double)sm/n,2);
    cout<<"Variance is: "<<ans<<endl;
    cout<<"Standard deviation is: "<<sqrt(ans)<<endl;
}




