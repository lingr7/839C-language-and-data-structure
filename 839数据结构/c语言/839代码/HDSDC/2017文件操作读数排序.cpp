#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 4
typedef   struct da{
	float  x1,y1,x2,y2;
} da;
int cmp(const void *a,const void *b){
	 da *aa=(da*)a;
	 da *bb=(da*)b;
	 float ds1=aa->x1*aa->x1+aa->y1*aa->y1;
	 float ds2=bb->x1*bb->x1+bb->y1*bb->y1;
	 float s1=(aa->x1-aa->x2)*(aa->y1-aa->y2);
	 float s2=(bb->x1-bb->x2)*(bb->y1-bb->y2); 
	 if(fabs(s1)>fabs(s2))   return 1;
	 else if(fabs(s1)<fabs(s2)) return -1;
		  else if(ds1>ds2) return 1;
			   else return -1;
}
int main(){
	FILE *fp;
	float x1,y1,x2,y2,s1,s2;
	da data[N];
	da dataa[N];
	int i,j;
	if((fp=fopen("D:\\lw.dat","r"))==NULL){
		printf("Cannot open this file\n");
		exit(1);
	}
	for(i=0;i<N;i++){
		fscanf(fp,"%f%f%f%f",&data[i].x1,&data[i].y1,
		&data[i].x2,&data[i].y2);
	} 
	for(i=0,j=0;i<N;i++){
		if(data[i].x1!=data[i].x2&&data[i].y1!=data[i].y2)
			data[j++]=data[i];
	} 
	qsort(dataa,j,sizeof(da),cmp);
	for(i=0;i<j;i++)
		printf("%.2f %.2f %.2f %.2f\n",dataa[i].x1,dataa[i].y1,
		dataa[i].x2,dataa[i].y2);
 	fclose(fp);
	return 0;
}
