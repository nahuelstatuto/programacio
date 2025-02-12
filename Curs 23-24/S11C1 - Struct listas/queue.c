#include<stdio.h>  
#include <stdlib.h>  
  
struct Node {  
    int data;  
    struct Node* next;  
};  
  
struct Node* front = NULL;  
struct Node* rear = NULL;  
  
void enqueue(int element) {  
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
    new_node->data = element;  
    new_node->next = NULL;  
    if (front == NULL && rear == NULL) {  
        front = rear = new_node;  
        return;  
    }  
    rear->next = new_node;  
    rear = new_node;  
}  
  
int dequeue() {  
    if (front == NULL) {  
        printf("Queue is empty");  
        return -1;  
    }  
    struct Node* temp = front;  
    int element = temp->data;  
    if (front == rear) {  
        front = rear = NULL;  
    }  
    else {  
        front = front->next;  
    }  
    free(temp);  
    return element;  
}  
  
int main() {  
    enqueue(10);  
    enqueue(20);  
    enqueue(30);  
    printf("%d ", dequeue());  
    printf("%d ", dequeue());  
    printf("%d ", dequeue());  
    printf("%d ", dequeue());  
    return 0;  
}  