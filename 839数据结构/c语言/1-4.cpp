#include <stdio.h>
/*当celsius=0, 20, ,300时，分别打印华氏温度与摄氏温度对照表  */
main()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0; /* 温度表下限 */
	upper = 300; /* 温度表上限 */
	step = 20; /*步长*/
	celsius = lower;
	while (celsius <= upper) {
		fahr = 9 * celsius / 5 +32;
		printf("%d\t%d\n", celsius, fahr);
		celsius = celsius + step;
	}
}
