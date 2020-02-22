#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

int main(int argc, char *argv[]){

  CURL *curl=curl_easy_init();
  CURLcode res;

  if(argc <= 0){
    perror("[[Protocol://]website] [output file]");
    exit(0);
  }
  
  FILE *fp=fopen(argv[2],"r+");
  
  if(curl){
    curl_easy_setopt(curl,CURLOPT_URL,argv[1]);
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,(void *)fp);

    res=curl_easy_perform(curl);
    if(res==CURLE_OK){
      printf("\x1b[42mRequest is Allowed\x1b[0m\n");
    }else{
      printf("\x1b[41mRequest Denied!!\x1b[0m\n");
    }
    
    curl_easy_cleanup(curl);
  }

  fclose(fp);
  return 0;
}
