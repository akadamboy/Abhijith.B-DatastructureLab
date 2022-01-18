// implement set and its operations using bitstring

// Universal set U = { 1,2,3,4,5,6,7,8,9 }

#include <stdio.h>
int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void input();
void output(int s[]);
void setUnion();
void intersection();
void difference();
void reset();

void main(){
	int choice = 0;
	
	while(choice != 5){
		printf("\n\nEnter your choice : \n1.Input\n2.Union\n3.Intersection\n4.Difference\n5.Exit\nYour choice : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: input();
				  break;
			case 2: setUnion();
				  break;
			case 3: intersection();
				  break;
			case 4: difference();
				  break;
			case 5: printf("\n See you again :)");
				  break;
				  
			default: printf("\nEnter a valid choice!");
		}
	}
}

void input(){
	reset(); // to reset old sets if any
	int size, x;
	printf("\nEnter size of first set (max 9) : ");
	scanf("%d", &size);
	printf("\nEnter elements to first set\n==========================");
	for(int i = 0; i < size; i++){
		printf("\nEnter element %d : ", i + 1);
		scanf("%d", &x);
		a[x-1] = 1;
	}
	
	printf("\nEnter size of second set (max 9) : ");
	scanf("%d", &size);
	printf("\nEnter elements to second set\n==========================");
	for(int i = 0; i < size; i++){
		printf("\nEnter element %d : ", i + 1);
		scanf("%d", &x);
		b[x-1] = 1;
	}
	
}

void output(int s[]){
	printf("\n{ ");
	for(int i = 0; i < 9; i++){
		if(s[i] == 1){
			printf("%d, ", i+1);
		}
	}
	printf(" }");	
}

void setUnion(){
	int uni[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0; i < 9; i++){
		if(a[i] == 1 || b[i] == 1){
			uni[i] = 1;
		}
	}
	printf("\nUnion of set-1 and set-2\n============================\n");
	output(uni);
}

void intersection(){
	int inter[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0; i < 9; i++){
		if(a[i] == 1 && b[i] == 1){
			inter[i] = 1;
		}
	}
	printf("\nIntersection of set-1 and set-2\n============================\n");
	output(inter);	
}

void difference(){
	int diff[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for(int i = 0; i < 9; i++){
		diff[i] = a[i];
		if(a[i] == 1 && b[i] == 1){
			diff[i] = 0;
		}

	}
	printf("\nDiffernce ( set_1 - set_2 )\n============================\n");
	output(diff);
}
 void reset(){
 	// to reset a and b to empty set
 	for(int i = 0; i < 9; i++){
		a[i] = 0;
		b[i] = 0;
	}
 }
