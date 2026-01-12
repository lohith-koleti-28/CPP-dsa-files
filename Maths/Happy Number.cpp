#include<simplecpp>
int sumSq(int n){
    int ans=0;
    while(n>0){
        ans += pow( n%10 ,2);
        n /= 10;
    }
    return ans;
}
int main(){
    int n,a,b;
    cin >>n;
    a=n;
    for(int i=1;i<11;i++){
        b = sumSq(a);
        if(b ==1){
            cout<<"Happy Number\n";
            break;
        }
        a = b;
    }
    cout<<"Result is: "<<b<<endl;;
}




