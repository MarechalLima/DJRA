#ifndef DJRA_B_RENDER_HPP
#define DJRA_B_RENDER_HPP

#include <GL/gl.h>
#include <GL/glut.h>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/types_c.h>
// #include <opencv4/opencv2/cxcore.h>
// #include <opencv4/opencv2/highgui.h>

/** Variables **/
extern int levelImage, quantidadeVidas;
extern GLdouble angle, dAspect, anglex, angley, anglez;
extern GLuint textureId;
extern IplImage *image, *imageBgd;
extern bool start;
extern double t;
extern char ti[];

/** Background images variables **/
extern char name0[]; extern char nameBgd0[]; extern char nameBgd2D0[];
extern char name1[]; extern char nameBgd1[]; extern char nameBgd2D1[];
extern char name2[]; extern char nameBgd2[];

extern void detMedVisualizacao();

void alteraJanela(
	GLsizei w,
	GLsizei h
);
void initTexture();
void init(
	int argc,
	char **argv,
	draw(),
	void *sairEsc(),
	void *tutorial(),
	void *TempoAtivo(),
	void *TransicaoFases()
);
void setCamera();
void BarraTempo(char *string);
void vidas();
void Tempo(int value);

#endif