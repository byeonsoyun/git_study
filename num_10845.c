#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue_t {
    int *arr;
    int front, rear, size, cap;
} queue_t;

queue_t *create_queue(int n) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->arr = malloc(n * sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->cap = n;
    return queue;
}

void push(queue_t *queue, int X) {
    if (queue->size != queue->cap) {
        queue->arr[queue->rear] = X;
        queue->rear = (queue->rear + 1) % queue->cap;
        queue->size++;
    }
}

void pop(queue_t *queue) {
    if (queue->size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", queue->arr[queue->front]);
    queue->front = (queue->front + 1) % queue->cap;
    queue->size--;
}

void size(queue_t *queue) {
    printf("%d\n", queue->size);
}

void empty(queue_t *queue) {
    if (queue->size == 0) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
}

void front(queue_t *queue) {
    if (queue->size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", queue->arr[queue->front]);
    }
}

void back(queue_t *queue) {
    if (queue->size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", queue->arr[(queue->rear - 1 + queue->cap) % queue->cap]);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    queue_t *queue = create_queue(N);
    char input[20];

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);

        char *token = strtok(input, " ");
        if (strcmp(token, "push") == 0) {
            int val;
            token = strtok(NULL, " ");
            sscanf(token, "%d", &val);
            push(queue, val);
        } else if (strcmp(token, "pop\n") == 0) {
            pop(queue);
        } else if (strcmp(token, "size\n") == 0) {
            size(queue);
        } else if (strcmp(token, "empty\n") == 0) {
            empty(queue);
        } else if (strcmp(token, "front\n") == 0) {
            front(queue);
        } else if (strcmp(token, "back\n") == 0) {
            back(queue);
        }
    }

    free(queue->arr);
    free(queue);

    return 0;
}


