#include <cmath>
#include <GL/freeglut.h>

const double Pi = 3.14159265358979;

void drawEllipse(double x, double y, double Ra, double Rb, double rotate){
    glBegin(GL_LINE_LOOP);
        for(double i = 0; i < 2 * Pi; i += .1){
            // ellipse 
            double X = Ra * cos(i), Y = Rb * sin(i);
            // rotate
            glVertex2f(x + X * cos(rotate) - Y * sin(rotate), y + X * sin(rotate) + Y * cos(rotate));
        }
    glEnd();
}

void drawEllipse(double x, double y, double Ra, double Rb){
    drawEllipse(x, y, Ra, Rb, 0);
}

void drawCircle(double x, double y, double r){
    drawEllipse(x, y, r, r);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0., 188./256, 212./256);

    drawEllipse(0, 0, 0.8, 0.3);
    drawEllipse(0, 0, 0.8, 0.3, Pi/3);
    drawEllipse(0, 0, 0.8, 0.3, Pi / 3 * 2);
    drawCircle(0, 0, 0.15);

    glFlush();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutCreateWindow("CG Assignment 1");
    glutDisplayFunc(&display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
