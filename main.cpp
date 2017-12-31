#include "background_render.hpp"

int main(int argc, char **argv){
	//image = cvLoadImage(name0, CV_LOAD_IMAGE_COLOR);
	glGenTextures(1, &textureId);
	imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);
    detMedVisualizacao();
	initTexture();
    init(argc,**argv);

	glutMainLoop();
	return 0;
}
