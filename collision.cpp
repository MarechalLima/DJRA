//
// Created by nicholas on 31/12/17.
//

#include "collision.hpp"
#include "background_render.hpp"
#include "exit.hpp"
#include "render.hpp"

double timePadrao = 30;
bool faseConcluida = false;
bool vidaExtra = false;
bool coinStatus = true;

void profundidadeColisao() {
	if (zRHand < zRHandDefault && zRHand != 0 && faseConcluida == false && pause==false) {
		if (levelImage == 0 && hover == false) {
			imageBgd = cvLoadImage(nameBgd2D0, CV_LOAD_IMAGE_COLOR);
			if (coinStatus == false) {
				//PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
			}
			hover = true;
		} else if (levelImage == 1 && hover == false) {
			imageBgd = cvLoadImage(nameBgd2D1, CV_LOAD_IMAGE_COLOR);
			if (coinStatus == false) {
				//PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
			}
			hover = true;
		}
	}
	else if (zRHand != 0 && zRHand >= zRHandDefault && faseConcluida == false && pause==false) {
		if (levelImage == 0 && hover == true) {
			imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);
			hover = false;
		}
		else if (levelImage == 1 && hover == true) {
			imageBgd = cvLoadImage(nameBgd1, CV_LOAD_IMAGE_COLOR);
			hover = false;
		}
	}
}

void colisao() {
	if (quantidadeVidas <= 0) {
		sairPrincipal();
	}
	if (xRHand == 0) {
		xRHand += 485;
	}
	if (yRHand == 0) {
		yRHand += 35;
	}
	CvScalar teste;
	int x = 0, y = 0;
	if (start == true) {
		for (double angulo = 0; angulo <= 360; angulo += 12) {
			x = xRHand + 15 * cos(angulo);
			y = yRHand + 15 * sin(angulo);

			teste = cvGet2D(image, y, x);
			if (teste.val[0] == 0 && teste.val[1] == 0 && teste.val[2] == 0 && pause == false) {
				//PlaySound((LPCSTR)musica, NULL, SND_FILENAME | SND_ASYNC);
				if (quantidadeVidas == 0) {
					sairPrincipal();
				}
				quantidadeVidas--;
				t = timePadrao;
				xRHand = 485;
				yRHand = 35;
				start = false;
				hover = false;
				break;
			} else if (teste.val[0] == 255 && teste.val[2] == 0 && teste.val[1] == 0 && pause == false) {
				//PlaySound((LPCSTR)winMusic, NULL, SND_FILENAME | SND_ASYNC);
				if (levelImage == 1) {
					faseConcluida = true;
					quantidadeVidas = 3;
					start = false;
					vidaExtra = false;
					hover = false;
				}
				else if (levelImage == 2) {
					faseConcluida = true;
					quantidadeVidas = 3;
					start = false;
					vidaExtra = false;
					hover = false;
				}
				else if(levelImage == 0){
					faseConcluida = true;
					quantidadeVidas = 3;
					start = false;
					vidaExtra = false;
					hover = false;
				}
				xRHand = 485;
				yRHand = 35;
			} else if (teste.val[0] == 0 && teste.val[1] == 0 && teste.val[2] == 255 && pause == false) {
				profundidadeColisao();
				if (zRHand <= zRHandDefault && zRHand != 0 && vidaExtra == false && pause == false) {
					quantidadeVidas++;
					//PlaySound((LPCSTR)coinMusic, NULL, SND_FILENAME | SND_ASYNC);
					coinStatus = false;
					vidaExtra = true;
				}
			} else if (againTime == true && pause == true) {
				if (teste.val[0] == 0 && teste.val[1] == 0 && teste.val[2] == 0) {
					if (zRHand < zRHandDefault && zRHand != 0 && hover == false) {
						imageBgd = cvLoadImage(nameTno, CV_LOAD_IMAGE_COLOR);
						//PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
						hover = true;
					}
					else if (zRHand >= zRHandDefault && zRHand != 0 && hover == true) {
						imageBgd = cvLoadImage(nameTnone, CV_LOAD_IMAGE_COLOR);
						hover = false;
					}
					if (zRHand <= zRHandDefault && zRHand != 0) {
						tut++;
						start = false;
						againTime = false;
						hover = false;
					}
				}
				else if (teste.val[0] == 0 && teste.val[1] == 0 && teste.val[2] == 255) {
					if (zRHand < zRHandDefault && zRHand != 0 && hover == false) {
						imageBgd = cvLoadImage(nameTyes, CV_LOAD_IMAGE_COLOR);
						//PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
						hover = true;
					}
					else if (zRHand >= zRHandDefault && zRHand != 0 && hover == true) {
						imageBgd = cvLoadImage(nameTnone, CV_LOAD_IMAGE_COLOR);
						hover = false;
					}
					if (zRHand <= zRHandDefault && zRHand != 0) {
						tut = 0;
						start = false;
						pause = true;
						hover = false;
						againTime = false;
					}
				}
			}
		}
	}
}
