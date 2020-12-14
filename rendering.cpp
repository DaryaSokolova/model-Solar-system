#include <iostream>

//библиотеки для рендеринга OpenGl
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
//библиотека, чтобы подцепить пикчу
#include "image.h"
#include "SpaceObject.h"
#include "Main.cpp"
#pragma comment(lib, "glew32.lib")

using namespace std;


void drawScene(void) {
	//frameCount++;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (changeCamera == 0)gluLookAt(0.0, CameraPosition, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 1)gluLookAt(0.0, 0.0, CameraPosition, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 2)gluLookAt(0.0, CameraPosition, 0.00001, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	if (bigOrbitActive == 1) orbitalTrails();

	GLUquadric* quadric;
	quadric = gluNewQuadric();

	//Солнце - Sun
	glPushMatrix(); // сохраняем текущие координаты
	//glRotatef(sun.orbit, 0.0, 1.0, 0.0); //поворачивает на угол sun.orbit против часовой стрелки вокруг вектора (x0,y0,z0)
	//glTranslatef(sun.distance, 0.0, 0.0); // сдвигаемся по оси Х на sun.distance
	//if (labelsActive == 1)
	//{
	glRasterPos3d(-1.2, 7.0, 0.0); //void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
	//Specify the x, y, z coordinates for the raster position. || беру из интернет-источников, поэтому пояснение
	glColor3ub(255, 255, 255); // цвет объекта на модели (белый)
	writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Sun"); //надпись (шрифт_размер, текст)
//}
	glPushMatrix(); //сохраняем текущие координаты
	glRotatef(sun.axisTilt, 1.0, 0.0, 0.0); //поворачивает на угол sun.axisTilt против часовой стрелки вокруг вектора (x0,y0,z0)
	glRotatef(sun.axisAni, 0.0, 1.0, 0.0); //поворачивает на угол sun.axisAni против часовой стрелки вокруг вектора (x0,y0,z0)
	glRotatef(90.0, 1.0, 0.0, 0.0); //поворачивает на угол 90* против часовой стрелки вокруг вектора (x0,y0,z0)
	//glEnable(GL_TEXTURE_2D);		// Разрешение наложения текстуры
	//glBindTexture(GL_TEXTURE_2D, sunTexture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//gluQuadricTexture(quadric, 1);
	glColor3ub(255, 255, 0); // цвет объекта на модели (жёлтый)
	gluSphere(quadric, sun.radius, 20.0, 20.0); // gluSphere() рисует сферу заданного радиуса с центром вокруг начала координат
	//glDisable(GL_TEXTURE_2D);  Снятие разрешения наложения текстуры
	glPopMatrix();
	glPopMatrix();

	//Mercury
	glColor3ub(255, 255, 255); //белый 
	glPushMatrix(); // сохраняем текущие координаты
	glRotatef(mer.orbit, 0.0, 1.0, 0.0); //поворачивает на угол mer.orbit против часовой стрелки вокруг вектора (x0,y0,z0)
	glTranslatef(mer.distance, 0.0, 0.0); // сдвигаемся по оси Х на mer.distance
	//if (labelsActive == 1){
	glRasterPos3d(0.0, 3, 0.0);
	glColor3ub(255, 255, 255);
	writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Mercury");
	//}
	glPushMatrix();
	glRotatef(mer.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(mer.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, merTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);*/
	glColor3ub(255, 255, 0); // цвет объекта на модели (жёлтый)
	gluSphere(quadric, mer.radius, 20.0, 20.0); //создали сферу
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();

	//Venus
	glColor3ub(255, 255, 255); //белый 
	glPushMatrix();
	glRotatef(ven.orbit, 0.0, 1.0, 0.0);
	glTranslatef(ven.distance, 0.0, 0.0);
	//if (labelsActive == 1){
	glRasterPos3d(0.0, 3, 0.0);
	glColor3ub(255, 255, 255);
	writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Venus");
	//}
	glPushMatrix();
	glRotatef(ven.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(ven.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, venTexture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//gluQuadricTexture(quadric, 1);
	glColor3ub(255, 255, 0); // цвет объекта на модели (жёлтый)
	gluSphere(quadric, ven.radius, 20.0, 20.0);
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();

	//Earth, Orbit, Moon
	glColor3ub(255, 255, 255); //белый 
	glPushMatrix();
	glColor3ub(255, 255, 255); // цвет объекта на модели (белый)
	glRotatef(ear.orbit, 0.0, 1.0, 0.0);
	glTranslatef(ear.distance, 0.0, 0.0);
	//if (labelsActive == 1){
	glRasterPos3d(0.0, 3, 0.0);
	glColor3ub(138, 43, 226);
	writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Earth");
	//}
	glPushMatrix();
	glRotatef(ear.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(ear.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, earTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);*/
	gluSphere(quadric, ear.radius, 20.0, 20.0);
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//if (smallOrbitActive == 1){
		//lun.drawSmallOrbit();
	//}
	//if (moonsActive == 1){
	lun.drawMoon();
	//}
	glPopMatrix();

	//Mars, Orbits, Moons
	glPushMatrix();
	glRotatef(mar.orbit, 0.0, 1.0, 0.0);
	glTranslatef(mar.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Mars");
	}
	glPushMatrix();
	glRotatef(mar.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(mar.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, marTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, mar.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		pho.drawSmallOrbit();
		dei.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		pho.drawMoon();
		dei.drawMoon();
	}
	glPopMatrix();

	//Jupiter, Orbits, Moons
	glPushMatrix();
	glRotatef(jup.orbit, 0.0, 1.0, 0.0);
	glTranslatef(jup.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Jupiter");
	}
	glPushMatrix();
	glRotatef(jup.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(jup.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, jupTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, jup.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		eur.drawSmallOrbit();
		gan.drawSmallOrbit();
		cal.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		eur.drawMoon();
		gan.drawMoon();
		cal.drawMoon();
	}
	glPopMatrix();

	//Saturn, Orbit, Moon
	glPushMatrix();
	glRotatef(sat.orbit, 0.0, 1.0, 0.0);
	glTranslatef(sat.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Saturn");
	}
	glPushMatrix();
	glRotatef(sat.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(sat.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, satTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, sat.radius, 20.0, 20.0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glColor3ub(158, 145, 137);
	glRotatef(-63.0, 1.0, 0.0, 0.0);
	glutWireTorus(0.2, 6.0, 30.0, 30.0);
	glutWireTorus(0.4, 5.0, 30.0, 30.0);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		tit.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		tit.drawMoon();
	}
	glPopMatrix();

	glColor3ub(255, 255, 255);		//FIXES SHADING ISSUE

	//Uranus, Orbit, Moon
	glPushMatrix();
	glRotatef(ura.orbit, 0.0, 1.0, 0.0);
	glTranslatef(ura.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Uranus");
	}
	glPushMatrix();
	glRotatef(ura.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(ura.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, uraTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, ura.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		puc.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		puc.drawMoon();
	}
	glPopMatrix();

	//Neptune, Orbit, Moon
	glPushMatrix();
	glRotatef(nep.orbit, 0.0, 1.0, 0.0);
	glTranslatef(nep.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Neptune");
	}
	glPushMatrix();
	glRotatef(nep.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(nep.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, nepTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, nep.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		tri.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		tri.drawMoon();
	}
	glPopMatrix();

	//Pluto, Orbit, Moon
	glPushMatrix();
	glRotatef(plu.orbit, 0.0, 1.0, 0.0);
	glTranslatef(plu.distance, 0.0, 0.0);
	if (labelsActive == 1) {
		glRasterPos3d(0.0, 3.0, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, "Pluto");
	}
	glPushMatrix();
	glRotatef(plu.axisTilt, 1.0, 0.0, 0.0);
	glRotatef(plu.axisAni, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, pluTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(quadric, 1);
	gluSphere(quadric, plu.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (smallOrbitActive == 1) {
		nix.drawSmallOrbit();
	}
	if (moonsActive == 1) {
		nix.drawMoon();
	}
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, staTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBegin(GL_POLYGON);
	glTexCoord2f(-1.0, 0.0); glVertex3f(-200, -200, -100);
	glTexCoord2f(2.0, 0.0); glVertex3f(200, -200, -100);
	glTexCoord2f(2.0, 2.0); glVertex3f(200, 200, -100);
	glTexCoord2f(-1.0, 2.0); glVertex3f(-200, 200, -100);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, staTexture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200, -83, 200);
	glTexCoord2f(8.0, 0.0); glVertex3f(200, -83, 200);
	glTexCoord2f(8.0, 8.0); glVertex3f(200, -83, -200);
	glTexCoord2f(0.0, 8.0); glVertex3f(-200, -83, -200);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glutSwapBuffers();
}