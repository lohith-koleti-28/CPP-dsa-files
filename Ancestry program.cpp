#include<iostream>
#include<cmath>
using namespace std;
struct Person{
    char p[10] , f[10];
};
void operator>>(istream &ist , Person &k){
    cin >> k.p>>k.f;
}
bool check(char *a , char*b){
    int n;
    bool ans = true;
    for(int i=0; ;i++){
        if(a[i] =='\0'){
            n= i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            ans = false;
            break;
        }
    }
    return ans;
}

int main(){
    cout<<"Enter number of generations: ";
    int gen; cin >> gen;gen--;
    Person p[gen];
    cout<<"Enter your ancestry as name and father name\n";
    for(int i=0;i<gen;i++)cin >>p[i];
    char name[10];
    cout<<"Enter name to be checked\n";
    cin >> name;
    int from;
    for(int i=0;i<3;i++){
        if(check(p[i].p,name)){
            from = i;
        }
    }
    cout<<"The Ancestry is:\n";
    cout<<p[from].p<<endl;
    for(int i=from;i<3;i++){
        cout<<p[i].f<<endl;
    }
}