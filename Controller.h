#pragma once
// угол поворота камеры
float angle = 0.0;
// координаты вектора направления движения камеры
float lx = 0.0f, lz = -1.0f;
// XZ позиция камеры
float x = 0.0f, z = 5.0f;
//Ключи статуса камеры. Переменные инициализируются нулевыми значениями
//когда клавиши не нажаты
float deltaAngle = 0.0f;
float deltaMove = 0;

void computePos(float deltaMove)
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle)
{
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
	case GLUT_KEY_LEFT:
		deltaAngle = -0.01f;
		break;
	case GLUT_KEY_RIGHT:
		deltaAngle = 0.01f;
		break;
	case GLUT_KEY_UP:
		deltaMove = 0.5f;
		break;
	case GLUT_KEY_DOWN:
		deltaMove = -0.5f;
		break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
		deltaAngle = 0.0f;
		break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN:
		deltaMove = 0;
		break;
	}
}
void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		deltaMove = 0.5f;
		break;
	case 'a':
	case 'A':
		deltaAngle = -0.01f;
		break;
	case 's':
	case 'S':
		deltaMove = -0.5f;
		break;
	case 'd':
	case 'D':
		deltaAngle = 0.01f;
		break;
	case 27:
		glutDestroyMenu(mainMenu);
		glutDestroyMenu(fillMenu);
		glutDestroyMenu(colorMenu);
		exit(0);
	}
}

