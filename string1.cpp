#include <iostream>
extern "C"{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
}

using namespace std;
//在github上修改。
typedef struct node * nodeptr;

typedef struct node{
	char* word;
	int count;
	nodeptr next;
}node;

#define NHASH 12
#define MULT  13

nodeptr bin[NHASH];
/*function starts here*/
unsigned int myhash(char *p){
	unsigned int h = 0;
	for(;*p != '\0';++p){
		h = MULT * h + *p;
	}
	return h % NHASH;
}
void incword(char* s){
	unsigned char h = myhash(s);
	nodeptr p = NULL;
	for(p = bin[h];p != NULL;p = p -> next){
		if(strcmp(s,p -> word) == 0){
			p -> count ++;
			return;
		}
	}
	p = (nodeptr)malloc(sizeof(nodeptr));
	p -> count = 1;
	p -> word = (char*)malloc(strlen(s) + 1);
	strcpy(p -> word,s);
	p -> next = bin[h];
	bin[h] = p;
	return;
}
/*end of function */

int main(int argc, char const *argv[]){

	int i{};
	nodeptr p = NULL;
	for(i = 0;i < NHASH;++i){
		bin[i] = NULL;
	}
	char buf[1024] = {0};
	
	while(scanf("%s",buf) != EOF)
		incword(buf);
	for(i = 0;i < NHASH;++i){
		for(p = bin[i];p != NULL;p = p -> next){
			cout << p -> word \
			 << " " \
			 << p -> count \
			 << endl;
		}
	}

	return 0;
}
