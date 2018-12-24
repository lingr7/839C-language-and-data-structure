#include<stdio.h>
#include<ctype.h>
int main(){
	char jiao[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	char id[18];
	int i,wei[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int  count=0,f=1; 
	for(i=0;i<18;i++){
		scanf("%c",&id[i]);
		if(!isdigit(id[i])){
		 	if(i!=17||id[i]!='X')
		 		f=0;break;
		}
		if(i!=17) count+=(id[i]-'0')*wei[i];
	}
	if(!f||(id[17]!=jiao[count%11])) printf("Wrong ID\n");
	else	printf("Right ID\n");	
	return 0;	
}
