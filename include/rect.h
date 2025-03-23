#include <raylib.h>

typedef struct Rect {
	
	float x;
	float y;
	int height;
	int width;
	Color color;

	int state;
}Rect; 

Rect create_rect(float x, float y, int width, int height);

void draw_rect(Rect rect[], int dim);

void rect_swap(Rect *r1, Rect *r2);
int rect_min_index(Rect rect[], int dim);

void fill_rectangles(Rect rectangles[], int a[] ,int dim);

void rect_bubble_sort(Rect rect[], int dim, int frame_step);
void rect_selection_sort(Rect rect[], int dim, int frame_step);
void rect_better_bubble(Rect rect[], int dim, int frame_step);
void rect_insertion_sort(Rect rect[], int dim, int frame_step);
void rect_merge_sort(Rect rect[], int size, int frame_step);

void rect_sorted_animation(Rect rect[], int size);
