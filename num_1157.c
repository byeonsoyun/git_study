#include <stdio.h>
#include <string.h>
#include <ctype.h>

char aph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int count[26] = {0x0};

int main() {
    char word[1000000];
    scanf("%s", word);
    
    int i, j;
    for (i = 0; word[i] != '\0'; i++) {
        char c = toupper(word[i]);
        for (j = 0; j < 26; j++) {
            if (aph[j] == c) {
                count[j] += 1;
                break;
            }
        }
    }
    
    int max_index = 0;
    int max_val = count[0];
    for (i = 1; i < 26; i++) {
        if (count[i] > max_val) {
            max_index = i;
            max_val = count[i];
        }
    }
    
    int flag = 0;
    for (i = 0; i < 26; i++) {
        if (i != max_index && count[i] == max_val) {
            flag = 1;
            break;
        }
    }
    
    if (flag) {
        printf("?");
    } else {
        printf("%c", aph[max_index]);
    }
    
    return 0;
}

