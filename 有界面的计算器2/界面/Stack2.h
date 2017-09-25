
#define MAXNUM 1000

#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef char DataType2;//ջ�д�ŵ�����Ԫ��

struct Stack2
{

	//s��ʾ���ջ������Ԫ�ص������洢������׵�ַ
	//�洢�ռ��СMAXNUM�������洢��Ԫ
	//sָʾ��Ϊջ��,Ԫ�ش�s��ʼ���δ��		

	//ջ��λ��:��ջ��Ԫ�ص��±��ʾ,
	//��Чֵ(-1,MAXNUM-1),Լ��: ��ջʱ��t=-1;
	//ջ�ǿ�ʱ: s[t]��ʾջ��Ԫ��
	
	DataType2 s[MAXNUM];	
	int t;  
};

//������ջ 
int InitializeEmptyStack2(Stack2 &S);

//��ջ,���µ�Ԫ��X����ջS�У���Ϊջ��
int Push2(Stack2 &op, DataType2 x);

//��ջ,��ջ��Ԫ��ɾ��
int Pop2(Stack2 &op);

//ȡջ��,��ȡջ��Ԫ��
DataType2 Top2(Stack2 S);


//��ջ��,��SΪ��ջ������TRUE������FALSE��  
int IsEmptyStack2(Stack2 S);


