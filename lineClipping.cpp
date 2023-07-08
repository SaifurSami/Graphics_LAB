#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
double xmin = 200,ymin = 100,xmax = 500,ymax = 300;
int t = 8, b = 4, r = 2, l = 1;
void window(int xmin,int ymin,int xmax,int ymax) {
    rectangle(xmin,ymin,xmax,ymax);

    //printing the coordinates of the window
    char buffer[100];
    sprintf(buffer,"(%d,%d)",xmin,ymin);
    outtextxy(xmin-30,ymin-20,buffer);
    sprintf(buffer,"(%d,%d)",xmax,ymin);
    outtextxy(xmax-30,ymin-20,buffer);
    sprintf(buffer,"(%d,%d)",xmin,ymax);
    outtextxy(xmin-30,ymax+5,buffer);
    sprintf(buffer,"(%d,%d)",xmax,ymax);
    outtextxy(xmax-30,ymax+5,buffer);
}
int regionCode(int x,int y) {
    int code = 0;
    if(x < xmin) code |= l;
    else if(x > xmax) code |= r;
    if(y < ymin) code |= b;
    else if(y > ymax) code |= t;
    return code;
}
void lineClipping(int x1,int y1,int x2,int y2) {
    int code1,code2;
    code1 = regionCode(x1,y1);
    code2 = regionCode(x2,y2);
    bool inside = false,outside = false;
    while(true) {
        if(!(code1|code2)) { //completely inside
            inside = true;
            break;
        }
        else if(code1&code2) break; //completely outside
        else {    //partially inside
            double m = (y2-y1)/(x2-x1),x,y;
            int code = code1? code1:code2;
            if(code & t) {
                y = ymax;
                x = x1 + (y2 - y1)/m;
            }
            else if(code & b) {
                y = ymin;
                x = x1 + (y2 - y1)/m;
            }
            else if(code & r) {
                x = xmax;
                y = y1 + (x2 - x1)*m;
            }
            else {
                x = xmin;
                y = y1 + (x2 - x1)*m;
            }
            if(code == code1) {
                x1 = x;
                y1 = y;
                code1 = regionCode(x1,y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = regionCode(x2,y2);
            }


        }
    }
    if(inside) {
        setcolor(YELLOW);
        line(x1,y1,x2,y2);
    }
}
int main() {
    initwindow(16*50,9*50);
    window(xmin,ymin,xmax,ymax);
    int numLine;
    cout<<"Enter the Number of Line = ";
    cin>>numLine;
    while(numLine--) {
        int x1,y1,x2,y2;
        cout<<"Enter the End-Points of the Line (x,y) : ";
        cin>>x1>>y1>>x2>>y2;
        lineClipping(x1,y1,x2,y2);
    }
    getch();
    closegraph();
    return 0;

}
