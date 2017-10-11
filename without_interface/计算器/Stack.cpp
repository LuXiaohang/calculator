
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int  InitializeEmptyStack(Stack &st)
{  
	st.t=-1;//表示当前栈为空栈,栈中没有数据元素
	return OK;
}

int Push (Stack &S, DataType x) 
{
   if (S.t>=(MAXNUM-1)) 
		{
			printf("Overflow!\n");
			return STACK_OVERFLOW;
		}
	S.t++;
    S.s[S.t]=x;
	return OK;
}

int Pop(Stack &S)
{
  if (S.t == -1)
	{ 
		printf("Underflow!\n");
		return STACK_UNDERFLOW;
	}	
	S.t--;
  return OK;
}

DataType Top(Stack S)
{
	DataType e;
	e=S.s[S.t];
  return e;
}

int IsEmptyStack(Stack S)
{
	if (S.t == -1) 
		return 1; 
	else
  	return 0;
}



