#include <cmath>
#include <GL/freeglut.h>

const double Pi = 3.14159265358979;

void drawRect(double x, double y, double width, double height){
    glBegin(GL_POLYGON);
    glVertex3f(x + width / 2 , y + height / 2, 0);
    glVertex3f(x - width / 2 , y + height / 2, 0);
    glVertex3f(x - width / 2 , y - height / 2, 0);
    glVertex3f(x + width / 2 , y - height / 2, 0);
    glEnd();
}

void drawStar(double x, double y, double size){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i = 0; i <= 10; i++){
        double arg = i * Pi / 5 + Pi / 2;
        double length = (i & 1) ? size * cos(Pi * 2 / 5) / cos(Pi / 5) : size;
        glVertex2f(x + length * cos(arg), y + length * sin(arg));
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    drawRect(0, 0, 2, 4./3);

    glColor3f(1,1,1);
    drawRect(0, 1./3, 2, 2./3);

    glColor3f(0,0,1);
    drawRect(-2./3, 1./3, 2./3, 2./3);

    glColor3f(1,1,1);
    drawStar(-2./3 , 1./3, 1./6);

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("CG Assignment 2");
    glutDisplayFunc(&display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
