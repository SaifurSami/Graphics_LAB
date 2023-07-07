#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void bresenham(int xa,int ya,int xb,int yb) {
    int dx,dy,p;
    dx = abs(xa-xb);
    dy = abs(ya-yb);
    p = 2 * dy - dx;
    int x,y,xEnd;
    if(xa > xb) {
        x = xb;
        y = yb;
        xEnd = xa;
    }
    else {
        x = xa;
        y = ya;
        xEnd = xb;
    }
    putpixel(x,y,WHITE);
    while(x < xEnd) {
        if(p < 0) {
            x += 1;
            p += (2*dy);
        }
        else {
            x += 1;
            y += 1;
            p += (2*dy - 2*dx);
        }
        putpixel(x,y,WHITE);
    }
}
int main() {
    initwindow(16*50,9*50);
    int xa,ya,xb,yb;
    cout<<"Enter the Endpoints (x,y) : ";
    cin>>xa>>ya>>xb>>yb;
    bresenham(xa,ya,xb,yb);
    getch();
    return 0;


}
