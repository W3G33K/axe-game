#include <stdio.h>
#include "raylib.h"

/**
 * External Libraries must be included with double quotes ("file.h") where as Standard Libraries must be included with angle brackets (<file>).
 **/

int main(int argc, char* argv[]) {
	int width = 350,
		height = 200; // Variable Group Initialization & Declaration.
	int center_x{ width / 2 }; // Braced Initialization.
	int center_y{ height / 2 }; // Braced Initialization.
	int center_z{}; // Braced Initialization (Declared & Initialized as 0).


	printf("(x=%d, y=%d, z=%d)\n", center_x, center_y, center_z);
	InitWindow(width, height, "Look ma, no hands!");
	return 0;
}
