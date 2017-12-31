//
// Created by nicholas on 31/12/17.
//
#include "spheres.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

bool againTime = false;
double tTransicao = 4;
bool pause = true;
bool start = false;
float auxx, auxy;
float xRHand = 0.0f, yRHand = 0.0f;
double r = 1, b = 0;

void drawSphereAuxiliar(){
    if(againTime == true && tTransicao==4 || pause == false && tTransicao==4){
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
    }else if(xRHand != 0 && yRHand != 0 || start==true){
        glTranslated((xRHand), yRHand, 0);
    }
    glColor3d(r, 0, b);
    glutSolidSphere(15, 16, 16);
    glPopMatrix();

}
