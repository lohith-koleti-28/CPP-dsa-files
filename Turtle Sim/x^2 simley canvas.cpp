#include<simplecpp>
main_program{
    initCanvas("New" , 600, 600);
    for(int i=0 ; i<=280;i++){
        Text t(290 +i ,580- (double)i*i/(580), ".");
        Text t1(290-i ,580- (double)i*i/(580), "." );
        t.imprint();
        t1.imprint();
    }

    getClick();
}



