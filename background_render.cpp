#include "background_render.hpp"

/** Variables **/
int levelImage = 0;
GLdouble angle, dAspect = 1;
GLdouble anglex = 0, angley = 0, anglez = -270;
GLuint textureId;
IplImage * image;
IplImage * imageBgd;
int quantidadeVidas = 3;
bool start = false;
double t = 30;
char ti[] = "30";
bool pause = true;

/** Background images variables **/
char name0[] = "imags/cenario1.png"; char nameBgd0[] = "imags/cenario1-exibir.png"; char nameBgd2D0[] = "imags/cenario1-exibir-2d.png";
char name1[] = "imags/cenario2.png"; char nameBgd1[] = "imags/cenario2-exibir.png"; char nameBgd2D1[] = "imags/cenario2-exibir-2d.png";
char name2[] = "imags/cenario3.png"; char nameBgd2[] = "imags/cenario3-exibir.png";

#define WIDTH 600
#define HEIGHT 600


void detMedVisualizacao(){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, dAspect, 1, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(anglex, angley, anglez, 0, 0, 0, 0, 1, 0);
}

void alteraJanela(GLsizei w, GLsizei h){
    if (h == 0) h = 1;

	glViewport(0, 0, w, h);
	dAspect = w / h;
}

void initTexture(){
    glBindTexture(GL_TEXTURE_2D, textureId);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imageBgd->width, imageBgd->height, GL_BGR_EXT, GL_UNSIGNED_BYTE, imageBgd->imageData);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0, HEIGHT);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(WIDTH, HEIGHT);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(WIDTH, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void init(
    int argc, 
    char **argv, 
    void draw(),
    void sairEsc(unsigned char key, int x, int y),
    void tutorial(int value),
    void TempoAtivo(int value),
    void Tempo(int value),
    void TransicaoFases(int value)
){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("MOVE");
	glutFullScreen();
	glutDisplayFunc(draw);
	glutKeyboardFunc(sairEsc);
	glutTimerFunc(5000, tutorial, 1);
	glutTimerFunc(1000, TempoAtivo, 1);
	glutTimerFunc(1000,Tempo,1);
	glutTimerFunc(1000, TransicaoFases, 1);
	glutIdleFunc(draw);
	glutReshapeFunc(&alteraJanela);
}

void setCamera(){
    GLfloat luzAmbiente[4] = { .4,.4,.4,1 };
	GLfloat luzDifusa[4] = { .7,.7,.7,1 };
	GLfloat luzEspecular[4] = { 1, 1, 1, 1 };
	GLfloat posicaoLuz[4] = { 0, 50, 50, 1 };
	GLfloat especularidade[4] = { 1,1,1,1 };
	GLint especMaterial = 60;

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	angle = 45;
}

void BarraTempo(char *string){

	glPushMatrix();

	glRasterPos2d(550,70);
	while(*string){
		glColor3f(0,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	}
	glPopMatrix();

}

void vidas(){
	for(int i=0;i<quantidadeVidas;i++){
		glPushMatrix();
		glColor3f(1,1,1);
		glTranslated(520+(i*20),40,0);
		glutSolidSphere(7,10,10);
		glPopMatrix();
	}

}

void Tempo(int value){
	if(t>0 && start==true && pause==false){
		t--;
	}
	//itoa(t,ti,10);
	sprintf(ti,"%f",t);
	glutTimerFunc(1000,Tempo,1);
}