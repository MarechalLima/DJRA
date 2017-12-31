#include "Kcode.h"
/*OpenGL initialization*/

void sairPrincipal() {
	fgets(numberTesteArray, 10, arqNumberTeste);
	numberTeste = _atoi64(numberTesteArray);
	resultadoTestes = "\nID: " + std::to_string(numberTeste) + " | Tempo: " + std::to_string(tempoAtivoSegundos) +
		" segundos | ";
	if (levelImage == 0) {
		resultadoTestes += "Fase 1: No | Fase 2: No | Fase 3: No";
	}
	else if (levelImage == 1) {
		resultadoTestes += "Fase 1: Sim | Fase 2: No | Fase 3: No";
	}
	else if (levelImage == 2) {
		resultadoTestes += "Fase 1: Sim | Fase 2: Sim | Fase 3: No";
	}
	else if (levelImage == 3) {
		resultadoTestes += "Fase 1: Sim | Fase 2: Sim | Fase 3: Sim";
	}

	//Gravando dados em novo arquivo
	fputs(resultadoTestes.c_str(), arqResultadoTestes);
	fclose(arqResultadoTestes);

	//Mudando ID
	numberTeste += 1;
	fclose(arqNumberTeste);

	FILE *arqNumberTeste = fopen("resultados//NumberTeste.txt", "wt");
	_itoa(numberTeste, numberTesteArray, 10);
	fputs(numberTesteArray, arqNumberTeste);
	fclose(arqNumberTeste);
	_fcloseall();
	exit(0);
}

void Tempo(int value){
	if(t>0 && start==true && pause==false){
		t--;
	}
	_itoa(t,ti,10);
	glutTimerFunc(1000,Tempo,1);
}

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

void tutorial(int value) {
	
	if (tut == 5) {
		image = cvLoadImage(name0, CV_LOAD_IMAGE_COLOR);
		imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);
		pause = false;
		tut++;
	}
	if(tut==4){
		image = cvLoadImage(nameTagain, CV_LOAD_IMAGE_COLOR);
		imageBgd = cvLoadImage(nameTnone, CV_LOAD_IMAGE_COLOR);
		againTime = true;
	}else if(start==false && tut==0 && levelImage==0){
		imageBgd = cvLoadImage(nameT1, CV_LOAD_IMAGE_COLOR);
		image= NULL;
		tut++;
	}
	else if(start==false && tut==1 && levelImage==0){
		imageBgd = cvLoadImage(nameT2, CV_LOAD_IMAGE_COLOR);
		image= NULL;
		tut++;
	}
	else if(start==false && tut==2 && levelImage==0){
		imageBgd = cvLoadImage(nameT3, CV_LOAD_IMAGE_COLOR);
		image= NULL;
		tut++;
	}
	else if(start==false && tut==3 && levelImage==0){
		imageBgd = cvLoadImage(nameT4, CV_LOAD_IMAGE_COLOR);
		tut++;
		image= NULL;
		pause=true;
	}

	
	glutTimerFunc(5000, tutorial, 1);
}

void TempoAtivo (int value) {
	tempoAtivoSegundos = tempoAtivoSegundos+1;
	glutTimerFunc(1000, TempoAtivo, 1);
}

void sairEsc(unsigned char key, int x, int y) {
	if (key == 27) {
		sairPrincipal();
	}
	if (key == 32 && tut < 4) {

		tut = 5;
		start = false;
		againTime = false;
		hover = false;
	}

}

void profundidadeColisao() {
	if (zRHand < zRHandDefault && zRHand != 0 && faseConcluida == false && pause==false) {
		if (levelImage == 0 && hover == false) {
			imageBgd = cvLoadImage(nameBgd2D0, CV_LOAD_IMAGE_COLOR);
			if (coinStatus == false) {
				PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
			}
			hover = true;
		} else if (levelImage == 1 && hover == false) {
			imageBgd = cvLoadImage(nameBgd2D1, CV_LOAD_IMAGE_COLOR);
			if (coinStatus == false) {
				PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
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
				PlaySound((LPCSTR)musica, NULL, SND_FILENAME | SND_ASYNC);
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
				PlaySound((LPCSTR)winMusic, NULL, SND_FILENAME | SND_ASYNC);
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
					PlaySound((LPCSTR)coinMusic, NULL, SND_FILENAME | SND_ASYNC);
					coinStatus = false;
					vidaExtra = true;
				}
			} else if (againTime == true && pause == true) {
				if (teste.val[0] == 0 && teste.val[1] == 0 && teste.val[2] == 0) {
					if (zRHand < zRHandDefault && zRHand != 0 && hover == false) {
						imageBgd = cvLoadImage(nameTno, CV_LOAD_IMAGE_COLOR);
						PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
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
						PlaySound((LPCSTR)buttonMusic, NULL, SND_FILENAME | SND_ASYNC);
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

/*Draw the opengl/glut scene*/
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	//profundidadeColisao();
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

int main(int argc, char* argv[]) {
	arqRead = fgetc(arq);
	if (arqRead == 'r') {
		nodeUser = NUI_SKELETON_POSITION_HAND_RIGHT;
	} else if (arqRead == 'l') {
		nodeUser = NUI_SKELETON_POSITION_HAND_LEFT;
	} else {
		printf("Arquivo vazio!\n");
	}


	HRESULT hr;

	image = cvLoadImage(name0, CV_LOAD_IMAGE_COLOR);
	imageBgd = cvLoadImage(nameBgd0, CV_LOAD_IMAGE_COLOR);

	if (image == NULL) {
		printf("Imagem não carregada!\n");
	}

	initKinect();

	printf("kinect init");

	//Background generate
	glGenTextures(1, &textureId);
	//Background generate
	if (!init(argc, argv))
		return 1;
	printf("\n OpenGL/Glut init");
	

	setCamera();
	glOrtho(0, WIDTH, HEIGHT, 0, 50, -50);

	
	// Main loop
	glutMainLoop();
	fclose(arq);
	return 0;
	NuiShutdown();

}
