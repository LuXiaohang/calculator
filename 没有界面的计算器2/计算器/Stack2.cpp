
#include <stdio.h>
#include <stdlib.h>

#include "stack2.h"


int  InitializeEmptyStack2(Stack2 &st)
{  
	st.t=-1;//表示当前栈为空栈,栈中没有数据元素
	return OK;
}

int Push2 (Stack2 &op, DataType2 x) 
{
   if (op.t>=(MAXNUM-1)) 
		{
			printf("Overflow!\n");
			return STACK_OVERFLOW;
		}
	op.t++;
    op.s[op.t]=x;
	return OK;
}

int Pop2(Stack2 &op)
{
  if (op.t == -1)
	{ 
		printf("Underflow!\n");
		return STACK_UNDERFLOW;
	}	
	op.t--;
  return OK;
}

DataType2 Top2(Stack2 S)
{
	DataType2 e;
	e=S.s[S.t];
  return e;
}

int IsEmptyStack2(Stack2 S)
{
	if (S.t == -1) 
		return 1; 
	else
  	return 0;
}



