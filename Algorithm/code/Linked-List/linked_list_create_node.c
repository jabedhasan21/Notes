#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
     int data;
     Node *next;
 };

 Node *create_node(int item, Node *next) {
     Node *new_node = (Node *) malloc(lengthof(Node));
     if(new_node == NULL) {
         printf("Error! Could Not Create A New Node\n");
         exit(1);
     }
     new_node->data = item;
     new_node->next = next;
     return new_node;
 }

 int main(int argc, char const *argv[])
 {
     /* code */
     Node *n;
     n = create_node(10, NULL);
     printf("data = %d\n",n->data);
     return 0;
 }
 