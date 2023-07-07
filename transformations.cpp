#include<bits/stdc++.h>
#include<graphics.h>
#define pi 3.14159265358979323846
using namespace std;
int vertex;
int x[100],y[100];
int tx,ty,sx,sy,xPivot,yPivot;
double angle;
void draw() {
    for(int i = 0; i < vertex; i++)
        line(x[i],y[i],x[(i+1)%vertex],y[(i+1)%vertex]);
}
void translation() {
    cout<<"Enter the Translation Factors : ";
    cin>>tx>>ty;
    for(int i = 0; i < vertex; i++) {
        x[i] += tx;
        y[i] += ty;
    }
    draw();
}
void scaling() {
    cout<<"Enter the Scaling Factors : ";
    cin>>sx>>sy;
    for(int i = 0; i < vertex; i++) {
        x[i] *= sx;
        y[i] *= sy;
    }
    draw();
}
void rotation() {
    cout<<"Enter the Angle (anti-clock) : ";
    cin>>angle;
    cout<<"Enter the Pivot Point : ";
    cin>>xPivot>>yPivot;
    angle *= pi;
    angle /= 180;
    for(int i = 0; i < vertex; i++) {
        int  temp1 = x[i] - xPivot, temp2 = y[i] - yPivot;
        x[i] = xPivot + (temp1*cos(angle) - temp2*sin(angle));
        y[i] = yPivot + (temp1 * sin(angle) + temp2 * cos(angle));
    }
    draw();
}
int main() {
    initwindow(16*50,9*50);
    cout<<"Enter the Number of Vertex of the Polygon = ";
    cin>>vertex;
    for(int i = 0; i < vertex; i++) {
        cout<<"Enter the Vertex (x"<<i+1<<", y"<<i+1<<") : ";
        cin>>x[i]>>y[i];
    }
    cout<<"Which Transformation? T-> Translation, S-> Scaling, R-> Rotation : ";
    char c;
    cin>>c;

    draw();
    setcolor(YELLOW);
    if(c == 'T') translation();
    else if(c == 'S') scaling();
    else rotation();
    getch();
    closegraph();
    return 0;

/*Input for Translation :
3
100 100
100 200
200 100
T
100 100

/*Input for Scaling :
3
100 100
100 200
200 100
S
2 2

Input for Rotation :
3
100 100
100 200
200 100
R
360
200 100
*/




}
