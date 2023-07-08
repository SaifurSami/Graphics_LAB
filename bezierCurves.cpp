#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define ep 0.0001
int numControl,degree;

int factorial(int num) {
    //cout<<"FUCK"<<endl;
    if(num <= 1)
        return 1;
    return num*factorial(num-1);
}
void bezier(int xp[],int yp[]) {
    putpixel(xp[0],yp[0],YELLOW);
    double b;
    int fact = factorial(degree);
    for(double u = 0; u <= 1; u += ep) {
        double xt = 0,yt = 0;
        for(int i = 0; i < numControl; i++) {
            b = fact*pow(u,i)*pow((1-u),(degree-i))/(factorial(i)*factorial(degree-i));
            xt += xp[i]*b;
            yt += yp[i]*b;
        }
        putpixel(xt,yt,YELLOW);
    }
    setcolor(RED);
    for(int i = 0; i < numControl; i++)
        circle(xp[i],yp[i],numControl);
}
int main() {
    initwindow(16*60,9*60);
    cout<<"Enter the Number of Control Points = ";
    cin>>numControl;
    degree = numControl - 1;
    int x[numControl],y[numControl];

    for(int i = 0; i < numControl; i++) {
        cout<<"Enter the Control Point : ";
        cin>>x[i]>>y[i];
    }
    bezier(x,y);
    getch();
    closegraph();
    return 0;
}
