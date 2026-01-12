#include<simplecpp>
int main(){
    int n;
    cout<<"Enter minutes: ";
    cin >>n;
    turtleSim();
    for(int i=0;i<n;i++){
        for(int j=1;j<61;j++){
            Text t1(100 ,100 , i);
            Text t2(110 ,100," : ");
            Text t3(120 , 100 , j);
            wait(1);
        }
    }
    getClick();

}



