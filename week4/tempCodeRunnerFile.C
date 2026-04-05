#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* head = NULL;

// Display forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 1. Add node at start
void addAtStart(int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// 2. Add node at end
void addAtEnd(int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// 3. Add node at specific position
void addAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        addAtStart(value);
        return;
    }

    DNode* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// 4. Update first node
void updateFirstNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    head->data = value;
}

// 5. Update last node
void updateLastNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->data = value;
}

// 6. Update node at specific position
void updateAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    DNode* temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    temp->data = value;
}

// 7. Delete first node
void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    DNode* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// 8. Delete last node
void deleteLastNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    DNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// 9. Delete node at specific position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteFirstNode();
        return;
    }

    DNode* temp = head;
    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Main function
int main() {
    addAtEnd(10);
    addAtEnd(20);
    addAtEnd(30);
    printf("Initial Doubly Linked List: ");
    displayForward();

    addAtStart(5);
    printf("After adding at start: ");
    displayForward();

    addAtPosition(15, 3);
    printf("After adding 15 at position 3: ");
    displayForward();

    updateFirstNode(100);
    printf("After updating first node: ");
    displayForward();

    updateLastNode(300);
    printf("After updating last node: ");
    displayForward();

    updateAtPosition(200, 3);
    printf("After updating node at position 3: ");
    displayForward();

    deleteFirstNode();
    printf("After deleting first node: ");
    displayForward();

    deleteLastNode();
    printf("After deleting last node: ");
    displayForward();

    deleteAtPosition(2);
    printf("After deleting node at position 2: ");
    displayForward();

    return 0;
}