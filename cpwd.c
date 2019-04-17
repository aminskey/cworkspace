#include<stdio.h>
#include<unistd.h>


int main(void){
	char pwd[1024];
	
	getwd(pwd);
	printf("%s\n",pwd);

	return 0;
}
