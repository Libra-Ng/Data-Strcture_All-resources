LinkedStack Init_LinkedStack()
{
	LinkedStack top = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));  
	                              //栈顶指针变量
	if(top != NULL)
	{
		top->next = NULL;
	}
	return top;
}//Init_LinkedStack

int LinkedStack_Empty(LinkedStack top)
{
	if(top->next == NULL)//如果栈顶的指针域指向空，则栈空
	{
		return 1;
	}
	else
	{
		return 0;
	}
}//LinkedStack_Empty

int Push_LinkedStack(LinkedStack top,elemtype x)
{
	LinkedStackNode * node = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
 
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		node->data = x;
		node->next = top->next;
		top->next = node;
		return 1;
	}
}//Push_LinkedStack

int Pop_LinkedStack(LinkedStack top,elemtype *x)
{
	LinkedStackNode *node;
	if(top->next == NULL)
	{
		return 0;
	}
	else
	{
		node = top->next;
		*x = node->data;
		top->next = node->next;
		free(node);
		return 1;
	}
}//Pop_LinkedStack

int Get_LinkedStack(LinkedStack top,elemtype *x)
{
	if(top->next == NULL)
	{
		return 0;
	}
	else
	{
		*x = top->next->data;
		return 1;
	}
}//Get_LinkedStack






