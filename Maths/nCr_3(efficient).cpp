#include<simplecpp>
int nCr(int n, int r){
    if(r==0 || r ==n) return 1;
    else if(r==1 || r==(n-1)) return n;
    else return ( nCr(n-1,r)  + nCr(n-1,r-1));
}
int ncr(int n,int r){
    int nr,dr;
    nr=dr=1;
    if(r >=(n-r)){
    for(int i=1;i<=(n-r);i++){
        dr *= i;
    }
    for(int i=r+1;i<=n;i++){
        nr *=i; 
    }
    }
    else{
        for(int i=1;i<=r;i++){
            dr *= i;
        }
        for(int i=(n-r+1);i<=n;i++){
            nr *=i;
        }
    }
    return (double)nr/dr;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}




