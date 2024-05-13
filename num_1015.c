#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*���� 1015: ũ�Ⱑ N�� �����迭 A�� �־��� ��
 0~N - 1������ ���� ���Ե� ����P�� ������ ũ�� N�� �迭�� �񳻸������� �Ǵ� ���� Pã��
 >>A�� ���ҵ��� ���ĵǵ��� �ϴ� �ε������� ������ �迭 P�� ��Ÿ����*/


//max_heap: A�� root->leaf���� ū ���� ������� ����� �Լ�
void max_heap(int AA[], int N);
//sort_heap: max_heap�Լ��� ����� ���� ������ ũ������� �����ϴ� �Լ�
void sort_heap(int AA[], int N);



int main() {
	//N: �迭 ũ��, i, j: �ݺ����� ���� ����, index: A�� ������ �ε����� �����ϴ� ����
	int N, i, j, index;
	//�迭�� ũ�⸦ �Է¹ް� �迭A, P, AA�� �����迭�Ҵ�(A�� ������ �뵵)
	scanf("%d", &N);
	int* A = (int*)calloc(N, sizeof(int));
	int* P = (int*)calloc(N, sizeof(int));
	int *AA = (int*)calloc(N, sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	memcpy(AA, A, sizeof(int)*N);

	//max_heap�Լ��� AA�� �������Ѵ�
	max_heap(AA, N);
	//���ĵ� AA�� �ùٸ� ������ �����Ѵ�
	sort_heap(AA, N);
	
	for (i = 0; i < N; i++) {
		//���� index�� A�� ���� �ε����� �ش��ϴ� ���� �����ϰ�
		index = A[i];
		//������� ���ĵ� AA���� �ش� ���Ұ� �����ϴ� �ε����� ã�´�
		for (j = 0; j < N; j++) {
			if (AA[j] == index) {
				//�ش� �ε����� ã����(j) �迭P�� ���ҷ� �߰��ϰ� �ش� ���� NULL�� ���´�(�ߺ�����)
				P[i] = j;
				AA[j] = NULL;
				//���ϴ� ������� ������Ƿ� �ٽ� ù �ݺ������� ���ư���
				break;
			}
		}
	}
	//P�� ����� ���Ҹ� ���� ����Ѵ�
	for (i = 0; i < N; i++) {
		printf("%d ", P[i]);
	}
	//�����޸��Ҵ��� �迭���� ��� free�Ͽ� �޸� ������ �����Ѵ�
	free(AA);
	free(A);
	free(P);
	return 0;
}

//�迭 AA�� ũ�� N�� �Ű������� �޴´�
void max_heap(int AA[], int N) {
	//i: �ݺ��� ����, temp; �� �ٲٱ�� ����, child, root: ���� ���� �θ���� �ڽĳ�带 ��Ÿ���� ����
	int i, temp, child, root;
	//Ʈ�� ����ó�� �����ϱ� ���� �ݺ�, child�� 1���� �����ϴ� ������ root�� 0���� �����ϱ� ����
	for (i = 1; i < N; i++) {
		//�ڽ� ���� i�� �ʱ�ȭ
		child = i;
		//�� Ʈ���� ��Ʈ <�ڽ�/�ڽ� �������� �� �θ� ���� ū ���� �ǵ��� �ϴ� �ݺ���
		while (child !=0) {
			root = (child - 1) / 2;
			//�θ�<�ڽ��̸� �� ���� ������ �ٲ۴�
			if (AA[root] < AA[child]) {
				temp = AA[root];
				AA[root] = AA[child];
				AA[child] = temp;
			}
			//�θ�>�ڽ��̸� break�Ѵ�
			else {
				break;
			}
			//child ��带 root�� �ʱ�ȭ�Ͽ� �ݺ����� ���� ����ؼ� ���ĵǵ��� �Ѵ�
			child = root;
		}

	}
}

//�Ű������� AA, ũ�� N�� �Է¹޴´�
void sort_heap(int AA[], int N) {
	//�������� ���� ���Ӱ� ����
	int i, temp, child, root;
	//���� AA�� ������������ �����Ǿ� �����Ƿ� ù ��° ���� ������ ���� �ٲٵ��� �ݺ����� �����Ѵ�
	for (i = N - 1; i >= 0; i--) {
		temp = AA[0];
		AA[0] = AA[i];
		AA[i] = temp;
		root = 0;
		child = 1;
		//�ڽ� ��尡 i���� �۴ٴ� ����: i���� ���ķδ� �̹� ������ �Ϸ�� �����̤ӱ� ����
		while (child < i) {
			//Ʈ���� ��Ʈ �κк��� �����Ѵ�
			child = root*2 + 1;
			//���� ��峢�� �� ū ���� �θ���� �񱳵ǵ��� �Ѵ�
			if (child < i - 1 && AA[child] < AA[child + 1]) {
				child++;
			}
			//�ڽĳ�尡 �θ��庸�� ū ��� ���� �ٲ۴�
			if (child < i && AA[root] < AA[child]) {
				temp = AA[root];
				AA[root] = AA[child];
				AA[child] = temp;
			}
			//root�� child������ �ʱ�ȭ���� ������ �Ʒ������ε� ��� ����ǵ��� �Ѵ�
			root = child;
		}
	}
}