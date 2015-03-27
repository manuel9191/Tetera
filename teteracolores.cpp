#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
int b;
double a1=0.329412f, a2=0.223529f, a3=0.027451f, d1=0.780392f, d2=0.568627f, d3=0.113725f, e1= 0.992157f, e2=0.941176f, e3 =0.807843f, s=27.8974f;
void ponermaterial ();
void keyboard(unsigned char key, int x, int y);
void init(void)
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}
void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION); /*ctivamos la matriz de proyeccion.*/
glLoadIdentity(); /*limpiamos" esta con la matriz identidad.*/
glOrtho(-300, 300, -300, 300, -300, 300); /*Usamos proyeccion ortogonal*/
glMatrixMode(GL_MODELVIEW); /*Activamos la matriz de modelado/visionado.*/
glLoadIdentity(); /*"Limpiamos" la matriz*/
}
void display(void)
{
GLfloat mat_ambient[] = {a1, a2 , a3};
GLfloat mat_diffuse[] = {d1, d2 , d3 };
GLfloat mat_specular[] = {e1, e2, e3 };
GLfloat shine[] = {s};
// "Limpiamos" el frame buffer con el color de "Clear", en este caso negro.
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
glutSolidTeapot(110.0);
glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case '1':
b=1;
ponermaterial();
break;
case '2':
b=2;
ponermaterial();
break;
case '3' :
b=3;
ponermaterial();
break;
case '4' :
b=4;
ponermaterial();
break;
case '5' :
b=5;
ponermaterial();
break;
}
glutPostRedisplay();
}
void ponermaterial()
{
if (b==1)
{
a1=0.135; a2=0.2225; a3=0.1575; d1=0.54; d2=0.89; d3=0.63; e1=0.316228; e2=0.316228; e3=0.316228; s=0.1;
}
if (b==2)
{
a1=0.05375; a2=0.05; a3=0.06625; d1=0.18275; d2=0.17; d3=0.22525; e1=0.332741; e2=0.328634; e3=0.346435; s=0.3;
}
if (b==3)
{
a1=0.25; a2=0.20725; a3=0.20725; d1=1.0; d2=0.829; d3=0.829; e1=0.296648; e2=0.296648; e3=0.296648; s=0.088;
}
if (b==4)
{
a1=0.1745; a2=0.01175; a3=0.01175; d1=0.61424; d2=0.04136; d3=0.04136; e1=0.727811; e2=0.626959; e3=0.625969; s=0.6;
}
if (b==5)
{
a1=0.1; a2=0.18725; a3=0.01745; d1=0.396; d2=0.74151; d3=0.69102; e1=0.297254; e2=0.30829; e3=0.306678; s=0.1;
}
}
int main(int argc, char **argv)
{
// Inicializo OpenGL
glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
glutCreateWindow ("Tetera Multicolor");
// Inicializamos el sistema
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
