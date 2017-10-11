#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Lyouxian.h"
int youxian4(char a,char b)
{
	switch(a)
	{
	case'+':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 0;
	         case'/':return 0;
			 case'(':return 0;
			 case')':return 1;
			 case'!':return 0;
			 case'^':return 0;
			}
	case'-':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 0;
	         case'/':return 0;
		     case'(':return 0;
			 case')':return 1;
			 case'!':return 0;
			 case'^':return 0;
			}
	case'*':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
			 case'(':return 0;
			 case')':return 1;
			case'!':return 0;
			 case'^':return 0;
			}
	case'/':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return 0;
			 case')':return 1;
			 case'!':return 0;
			 case'^':return 0;
			}
	case'(':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 0;
	         case'/':return 0;
             case'(':return 0;
			 case')':return equal;
			 case'!':return 0;
			 case'^':return 0;
			}
	case')':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return error;
			 case')':return 1;
			case'!':return 0;
			 case'^':return 0;
			}
	case'!':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return 1;
			 case')':return 1;
			 case'^':return 1;
			}
	case'^':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return 0;
			 case')':return 1;
			 case'^':return 1;
			}
	}
}