#include <stdio.h>
/* copy input to output; 1st version */
main()
{
	int c;
	//c = getchar();
	int i = 0;
	while (c = (getchar() != EOF) )
		printf("%d %d\n", c, i++); 
	printf("%d - at EOF\n", c);
}
/*在while判断里，c = 非0值，则满足条件，进入循环，当c赋值为0，则为假，退出循环*/
