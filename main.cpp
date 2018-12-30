#include "background_render.hpp"
#include "render.hpp"
#include "exit.hpp"
#include "transition.hpp"

#define WIDTH 600
#define HEIGHT 600

int main(int argc, char *argv[]){
	arqRead = fgetc(arq);
	if (arqRead == 'r') {
		//nodeUser = NUI_SKELETON_POSITION_HAND_RIGHT;
	} else if (arqRead == 'l') {
		//nodeUser = NUI_SKELETON_POSITION_HAND_LEFT;
	} else {
		printf("Arquivo vazio!\n");
	}


	//HRESULT hr;
	
	image = cv::imread(name0, cv::IMREAD_COLOR);
	imageBgd = cv::imread(nameBgd0, cv::IMREAD_COLOR);

	if (image.data == NULL) {
		printf("Imagem não carregada!\n");
	}

	//initKinect();

	//Background generate
	glGenTextures(1, &textureId);
	
	init(argc, argv, draw, sairEsc,
	tutorial, TempoAtivo,
	TransicaoFases);


	setCamera();
	glOrtho(0, WIDTH, HEIGHT, 0, 50, -50);


	// Main loop
	glutMainLoop();
	fclose(arq);
	return 0;
	//NuiShutdown();

	return 0;
}
