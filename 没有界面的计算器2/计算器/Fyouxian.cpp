#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Fyouxian.h"
int youxian3(char a,char b)
{
	switch(a)
	{
	case'+':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
			 case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
	case'-':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
		     case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
	case'*':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 1;
	         case'/':return 1;
			 case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
	case'/':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
	case')':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return -1;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
  case'!':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 0;
	         case'/':return 0;
             case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
  case'^':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 0;
	         case'/':return 0;
             case'(':return 0;
			 case')':return 1;
			 case'!':return 1;
			 case'^':return 1;
			}
	}
}