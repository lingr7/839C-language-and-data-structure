/*2018年10月10日(星期三)
lingr7
2018年10月20日21:05:25
2018年10月20日 星期六*/
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
				   (screen.pt1.y + screen.pt2.y)/2);
/* addpoint函数：将两个点相加*/
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}
/*结构类型的参数也是通过值传递的*/
/* ptinrect函数：如果点p在矩形r内，则返回1，否则返回0*/
int ptinrect(struct point p, struct rect r){
	return p.x >=r.pt1.x && p.x < r.pt2.x
	    && p.y >=r.pt1.y && p.y < r.pt2.y; 
}
/*返回一个规范形式的矩形的函数*/
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b)) 
/*标准形式，其中pt1坐标小于pt2坐标*/
/*canonrect函数：将矩形坐标规范化*/
struct rect canonrect(struct rect r){
	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r,pt2.y);
	return temp;
} 
/*传递给函数的结构很大，使用指针方式的效率通常比复制整个结构的效率要高*/
struct point *pp;
/*pp为一指向struct point类型对象的指针。*/
struct point origin, *pp;

pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y); /*.的优先级要高于**/
/*结构指针使用频率很高，为了使用方便，c语言提供了另一种简写方式，假定pp是一个指向结构的指针*/
/*p->结构成员*/
printf("origin is (%d,%d)\n", pp->x, pp->y);
/*  
*p->str 读取指针str所指向的对象的值；
*p->str++ 先读取指针str指向的对象的值，然后再将str+1;
(*p->str)++
*p++->str先读取指针str指向的值，然后再将p加1 
*/
char *keyword[NKEYS];
int keycount[NKEYS];

/*结构数组实现方式*/
struct key {
	char *word;
	int count;
}keytab[NKEYS]; 

struct key {
	char *word;
	int count;
}; 
struct key keytab[NKEYS];

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
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0 
} ;/*神奇*/
/*还有更精确地做法，将每一行（即每个结构的初值）都括在花括号内*/
	{"auto", 0},
	{"break", 0},
	{"case", 0},
