//
// Created by nicholas on 31/12/17.
//

#include "render.hpp"
#include "exit.hpp"
#include "spheres.hpp"
#include "background_render.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    processSkeleton();
    if (t == 0 && quantidadeVidas == 0) {
        sairPrincipal();
    }
    else if (t == 0 && quantidadeVidas > 0) {
        quantidadeVidas--;
        t = timePadrao;
        xRHand = 485;
        yRHand = 35;
        start = false;
    }
    colisao();
    BarraTempo(ti);
    drawSphereAuxiliar();
    drawSphere();
    vidas();
    r = 1;
    b = 0;
    initTexture();
    glutSwapBuffers();
    glutPostRedisplay();
}