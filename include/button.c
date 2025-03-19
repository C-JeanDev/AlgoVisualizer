#include "button.h"
#include "raylib.h"
#include "rect.h"

#define WIDTH 1400
#define HEIGHT 900

Button create_button(float x, float y, int width, int height, enum sort sort_type){
	Button button;
	
	button.x = x;
	button.y = y;
	button.width = width;
	button.height = height;
	button.sort_type = sort_type;
	button.color = WHITE;
	return button;
}

void fill_button_array(Button buttons[]){
	for (int i = 0; i < 5; i++){
		buttons[i] = create_button(WIDTH-1200 +( 150 * i), HEIGHT - 100, 100, 40, bubble);
	}
	buttons[1].sort_type = selection;
	buttons[2].sort_type = insertion;
	buttons[3].sort_type = merge;
	buttons[4].sort_type = quick;
}

void draw_buttons_utils(void * rect ,Button  button){
	const int font_size = 18;
	DrawRectangleLines(button.x, button.y, button.width, button.height, button.color);
	DrawText("Generate",button.x + 7 ,button.y,font_size, WHITE);
	DrawText(" Array",button.x + 16 ,button.y + font_size,font_size, WHITE);
}

enum sort g_type = -1;

enum sort button_collision(Button buttons[], int dim){

	float x = GetMousePosition().x;
	float y = GetMousePosition().y;
	
	enum sort t = -1;

	for(int i = 0; i < dim; i++){
		if (buttons[i].x < x && x < buttons[i].x + buttons[i].width  && buttons[i].y < y && buttons[i].y + buttons[i].width > y){

			buttons[i].color = GREEN; 
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
				g_type = buttons[i].sort_type;
			} 
		}else {
			buttons[i].color = WHITE; 
		}
	}
	
	return -1;
}

void draw_buttons(Button buttons[], int dim){

	char names[5][10] = {"Bubble", "Selection", "Insertion", "Merge", "Quick"};
	const int font_size = 20;
	for (int i = 0; i < dim; i++){
		DrawRectangleLines(buttons[i].x, buttons[i].y, buttons[i].width, buttons[i].height, buttons[i].color);
		DrawText(names[i],buttons[i].x + 5 ,buttons[i].y + font_size,font_size, WHITE);
	}
	
}
