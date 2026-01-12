#include<simplecpp>
double pre(double x){
    int a = x*1000;
    return double(a)/1000;
}
int main(){
    double pheads=0 ;
    int heads=0;
    int i;
    for(i=1;abs(pre(pheads)-0.500)>= 0.001;i++){
        srand(i);
        int a = 1 + (2)*rand()/(double)RAND_MAX;
        if(a==1){
            heads++;
        }
        pheads = (double)heads/i;
    }
    i--;
    cout<<"Probability of Heads: "<<pheads<<endl;
    cout<<"Number of iterations: "<<i<<endl;
    cout<<"Heads: "<<heads<<endl;
    cout<<"Tails: "<<i-heads<<endl;
}




