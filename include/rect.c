#include "rect.h"
#include <raylib.h>

int i = 0;
int j = 0;
int assignation_counter = 0;
int compare = 0;

int flag_stop_sorting = 0;

Rect create_rect(float x, float y, int width, int height){
	Rect rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return rect;
}

void fill_rectangles(Rect rectangles[], int a[] ,int dim){
	
	const int width = 2;
	const int startXPos = 50;

	for(int i = 0; i < dim; i++){
		rectangles[i] = create_rect(startXPos +(i + 1) * width, 750 - rectangles[i].height , width,  a[i]);
	}
}

void draw_rect(Rect rect[], int dim){

	for (int i = 0; i < dim; i++){
		int y = 750 - rect[i].height;
		DrawRectangle(rect[i].x,y,rect[i].width, rect[i].height, WHITE);
	}

}

void rect_swap(Rect *r1, Rect *r2){
	
	int temp = r1->height;
	r1->height = r2->height;
	r2->height = temp;
}

void rect_bubble_sort(Rect rect[], int dim, int frame_step) {
	int prev_compare = compare; 

	for (int k = 0; k < frame_step;k++){
		if (i < dim - 1) {

			for (j = 0;j < dim - i - 1;j++) {
				if (rect[j].height > rect[j + 1].height) {
					assignation_counter+=3;
					compare++;
					rect_swap(&rect[j], &rect[j + 1]);
				}
			}


		} else {
			i++;
			}
		}

	
	if (compare == prev_compare) {flag_stop_sorting = 1;};
}



int rect_min_index(Rect *rect, int dim){
	int min_rect = 0;

	for (int i = 1; i < dim; i++){
		if (rect[i].height < rect[min_rect].height){
			compare++;
			min_rect = i;	
		}
	}

	return min_rect;

}

void rect_selection_sort(Rect *rect, int dim, int frame_step){

	for (int k = 0; k < frame_step; k++){
		if ( i < dim){
			compare++;
			assignation_counter+=3;
			int min = rect_min_index(rect + i, dim - i) + i;
			rect_swap(&rect[i], &rect[min]);
		}else {
			i = dim;
		} 
		i++;
	}

	
	if (i >= dim) flag_stop_sorting = 1;

}

void insert_rect_sorted(Rect rectangles[],int dim ,Rect x){
	
	for ( j = dim; j > 0 && x.height < rectangles[j-1].height;j--){
		compare++;
		assignation_counter++;
		rectangles[j].height = rectangles[j - 1].height;	
	}
	
	assignation_counter++;
	rectangles[j].height = x.height;
}

void rect_insertion_sort(Rect *rect, int dim, int frame_step){
		
	for (int k = 0; k < frame_step;k++){
		if (i < dim - 1){
			i++;
			insert_rect_sorted(rect,i,rect[i]);
		}else {
			i = dim;
		}

	}

	if (i >= dim - 1) flag_stop_sorting = 1;
}
