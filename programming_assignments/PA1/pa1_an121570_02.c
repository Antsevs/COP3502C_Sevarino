#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* whatDoesItDo(struct Node* head) {
    struct Node* current = head;
    struct Node* other, *temp;

    if (current == NULL)
        return head;

    other = current->next;

    if (other == NULL)
        return head;

    other = other->next;
    temp = current->next;
    current->next = other->next;
    current = other->next;

    if (current == NULL) {
        head->next = temp;
        return head;
    }

    other->next = current->next;
    current->next = temp;

    return head;
}

int main() {
    struct Node* head = createNode(100);
    struct Node* first = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    struct Node* fifth = createNode(5);
    struct Node* sixth = createNode(6);
    struct Node* seventh = createNode(7);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    printf("Before: ");
    printLinkedList(head);

    head = whatDoesItDo(head);

    printf("After: ");
    printLinkedList(head);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

/* The linked list is rearranged from
head > 1 > 2 > 3 > 4 > 5 > 6 > 7 > NULL
to
head > 3 > 1 > 2 > 4 > 5 > 6 > 7 > NULL
*/