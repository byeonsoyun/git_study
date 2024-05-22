#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_t {
    int *arr;
    int size, cap;
} stack_t;

stack_t *create_stack(int n){
	stack_t *stack = malloc(sizeof(stack_t));
	stack->arr = malloc(n*sizeof(int));
	stack->size = 0;
	stack->cap = n;
	return stack;
}


void
push(stack_t*stack, int X){
	if(stack->size!=stack->cap){
		stack->arr[stack->size] = X;
		stack->size ++;
	}
}


void
pop(stack_t*stack){
	if(stack->size==0){
		printf("-1\n");
		return;
	}
	
	printf("%d\n", stack->arr[stack->size-1]);
	stack->size --;
}

void 
size(stack_t*stack) {
    printf("%d\n", stack->size);
}

void 
empty(stack_t*stack) {
    if (stack->size == 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void
top(stack_t*stack){
	if(stack->size==0){
		printf("-1\n");
		return;
	}
	
	printf("%d\n", stack->arr[stack->size-1]);
}

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	
	stack_t* stack = create_stack(N);
	char input[20];
	
	for(int i = 0;i<N;i++){
		fgets(input, sizeof(input), stdin);
		
		char *token = strtok(input, " ");
		if(strcmp(token, "push")==0){
			int val;
            token = strtok(NULL, " ");
            sscanf(token, "%d", &val);
            push(stack, val);
		}
		else if (strcmp(token, "pop\n") == 0) {
            pop(stack);
        } 
		else if (strcmp(token, "size\n") == 0) {
            size(stack);
        } 
		else if (strcmp(token, "empty\n") == 0) {
            empty(stack);
        }
        else if(strcmp(token, "top\n")==0){
        	top(stack);
		}
	}
	
	free(stack->arr);
	free(stack);
	return 0;
}

