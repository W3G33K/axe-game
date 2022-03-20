#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main() {
	int width = 350;
	int height = 200;

	int circle_x = (width / 2);
	int circle_y = (height / 2);
	const int circle_radius = 32;

	InitWindow(width, height, "Look ma, no hands!");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(PURPLE);

		DrawCircle(circle_x, circle_y, circle_radius, BLUE);
		if (IsKeyDown(KEY_A) && circle_x > (0 + circle_radius)) {
			circle_x = (circle_x - 8);
		}

		if (IsKeyDown(KEY_D) && circle_x < (width - circle_radius)) {
			circle_x = (circle_x + 8);
		}

		EndDrawing();
	}

	return 0;
}
