#include<unistd.h>
#include<stdio.h>
int main(int argc, char* argv[])
{
    
    encrypt(argv[1],10);

    printf("%s",argv[1]);
    return 0;
}
