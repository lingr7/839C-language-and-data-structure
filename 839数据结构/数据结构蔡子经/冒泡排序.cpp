void bubble_sort(int a[], int n){
	int i , j;
	int t;
	n--;
	while(n > 0){
		j = 0;
		for(i = 0; i < n; i++){/*一趟冒泡*/
			if(a[i] > a[i+1]){
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				j = i;
			}
		}/*j代表a[0],a[1]...到a[j]还没有确定次序，j+1项及后续，都已经是升序了*/
		n = j;
	}
}
