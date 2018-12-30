//
// Created by nicholas on 31/12/17.
//

#include "tutorial.hpp"
#include "background_render.hpp"
char nameT1[] = "imags//tutorial//1.png";
char nameT2[] = "imags//tutorial//2.png";
char nameT3[] = "imags//tutorial//3.png";
char nameT4[] = "imags//tutorial//4.png";

char nameTnone[] = "imags//tutorial//again//againNone.png";
char nameTno[] = "imags//tutorial//again//againNo.png";
char nameTyes[] = "imags//tutorial//again//againYes.png";
char nameTagain[] = "imags//tutorial//again//again.png";
bool againTime = false;

int tut = 0;
bool hover = false;
bool pause = true;

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