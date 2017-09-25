
#define MAXNUM 1000
#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef char DataType3;//ջ�д�ŵ�����Ԫ��

struct Stack3
{

	//s��ʾ���ջ������Ԫ�ص������洢������׵�ַ
	//�洢�ռ��СMAXNUM�������洢��Ԫ
	//sָʾ��Ϊջ��,Ԫ�ش�s��ʼ���δ��		

	//ջ��λ��:��ջ��Ԫ�ص��±��ʾ,
	//��Чֵ(-1,MAXNUM-1),Լ��: ��ջʱ��t=-1;
	//ջ�ǿ�ʱ: s[t]��ʾջ��Ԫ��
	
	DataType3 s[MAXNUM];	
	int t;  
};

//������ջ 
int InitializeEmptyStack3(Stack3 &S);

//��ջ,���µ�Ԫ��X����ջS�У���Ϊջ��
int Push3(Stack3 &S3, DataType3 x);

//��ջ,��ջ��Ԫ��ɾ��
int Pop3(Stack3 &S);

//ȡջ��,��ȡջ��Ԫ��
DataType3 Top3(Stack3 S);


//��ջ��,��SΪ��ջ������TRUE������FALSE��  
int IsEmptyStack3(Stack3 S);

//��Ԫ�ش�һ��ջ������һ��ջ��
void StackToStack3(Stack3 &S1,Stack3 &S2);


