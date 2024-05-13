#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*문제 1015: 크기가 N인 정수배열 A가 주어질 때
 0~N - 1까지의 값이 포함된 수열P를 적용한 크기 N인 배열이 비내림차순이 되는 수열 P찾기
 >>A의 원소들이 정렬되도록 하는 인덱스들의 집합을 배열 P로 나타낸다*/


//max_heap: A를 root->leaf까지 큰 원소 순서대로 만드는 함수
void max_heap(int AA[], int N);
//sort_heap: max_heap함수의 결과를 토대로 원소의 크기순으로 정렬하는 함수
void sort_heap(int AA[], int N);



int main() {
	//N: 배열 크기, i, j: 반복문에 쓰일 변수, index: A의 원소의 인덱스를 저장하는 변수
	int N, i, j, index;
	//배열의 크기를 입력받고 배열A, P, AA를 동적배열할당(A를 정렬할 용도)
	scanf("%d", &N);
	int* A = (int*)calloc(N, sizeof(int));
	int* P = (int*)calloc(N, sizeof(int));
	int *AA = (int*)calloc(N, sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	memcpy(AA, A, sizeof(int)*N);

	//max_heap함수로 AA를 힙정렬한다
	max_heap(AA, N);
	//정렬된 AA를 올바른 순서로 정렬한다
	sort_heap(AA, N);
	
	for (i = 0; i < N; i++) {
		//변수 index에 A의 원소 인덱스에 해당하는 값을 저장하고
		index = A[i];
		//순서대로 정렬된 AA에서 해당 원소가 등장하는 인덱스를 찾는다
		for (j = 0; j < N; j++) {
			if (AA[j] == index) {
				//해당 인덱스를 찾으면(j) 배열P의 원소로 추가하고 해당 값을 NULL로 놓는다(중복제어)
				P[i] = j;
				AA[j] = NULL;
				//원하는 결과값을 얻었으므로 다시 첫 반복문으로 돌아간다
				break;
			}
		}
	}
	//P에 저장된 원소를 전부 출력한다
	for (i = 0; i < N; i++) {
		printf("%d ", P[i]);
	}
	//동적메모리할당한 배열들을 모두 free하여 메모리 누수를 방지한다
	free(AA);
	free(A);
	free(P);
	return 0;
}

//배열 AA와 크기 N을 매개변수로 받는다
void max_heap(int AA[], int N) {
	//i: 반복문 변수, temp; 값 바꾸기용 변수, child, root: 각각 윗쪽 부모노드와 자식노드를 나타내는 변수
	int i, temp, child, root;
	//트리 구조처럼 정렬하기 위해 반복, child가 1부터 시작하는 이유는 root를 0부터 시작하기 때문
	for (i = 1; i < N; i++) {
		//자식 노드는 i로 초기화
		child = i;
		//각 트리의 루트 <자식/자식 구조에서 각 부모가 가장 큰 값이 되도록 하는 반복문
		while (child !=0) {
			root = (child - 1) / 2;
			//부모<자식이면 이 둘의 순서를 바꾼다
			if (AA[root] < AA[child]) {
				temp = AA[root];
				AA[root] = AA[child];
				AA[child] = temp;
			}
			//부모>자식이면 break한다
			else {
				break;
			}
			//child 노드를 root로 초기화하여 반복문을 통해 계속해서 정렬되도록 한다
			child = root;
		}

	}
}

//매개변수로 AA, 크기 N을 입력받는다
void sort_heap(int AA[], int N) {
	//변수들은 위의 쓰임과 같다
	int i, temp, child, root;
	//현재 AA는 내림차순으로 정리되어 있으므로 첫 번째 값과 마지막 값을 바꾸도록 반복문을 실행한다
	for (i = N - 1; i >= 0; i--) {
		temp = AA[0];
		AA[0] = AA[i];
		AA[i] = temp;
		root = 0;
		child = 1;
		//자식 노드가 i보다 작다는 조건: i번쨰 이후로는 이미 정렬이 완료된 상태이ㅣ기 때문
		while (child < i) {
			//트리의 루트 부분부터 정렬한다
			child = root*2 + 1;
			//형제 노드끼리 더 큰 값이 부모노드와 비교되도록 한다
			if (child < i - 1 && AA[child] < AA[child + 1]) {
				child++;
			}
			//자식노드가 부모노드보다 큰 경우 값을 바꾼다
			if (child < i && AA[root] < AA[child]) {
				temp = AA[root];
				AA[root] = AA[child];
				AA[child] = temp;
			}
			//root를 child값으로 초기화시켜 정렬이 아래쪽으로도 계속 진행되도록 한다
			root = child;
		}
	}
}