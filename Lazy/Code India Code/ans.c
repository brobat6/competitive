#include<stdlib.h>

typedef struct node {
int data;
struct node *next;
} NODE;

NODE* InterChange (NODE *first) {
    NODE *temp1, *temp2;
    //Do not declare any new pointer variable(s).
    //Write code below considering the list has either zero or one node.
    if(first == NULL || first->next == NULL) {
        return first;
    }
    temp1 = first;
    //Write code below to point temp1 to second last node.
    while(temp1->next->next != NULL) {
        temp1 = temp1->next;
    }
    //Using temp2 as an additional variable, write code below to perform
    //the required task of interchanging.
    temp2 = temp1->next;
    temp1->next = first;
    temp2->next = first->next;
    first = temp2;
    temp1->next->next = NULL;
    //Finally, check if the above code also works for 2-element list.
    //Write "YES IT WORK" if it works; "NO, IT WONT WORK" if it doesn’t.
    //If your answer is NO, write code below to make it work.
    
    return first;
}