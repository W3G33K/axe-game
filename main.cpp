#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main(int argc, char** argv) {
	int width = 350;
	int height = 200;

	InitWindow(width, height, "Look ma, no hands!");
	while (true) {
		BeginDrawing();
		ClearBackground(PURPLE);
		EndDrawing();
	}

	return 0;
}
