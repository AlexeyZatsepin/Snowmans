#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "Snowman.h"
#include "Controller.h"
#include "Context.h"

Context properties;
// переменные для вычисления количества кадров в секунду
//int frame;
//long time, timebase;
//char s[50]; 
int h, w;// высота и ширина окна

void changeSize(int ww, int hh) {
	// предотвращение деления на ноль
	h = hh;
	w = ww;
	if (h == 0)
		h = 1;
	double ratio = w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
}


//void restorePerspectiveProjection() {
//	glMatrixMode(GL_PROJECTION);
//	//восстановить предыдущую матрицу проекции
//	glPopMatrix();
//	//вернуться в режим модели
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void setOrthographicProjection() {
//	//выбрать режим проекции
//	glMatrixMode(GL_PROJECTION);
//	//Сохраняем предыдущую матрицу, которая содерж
//	//параметры перспективной проекции
//	glPushMatrix();
//	//обнуляем матрицу
//	glLoadIdentity();
//	//устанавливаем 2D ортогональную проекцию
//	gluOrtho2D(0, w, h, 0);
//	//выбираем режим обзора модели
//	glMatrixMode(GL_MODELVIEW);
//}

void moveSnowman() {
	Snowman& man = properties.getSnowmanById(36);
	float x = man.getX();
	float y = man.getY();
	//man.move(x++, y++);
}

void renderScene(void) {
	glClearColor(0, 0.5f , 1.0f, 1.0);
	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);
	//очистить буфер цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// обнулить трансформацию
	glLoadIdentity();
	// установить камеру
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);
	// нарисуем "землю"
	glColor3f(red, green, blue);

	glBegin(GL_QUADS);// полигон с коондинатами
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	// Нарисуем 64 снеговика

	/*for (int i = -4; i < 4; i++)
		for (int j = -4; j < 4; j++)
		{
			drawSnowMan(i,j);
		}
	*/
	moveSnowman();
	properties.drawAll();

	//frame++;

	//time = glutGet(GLUT_ELAPSED_TIME);
	//if (time - timebase > 1000) {
	//	sprintf_s(s, "FPS:%4.2f",
	//		frame*1000.0 / (time - timebase));
	//	timebase = time;
	//	frame = 0;
	//}
	////Код для отображения строки (кадров в секунду) с растровых шрифтов
	//setOrthographicProjection();
	//glPushMatrix();
	//glLoadIdentity();
	//renderBitmapString(5, 30, 0, GLUT_BITMAP_HELVETICA_18, s);
	//glPopMatrix();

	//restorePerspectiveProjection();
	
	glutSwapBuffers();
}


void init() {
	properties.initFigures();
	// регистрация вызовов
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(pressKey);
	glutKeyboardFunc(processNormalKeys);

	// Новые функции для регистрации
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	createPopupMenus();
}


int main(int argc, char **argv) {

	// инициализация GLUT и создание окна
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Snowmans attack");

	init();

	// главный цикл
	glutMainLoop();

	return 1;
}