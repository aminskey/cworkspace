#include<stdio.h>

int main(void){
	char a[]="hello hello";
	char b[sizeof((char *)a)];

	for(int i=0;i<sizeof((char *)a);i++){
		switch(a[i]){
			case 'a'-'z':
				b[i]=(unsigned int)a[i];
				break;
			case '1'-'9':
				b[i]=a[i];
				break;
			default:
				break;
		}
	}

	printf("%s",b);
	getchar();
	return 0;
}
