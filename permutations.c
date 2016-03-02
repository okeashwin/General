#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *n1, char *n2) {
	char c=*n1;
	*n1=*n2;
	*n2=c;
}

void permute(int start, int end, char *str) {
	if(start>end) {
		return;
	}
	if(start==end) {
		printf("%s\n",str);
		return;
	}
	int i=start;
	for(;i<=end;i++) {
		swap(str+start, str+i);
		permute(start+1, end, str);
		swap(str+i, str+start);
	}
}

int main() {
	char *str="abc";
	char *dest;
	//scanf("%s",str);
	dest=strdup(str);
	permute(0, strlen(dest)-1, dest);
}