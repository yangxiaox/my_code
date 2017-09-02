/*************************************************************************
	> File Name: 7.23.0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月23日 星期日 14时05分47秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "xtest.h"



typedef struct Node{
    int data;
    struct Node *next;
} Linkedlist, *pLinkedlist;

pLinkedlist create_node(int data) {
    pLinkedlist p = (pLinkedlist)malloc(sizeof(Linkedlist));
    p->data = data;
    p->next = NULL;
    return p;
}

void clear(pLinkedlist head) {
    pLinkedlist p, q;
    p = head;
    while (q) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

pLinkedlist insert(pLinkedlist head, pLinkedlist new_node, int index) {  //zeng
    Linkedlist ret;
    pLinkedlist p;
    ret.next = head;
    p = &ret;
    while (index-- && p != NULL) {
        p = p->next;
    }
    if (p == NULL) {
        return ret.next;
    }
    new_node->next = p->next;
    p->next = new_node;
    return ret.next;
}

pLinkedlist search(pLinkedlist head, int x) {  //cha
    pLinkedlist p = head;
    while (p != NULL) {
        if(p->data == x)
            break;
        p = p->next;
    }
    return p;
}

pLinkedlist delete_node(pLinkedlist head, int x) {  //shan
    pLinkedlist p, q;
    Linkedlist ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && q->data != x) {
        p = p->next;
        q = q->next;
    }
    if (q) {
        p->next = q->next;
        free(q);
    }
    return ret.next;
}

pLinkedlist modify(pLinkedlist head, int index, int x) {  //gai
    pLinkedlist p =head;
    while (p && index) {
        p = p->next;
        --index;
    }
    if (p) {
        p->data = x;
    }
   return head;

}


int main() {
    return 0;
}

TEST(Linkedlist, insert) {
    pLinkedlist p, head = NULL;
    for(int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, 0);
        ASSERT_EQ(head, p);
    }
    clear(head);
}

TEST(Linkedlist, insert_tail) {
    pLinkedlist p, head = NULL, q = NULL;
    for (int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, i);
        if (q == NULL) {
            q = head;
        } else {
            q = q->next;
        }
        ASSERT_EQ(q, p);
    }
    clear(head);
};

TEST(Linkedlist, queryy) {
    pLinkedlist p, head = NULL, q;
    for (int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, i);
    }
    q = head;
    for (int i = 0; i < 10; ++i) {
        p = search(head, i);
        ASSERT_EQ(p, q);
        q = q->next;
    }
    clear(head);
}


TEST(Linkedlist, queryy_error) {
    pLinkedlist p, head = NULL, q;
    for (int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, 0);
    }
    q = head;
    for (int i = 0; i < 10; ++i) {
        p = search(head, i);
        ASSERT_NE(p->data, q->data);
        q = q->next;
    }
    clear(head);
}

TEST(Linkedlist, _delete) {
    pLinkedlist head = NULL, p, q;
    for (int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, 0);
    }
    for (int i = 0; i < 10; ++i) {
        p = search(head, i);
        delete_node(head, i);
        q = search(head, i);
        ASSERT_NE(p, q);
    }
    clear(head);
}

TEST(Linkedlist, moddify) {
    pLinkedlist head = NULL, p, q;
    int a;
    for (int i = 0; i < 10; ++i) {
        p = create_node(i);
        head = insert(head, p, 0);
    }
    q = p = head;
    a = p->data;
    for (int i = 0; i < 10; ++i) {
        modify(head, i, i);
      //  printf("%d %d\n", a, q->data);
        ASSERT_NE(a, q->data);
        if(i == 9)
            break;
        q = q->next;
        p = p->next;  
        a = p->data;
    }
    //printf("ooo\n");
    clear(head);
    //printf("OK\n");
}
