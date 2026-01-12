#include<simplecpp>
main_program{
  int c =50, q , w=0;
  char in ;
  cout<<"Enter a command\n";
  cin >> in;
  while(in != 'x'){
  if(in =='+'){
    cin >>q;
    if(q>c){
      cout<<"Wasted water: "<<(q-c);
      w = c;
    }
    else{
      cout<<"Done";
      w = q;
    }
    cout<<" Water in tank: "<<w<<endl;
  }
  else if(in =='-'){
    cin >> q;
    if(w < q){
      cout<<"Water given: "<<(w);
      w =0;
    }
    else{
      cout<<"Done";
      w = w -q;
    }
     cout<<" Water in tank: "<<w<<endl;
  }
  cin >> in;
  }
  cout<<"Thank you\n";
}




