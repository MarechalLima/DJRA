#include <GL/gl.h>
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

void detMedVisualizacao();
void alteraJanela(
    GLsizei w,
    GLsizei h
);
void initTexture();
void init(
    int argc,
    char **argv,
    void draw(),
    void sairEsc(),
    void tutorial(),
    void TempoAtivo(),
    void Tempo(),
    void TransicaoFases()
);
void setCamera();


