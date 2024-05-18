#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void drawCircle(int xc, int yc, int r);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, r;

    cout << "Enter the center coordinates of the circle (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter the radius of the circle: ";
    cin >> r;

    drawCircle(xc, yc, r);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    // Plot the initial point
    putpixel(xc + x, yc - y, WHITE);

    // Mid-Point Circle Drawing Algorithm
    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
	putpixel(xc - y, yc + x,WHITE);
}
}