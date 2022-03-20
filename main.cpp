#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main() {
	int width = 800;
	int height = 450;

	int circle_x = (width / 2);
	int circle_y = (height / 2);
	const int circle_radius = 32;

	int axe_x = 200;
	int axe_y = 0;
	const int axe_size = 64;

	InitWindow(width, height, "Look ma, no hands!");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(PURPLE);

		DrawCircle(circle_x, circle_y, circle_radius, BLUE);
		DrawRectangle(axe_x, axe_y, axe_size, axe_size, RED);

		axe_y = (axe_y + 8);

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
