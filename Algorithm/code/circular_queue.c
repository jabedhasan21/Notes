#include<stdio.h>

#define Q_length 6

typedef struct {
    int data[Q_length+1];
    int head, tail;
} Queue;

void enqueue(Queue *q, int item) {
    if ((q->tail + 1) % (Q_length + 1) == q->head) {
        printf("\nQueue is full!\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_length + 1);
}

int dequeue(Queue *q) {
    int item;
    if(q->tail  == q->head) {
        printf("\nQueue is empty!\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (Q_length + 1);
    return item;
}

void displayQueue(Queue *q) {
    int i;
    printf("Elements in Circular Queue are: ");
    if (q->head == q->tail) {
        printf("Empty!\n");
        return;
    }
    if (q->tail > q->head) {
        for (i = q->head; i <q->tail; i++) {
            printf(" %d", q->data[i]);
        }
    } else {
        for (i = q->head; i <= Q_length; i++) {
            printf(" %d", q->data[i]);
        }
        for (i = 0; i < q->tail; i++) {
            printf(" %d", q->data[i]);
        }
    }
    printf("\n");
}

int length(Queue *q) {
    if ((q->tail + 1) % (Q_length + 1) == q->head) {
        return Q_length;
    }
    if (q->head == q->tail) {
        return 0;
    } else if (q->head > q->tail) {
        return ((Q_length +1 ) - q->head) + q->tail;
    } else {
       return (q->tail - q->head);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    Queue my_q;
    my_q.head = 0;
    my_q.tail = 0;

    enqueue(&my_q, 2);
    printf("\ntail = %d\n", my_q.tail);
    printf("Queue length = %d\n", length(&my_q));
    enqueue(&my_q, 4);
    printf("\ntail = %d\n", my_q.tail);
    printf("Queue length = %d\n", length(&my_q));
    enqueue(&my_q, 5);
    printf("\ntail = %d\n", my_q.tail);
    printf("Queue length = %d\n", length(&my_q));
    enqueue(&my_q, 6);
    printf("\ntail = %d\n", my_q.tail);
    printf("Queue length = %d\n", length(&my_q));
    enqueue(&my_q, 3);
    printf("\ntail = %d\n", my_q.tail);
    printf("Queue length = %d\n", length(&my_q));
    enqueue(&my_q, 17);

    displayQueue(&my_q);
    printf("\nBeginning head = %d\n", my_q.head);
    printf("Queue length = %d\n", length(&my_q));

    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("Queue length = %d\n", length(&my_q));

    displayQueue(&my_q);

    printf("\nHead = %d\n", my_q.head);
    printf("Tail = %d\n", my_q.tail);
    enqueue(&my_q, 4);
    enqueue(&my_q, 3);
    enqueue(&my_q, 5);
    enqueue(&my_q, 66);
    displayQueue(&my_q);
    printf("\nHead = %d\n", my_q.head);
    printf("Tail = %d\n", my_q.tail);
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    displayQueue(&my_q);
    enqueue(&my_q, 77);
    enqueue(&my_q, 33);
    enqueue(&my_q, 43);
    displayQueue(&my_q);

    printf("\nHead = %d\n", my_q.head);
    printf("\nTail = %d\n", my_q.tail);
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    printf("\nitem = %d, head = %d\n",dequeue(&my_q), my_q.head);
    displayQueue(&my_q);
    enqueue(&my_q, 22);
    printf("\nHead = %d\n", my_q.head);
    printf("\nTail = %d\n", my_q.tail);
    displayQueue(&my_q);
    printf("Queue length = %d\n", length(&my_q));
    printf("\n");
    return 0;
}