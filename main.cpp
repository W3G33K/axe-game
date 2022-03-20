#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main() {
	const int width = 800;
	const int height = 450;

	int circle_x = (width / 2);
	int circle_y = (height / 2);
	const int circle_radius = 20;

	int axe_direction = 10;
	int axe_x = 200;
	int axe_y = 0;
	const int axe_size = 50;

	int axe_x_bb_left{}, axe_x_bb_right{}, axe_y_bb_top{}, axe_y_bb_bottom{},
		circle_x_bb_left{}, circle_x_bb_right{}, circle_y_bb_top{}, circle_y_bb_bottom{};

	InitWindow(width, height, "Axe");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(PURPLE);

		circle_x_bb_left = (circle_x - circle_radius);
		circle_x_bb_right = (circle_x + circle_radius);
		circle_y_bb_top = (circle_y - circle_radius);
		circle_y_bb_bottom = (circle_y + circle_radius);

		axe_x_bb_left = (axe_x);
		axe_x_bb_right = (axe_x + axe_size);
		axe_y_bb_top = (axe_y);
		axe_y_bb_bottom = (axe_y + axe_size);

		if ((axe_y_bb_bottom >= circle_y_bb_top) && (axe_y_bb_top <= circle_y_bb_bottom) &&
			(axe_x_bb_left <= circle_x_bb_right) && (axe_x_bb_right >= circle_x_bb_left)) {
			DrawText("Game Over!", ((width / 2) - 58), (height / 2), 24, WHITE);
		} else {
			DrawText("@", ((width / 2) - 8), (height / 2), 24, WHITE);
			DrawCircle(circle_x, circle_y, circle_radius, BLUE);
			DrawRectangle(axe_x, axe_y, axe_size, axe_size, RED);

			axe_y = (axe_y + axe_direction);
			if ((axe_y <= 0) || ((axe_y + axe_size) >= height)) {
				axe_direction = -axe_direction;
			}
			
			if (IsKeyDown(KEY_A) && (circle_x - circle_radius) > 0) {
				circle_x = (circle_x - 10);
			}

			if (IsKeyDown(KEY_D) && (circle_x + circle_radius) < width) {
				circle_x = (circle_x + 10);
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
