#include<simplecpp>
int main(){
    initCanvas();
    Turtle t[24];
    int i;
    for(i=0;i<24;i++){
        t[i].left(15*i);
    }
    repeat(360){
    for(i=0;i<24;i++){
        t[i].forward(1);
        t[i].left(1);
    }
    }
    for(i=0;i<24;i++){
        t[i].hide();
    }
    getClick();
}




