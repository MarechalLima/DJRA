//
// Created by nicholas on 31/12/17.
//
#include "spheres.hpp"
#include "background_render.hpp"
#include "transition.hpp"
#include "tutorial.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

float auxx, auxy;
float xRHand = 0.0f, yRHand = 0.0f;
GLfloat zRHand = 0;
GLfloat zRHandDefault = 0;
double r = 1, b = 0;

void drawSphereAuxiliar(){
	if((againTime == true && tTransicao==4) || (pause == false && tTransicao==4)){
		if(start==false){
			glPushMatrix();
			glColor3f(1,1,1);
			glTranslated(auxx,auxy,0);
			glutSolidSphere(10,10,10);
			glPopMatrix();
		}
	}

}
void drawSphere() {

	glPushMatrix();
	glTranslated(0, 0, 0);

	if (xRHand == 0 && yRHand == 0)
	{
		glTranslated(15, 15, 0);
	}else if((xRHand != 0 && yRHand != 0) || start==true){
		glTranslated((xRHand), yRHand, 0);
	}
	glColor3d(r, 0, b);
	glutSolidSphere(15, 16, 16);
	glPopMatrix();

}
