#include <raylib.h>

enum sort {

	bubble,
	selection,
	insertion,
	merge,
	quick,
	
};

typedef struct Button{

	float x;
	float y;
	int width;
	int height;
	enum sort sort_type;
	Color color;
}Button;

Button create_button(float x, float y, int width, int height, enum sort sort_type);
enum sort button_collision(Button buttons[], int dim);
void fill_button_array(Button buttons[]);
void draw_buttons(Button buttons[], int dim);
void draw_buttons_utils(void *rect, Button button);
