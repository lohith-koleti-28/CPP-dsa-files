#include<simplecpp>
main_program{
    turtleSim();
    int n;cout<<"Enter n\n";
     cin >>n;
     cout<<"Enter the co-ordinates\n";
    double x1 ,y1,x2,y2;
    cin >>x1>>y1;
    double x_f = x1 , y_f = y1;
    for(int i =1; i<=n-1 ; i++){
        cin >>x2>>y2;
        Line l (x1,y1,x2,y2);
        l.imprint();
        x1 = x2 ; y1 = y2;
    }
    Line l1 (x_f , y_f ,x2 , y2);
    getClick();
}
