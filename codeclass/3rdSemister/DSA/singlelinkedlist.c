#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPos(Node** head, int value, int pos) {
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 0) {
        insertAtBeg(head, value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *head;
    int cnt = 0;
    
    // Find the node at position pos-1
    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    
    if (temp == NULL) {
        printf("Invalid position. Position exceeds list length.\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeg(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) { 
        free(*head);
        *head = NULL;
        return;
    }
    Node *curr = *head, *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
}

void deleteAtPos(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 0) {
        deleteAtBeg(head);
        return;
    }
    
    Node *curr = *head, *prev = NULL;
    int cnt = 0;
    
    // Find the node at the specified position
    while (curr != NULL && cnt < pos) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    
    if (curr == NULL) {
        printf("Invalid position. Position exceeds list length.\n");
        return;
    }
    
    prev->next = curr->next;
    free(curr);
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    do {
        printf("\nEnter\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n");
        printf("7. Display\n8. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeg(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPos(&head, value, pos);
                break;
            case 4:
                deleteAtBeg(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);

    // Free all allocated memory before exiting
    freeList(&head);
    
    return 0;
}