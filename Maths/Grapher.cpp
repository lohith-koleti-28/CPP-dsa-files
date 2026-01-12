#include<simplecpp>

double f(double x){
    return  pow(x+1,2);
}
double fmax(double f(double)){
    double ans =f(0);
    for(int i = 1;i<5000;i++){
        if(ans<abs(f(i/1000.0))){
            ans  =f(i/1000.0);
        }
        if(ans<abs(f(-i/1000.0))){
            ans = f(-i/1000.0);
        }
    }
    return ans;
}

void grapher(double f(double)){
    double k = 299.0/fmax(f);
    //Axes
    Line y(300,0,300,600);
    y.imprint();
    Line x(0,300,600,300);
    x.imprint();
    //Graph
    for(int i = 0;i<=290;i++){
        Text t(300+i , 300 - k*f(i/58.0) , ".");
        t.imprint();
        Text t1(300 -i , 300 - k*f(-i/58.0),".");
        t1.imprint();
    }
    //x varies from -5 to +5
    //y varies in scale 20

}

int main(){
    initCanvas("Test"  ,600,600);
    grapher(f);
    getClick();
}





