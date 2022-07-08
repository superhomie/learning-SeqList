/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
	int* tmp=(int*)malloc(10000*sizeof(int));
	returnSize=tmp;
	int a=left,b=0,i=0;
	for(i=0; a<=right; a++) {
		if(a%10!=0) {
			int x,y,z,p;
			if(a<10) {
				returnSize[i++]=a;
				b++;
			} else if(a<100) {
				x=a%10,y=(a/10)%10;
				if(x*y!=0&&(a%x==0)&&(a%y==0)) {
					returnSize[i++]=a;
					b++;
				}
			} else if(a<1000) {
				x=a%10,y=(a/10)%10,z=(a/100)%10;
				if(x*y*z!=0&&(a%x==0)&&(a%y==0)&&a%z==0) {
					returnSize[i++]=a;
					b++;
				}
			} else if(a<10000) {
				x=a%10,y=(a/10)%10,z=(a/100)%10,p=(a/1000)%10;
				if(x*y*z*p!=0&&(a%x==0)&&(a%y==0)&&a%z==0&&a%p==0) {
					returnSize[i++]=a;
					b++;
				}
			}
		}
	}


	printf("[");
	for(i=0; i<b; i++) {
		printf("%d",returnSize[i]);
		if((i+1)<b)
			printf(",");
	}
	printf("]");
	return returnSize;

}

int main() {
	int left=1,right=22;
	int* p;
	selfDividingNumbers(89,123,p);

	return 0;	

}