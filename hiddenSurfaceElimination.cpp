#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void CirCle() {
    setcolor(RED);
    circle(100,100,80);
    setfillstyle(SOLID_FILL,RED);
    floodfill(100,100,RED);
}
void RectAngle() {
    setcolor(GREEN);
    rectangle(100,100,240,240);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(101,101,GREEN);
}
void TriAngle() {
    setcolor(BLUE);
    line(120,250,250,120);
    line(120,250,300,300);
    line(250,120,300,300);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(260,260,BLUE);
}
int main() {
    string sequence;
    cin>>sequence;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    for(auto x:sequence) {
        if(x=='C') CirCle();
        else if(x=='R') RectAngle();
        else TriAngle();
    }
    getch();
    closegraph();
    return 0;
}
