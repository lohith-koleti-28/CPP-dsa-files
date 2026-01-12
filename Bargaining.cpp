#include<iostream>
using namespace std;
int main(){
  int p ,q;
  cout<<"How much money will you give\n";
  cin >> p;
  while(p<500){
    q = 1000 -p;
    cout<<"Can you give: "<<q<<endl;
    cin >>p;
  }
  cout<<"Sold!!\n";
}




