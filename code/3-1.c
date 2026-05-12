#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    char command[20];

    while (1) {
        if (scanf("%s", command) == EOF) break;

        if (strcmp(command, "add") == 0) {
            char name[50];
            int score;
            scanf("%s %d", name, &score);

            Node* newNode = (Node*)malloc(sizeof(Node));
            strcpy(newNode->name, name);
            newNode->score = score;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        } else if (strcmp(command, "delete") == 0) {
            char name[50];
            scanf("%s", name);

            Node* current = head;
            Node* prev = NULL;

            while (current != NULL && strcmp(current->name, name) != 0) {
                prev = current;
                current = current->next;
            }

            if (current != NULL) {
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
        } else if (strcmp(command, "print") == 0) {
            Node* current = head;
            while (current != NULL) {
                printf("%s %d\n", current->name, current->score);
                current = current->next;
            }
        } else if (strcmp(command, "quit") == 0) {
            Node* current = head;
            while (current != NULL) {
                Node* nextNode = current->next;
                free(current);
                current = nextNode;
            }
            break;
        }
    }
    return 0;
}
