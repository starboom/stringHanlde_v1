#include <iostream>
using namespace std;

typedef struct node * nodeptr;

typedef struct node{
	char* word;
	int count;
	nodeptr next;
}node;

#define NHASH 29989
#define MULT  31

nodeptr bin[NHASH];

/*function starts here*/
unsigned int hash(char *p){
	unsigned int h = 0;
	for(p;*p;++p){
		h = MULT * h + *p;
	}
	return h % NHASH;
}
void incword(char* s){
	h = hsah(s);
	nodeptr p = NULL;
	for(p = bin[h];p != NULL;p = p -> next){
		if(strcmp(s,p -> word) == 0){
			p -> count ++;
			return;
		}
	}
	p = malloc(sizeof(nodeptr));
	p -> count = 1;
	p -> word = malloc(strlen(s) + 1);
	strcpy(p -> word,s);
	p -> next = bin[h];
	bin[h] = p;
	return;
}
/*end of function */

int main(int argc, char const *argv[]){

	int i{};
	for(i = 0;i < NHASH;++i){
		bin[i] = NULL;
	}
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