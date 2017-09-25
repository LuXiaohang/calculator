

#include <stdio.h>
#include <stdlib.h>
#include "Lstack.h"
int  InitializeEmptyStack4(Stack4 &S)
{  
	S.t=-1;//表示当前栈为空栈,栈中没有数据元素
	return OK;
}

int Push4(Stack4 &S, DataType4 x) 
{
   if (S.t>=(MAXNUM-1)) 
		{
			return STACK_OVERFLOW;
		}
	S.t++;
    S.s[S.t]=x;
	return OK;
}

int Pop4(Stack4 &S)
{
  if (S.t == -1)
	{ 
		return STACK_UNDERFLOW;
	}	
	S.t--;
  return OK;
}

DataType4 Top4(Stack4 S)
{
	DataType4 e;
	e=S.s[S.t];
  return e;
}

int IsEmptyStack4(Stack4 S)
{
	if (S.t == -1) 
		return 1; 
	else
  	return 0;
}
void StackToStack4(Stack4 &S1,Stack4 &S2)
{
	int a=0;
	while(!IsEmptyStack4(S1))
	{
		 Push4 (S2,Top4(S1)) ;
		 Pop4(S1);
	}
}





