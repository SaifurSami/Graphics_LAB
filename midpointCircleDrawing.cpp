#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void pixelPlot(int xc,int yc,int x,int y) {
    putpixel(xc+x,yc+y,YELLOW);
    putpixel(xc+x,yc-y,YELLOW);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc-x,yc-y,YELLOW);

    putpixel(xc+y,yc+x,YELLOW);
    putpixel(xc+y,yc-x,YELLOW);
    putpixel(xc-y,yc+x,YELLOW);
    putpixel(xc-y,yc-x,YELLOW);
    delay(50);
}
int main() {
    initwindow(16*50,9*50);
    int xc,yc,r;
    cout<<"Enter the Center & radius : ";
    cin>>xc>>yc>>r;
    int x,y,p;
    x = 0;
    y = r;
    p = 1 - r;
    pixelPlot(xc,yc,x,y);
    while(x < y) {
        x++;
        if(p < 0) p += (2 * x + 1);
        else {
            y--;
            p += (2 * x + 1 - 2 * y);
        }
        pixelPlot(xc,yc,x,y);
    }
    getch();
    closegraph();
    return 0;
}
