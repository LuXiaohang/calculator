
#define MAXNUM 1000
#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef char DataType3;//栈中存放的数据元素

struct Stack3
{

	//s表示存放栈中数据元素的连续存储区域的首地址
	//存储空间大小MAXNUM的连续存储单元
	//s指示的为栈底,元素从s开始依次存放		

	//栈顶位置:用栈顶元素的下标表示,
	//有效值(-1,MAXNUM-1),约定: 空栈时令t=-1;
	//栈非空时: s[t]表示栈顶元素
	
	DataType3 s[MAXNUM];	
	int t;  
};

//创建空栈 
int InitializeEmptyStack3(Stack3 &S);

//入栈,将新的元素X插入栈S中，置为栈顶
int Push3(Stack3 &S3, DataType3 x);

//出栈,将栈顶元素删除
int Pop3(Stack3 &S);

//取栈顶,读取栈顶元素
DataType3 Top3(Stack3 S);


//判栈空,若S为空栈，返回TRUE，否则FALSE。  
int IsEmptyStack3(Stack3 S);

//将元素从一个栈弹到另一个栈中
void StackToStack3(Stack3 &S1,Stack3 &S2);


