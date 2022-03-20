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

	int circle_x_bb_left = (circle_x - circle_radius);
	int circle_x_bb_right = (circle_x + circle_radius);
	int circle_y_bb_top = (circle_y - circle_radius);
	int circle_y_bb_bottom = (circle_y + circle_radius);

	int axe_direction = 10;
	int axe_x = 200;
	int axe_y = 0;
	const int axe_size = 64;

	int axe_x_bb_left = (axe_x);
	int axe_x_bb_right = (axe_x + axe_size);
	int axe_y_bb_top = (axe_y);
	int axe_y_bb_bottom = (axe_y + axe_size);

	bool has_collided = (
		(axe_y_bb_bottom >= circle_y_bb_top) &&
		(axe_y_bb_top <= circle_y_bb_bottom) &&
		(axe_x_bb_left <= circle_x_bb_right) &&
		(axe_x_bb_right >= circle_x_bb_left)
	);

	InitWindow(width, height, "Look ma, no hands!");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(PURPLE);

		if (has_collided) {
			DrawText("Game Over!", ((width / 2) - 58), (height / 2), 24, WHITE);
		} else {
			circle_x_bb_left = (circle_x - circle_radius);
			circle_x_bb_right = (circle_x + circle_radius);
			circle_y_bb_top = (circle_y - circle_radius);
			circle_y_bb_bottom = (circle_y + circle_radius);

			axe_x_bb_left = (axe_x);
			axe_x_bb_right = (axe_x + axe_size);
			axe_y_bb_top = (axe_y);
			axe_y_bb_bottom = (axe_y + axe_size);

			has_collided = (
				(axe_y_bb_bottom >= circle_y_bb_top) &&
				(axe_y_bb_top <= circle_y_bb_bottom) &&
				(axe_x_bb_left <= circle_x_bb_right) &&
				(axe_x_bb_right >= circle_x_bb_left)
			);

			DrawCircle(circle_x, circle_y, circle_radius, BLUE);
			DrawRectangle(axe_x, axe_y, axe_size, axe_size, RED);

			axe_y = (axe_y + axe_direction);
			if ((axe_y <= 0) || ((axe_y + axe_size) >= height)) {
				axe_direction = -axe_direction;
			}

			if (IsKeyDown(KEY_A) && circle_x >= (0 + circle_radius)) {
				circle_x = (circle_x - 8);
			}

			if (IsKeyDown(KEY_D) && circle_x <= (width - circle_radius)) {
				circle_x = (circle_x + 8);
			}
		}

		EndDrawing();
	}

	return 0;
}
