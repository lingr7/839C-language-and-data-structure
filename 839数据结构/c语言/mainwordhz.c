#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup(char *);
struct tnode {			/*树的节点*/
	char *word;			/*指向单词的指针*/
	int count;			/*单词出现的次数*/
	struct tnode *left;	/*左子节点*/
	struct tnode *right;/*右子节点*/
};

/* 单词频率的统计 */
int main(int argc, char *argv[]) {
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) 
			root = addtree(root, word);/*递归的*/
	treeprint(root); 
	return 0;
}
/* getword函数：从输入中读取下一个单词或字符*/
int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);/**/ 
            break;
        }
    *w = '\0';
    return word[0];
} 


/* addtree函数:在p的位置或p的下方增加一个w结点*/
struct tnode *addtree(struct tnode *p, char *w){
	int cond;
	
	if (p == NULL){   /* 该单词是一个新单词 */
		p = talloc(); /* 创建一个新节点 */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL; 
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/*新单词与节点中的单词匹配 */
	else if(cond < 0)	/*如果小于该节点中的单词，则进入左子树 */ 
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;	
}
/* treeprint函数:按序打印树p*/
void treeprint(struct tnode *p){
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloc函：创建一个tnode*/
struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}
/* 复制s到某个位置*/
char *strdup(char *s){
	char *p;
	
	p = (char *) malloc(strlen(s)+1);/* 执行加1操作是为了在结尾加上字符 \0*/ 
	if (p != NULL)
		strcpy(p, s);
	return p;
}
