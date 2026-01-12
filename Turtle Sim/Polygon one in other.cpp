#include<simplecpp>
int main(){
    int n;
    cin >> n;
    int a = 50;
    turtleSim();
    // wait(3);
    for(int i=3;i<=n;i++){
        left(180.0/i);
        for(int j=1;j<=i;j++){
            forward(a);
            if(j != (i))
            left(360.0/i);
            else left(180.0/i);
            // int k;
            // cin >> k;
        }
        a += 10;
    }
    getClick();
}