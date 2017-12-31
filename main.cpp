#include "background_render.hpp"
#include "render.hpp"
#include "exit.hpp"

#define WIDTH 600
#define HEIGHT 600

int main(int argc, char **argv){
    arqRead = fgetc(arq);
    if (arqRead == 'r') {
        nodeUser = NUI_SKELETON_POSITION_HAND_RIGHT;
    } else if (arqRead == 'l') {
        nodeUser = NUI_SKELETON_POSITION_HAND_LEFT;
    } else {
        printf("Arquivo vazio!\n");
    }


    //HRESULT hr;

    image = cvLoadImage(name0, CV_LOAD_IMAGE_COLOR);
    imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);

    if (image == NULL) {
        printf("Imagem não carregada!\n");
    }

    //initKinect();

    printf("kinect init");

    //Background generate
    glGenTextures(1, &textureId);
    //Background generate
    //init();


    setCamera();
    glOrtho(0, WIDTH, HEIGHT, 0, 50, -50);


    // Main loop
    glutMainLoop();
    fclose(arq);
    return 0;
    //NuiShutdown();

    return 0;
}
