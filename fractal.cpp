#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define pi 3.14159265359
int it;
void koch(int x1,int y1,int x2,int y2,int it) {
    int x3,y3,x4,y4,x,y,dx,dy;
    double angle = (-1*60 * pi)/180;//do check -60 degree if 60 doesn't give good fractal :3
    x3 = (2*x1+x2)/3;
    y3 = (2*y1+y2)/3;
    x4 = (2*x2+x1)/3;
    y4 = (2*y2+y1)/3;

    //anticlock-wise rotation
    dx = x4 - x3;
    dy = y4 - y3;
    x = x3 + dx*cos(angle) + dy*sin(angle);
    y = y3 - dx*sin(angle) + dy*cos(angle);

    if(it > 0) {
        koch(x1,y1,x3,y3,it-1);
        koch(x3,y3,x,y,it-1);
        koch(x,y,x4,y4,it-1);
        koch(x4,y4,x2,y2,it-1);
    }
    else {

        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}
int main() {
    initwindow(16*50,9*50);
    cout<<"Enter the Number of Iteration = ";
    cin>>it;
    it--;
    if(it < 0) {
        line(250,270,450,270);
        line(450,270,350,165);
        line(350,165,250,270);
        getch();
        return 0;
    }
    koch(250,270,450,270,it);
    koch(450,270,350,165,it);
    koch(350,165,250,270,it);
    getch();
    return 0;

}
