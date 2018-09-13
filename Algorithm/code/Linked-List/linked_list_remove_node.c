#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node {
 int data;
 Node *next;
};

Node *remove_node(Node *head, Node *node) {
 return head;
}

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

void show_list(Node *head) {
    Node *temp = head;
    printf("\nNode list : ");
    while (temp->next != NULL) {
        printf(" %d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 int main(int argc, char const *argv[])
 {
     /* code */
     Node *a,*b,*c,*d;
     a = create_node(10, b);
     b = create_node(2, c);
     c = create_node(13, d);
     d = create_node(7, NULL);
     show_list(b);
     return 0;
 }
 
