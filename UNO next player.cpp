#include<iostream>
using namespace std;
int main(){
   int T;
   cin >> T;
   for(int i=0;i<T;i++){
      int n , k;
      int nextPlayer=1;
      cin >> n >> k;
      char a[k+1];
      cin >> a;
      bool reverse=false;
      for(int j=0;j<k;j++){
         if(a[j] == 'R'){
            reverse = (reverse) ? false : true ;
            if(reverse){
               nextPlayer =(nextPlayer - 1) %n;
            }
            else{
               nextPlayer = (nextPlayer)% n +1;
            }  
         }
         if(reverse){
            if(a[j] == 'U'){
               nextPlayer = (nextPlayer -2)% n +1;
            }
            else if(a[j] == 'S'){
               nextPlayer = (nextPlayer -3 )%n + 1;
            }
         }
         else{
            if(a[j] == 'U'){
               nextPlayer = (nextPlayer)% n +1;
            }
            else if(a[j] == 'S'){
               nextPlayer = (nextPlayer + 1)%n + 1;
            }
         }
         if(nextPlayer <=0){
            nextPlayer = n + nextPlayer;
         }
      }
      cout<<"Next Player is: "<<nextPlayer<<endl;
   }
}