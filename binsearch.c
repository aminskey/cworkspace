#include<string.h>
#include<stdio.h>

int binsearch(int x, int v[], int n){

	int low, high, mid;

	low=0;
	high = n - 1;
	while(low <= high){
		mid = (low+high)/2;
		if(x<v[mid])
			high= mid - 1;
		else if(x > v[mid])
			low = mid +1;
		else
			return mid;
	}
}

int main(void){
	int str[]={1,2,24};
	printf("%d",binsearch(1,str,3));
	return 0;
}
