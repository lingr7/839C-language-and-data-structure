int compare(const  void *a,const  void *b}{
	return strcmp((char*)a,(char *b));
}
void *bsearch(void *key,void *base,size_t num,size_t width,
int (*compare)(const void *elem1,const void *elem2)){
	int result;
	size_t low=0,high=num,mid;
	while(low<high){
		mid=low+(high-low)/2;
		result=compare(key,base+mid*width);
		if(result<0) high=mid
		else if(result>0)  low=mid+1; 
		else return (void*)base+width*mid;
	}
	return NULL;
}
