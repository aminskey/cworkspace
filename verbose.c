#include<stdio.h>
#include<curl/curl.h>

int main(int argc, char *argv[]){
  CURL *curl=curl_easy_init();

  if(curl){
    curl_easy_setopt(curl,CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl,CURLOPT_VERBOSE, 1L);

    curl_easy_perform(curl);
    
    curl_easy_cleanup(curl);
  }
  return 0;
}
