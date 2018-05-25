#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*实现队列*/
using namespace std;
#define Item int

typedef struct Node_t
{
    Item data;
    struct Node_t* next;
}Node;

typedef struct Queue_t
{
    size_t count;
    Node* head;
    Node* tail;
}Queue;

Queue* queueInit(){
    Queue* que = (Queue*)malloc(sizeof(Queue));
    que->head = que->tail = NULL;
    que->count = 0;
    return que;
}

void queuePush(Item ai_src, Queue* aq_que)
{
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->data = ai_src;
    pNode->next = NULL;

    if(aq_que->count == 0)
    {
        aq_que->head = pNode;
    }
    else
    {
        aq_que->tail->next = pNode;
    }
    aq_que->tail = pNode;
    aq_que->count += 1;
}

Node* queuePop(Queue* aq_que)
{
    if(aq_que->count == 0)
        return NULL;

    aq_que->count -= 1;
    Node* pNode = (Node*)malloc(sizeof(Node));
    pNode->data = aq_que->head->data;
    pNode->next = NULL;
    aq_que->head = aq_que->head->next;
    return pNode;
}

int main()
{
    Queue* queue = queueInit();
    Item a = 100,b = 200,c = 300;
    cout << queue->count << endl;
    queuePush(a,queue);
    queuePush(b,queue);
    queuePush(c,queue);
    cout << queue->count << " " << queue->head->data << " " << queue->tail->data << endl;
    queuePop(queue);
    cout << queue->count << " " << queue->head->data << " " << queue->tail->data<< endl;
    return 0;
}
