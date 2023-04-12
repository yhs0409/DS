//基本操作
InitQueue(&Q);                          //初始化队列，构造空队列Q
QueueEmpty(Q);                          //判断队列Q空，若空返回true，否则返回false
EnQueue(&Q,x);                          //入队，若队列Q未满，将x加入，使之成为新队尾
DeQueue(&Q,&x);                         //出队，若队列Q非空，删除队头元素，用x返回
GetHead(Q,&x);                          //读队头元素


//队列的顺序存储类型
#define MaxSize 50                      //定义队列中元素最大个数
typedef struct
{
    ElemType data[MaxSize];             //存放队列元素
    int front,rear;                     //队头指针和队尾指针
}SqQueue;

//循环队列
//初始化
void InitQueue(SqQueue Q)
{
    Q.rear=Q.front=0;                   //初始化队首，队尾指针
}
//判队空
bool isEmpty(SqQueue Q)
{
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear+1)%MaxSize==Q.front)     //队满，报错
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;          //队尾指针+1取模
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)                 //队空，报错
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;        //队头指针+1取模
    return true;
}

//队列链式存储
typedef struct LinkNode                 //链式队列结点
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct                          //链式队列
{
    LinkNode *front,*rear;              //队列的队头和队尾指针
}LinkQueue;

//链式队列
//初始化
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
    Q.front->next=NULL;                                 //初始为空
}
//判队空
bool IsEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    else    
        return false;
}
//入队
void EnQueue(LinkNode &Q,ElemType x)
{
    LinkNode *S=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;                       //创建新结点插入到链队尾
    Q.rear->next=s;
    Q.rear=s;
}
//出队
bool DeQueue(LinkNode &Q,ElemType &x)
{
    if(Q.front==Q.rear)
        return false;                   //队空 报错
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;                 //若原队列中只有一个结点，删除后队列变空
    free(p);
    return true;
}