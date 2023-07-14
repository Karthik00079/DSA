#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    int next;
};

struct Node list[MAX_SIZE];
int freeIndex;

void initializeList() {
    int i;
    for (i = 0; i < MAX_SIZE - 1; i++) {
        list[i].next = i + 1;
    }
    list[MAX_SIZE - 1].next = -1;
    freeIndex = 0;
}

int getNode() {
    int nodeIndex = freeIndex;
    if (freeIndex != -1) {
        freeIndex = list[freeIndex].next;
        return nodeIndex;
    } else {
        printf("List is full\n");
        return -1;
    }
}

void releaseNode(int nodeIndex) {
    list[nodeIndex].next = freeIndex;
    freeIndex = nodeIndex;
}

void insertAtBeginning(int data) {
    int newNodeIndex = getNode();
    if (newNodeIndex != -1) {
        list[newNodeIndex].data = data;
        list[newNodeIndex].next = -1;

        if (list[0].next != -1) {
            list[newNodeIndex].next = list[0].next;
        }
        list[0].next = newNodeIndex;
    }
}

void display() {
    int current = list[0].next;
    while (current != -1) {
        printf("%d ", list[current].data);
        current = list[current].next;
    }
    printf("\n");
}

int main() {
    initializeList();

    // Insert nodes at the beginning of the list
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);

    // Display the list
    printf("Linked List: ");
    display();

    return 0;
}
