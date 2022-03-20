#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main(int argc, char** argv) {
	int width = 350;
	int height = 200;

	int centerX = (width / 2);
	int centerY = (height / 2);

	InitWindow(width, height, "Look ma, no hands!");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(PURPLE);

		DrawCircle(centerX, centerY, 32, BLUE);

		EndDrawing();
	}

	return 0;
}
