#include <stdio.h>
/*cat函数：连接多个文件，版本1*/
int main(){
	FILE *fp;/*指向结构FILE的指针*/
	void filecopy(FILE *, FILE *);
	
	if(argv == 1) /*如果没有命令行参数，则复制标准输入*/
		filecopy(stdin, stdout);
	else 
		while(--argc > 0)
			if((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1; 
			}else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}
