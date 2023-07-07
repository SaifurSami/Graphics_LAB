#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main() {
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    //initwindow(16*50,9*50);
    //rectangle
    setcolor(GREEN);
    rectangle(40,80,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(100,100,GREEN);

    //circle
    setcolor(RED);
    circle(320,240,100);
    setfillstyle(SOLID_FILL,RED);
    floodfill(320,240,RED);

    getch();
    closegraph();
    return 0;

}
