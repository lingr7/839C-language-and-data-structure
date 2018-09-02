#include<stdio.h>
#include<stdlib.h> 
int main(){
	int n,i,j,k,l;
	int m,count;
	int a[36][36];
	FILE *fp;
	fp=fopen("D:\\dataIN.txt","r");
	if(fp==NULL){
		printf("Cannot open this file.\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	m=n*n;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			fscanf(fp,"%d",&a[i][j]);
    for(i=0;i<m;i++){
	   for(k=1;k<=m;k++){
	   		count=0;
 			for(j=0;j<m;j++)
 				if(a[i][j]==k) count++;
 			if(count!=1){
 				printf("No\n");return 0;
			 } 
 	   }
 	}	
 	for(i=0;i<m;i++){
	   for(k=1;k<=m;k++){
	   		count=0;
 			for(j=0;j<m;j++)
 				if(a[j][i]==k) count++;
 			if(count!=1){
 				printf("No\n");return 0;
			 } 
 	   }
 	}
 	for(l=0;l<n;l++){
 		for(k=0;k<n;k++){
 		for(int f=1;f<=m;f++){
		 	count=0;
 			for(i=3*k;i<3*k+3;i++)
 				for(j=3*l;j<3*l+3;j++) if(a[i][j]==f) count++;
		 if(count!=1){
		 	printf("No\n");return 0;
		 }
		 }
	}
	}
	printf("Yes\n");
	return 0;
} 









