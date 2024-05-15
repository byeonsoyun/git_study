#include <stdio.h>
#include <string.h>
#define alpha 26

int main(){
	char arr[100];
	scanf("%s", arr);
	
	int i;
	int compare[alpha];
	for(i = 0;i<alpha;i++){
		compare[i] = -1;
	}
	
	for(i = 0;i<strlen(arr);i++){
		char val = 'a';
		int count = 0;
		if (arr[i] >= 'a' && arr[i] <= 'z'){
			while(count<alpha){
				if(arr[i]-val==0&&compare[count]==-1){
					compare[count] = i;
					break;
				}
				count++;
				val = val+1;
			}
		}
	}
	for(i = 0;i<alpha;i++){
		printf("%d ", compare[i]);
	}
}
