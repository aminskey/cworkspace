#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dir;

	int i=0;

	if(argc<0){
		printf("usage : ls dir_name\n");
		return 0;
	}
	if((dp=opendir(argv[1])) == NULL)
		perror("CANNOT OPEN");
	while((dir=readdir(dp))!=NULL){
		printf("%s\n",dir->d_name);
		
	}

	closedir(dp);
	return 0;
}
