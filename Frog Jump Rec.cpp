#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;

// if(frog == n-2){
   //    if(abs(a[frog-1] - a[frog+1]) < abs(a[frog-1] - a[frog])){
   //       return abs(a[frog-1] - a[frog+1]);
   //    }
   //    return abs(a[frog-1] - a[frog]) + frogP(a,frog+1,n);
   // }

int frogP(int *a,int frog,int n){
   if(frog == n) return 0;
   if(frog ==n-1){
      return abs(a[frog-1] - a[frog]);
   }
   if(abs(a[frog-1] - a[frog+1]) <= abs(a[frog-1] - a[frog])){
         return abs(a[frog-1] - a[frog+1]) + frogP(a,frog+2,n);
      }
   return abs(a[frog-1] - a[frog]) + frogP(a,frog+1,n);
}

int main(){
   int n;
   cin >> n;
   int a[n];
   for(int &i :a) cin >> i;
   cout<<frogP(a,1,n)<<endl;
}