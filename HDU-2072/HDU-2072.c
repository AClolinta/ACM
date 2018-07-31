#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#define MAX 130
#define MAX_Long 1026
int main() {
	char s [MAX], str[MAX];
	char words [MAX_Long][MAX];
	while (gets(s)) {
		memset(words, 0, sizeof(words));    //清空数组
        int m = 0,k=0;
        if ( !strcmp(s,"#")) 
            break;
		for (int i = 0; i < strlen(s); i++) {
			int j = 0;
			int flag = 0;
            while(*(s + i) >= 'a' && *(s + i) <= 'z') {
                flag=1;     //判断该位置是否为字符
                *(str+(j++))=*(s+(i++)) ;
                *(str+j)='\0' ; //截断单词
            } 
            if (flag) {
                for (k = 0; k < m; k++)
                    if ( !strcmp(str, words[k]) ) //判断相同单词，存在则不向words内读入
                        break;
                if (k == m) {
                    strcpy(words[m++], str);
                }
            }
		}
        printf("%d\n",m);
	}
	return 0;
}