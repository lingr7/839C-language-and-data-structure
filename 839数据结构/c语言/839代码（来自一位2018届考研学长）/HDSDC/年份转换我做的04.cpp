#include<stdio.h>
int  leap(int n){
	if(n<1900)printf("Wrong!\n"); 
	if(n%4==0&&n%100!=0||n%400==0)
	return 1;
	else return 0;
}
long date_convert(long ymd){
	int y=ymd/10000;
	int m=ymd%10000/100;
	int d=ymd%100;
	int i,j;int day=0;int date;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
	for(i=0;i<m-1;i++){
	day+=month[i];	
	}
	if(m>=2&&leap(y)) day++;
	day+=d;
	date=y*1000+day;
	return date;
}
int main(){
	int long year;long date;
	printf("Please input the year:\n");
	scanf("%d",&year);
	date=date_convert(year);
	printf("%d  可以转化为: %ld\n\n",year,date);
	return 0;
}
 
