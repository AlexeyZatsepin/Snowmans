#pragma once
#include <GLUT/glut.h>
#include <string>

class Snowman {
private:
	size_t id;
	size_t hp;
	float x;
	float y;
	float z;
public:
	Snowman() {};
	~Snowman() {};
	void create(int i,int j);
	void move(size_t,size_t);
	void melt() {
		hp--;
	};
	float getX() {
		return x;
	};
	float getY() {
		return y;
	};
	float getZ() {
		return z;

	};
	size_t getHP() {
		return hp;
	};
	size_t getId() {
		return id;
	};
	void draw();
	
};

void renderBitmapString(
        float x,
        float y,
        float z,
        void *font,
        std::string str) {
    glRasterPos3f(x, y, z);
    for (auto c = 0; c != str.size(); c++) {
        glutBitmapCharacter(font, str[c]);
    }
}

inline void Snowman::create(int i,int j)
{
	id = (i + 4) * 8 + (j + 4) + 1;
	hp = 100;
	x = 7.0 *i;
	y = 7.0 *j;
}

inline void Snowman::move(size_t newX, size_t newY)
{
	x = newX;
	y = newY;
}

void Snowman::draw() {
	glPushMatrix();
	glTranslatef(x, 0, y);

	/*char number[10];
	sprintf_s(number, "BOT%d", id);*/

	glColor3f(1.0f, 1.0f, 1.0f);
	// тело снеговика
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);
	// голова снеговика
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);
	// глаза снеговика
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();
	// нос снеговика
	glColor3f(1.0f, 0.5f, 0.5f);
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f, 0.5f, 10, 2);

	std::string name = "BOT" + std::to_string(id);
	std::string helth = std::to_string(hp)+"%";
	//name
	renderBitmapString(0.0f, 0.6f, 0.0f, (void *)GLUT_BITMAP_HELVETICA_12, name);
	renderBitmapString(0.0f, 0.4f, 0.0f, (void *)GLUT_BITMAP_HELVETICA_12, helth);

	glPopMatrix();
}