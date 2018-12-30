//
// Created by nicholas on 31/12/17.
//

#include "transition.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include "background_render.hpp"
#include "exit.hpp"
#include "collision.hpp"

char nameTemp0_1[] = "imags//transicao//0_1.png";
char nameTemp0_2[] = "imags//transicao//0_2.png";
char nameTemp0_3[] = "imags//transicao//0_3.png";
char nameTemp1_1[] = "imags//transicao//1_1.png";
char nameTemp1_2[] = "imags//transicao//1_2.png";
char nameTemp1_3[] = "imags//transicao//1_3.png";
char nameTemp2_1[] = "imags//transicao//2_1.png";
char nameTemp2_2[] = "imags//transicao//2_2.png";
char nameTemp2_3[] = "imags//transicao//2_3.png";

double tTransicao = 4;

void TransicaoFases(int value) {
	if (tTransicao>0 && faseConcluida == true) {
		start = false;
		if (tTransicao == 4) {
			if (levelImage == 0) {
				imageBgd = cvLoadImage(nameTemp0_3, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cvLoadImage(nameTemp1_3, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cvLoadImage(nameTemp2_3, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
		}
		if (tTransicao == 3) {
			if (levelImage == 0) {
				imageBgd = cvLoadImage(nameTemp0_2, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cvLoadImage(nameTemp1_2, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cvLoadImage(nameTemp2_2, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
		}
		if (tTransicao == 2) {
			if (levelImage == 0) {
				imageBgd = cvLoadImage(nameTemp0_1, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cvLoadImage(nameTemp1_1, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cvLoadImage(nameTemp2_1, CV_LOAD_IMAGE_COLOR);
				image = NULL;
			}
		}
		tTransicao--;
	}
	if (tTransicao == 0) {
		faseConcluida = false;
		tTransicao = 4;
		levelImage++;
		if (levelImage == 3) {
			sairPrincipal();
		}
		if (levelImage == 0) {
			image = cvLoadImage(name0, CV_LOAD_IMAGE_COLOR);
			imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);
			timePadrao = 30;
			t = timePadrao;

		} else if (levelImage == 1) {
			image = cvLoadImage(name1, CV_LOAD_IMAGE_COLOR);
			imageBgd = cvLoadImage(nameBgd1, CV_LOAD_IMAGE_COLOR);
			timePadrao = 45;
			t = timePadrao;

		} else if (levelImage == 2) {
			image = cvLoadImage(name2, CV_LOAD_IMAGE_COLOR);
			imageBgd = cvLoadImage(nameBgd2, CV_LOAD_IMAGE_COLOR);
			timePadrao = 60;
			t = timePadrao;
		}
	}
	glutTimerFunc(1000, TransicaoFases, 1);
}