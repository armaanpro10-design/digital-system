#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    
    circle(300, 300, 50);
    outtextxy(250, 370, (char*)"Graphics is working!");
    
    getch();
    closegraph();
    return 0;
}