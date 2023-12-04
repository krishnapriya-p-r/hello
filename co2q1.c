#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32 // Assuming a maximum of 32 elements for simplicity

typedef struct {
    unsigned int elements[MAX_SIZE];
} BitSet;

// Function to initialize an empty set
void initializeSet(BitSet *set) {
    for (int i = 0; i < MAX_SIZE; i++) {
        set->elements[i] = 0;
    }
}

// Function to add an element to the set
void addElement(BitSet *set, int element) {
    if (element >= 0 && element < MAX_SIZE) {
        set->elements[element / 32] |= (1u << (element % 32));
    } else {
        printf("Error: Element out of range\n");
    }
}

// Function to remove an element from the set
void removeElement(BitSet *set, int element) {
    if (element >= 0 && element < MAX_SIZE) {
        set->elements[element / 32] &= ~(1u << (element % 32));
    } else {
        printf("Error: Element out of range\n");
    }
}

// Function to perform the union of two sets
void unionSet(BitSet *result, const BitSet *set1, const BitSet *set2) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elements[i] = set1->elements[i] | set2->elements[i];
    }
}

// Function to perform the intersection of two sets
void intersectionSet(BitSet *result, const BitSet *set1, const BitSet *set2) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elements[i] = set1->elements[i] & set2->elements[i];
    }
}

// Function to perform the difference of two sets (set1 - set2)
void differenceSet(BitSet *result, const BitSet *set1, const BitSet *set2) {
    for (int i = 0; i < MAX_SIZE; i++) {
        result->elements[i] = set1->elements[i] & ~(set2->elements[i]);
    }
}

// Function to display the elements of a set
void displaySet(const BitSet *set) {
    printf("{ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < 32; j++) {
            if ((set->elements[i] & (1u << j)) != 0) {
                printf("%d ", i * 32 + j);
            }
        }
    }
    printf("}\n");
}

int main() {
    BitSet setA, setB, resultSet;

    initializeSet(&setA);
    initializeSet(&setB);
    initializeSet(&resultSet);

    addElement(&setA, 5);
    addElement(&setA, 10);
    addElement(&setA, 15);

    addElement(&setB, 10);
    addElement(&setB, 20);

    // Display original sets
    printf("Set A: ");
    displaySet(&setA);

    printf("Set B: ");
    displaySet(&setB);

    // Perform operations
    unionSet(&resultSet, &setA, &setB);
    printf("Union of A and B: ");
    displaySet(&resultSet);

    intersectionSet(&resultSet, &setA, &setB);
    printf("Intersection of A and B: ");
    displaySet(&resultSet);

    differenceSet(&resultSet, &setA, &setB);
    printf("Difference of A and B: ");
    displaySet(&resultSet);

    return 0;
}

