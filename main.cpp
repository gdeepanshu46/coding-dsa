// C program to demonstrate
// drawing a circle using
// OpenGL
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857


// function to initialize
void myInit(void)
{
	// making background color black as first
	// 3 arguments all are 0.0
	//glClearColor(0.0, 0.0, 0.0, 1.0);

	// making picture color green (in RGB mode), as middle argument is 1.0
	//glColor3f(1.0, 0.0, 0.0);

	// breadth of picture boundary is 1 pixel
	//glPointSize(1.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

void draw_line()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);

          glVertex2f(-100,-100);
      glVertex2f(-100,100);
      glVertex2f(100,100);
      glVertex2f(100,-100);
      glVertex2f(-100,-100);

    glEnd();
    glFlush();
}
void draw_line2()
{
    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_LINE_STRIP);
//
//        glVertex2f(0,200);
//      glVertex2f(200,200);
//      glVertex2f(200,0);
//      glVertex2f(0,0);
//      glVertex2f(0,200);
//
//
//
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//
//          glVertex2f(-100,-100);
//      glVertex2f(-100,100);
//      glVertex2f(100,100);
//      glVertex2f(100,-100);
//      glVertex2f(-100,-100);
//
//    glEnd();
//
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(1.0, 0.0, 0.0);
//
//
//        glVertex2f(0,0);
//        glVertex2f(0,100);
//      glVertex2f(100,100);
//      glVertex2f(100,0);
//

      //glVertex2f(0,0);





//    glEnd();
float x, y, i;
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(0.0, 0.0, 1.0);
//    for ( i = 0; i < (2 * pi); i += 0.001)
//	{
//		// let 200 is radius of circle and as,
//		// circle is defined as x=r*cos(i) and y=r*sin(i)
//		x = 200 * cos(i);
//		y = 200 * sin(i);
//
//		glVertex2i(x, y);
//	}
//	for ( i = 0; i < (2 * pi); i += 0.001)
//	{
//		// let 200 is radius of circle and as,
//		// circle is defined as x=r*cos(i) and y=r*sin(i)
//		x = 200 * cos(i);
//		y = 200 * sin(i);
//
//		glVertex2i(x+100, y+100);
//	}
//	glEnd();
int x1,y1,x2,y2;
int cnt=0;
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 0);
    glVertex2i(0,0);
    glVertex2i(0,100);
    glVertex2i(100,100);
    glVertex2i(100,0);

    glEnd();
//    for ( i = 0; i < (2 * pi); i += 0.001)
//	{
//		// let 200 s radius of circle and as,
//		// circle is defined as x=r*cos(i) and y=r*sin(i)
//		x = 200 * cos(i);
//		//x1 = 200*cos(i+0.001);
//		y = 200 * sin(i);
//
//		glVertex2i(x, y);
//
//
//
//	}
//	glEnd();

//	glBegin(GL_LINES);
//    glColor3f(0.0, 1.0, 0.0);
//    for ( i = 0; i < (2 * pi); i += 0.001)
//	{
//		// let 200 s radius of circle and as,
//		// circle is defined as x=r*cos(i) and y=r*sin(i)
//		x1 = 220 * cos(i);
//		x = 240 * cos(i);
//		x2 = 260 * cos(i);
//		//x1 = 200*cos(i+0.001);
//		y = 240 * sin(i);
//		y1 = 220 * sin(i);
//		y2 = 260 * sin(i);
//        if(cnt%50==0)
//        {
//            glVertex2i(x1,y1);
//            glVertex2i(x, y);
//		//cnt =0;
//        }
//        if(cnt%100==0)
//        {
//            glVertex2i(x1,y1);
//            glVertex2i(x2, y2);
//		cnt =0;
//        }
//        cnt++;
//
//	}
//	glEnd();

    glFlush();
}
void draw_square()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);

     glVertex2f(0,200);
      glVertex2f(200,200);

      glVertex2f(200,0);
      glVertex2f(0,0);




    glEnd();
    glFlush();
}

void draw_rect2(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);

     glVertex2f(0,150);
    glVertex2f(150,150);
     glVertex2f(0,0);
     glVertex2f(150,0);
    glEnd();


    glFlush();
}

void draw_circle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, i;

	// iterate y up to 2*pi, i.e., 360 degree
	// with small increment in angle as
	// glVertex2i just draws a point on specified co-ordinate
	for ( i = 0; i < (2 * pi); i += 0.001)
	{
		// let 200 is radius of circle and as,
		// circle is defined as x=r*cos(i) and y=r*sin(i)
		x = 200 * cos(i);
		y = 200 * sin(i);

		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}

void draw_rect(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glLineWidth(30);

    glBegin(GL_POLYGON);
        glVertex2i(50,90);
        glVertex2i(100,90);
        glVertex2i(100,150);
        glVertex2i(50,150);
    glEnd();
    glFlush();
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0,0);

	// Giving name to window
	glutCreateWindow("Circle Drawing");
	myInit();

	//glutDisplayFunc(draw_line);
	glutDisplayFunc(draw_line2);
    //glutDisplayFunc(draw_line);

	glutMainLoop();
	return 0;
}

