#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j);
int min_index(int a[], int dim);
void insert_sorted(int a[], int *dim, int x);

void input_array(int a[], int dim){

	for(int i = 0;i < dim; i++){
		scanf("%d", &a[i]);
	}

}

void output_array(int a[], int dim){

	for(int i = 0;i < dim; i++){
		printf(" %d ", a[i]);
	}

}

void random_array(int a[], int dim, int max_value){

	
	for (int i = 0;i < dim; i++){
		int num = random() % (max_value - 1) + 1;
		a[i] =  num;
	}

}

void selection_sort(int a[], int dim){

	for(int i = 0; i < dim; i++){
		int min = min_index(a+i,dim - i)+ i;
		swap(a+i, a+min);
	}

}

void bubble_sort(int a[], int dim){
	
	for(int i = 1; i < dim; i++){
		for (int j = 0;j < dim - i; j++){
			if (a[j] > a[j+1]){
				swap(a + j, a + j + 1);
			}
		}
	}

}

void adaptive_bubble_sort(int a[], int dim){
	int sorted = 0;	

	for(int i = 1; i < dim && !sorted; i++){
		sorted = 1;
		for (int j = 0;j < dim - i; j++){
			if (a[j] > a[j + 1]){
				swap(a + j, a + j + 1);
				sorted = 0;
			}
		}
	}

}

void insertion_sort(int a[], int dim){
	
	for (int i = 1; i < dim;){
		insert_sorted(a, &i, a[i]);
	}

}

int find_element(int a[], int dim, int x){
	
	for (int i = 0; i < dim; i++){
		if (a[i] == x)
			return 1;
	}		

	return 0;
}

void swap(int *i, int *j){

	int temp = *i;
	*i = *j;
	*j = temp;

}

int min_index(int a[], int dim){

	int min = 0;
	
	for(int i = 1; i < dim; i++){
		if (a[i] < a[min]){
			min = i;
		}	
	}

	return min;

}

void insert_sorted(int a[], int *dim, int x){
	
	int i; 

	for (i = *dim; i > 0 && x < a[i-1] ;i--){
		a[i] = a[i-1]; 
	}

	a[i] = x;
	(*dim)++;
}
