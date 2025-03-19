#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

#include "../include/rect.h"
#include "../include/vector.h"
#include "../include/button.h"

#define ARR_LEN 650
#define WIDTH 1400
#define HEIGHT 900


int ms = 1;
int sorted = 0;
double time_taken = 0; 
clock_t clock_start,clock_end;

extern int i;
extern int j;
extern int g_type;
extern int compare;
extern int flag_stop_sorting;
extern int assignation_counter;

void draw_algo_info();
void handle_algo(char ** str_current_algo, Rect rectangles[], int ms);
void check_collision_generation(Rect rect[], int arr[], Button * button);


int main(){

	const int FPS = 30;
	const int RECT_BASE = 750;
	

	srandom(time(NULL));	
	
	int array[ARR_LEN];
	random_array(array, ARR_LEN, 700);

	Rect rectangles[ARR_LEN];
	fill_rectangles(rectangles,array,ARR_LEN);

	char window_name[] = "Algorithm Visualization";
	InitWindow(WIDTH, HEIGHT, window_name);
	SetTargetFPS(FPS);
	
	int clock_flag = 0;
	int len_buttons = 5;

	Button buttons[len_buttons];
	fill_button_array(buttons);

	
	char *str_current_algo = "Algorithm: None";

	Button generate_button =create_button(WIDTH-1200 +( 150 * 5), HEIGHT - 100, 100, 40, bubble);

	while(!WindowShouldClose()){

		BeginDrawing();
		
		ClearBackground(BLACK);

		draw_algo_info();
		draw_rect(rectangles,ARR_LEN);
		draw_buttons(buttons,len_buttons);	
		draw_buttons_utils(rectangles, generate_button);

		DrawText(str_current_algo, 800, 10, 20, GREEN);

		EndDrawing();
			
		if (g_type == -1){

			if (sorted == 0){
				button_collision(buttons, len_buttons);
			}

			check_collision_generation(rectangles,array,&generate_button);
			
			//Speed 
			if (IsKeyPressed(KEY_UP)){
				ms++;
			}else if (IsKeyPressed(KEY_DOWN)){
				if (ms > 1) 
					ms--;
			}

		}

		handle_algo(&str_current_algo, rectangles, ms);

	}

	CloseWindow();
	return 0;
}

void handle_algo(char **str_current_algo, Rect rectangles[], int ms){

		if (g_type != -1){
			// time should start here
		}

		if (g_type == bubble){ 	
			rect_bubble_sort(rectangles, ARR_LEN, ms);
			*str_current_algo = "Algorithm: Bubble Sort";
		}
		else if (g_type == selection){
			rect_selection_sort(rectangles, ARR_LEN, ms);
			*str_current_algo = "Algorithm: Selection Sort";
		}else if (g_type == insertion){
			rect_insertion_sort(rectangles,ARR_LEN, ms);
			*str_current_algo = "Algorithm: Insertion Sort";
		}else if (g_type == merge){
			*str_current_algo = "Algorithm: Merge Sort";
		}else if (g_type == quick){
			*str_current_algo = "Algorithm: Quick Sort";
		}else {
			*str_current_algo = "Algorithm: None";
		}
		
		if (flag_stop_sorting == 1){

			*str_current_algo = "Algorithm: None Palle";
			flag_stop_sorting = 0;
			i = 0;
			j = 0;
			g_type = -1;
			sorted = 1;

			// time should end here
		}		

}

/*
 *
 * When its sorted it should become green for a moment
 *
 */

void check_collision_generation(Rect rect[], int arr[], Button * button){
	float x = GetMousePosition().x;
	float y = GetMousePosition().y;

	if (button->x < x && x < button->x + button->width  && button->y < y && button->y + button->width > y){

		button->color = GREEN; 
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			random_array(arr, ARR_LEN, 700);
			fill_rectangles(rect, arr, ARR_LEN);
			compare = 0;
			assignation_counter = 0;
			sorted = 0;
		} 
	}else {
		button->color = WHITE; 
	}

}

void draw_algo_info(){

	int y = 10;
	DrawFPS(10, y);
	
	char str[20];
	sprintf(str,"\t Assignation : %d",assignation_counter);
	DrawText(str,100,y,20,GREEN);

	char str1[20];
	sprintf(str1,"\t Compare : %d",compare);
	DrawText(str1,350,y,20,GREEN );

	char str2[20];
	sprintf(str2,"\t Elements : %d", ARR_LEN);
	DrawText(str2,550,y,20,GREEN);
	
	char str3[20];
	sprintf(str3,"\t Time : %.2f", time_taken);
	DrawText(str3,1060,y,20,GREEN);
	
	char str4[20];
	sprintf(str4,"\t Speed: %d", ms);
	DrawText(str4,1250,y,20,GREEN);


	DrawText("Speed: Arrow UP/DOWN",WIDTH-1200 +( 150 * 6), HEIGHT - 100 + 10 ,20,WHITE);
}

