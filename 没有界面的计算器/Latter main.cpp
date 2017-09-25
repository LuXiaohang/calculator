#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Lyouxian.h"
#include"Lstack.h"
static int t;
void StackToStack41(Stack4 &S1,Stack4 &S2);
void houzhui(char *shizi)
{
	int len,q,r=0;
	int i=1,j=0;
	len=strlen(shizi)-2;
	Stack4 L1,L2,L3;//L1用于存储整个后缀表达式；L2用于暂时储存运算符;L3用于栈的倒置
	InitializeEmptyStack4(L1);
	InitializeEmptyStack4(L2);
	InitializeEmptyStack4(L3);
    for(i=1;i<=len;i++)
	{   
		
		if((shizi[i]>=48&&shizi[i]<94)||shizi[i]=='.')
		{
			 Push4(L1,shizi[i]);
		}
		else
		{
			Push4(L1,'#');
			 t++;
		    if( IsEmptyStack4(L2))
		    {
				 Push4(L2,shizi[i]);
			}
			else
			{
			   q=youxian4(Top4(L2),shizi[i]);
			   if(q==0)
			   {
				Push4(L2, shizi[i]);
			   }
			   else
			   {
				Push4(L1, Top4(L2));
				Pop4(L2);
				i--;
			    }
		    }
	      }
	}
	Push4(L1, '#');
	StackToStack41(L2,L1);
	StackToStack4(L1,L3);
	printf("后缀表达式为：\n");
	for(i=1;i<=len+t+1;i++)
	{
		if(Top4(L3)=='#')
		{  
		  Pop4(L3);
		  if(Top4(L3)!='#'&&r==0)
		  {
		    printf(" ");
			r=1;
		  }
		  continue;
		}

       if(Top4(L3)!=')')
	   {
		  
		   if(Top4(L3)!='(')
		   {
			   r=0;
		    printf("%c",Top4(L3));
		   }
	   }
	   Pop4(L3);
	}
}
void StackToStack41(Stack4 &S1,Stack4 &S2)
{
	int a=0;
	while(!IsEmptyStack4(S1))
	{
		 Push4 (S2,Top4(S1)) ;
		 Push4 (S2,'#') ;
		 Pop4(S1);
		 t++;
	}
}

	


	





