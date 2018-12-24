/*keytab.h*/
#define NKEYS ( sizeof keytab / sizeof(struct key))
/*结构初始化*/
/*最好声明为外部变量*/
struct key {
	char *word;
	int count;
} keytab[] ={
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"main", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0,
};/*神奇*/
