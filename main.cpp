#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include<GL/glu.h>
int firsttime = 0;
float x = 0 , y = 0, z = 0.0;
GLfloat oldy = 0, oldz = 0, tempz, dy = 0, dz = 0;
int triggered = 0;
GLfloat court[][3] = {
                                {-2.5, -1.0, -4.7},
                                {2.5, -1.0, -4.7},
                                {2.5, -1.0, 4.7},
                                {-2.5, -1.0, 4.7}
                                                    };

GLfloat firstPole[][3] = {
                                    {-0.1, -1.0, -5.2},
                                    {0.1, -1.0, -5.2},
                                    {-0.1, -1.0, -5.0},
                                    {0.1, -1.0, -5.0},

                                    {-0.1, 0.5, -5.2},
                                    {0.1, 0.5, -5.2},
                                    {-0.1, 0.4, -5.0},
                                    {0.1, 0.4, -5.0},

                                    {-0.1, 1.3, -4.4 },
                                    { 0.1, 1.3 , -4.4},
                                    {-0.1, 1.7, -4.4 },
                                    { 0.1, 1.7, -4.4 }
                                                            };


GLfloat firstBoard[][3] = {
                                    {-0.5, 1.0, -4.3},
                                    { 0.5, 1.0, -4.3},
                                    {-0.5, 1.0, -4.4},
                                    { 0.5, 1.0, -4.4},


                                    {-0.5, 2.0, -4.3},
                                    { 0.5, 2.0, -4.3},
                                    {-0.5, 2.0, -4.4},
                                    { 0.5, 2.0, -4.4},
                                                            };
GLfloat baseVertices[][3] = {

	{-3.0, -1.0001, -5.2}, {3.0, -1.0001, -5.2},
	{-3.0, -1.0001, 5.2}, {3.0, -1.0001, 5.2},

      {-3.0, -1.5, -5.2}, {3.0, -1.5, -5.2},
      {-3.0, -1.5, 5.2}, {3.0, -1.5, 5.2},

  };
void poles(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);

        glColor3f(55.0 / 255.0, 51.0/ 255.0, 49.0/ 255.0);
        glVertex3fv(firstPole[a]);
        glVertex3fv(firstPole[b]);
        glVertex3fv(firstPole[c]);
        glVertex3fv(firstPole[d]);
	glEnd();

	glBegin(GL_LINE_LOOP);
        glColor3f(43.0 / 255.0, 39.0/ 255.0, 37.0/ 255.0);
        glVertex3fv(firstPole[a]);
        glVertex3fv(firstPole[b]);
        glVertex3fv(firstPole[c]);
        glVertex3fv(firstPole[d]);
	glEnd();

}
    void lines(float a, float b, float c, float d)
	{
        glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(a , -0.9999 , b);
            glVertex3f(d , -0.9999 , b);
            glVertex3f(d , -0.9999 , c);
            glVertex3f(a , -0.9999 , c);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(a , -0.9999 , b);
            glVertex3f(d , -0.9999 , b);
            glVertex3f(d , -0.9999 , c);
            glVertex3f(a , -0.9999 , c);
        glEnd();
	}
  void onBoardLines(float a, float b, float c, float d)
	{
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(a, b, -4.29);
        glVertex3f(d, b, -4.29);
        glVertex3f(d, c, -4.29);
        glVertex3f(a, c, -4.29);
	glEnd();


	}
  void board(int a, int b, int c, int d)
	{
	glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3fv(firstBoard[a]);
        glVertex3fv(firstBoard[b]);
        glVertex3fv(firstBoard[c]);
        glVertex3fv(firstBoard[d]);
    glEnd();

	glBegin(GL_LINE_LOOP);
        glColor3f(86.0/255.0, 86.0/255.0, 86.0/255.0);
        glVertex3fv(firstBoard[a]);
        glVertex3fv(firstBoard[b]);
        glVertex3fv(firstBoard[c]);
        glVertex3fv(firstBoard[d]);
    glEnd();

}
 void base(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex3fv(baseVertices[a]);
        glVertex3fv(baseVertices[b]);
        glVertex3fv(baseVertices[c]);
        glVertex3fv(baseVertices[d]);
    glEnd();

	glBegin(GL_LINE_LOOP);
        glColor3f(1,0,0);
        glVertex3fv(baseVertices[a]);
        glVertex3fv(baseVertices[b]);
        glVertex3fv(baseVertices[c]);
        glVertex3fv(baseVertices[d]);
    glEnd();
}
void polygon(int a, int b, int c, int d)
{
        base(0, 1, 3, 2);
        base(4, 5, 7, 6);
        base(2, 3, 7, 6);
        base(0, 1, 5, 4);
        base(0, 2, 6, 4);
        base(1, 3, 7, 5);
	//court color
        glBegin(GL_POLYGON);
            glColor3f(0.0,0.5,0.0);
            glVertex3fv(court[a]);
            glColor3f(0.0,0.5,0.0);
            glVertex3fv(court[b]);
            glColor3f(0.0,0.5,0.0);
            glVertex3fv(court[c]);
            glColor3f(0.0,0.5,0.0);
            glVertex3fv(court[d]);
        glEnd();
	    poles(0, 1, 3, 2);
        poles(4, 5, 7, 6);
        poles(2, 3, 7, 6);
        poles(4, 5, 1, 0);
        poles(3, 1, 5, 7);
        poles(0, 2, 6, 4);

        poles(6, 7, 9, 8);
        poles(4, 5, 11, 10);
        poles(6, 4, 10 , 8);
        poles(7, 5, 11, 9);


        board(0, 1, 3, 2);
        board(4, 5, 7, 6);
        board(0, 2, 6, 4);
        board(1, 3, 7, 5);
        board(0, 1, 5, 4);
        board(3, 7, 6, 2);


        lines(-2.5, -0.05, 0.05, 2.5);


        lines(-2.50, 4.7, -4.7, -2.55);
        lines(2.50, 4.7, -4.7, 2.55);


        lines(-2.55, 4.70, 4.75, 2.55);
        lines(-2.55, -4.70, -4.75, 2.55);



        lines(-2.2, 4.7, 4.05, -2.27);
        lines( 2.2, 4.7, 4.05, 2.27);

        lines(-2.2, -4.7, -4.05, -2.27);
        lines( 2.2, -4.7, -4.05, 2.27);


        lines(-0.6, 4.7, 2.8, -0.64);
        lines(0.6, 4.7, 2.8, 0.64);

        lines(-0.6, -4.7, -2.8, -0.64);
        lines(0.6, -4.7, -2.8, 0.64);


        lines(-0.6, 2.8, 2.84, 0.6);
        lines(-0.6, -2.8, -2.84, 0.6);

	    onBoardLines(-0.15, 1.2, 1.24, 0.15);
	    onBoardLines(-0.15, 1.5, 1.54, 0.15);

        onBoardLines(-0.15, 1.2, 1.5, -0.10);
        onBoardLines(0.15, 1.2, 1.5, 0.10);

}
void circle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++)
	{
      glVertex3f( (r * cos(2*3.14159 * i/1000.0)), -0.9999, (r * sin(2*3.14159 * i/1000.0)));
    }
    glEnd();
}
void Dcircle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++)
	{
        glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.9999, 2.8 - (r * sin(1*3.14159 * i/1000.0)));
        glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.9999, -2.8 + (r * sin(1*3.14159 * i/1000.0)));
    }
    for(i = 0; i < 20; i++)
	{

        glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.9999, 2.8 + (r * sin(1*3.14159 * i/20.0)));
        glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.9999, -2.8 - (r * sin(1*3.14159 * i/20.0)));
    }
    glEnd();
}
void ring(float r)
{
	int i;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
    for(i = 0; i< 1000; i++)
	{
        glVertex3f((r * cos(2*3.14159 * i/1000.0)), 1.2, -4.3 + 0.19 + (r * sin(2*3.14159 * i/1000.0)));
    }
    glEnd();
}

void semicircle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
    for(i = 0; i < 1000; i++)
	{
        glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.9999, 4.05 - (r * sin(1*3.14159 * i/1000.0)));
        glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.9999, -4.05 + (r * sin(1*3.14159 * i/1000.0)));
    }
    glEnd();
}

void ball()
{
    if(firsttime)
    {
        glTranslatef(0.0, 1.2, -1.5);
	}
	else
	{
        glTranslatef(0.0, 0.8, -2.8);
	}
	glColor3f(0.81176, 0.3254, 0.0);
    glutSolidSphere(0.15, 1000, 20);
}
void draw(void)
{
    glPushMatrix();
    if(firsttime == 0)
    {
        glTranslatef(0, y, dz);
    }
	ball();
    glPopMatrix();

	polygon(0, 1, 2, 3);
	  circle(0.60);
      Dcircle(0.6);

	  ring(0.17);
      semicircle(2.22);
	}
  static GLfloat theta[] = {0.0, 0.0, 0.0};
  static GLint axis = 2;
  static GLdouble viewer[] =  {0.0, 7.0, 7.0};
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);
	draw();
	glFlush();
    glutSwapBuffers();
}
void update(int value)
{
	if(firsttime)
	{
        y = 0.5;
        dz = 1.2;
        firsttime = 0;
    }
    if(triggered && y >= -2 && z >= -1.0)
	{
        y = -(2 * dz * dz) + 3.6;
        dz -= 0.05;
	}
	else
	{
        y = -0.7;
        dz = 1.4;
        triggered = 0;
    }
	glutPostRedisplay();
    glutTimerFunc(25,update,0);
}
void myReshape(int w, int h)
{
	glViewport(0, 0, w , h);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w , 2.0 * (GLfloat)h / (GLfloat)w, 2.0, 20.0);
    else
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h , 2.0 * (GLfloat)w / (GLfloat)h,  2.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
}
void keys(unsigned char key, int x, int y)
{
    if(key == 'x' && viewer[0] != -6) viewer[0] -= 1.0;
	if(key == 'X' && viewer[0] != 6) viewer[0] += 1.0;
	if(key == 'y' && viewer[1] != 0) viewer[1] -= 1.0;
	if(key == 'Y' && viewer[1] != 9) viewer[1] += 1.0;
	if(key == 'z'  && viewer[2] != 4) viewer[2] -= 1.0;
	if(key == 'Z'  && viewer[2] != 10) viewer[2] += 1.0;
    if(key == 'c')
{
        triggered = 1;
        firsttime = 1;
    }
    display();
}
int main(int argc, char *argv[])
{
	glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Colourable viewer");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(1, update, 0);
	glClearColor(0, 0, 0, 0);
	glutMainLoop();
	return 0;
}
