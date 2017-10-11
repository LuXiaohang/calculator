

#include <stdio.h>
#include <stdlib.h>
#include "Fstack.h"
int  InitializeEmptyStack3(Stack3 &S)
{  
	S.t=-1;//表示当前栈为空栈,栈中没有数据元素
	return OK;
}

int Push3 (Stack3 &S, DataType3 x) 
{
   if (S.t>=(MAXNUM-1)) 
		{
			return STACK_OVERFLOW;
		}
	S.t++;
    S.s[S.t]=x;
	return OK;
}

int Pop3(Stack3 &S)
{
  if (S.t == -1)
	{ 
		return STACK_UNDERFLOW;
	}	
	S.t--;
  return OK;
}

DataType3 Top3(Stack3 S)
{
	DataType3 e;
	e=S.s[S.t];
  return e;
}

int IsEmptyStack3(Stack3 S)
{
	if (S.t == -1) 
		return 1; 
	else
  	return 0;
}
void StackToStack3(Stack3 &S1,Stack3 &S2)
{
	while(!IsEmptyStack3(S1))
	{
		 Push3 (S2,Top3(S1)) ;
		 Pop3(S1);
	}
	
}





