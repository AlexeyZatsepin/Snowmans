#pragma once
#include "Snowman.h"

class Context {
private:
	Snowman * figures;
public:
	Context() : figures(new Snowman[64]) {};
	~Context() {
		delete[] figures;
	};
	void initFigures() {
		for (int i = -4; i < 4; i++)
			for (int j = -4; j < 4; j++)
			{
				figures[(i + 4) * 8 + (j + 4)].create(i, j);
			}
	};
	void drawAll() {
		for (int i = 0; i <= 64; i++)
		{
			figures[i].draw();
		}
	};
	Snowman& getSnowmanById(size_t id) {
		for (int i = 0; i <= 64; i++) {
			if (figures[i].getId() == id) {
				return figures[i];
			}
		}
	}

	
};
