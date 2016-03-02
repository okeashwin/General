#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node {
	int val;
	struct node *next;
}node;

node *top=NULL;
void push(int data) {
	node *new_el=malloc(sizeof(node));
	new_el->val=data;
	new_el->next=NULL;
	if(!top) {
		top=new_el;
	}
	else {
		new_el->next=top;
		new_el=top;
	}
}
int pop() {

}

int isEmpty() {

}
int isPalindrome(char *str) {
	char *start=str;
	char *end=str;
	while(*end) {
		end++;
	}
	end--;
	while(start<=end) {
		if(*start!=*end) {
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}
int missingNumber(int arr[], int size) {
	unsigned int xor_org=0, xor_act=0;
	int i;
	for(i=1;i<=size+1;i++) {
		xor_org=xor_org^i;
	}
	for(i=0;i<size;i++) {
		xor_act=xor_act^arr[i];
	}
	return xor_act^xor_org;
}

int findMissing(int arr[], int size) {
	//int min=arr[0];
	int i=1;
	for(;i<size;i++) {
		if(arr[i+1]!=arr[i]+1) {
			return arr[i]+1;
		}
	}
	return arr[size-1]+1;
}

int findMissingBinaryHelper(int arr[], int offset, int start, int end) {
	if(start>end) {
		return start+offset;
	}
	int middle=start+(end-start)/2;
	if(middle < arr[middle]-offset) {
		return findMissingBinaryHelper(arr, offset, start, middle-1);	
	}
	else if(middle==arr[middle]-offset) {
		return findMissingBinaryHelper(arr, offset, middle+1, end);
	}
}

int findMissingBinary(int arr[], int size) {
	int offset=arr[0];
	return findMissingBinaryHelper(arr, offset, 0, size-1);
}

int compareIps(char *ip1, char *ip2) {
	char *save_ptr1, *save_ptr2;
	char *tok1, *tok2;
	printf("Hi\n");
	tok1=strtok_r(ip1,".",&save_ptr1);
	tok2=strtok_r(ip2,".",&save_ptr2);
	while(tok1 && tok2) {
		tok1=strtok_r(NULL,".", &save_ptr1);
		tok2=strtok_r(NULL,".", &save_ptr2);
		if(atoi(tok1)>atoi(tok2)) {
			return 1;
		}
		else if(atoi(tok2)>atoi(tok1)) {
			return -1;
		} 
	}

	return 0;
}
void printReverse(char *s) {
	if(*s=='\0') {
		return;
	}
	printReverse(s+1);
	printf("%c", *s);
}
int main() {
	char *str="LiniL";
	printf("%d\n",isPalindrome(str));
	char *str1="LiiL";
	printf("%d\n",isPalindrome(str1));

	// int arr[10]={2,3,4,6,7,8,9,10,11,12};
	// printf("%d\n", missingNumber(arr, 10));
	int arr[2]={1,2};

	char *ip1=strdup("1.1.1.12");
	char *ip2=strdup("1.1.1.2");
	printf("%d\n", compareIps(ip1,ip2));
	char *s="Linux";
	printReverse(s);
	printf("\n");

	printf("%d\n", findMissing(arr,2));
	printf("%d\n", findMissingBinary(arr,2));
}