//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
}

void polygon(float radio, int n){
    float w = glutGet(GLUT_WINDOW_WIDTH);
    float h = glutGet(GLUT_WINDOW_HEIGHT);
    float xc = w/2;
    float yc = h/2;
    float x, y, x1, y1;
    float vertex = ceil(360.0f/n);
    for(int i=0;i<n;i++){
        x = xc + radio * cos(vertex*i*static_cast<float>(M_PI)/180.0f);
        y = yc + radio * sin(vertex*i*static_cast<float>(M_PI)/180.0f);
        x1 = xc + radio * cos(vertex*(i+1)*static_cast<float>(M_PI)/180.0f);
        y1 = yc + radio * sin(vertex*(i+1)*static_cast<float>(M_PI)/180.0f);
        glBegin(GL_LINES);
            glVertex2f(x,y);
            glVertex2f(x1,y1);
        glEnd();
    }

}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glLoadIdentity();
   float Radio = 150;
   int N = 2*static_cast<int>(static_cast<float>(M_PI)*Radio); // Calculo de los lados de la circunferencia n = 2*pi*radio.
   cout<<N<<endl;
   polygon(Radio, N); //poligon(radio, #lados)
   glFlush();  // Render now
}

void Init(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutInitWindowSize(500, 400);   // Set the window's initial width & height
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   Init();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutReshapeFunc(reshape);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}
