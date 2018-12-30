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
				imageBgd = cv::imread(nameTemp0_3, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cv::imread(nameTemp1_3, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cv::imread(nameTemp2_3, cv::IMREAD_COLOR);
				image = NULL;
			}
		}
		if (tTransicao == 3) {
			if (levelImage == 0) {
				imageBgd = cv::imread(nameTemp0_2, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cv::imread(nameTemp1_2, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cv::imread(nameTemp2_2, cv::IMREAD_COLOR);
				image = NULL;
			}
		}
		if (tTransicao == 2) {
			if (levelImage == 0) {
				imageBgd = cv::imread(nameTemp0_1, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 1) {
				imageBgd = cv::imread(nameTemp1_1, cv::IMREAD_COLOR);
				image = NULL;
			}
			if (levelImage == 2) {
				imageBgd = cv::imread(nameTemp2_1, cv::IMREAD_COLOR);
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
			image = cv::imread(name0, cv::IMREAD_COLOR);
			imageBgd = cv::imread(nameBgd0, cv::IMREAD_COLOR);
			timePadrao = 30;
			t = timePadrao;

		} else if (levelImage == 1) {
			image = cv::imread(name1, cv::IMREAD_COLOR);
			imageBgd = cv::imread(nameBgd1, cv::IMREAD_COLOR);
			timePadrao = 45;
			t = timePadrao;

		} else if (levelImage == 2) {
			image = cv::imread(name2, cv::IMREAD_COLOR);
			imageBgd = cv::imread(nameBgd2, cv::IMREAD_COLOR);
			timePadrao = 60;
			t = timePadrao;
		}
	}
	glutTimerFunc(1000, TransicaoFases, 1);
}