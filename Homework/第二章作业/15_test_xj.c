#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *preXORnext;
}polynode;

polynode* create(polynode **preNode, polynode **nextNode); //������������
void output(polynode* head, polynode* prepre);

int main(){
    polynode *pre, *next;
    polynode *head = create(&pre, &next);
    printf("˳ʱ�룺");
    output(head, pre);
    return 0;
}

polynode *create(polynode **preNode, polynode **nextNode){
    polynode *head = (polynode*)malloc(sizeof(struct Node));
    int x, len=0, n=0;
    polynode *p = head;
    polynode *prep = 0;   //��ʼͷ�ڵ�������൱��next����0���ĳ��������������
    polynode *nextp;
    polynode *first = NULL, *second = NULL;
    printf("���������ȣ�"); 
    scanf("%d", &len);
    getchar();
    printf("�����������ݣ�"); 
    for(n=1; n<=len; n++){
        scanf("%d", &x);
        polynode *newnode = (polynode*)malloc(sizeof(struct Node));
        if (n == 1) first = newnode;
        if (n == 2) second = newnode;
        newnode->data = x;
        nextp = newnode;
        p->preXORnext = (polynode*)((long long)prep ^ (long long)nextp);
        prep = p;
        p = newnode;
    }
    p->preXORnext = (polynode*)((long long)prep ^ (long long)first);	//��βָ����������һ���ڵ������
    first->preXORnext = (polynode*)((long long)p ^ (long long)second);  //�γɻ��󣬸��µ�һ���ڵ������
    *preNode = p;
    *nextNode = second;
    return head;
}

void output(polynode *head, polynode *prepre){
    polynode *first = head->preXORnext;
    polynode *pre = first;
    printf("%d", first->data);
    polynode *p = (polynode*)((long long)pre->preXORnext ^ (long long)(prepre));
    while(p != first){
        printf(" %d", p->data);
        prepre = pre;
        pre = p;
        p = (polynode*)((long long)pre->preXORnext ^ (long long)(prepre));
    }
}

