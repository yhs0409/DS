//单链表节点类型
typedef struct LNode
{
    ElemType data;          //数据域
    struct LNode *next;     //指针域
}LNode, *LinkList;

//头插法
LinkList List_HeadInsert(LinkList &L)       //逆向建立单链表
{
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));      //创建头结点
    L->next=NULL;                           //初始为空链表
    scanf("%d",&x);                         //输入结点的值
    while(x!=9999)                          //输入9999表示结束
    {
        s=(LNode *)malloc(sizeof(LNode));    //创建新结点
        s->data=x;
        s->next=L->next;                    //将新结点插入表中，L为头指针
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法
LinkList List_TailInsert(LinkList &L)       //正向建立单链表
{
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;                          //r为表尾指针
    scanf("%d",&x);                         //输入结点的值
    while(x!=9999)                          //输入9999表示结束
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;                                //r指向新的表尾结点
        scanf("%d",&x);
    }
    r->next=NULL;                           //尾结点指针为空
    return L;
}

//按序号查找结点值
LNode *GetElem(LinkList L,int i)
{
    int j=1;                                //计数，初始为1
    LNode *p=L->next;                       //第1个结点指针赋给p
    if(i==0)
        return L;                           //若i等于0，返回头结点
    if(i<1)
        return NULL;                        //若i无效，返回NULL
    while(p&&j<i)
    {
        p=p->next;                          //从第1个结点开始查找到第i个
        j++;
    }
    return p;                               //返回第i个结点指针，若i大于表长，返回NULL
}

//按值查找表结点
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p=L->next;                       //第1个结点指针赋给p
    while(p!=NULL&&p->data!=e)              //从第1个结点开始查找data域为e的结点
        p=p->next;
    return p;                               //找到返回该结点指针，否则返回NULL
}

//插入结点
p=GetElem(L,i-1);                           //查找插入位置的前驱结点
s->next=p->next;
p->next=s;

//前插
s->next=p->next;                            //修改指针域
p->next=s;
temp=p->data;                               //交换数据域
p->data=s->data;
s->data=temp;

//删除
p=GetElem(L,i-1);                           //查找删除位置的前驱结点
q=p->next;                                  //令q指向被删除结点
p->next=q->next;                            //将*q从链中断开
free(q);                                    //释放结点存储空间


//双链表 结点类型描述
typedef struct DNode                        //定义双链表结点类型
{
    ELemType data;                          //数据域
    struct DNode *prior,*next;              //前驱和后继指针
}DNode,*DLinkList;

//插入
s->next=p->next;
p->next->prior=s;
s->prior=p;
p->next=s;

//删除
p->next=q->next;
q->next->prior=p;
free(q);