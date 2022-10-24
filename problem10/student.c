#include <stdio.h>
#include <search.h>
#include <string.h>
#include <stdlib.h>

struct node {
char *name;
int midterm;
int final;
};

int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level)
{
	if(order == preorder || order == leaf)
	{
		printf("이름 = %-20s, 중간점수 = %d, 기말점수 = %d\n",(*(struct node **)nodeptr)->name, (*(struct node **)nodeptr)->midterm, (*(struct node **)nodeptr)->final);
	}
}

int main()
{
	int num;
	printf("학생 인원을 입력하세요: ");
	scanf("%d", &num);	
	struct node *root = NULL; //루트노드
	char *nameptr = (char *)malloc(num* sizeof(struct node));
	struct node *nodeptr = (struct node *)malloc(num* sizeof(struct node));
	struct node **ret;
	int i=0;
	while (scanf("%s%d%d", nameptr, &nodeptr->midterm, &nodeptr->final) != EOF && i++ < num) {
		nodeptr->name = nameptr;
		
		/* 트리에 넣기 */
		ret = (struct node **) tsearch((void *) nodeptr, (void **) &root, compare);
		printf("\"%s\" 님이 ", (*ret)->name);
		if (*ret == nodeptr)
			printf("트리에 추가되었습니다.\n");
		else
			printf("트리에 이미 존재합니다.\n");
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
	}	
	twalk((void *) root, print_node);
}

