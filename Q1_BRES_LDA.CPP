#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void drawLine(int x1, int y1, int x2, int y2);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Adjust the path if necessary

    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    drawLine(x1, y1, x2, y2);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    int steps;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    int xIncrement = dx / steps;
    int yIncrement = dy / steps;

    putpixel(x, y, 23); // 15 is the color code, change as needed

    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;

        putpixel(x, y, 23); // 15 is the color code, change as needed
}
}