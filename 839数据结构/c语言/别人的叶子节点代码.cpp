BTree * linkLeafNode(BTree *T) 
{ 

	BTree * list = (BTree*)malloc(sizeof(BTree)); 

	BTree * p = list; 
	int top = -1; 
	int linking = 0; 
	BTree * s[1000]; 
	while (T != NULL || top != -1) 
	{ 
		while (T != NULL) 
		{ 
		//cout << T->data << endl; 
			if(T->lchild==NULL && T->rchild==NULL){ 
				printf("linking %d\n",T->data); 
				p->lchild = T; 
				p = p->lchild; 
				linking = 1; 
			} 
			s[++top] = T; /*Ñ¹Èë¶ÑÕ»*/
			if(linking == 1){ 
				T = NULL; 
				linking = 0; 
			} else { 
				T = T->lchild; 
			} 
		} 
		if (top != -1) 
		{ 
		// gettop and pop 
			T = s[top--]; /*³öÕ»*/
			T = T->rchild; 
		} 
	} 
	return list; 
} 
