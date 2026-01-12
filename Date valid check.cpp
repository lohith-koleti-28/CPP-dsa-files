#include<iostream>
#include<ctime>
using namespace std;

struct date{
    int yr , mon , dt;
};
bool leap(date d){
    if(d.yr %100 ==0){
        if(d.yr % 400 ==0){
            return 1;
        }
        else return 0;
    }
    else{
        if(d.yr %4==0) return 1;
        else return 0;
    }
}
bool check(const date &d){
    if(d.mon <1 || d.mon >12) return 0;
    int big[7] = {1,3,5,7,8,10,12};
    bool th1 = false;//If this is true then month has 31 days
    for(int i=0;i<7;i++){
        if(big[i] == d.mon){
            th1 = true;
            break;
        }
    }
    if(th1 && (d.dt<1 || d.dt >31)) return 0;
    else if((!(d.mon == 2)) && (d.dt<1 || d.dt >30)) return 0;
    else if(leap(d) && (d.dt<1 || d.dt >29)) return 0;
    else if((!leap(d)) && (d.dt<1 || d.dt >28)) return 0;
    return 1;
}


int main(){
    date d;
    cout<<"Enter date yyyy/mm/dd: ";
    cin >> d.yr >> d.mon >> d.dt;//Taking date as input
    //Date as random number
    // srand(time(0));
    // d.yr = 1 + 3000.0*rand()/RAND_MAX; 
    // d.mon = 15.0*rand()/RAND_MAX;
    // d.dt = 32.0*rand()/RAND_MAX;
    // cout<<d.yr<<" "<<d.mon<<" "<<d.dt<<endl;
    if(check(d)){
        cout<<"Valid date\n";
    }
    else cout<<"Invalid date\n";
}