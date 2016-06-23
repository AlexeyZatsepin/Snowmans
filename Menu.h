#pragma once
#include <GLUT/glut.h>

#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4

#define FILL	1
#define LINE	2
// идентификаторы меню
int mainMenu, fillMenu, colorMenu;
// цвет земли
float red = 0.9f, blue = 0.9f, green = 0.9f;
// размер снеговика
float scale = 1.0f;
// статус меню
int menuFlag = 0;


void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE)
		menuFlag = 1;
	else
		menuFlag = 0;
}

void processMainMenuEvents(int option) {

	//ничего здесь не делаем
	//все действия для подменю
}

void processFillMenuEvents(int option) {
	switch (option) {
	case FILL: glPolygonMode(GL_FRONT, GL_FILL); break;
	case LINE: glPolygonMode(GL_FRONT, GL_LINE); break;
	}
}

void processColorMenuEvents(int option) {

	switch (option) {
	case RED:
		red = 0.4f;
		green = 0.0f;
		blue = 0.0f; break;
	case GREEN:
		red = 0.0f;
		green = 0.79f;
		blue = 0.34f; break;
	case BLUE:
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f; break;
	case YELLOW:
		red = 0.93f;
		green = 0.93f;
		blue = 0; break;
	}
}

void createPopupMenus() {
	fillMenu = glutCreateMenu(processFillMenuEvents);
	glutAddMenuEntry("Fill", FILL);
	glutAddMenuEntry("Line", LINE);
	colorMenu = glutCreateMenu(processColorMenuEvents);
	glutAddMenuEntry("Red",    RED);
	glutAddMenuEntry("Blue",   BLUE);
	glutAddMenuEntry("Green",  GREEN);
	glutAddMenuEntry("Yellow", YELLOW);
	mainMenu = glutCreateMenu(processMainMenuEvents);
	glutAddSubMenu("Mode", fillMenu);
	glutAddSubMenu("Color", colorMenu);

	// прикрепить меню к правой кнопке
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//статус активности меню
	glutMenuStatusFunc(processMenuStatus);
}