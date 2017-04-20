#include "stdio.h"
#include "stdlib.h"

typedef struct _node{
    int val;
    struct _node* next;
}Node;

void output(Node* p) {
    int count = 0;
    while(p != NULL && count < 10) {
        printf("%d -> ", p->val);
        p = p->next;
        count++;
    }
    if (p == NULL) {
        printf("NULL\n");
    }
}

Node* reverse(Node* cur) {
    if(cur == NULL) {
        return NULL;
    }
    if(cur->next == NULL) {
        // *head = cur;
        return cur;
    }

    // printf("%d -> ", cur->val);
    Node* tmp = reverse(cur->next);
    tmp->next = cur;
    cur->next = NULL;

    return cur;
}

int main() {
    Node* head = malloc(sizeof(Node));
    Node* cur = head;

    cur->val = 1;
    cur->next = malloc(sizeof(Node));

    cur = cur->next;
    cur->val = 2;
    cur->next = malloc(sizeof(Node));

    cur = cur->next;
    cur->val = 3;
    cur->next = malloc(sizeof(Node));
    
    cur = cur->next;
    cur->val = 4;
    cur->next = malloc(sizeof(Node));
    
    cur = cur->next;
    cur->val = 5;
    cur->next = NULL;
    
    output(head);

    Node* rhead = cur;
    reverse(head);

    output(rhead);

    return 0;
}