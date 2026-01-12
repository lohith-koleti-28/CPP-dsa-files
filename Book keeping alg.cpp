#include<iostream>
#include<cmath>
using namespace std;
struct Book{
    char name[10],auth[10];
    double price;
    int libAsc , pat;
    void issue(){
        if(pat ==0){
            int temp;//Identification number
            cout<<"Enter identification number: ";
            cin >> temp;
            pat = temp;
            cout<<"Issued successfully\n";
        }
        else cout<<"Book is borrowed\n";
    }
    void ret(){
        if(pat != 0){
            pat=0;
            cout<<"Returned Successfully\n";
        }
    }
};

int main(){
    Book b;
    char c;
    b.pat=0;
    cout<<"Enter I for issue , R for return and X for end\n";
    while(true){
        cin >> c;
        if(c == 'I'){
            b.issue();
        }
        else if(c == 'R'){
            b.ret();
        }
        else if(c == 'X') break;
    }
}