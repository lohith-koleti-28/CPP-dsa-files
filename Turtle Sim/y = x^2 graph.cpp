#include<simplecpp>
main_program{
    initCanvas("new"  , 610,610);
    //axes
    Line y (300,0,300,610);
    Line x (0,585 , 610 ,585);
    // x points
    int a = 0;
    for(int i = -10;i<=10 ;i++){
        if(i==0) continue;
        Text t1 (10 + a , 595 , i);
        t1.imprint();
        a += 30;
    }
    // y points
    int b = 28;
    for(int i = 1 ; i<=10;i++){
        Text t4 (295 , 580 -b , i*i);
        t4.imprint();
        b += 28;
    }
    //Origin
    Text t2 (295,595,"0");
    // graph x*x
    for(int i =1;i<=299;i++ ){
        Text t3 (299 + i , 580- 280*i*i/90000.0 , "." );
        t3.imprint();
    }
    for(int i =1;i<=299;i++ ){
        Text t3 (299 - i , 580- 280*i*i/90000.0 , "." );
        t3.imprint();
    }
    getClick();
}