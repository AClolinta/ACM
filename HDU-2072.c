#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#define MAX 130
#define MAX_Long 1026
int main() {
	char s [MAX], str[MAX];
	char words [MAX_Long][MAX];
	while (gets(s)) {
		memset(words, 0, sizeof(words));    //�������
        int m = 0,k=0;
        if ( !strcmp(s,"#")) 
            break;
		for (int i = 0; i < strlen(s); i++) {
			int j = 0;
			int flag = 0;
            while(*(s + i) >= 'a' && *(s + i) <= 'z') {
                flag=1;     //�жϸ�λ���Ƿ�Ϊ�ַ�
                *(str+(j++))=*(s+(i++)) ;
                *(str+j)='\0' ; //�ضϵ���
            } 
            if (flag) {
                for (k = 0; k < m; k++)
                    if ( !strcmp(str, words[k]) ) //�ж���ͬ���ʣ���������words�ڶ���
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