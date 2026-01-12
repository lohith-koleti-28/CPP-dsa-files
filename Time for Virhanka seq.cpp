#include<iostream>
#include<ctime>
using namespace std;

int V(int n ){
    if(n ==1 || n==2) return 1;
    else return V(n-1) + V(n-2);
}
int fib(int n){
    int a1=1,a2=1,ai;
    for(int i=1;i<=(n-2);i++){
        ai  = a1+a2;
        a1 = a2;
        a2 = ai;
    }
    return ai;
}
int main(){
    int n;
    cin >>n;
    clock_t start ,end;
    start = clock();
    cout<<fib(n)<<endl;
    end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << cout.precision(5);
    cout << " sec " << endl;
}



