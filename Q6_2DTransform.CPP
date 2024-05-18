#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
// Structure for a 2D point
struct Point2D {
    float x, y, w; // Homogeneous coordinates (x, y, w)
};

// Function to initialize the graphics mode
void initializeGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
}

// Function to set the pixel with appropriate color
void setPixel(int x, int y) {
    putpixel(x, y, WHITE);
}

// Function to draw the 2D object
void drawObject(Point2D points[], int numPoints) {
    for (int i = 0; i < numPoints - 1; i++) {
        line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    line(points[numPoints - 1].x, points[numPoints - 1].y, points[0].x, points[0].y);
}

// Function to translate the object by (tx, ty)
void translate(Point2D points[], int numPoints, float tx, float ty) {
    for (int i = 0; i < numPoints; i++) {
        points[i].x += tx * points[i].w;
        points[i].y += ty * points[i].w;
    }
}

// Function to scale the object by (sx, sy) wrt a reference point (refX, refY)
void scale(Point2D points[], int numPoints, float sx, float sy, float refX, float refY) {
    for (int i = 0; i < numPoints; i++) {
        points[i].x = refX + (points[i].x - refX) * sx;
        points[i].y = refY + (points[i].y - refY) * sy;
    }
}

// Function to rotate the object by angle theta wrt a reference point (refX, refY)
void rotate(Point2D points[], int numPoints, float theta, float refX, float refY) {
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    for (int i = 0; i < numPoints; i++) {
        float newX = refX + (points[i].x - refX) * cosTheta - (points[i].y - refY) * sinTheta;
        float newY = refY + (points[i].x - refX) * sinTheta + (points[i].y - refY) * cosTheta;
        points[i].x = newX;
        points[i].y = newY;
    }
}

// Function to shear the object along x-axis and y-axis
void shear(Point2D points[], int numPoints, float shx, float shy) {
    for (int i = 0; i < numPoints; i++) {
        float newX = points[i].x + shx * points[i].y;
        float newY = points[i].y + shy * points[i].x;
        points[i].x = newX;
        points[i].y = newY;
    }
}

int main() {
    initializeGraphics();

    // Define the object (rectangle)
    Point2D points[] = {{100, 100, 1}, {200, 100, 1}, {200, 200, 1}, {100, 200, 1}};
    int numPoints = sizeof(points) / sizeof(points[0]);

    // Draw the original object
    setcolor(WHITE);
    drawObject(points, numPoints);

    // Perform transformations
    // Translation
    translate(points, numPoints, 50, 50);
    // Scaling
    scale(points, numPoints, 1.5, 1.5, 150, 150);
    // Rotation (45 degrees)
    rotate(points, numPoints, 45 * 3.14159 / 180.0, 150, 150);
    // Shearing
    //shear(points, numPoints, 0.5, 0.5);

    // Draw the transformed object
    setcolor(YELLOW);
    drawObject(points, numPoints);

    getch();
    closegraph();
return 0;
}
