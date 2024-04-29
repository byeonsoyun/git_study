#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	double sum = 0.0;
	int sub_num;
	scanf("%d", &sub_num);
	int* score_arr = (int*)malloc(sub_num * sizeof(int));
	int i;
	for (i = 0; i < sub_num; i++) {
		scanf("%d", &score_arr[i]);
	}
	int max = score_arr[0];
	for (i = 1; i < sub_num; i++) {
		if (max < score_arr[i]) {
			max = score_arr[i];
		}
	}
	for (i = 0; i < sub_num; i++) {
		double dscore;
		dscore = ((double)score_arr[i] / max) * 100;
		sum += dscore;
	}
	printf("%lf", sum/sub_num);
	free(score_arr);
	return 0;
}