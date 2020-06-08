#include<time.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/sysmacros.h>


int main(int argc, char *argv[]){

	int fd, rnum;
	char ch;

	struct stat statbuf;

	if(stat(argv[1],&statbuf)==-1){
		perror("Something Went wrong!");
		exit(EXIT_FAILURE);
	}
	printf("ID of containing device [%lx, %x]\n",(long) major(statbuf.st_dev), minor(statbuf.st_dev));
	printf("Size of file: %ld\n",(long)statbuf.st_size);
	printf("Inode number: %ld\nMode: %lo\n",(long) statbuf.st_ino,(unsigned long)statbuf.st_mode);
	printf("Ownership: User ID=%ld Group ID=%ld\n",(long) statbuf.st_uid, (long) statbuf.st_gid);
	printf("Number of blocks allocated: %ld\n",(unsigned long)statbuf.st_blocks);
	printf("Time of last acces: %s\nTime of last modification: %s\nTime of last status change: %s",ctime(&statbuf.st_atime),ctime(&statbuf.st_mtime),ctime(&statbuf.st_ctime));

	return 0;

}
