#include "rect.h"
#include <stdlib.h>

int i = 0;
int j = 0;
int assignation_counter = 0;
int compare = 0;
int flag_stop_sorting = -1;


Rect create_rect(float x, float y, int width, int height){
	Rect rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	rect.color = WHITE;
	rect.state = 1;
	return rect;
}

int sort_counter = 0;

void rect_white(Rect rectangles[], int dim){
	for (int i = 0; i < dim; i++)
		rectangles[i].state = 1;
}

void rect_sorted_animation(Rect rectangles[], int dim){

	for (int i = 0; i< 5; i++){
		if (sort_counter<dim)
			rectangles[sort_counter].state = 2;
		else if (sort_counter >= dim){
			rect_white(rectangles,dim);
		}
		sort_counter++;		
	}

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
		if (rect[i].state == 1)
			DrawRectangle(rect[i].x,y,rect[i].width, rect[i].height, WHITE);
		else if (rect[i].state == 0) 
			DrawRectangle(rect[i].x,y,rect[i].width, rect[i].height, RED);
		else
			DrawRectangle(rect[i].x,y,rect[i].width, rect[i].height, GREEN);
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

int size = 1;
int left = 0;
int mid, i, j, k, right;
int current_delay = 0;
int delay_amount = 1;

void rect_merge_sort(Rect rect[], int n, int m) {

        if (size >= n/2) {
                delay_amount = 40;
        } else if (size >= n/4) {
                delay_amount = 35;
        } else if (size >= n/8) {
                delay_amount = 10;
        } else {
                delay_amount = m;
        }
        
        current_delay++;
        if (current_delay < delay_amount) {
                return;
        }
        current_delay = 0;
        
        int *temp = (int *)malloc(n * sizeof(int));
        if (temp == NULL) return;
        
        if (size >= n) {
                free(temp);
                flag_stop_sorting = 0;
                return;
        }
        
        if (left < n) {
                mid = left + size - 1;
                if (mid >= n) mid = n - 1;
                
                right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
                
                i = left;
                j = mid + 1;
                k = 0;
                
                while (i <= mid && j <= right) {
                        if (rect[i].height <= rect[j].height) {
				compare++;
				assignation_counter++;
                                temp[k++] = rect[i++].height;
                        } else {
				assignation_counter++;
                                temp[k++] = rect[j++].height;
                        }
                }
                
                while (i <= mid) {
			temp[k++] = rect[i++].height;
			compare++;
			assignation_counter++;
		}
                while (j <= right) {

			temp[k++] = rect[j++].height;
			compare++;
			assignation_counter++;
		}
                
                for (i = 0; i < k; i++) {
			assignation_counter++;
                        rect[left + i].height = temp[i];
                }
                
                left += 2 * size;
        } else {
                left = 0;
                size *= 2;
        }
        
        free(temp);
}
