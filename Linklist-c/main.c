#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* pNext;
}Node, *PNode;

PNode createList();
void traverse(PNode pHead);
bool isEmpty(PNode pHead);
int length(PNode pHead);
bool insert(PNode pHead, int pos, int val);
bool del(PNode pHead, int pos);
PNode get(PNode pHead, int k); //按序号查找
PNode locate(PNode pHead, int value);//按值查找

int main(void)
{
   //test

   return 0;
}

PNode createList()
{
    int len, value;

    PNode pHead = (PNode)(malloc(sizeof(Node)));
    PNode pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入你要的节点个数：");
    scanf("%d", &len);
    for(int i=1;i<=len;i++){
        printf("请输入第%d个节点的值：", i);
        scanf("%d", &value);

        PNode pNew = (PNode)malloc(sizeof(Node));
        pNew->data = value;
        pTail->pNext = pNew;
        pTail = pNew;
        pTail->pNext = NULL;
    }

    return pHead;
}


void traverse(PNode pHead)
{
    printf("遍历结果为:\n");
    PNode pTra = pHead;
    while(pTra->pNext != NULL)
    {
        printf("%d ", pTra->pNext->data);
        pTra = pTra->pNext;
    }
    printf("\n");
}

bool isEmpty(PNode pHead)
{
    if(pHead->pNext==NULL)
      return true;
    else
      return false;
}

int length(PNode pHead)
{
    int len = 0;
    while(pHead->pNext!=NULL){
        pHead = pHead->pNext;
        len++;
    }
    return len;

}

bool insert(PNode pHead, int pos, int val)
{
    if(pos<1 || pos>length(pHead)){
        return false;
    }else{
        PNode pInsert = pHead;
        for(int i=1;i<pos;i++){
            pInsert = pInsert->pNext;
        }

        PNode pNew = (PNode)malloc(sizeof(Node));
        pNew->data = val;
        pNew->pNext = pInsert->pNext;
        pInsert->pNext = pNew;

        return true;
    }

}

bool del(PNode pHead, int pos)
{
    if(pos<1 || pos>length(pHead)){
        return false;
    }else{
        PNode pDel = pHead;
        for(int i=1;i<pos;i++){
            pDel = pDel->pNext;
        }

        if(pos==length(pHead)){
          free(pDel->pNext);
          pDel->pNext = NULL;
        }else{
            PNode pNext = pDel->pNext->pNext;
            free(pDel->pNext);
            pDel->pNext = pNext;
        }

        return true;

    }


}

PNode get(PNode pHead, int k)
{
    PNode p = pHead;
    for(int i=1;i<=k;i++){
        p = p->pNext;
    }
    return p;

}
PNode locate(PNode pHead, int value)
{
    PNode p = pHead->pNext;
    while(p&&p->data!=value){      //NULL 是 0
        p = p->pNext;
    }
    return p;
}
