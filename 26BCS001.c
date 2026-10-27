#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5
#define ROLL "26BCS001"
#define STUDENT_NAME "YOUR NAME"

static int deque[CAPACITY];
static int front = -1;
static int rear = -1;

/* IsEmpty: Parameters: none. Returns true when front == -1, else false.
   Logic: the empty state is represented by both indices being -1. */
bool IsEmpty(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    return front == -1;
}

/* IsFull: Parameters: none. Returns true when no array slot is available.
   Logic: in a circular deque, the next rear position must not equal front. */
bool IsFull(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    return (front == 0 && rear == CAPACITY - 1) || (front == rear + 1);
}

/* Insertfront: reads one integer; returns nothing. Checks full, initializes
   an empty deque, otherwise moves front backward circularly and stores it. */
void Insertfront(void) {
    int value;
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsFull()) { puts("Deque is full."); return; }
    printf("Enter value: ");
    if (scanf("%d", &value) != 1) { puts("Invalid input."); return; }
    if (front == -1) front = rear = 0;
    else if (front == 0) front = CAPACITY - 1;
    else front--;
    deque[front] = value;
    puts("Inserted at front.");
}

/* InsertRear: reads one integer; returns nothing. Checks full, initializes an
   empty deque, otherwise advances rear circularly and stores the value. */
void InsertRear(void) {
    int value;
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsFull()) { puts("Deque is full."); return; }
    printf("Enter value: ");
    if (scanf("%d", &value) != 1) { puts("Invalid input."); return; }
    if (front == -1) front = rear = 0;
    else if (rear == CAPACITY - 1) rear = 0;
    else rear++;
    deque[rear] = value;
    puts("Inserted at rear.");
}

/* Deletefront: parameters: none; returns nothing. Rejects empty state,
   clears indices for the last item, otherwise advances front circularly. */
void Deletefront(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsEmpty()) { puts("Deque is empty."); return; }
    printf("Deleted: %d\n", deque[front]);
    if (front == rear) front = rear = -1;
    else if (front == CAPACITY - 1) front = 0;
    else front++;
}

/* DeleteRear: parameters: none; returns nothing. Rejects empty state,
   clears indices for the last item, otherwise moves rear backward circularly. */
void DeleteRear(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsEmpty()) { puts("Deque is empty."); return; }
    printf("Deleted: %d\n", deque[rear]);
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = CAPACITY - 1;
    else rear--;
}

/* getRear: parameters: none; returns nothing (prints value/status). Checks
   empty state, then reads the element at rear without removing it. */
void getRear(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsEmpty()) puts("Deque is empty."); else printf("Rear: %d\n", deque[rear]);
}

/* getFront: parameters: none; returns nothing (prints value/status). Checks
   empty state, then reads the element at front without removing it. */
void getFront(void) {
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsEmpty()) puts("Deque is empty."); else printf("Front: %d\n", deque[front]);
}

/* display: parameters: none; returns nothing. Traverses front to rear with
   modulo wrap-around and prints each element; reports an empty deque. */
void display(void) {
    int i;
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    if (IsEmpty()) { puts("Deque is empty."); return; }
    printf("Deque: ");
    for (i = front; ; i = (i + 1) % CAPACITY) {
        printf("%d ", deque[i]);
        if (i == rear) break;
    }
    putchar('\n');
}

/* main: parameters: none; returns 0 on normal exit. Prints identity, loops
   over the menu, dispatches operations, handles invalid choices and Exit. */
int main(void) {
    int choice;
    printf("Roll: %s | Name: %s\n", ROLL, STUDENT_NAME);
    do {
        puts("\n1.Insertfront 2.InsertRear 3.Deletefront 4.DeleteRear 5.getRear");
        puts("6.getFront 7.display 8.IsEmpty 9.IsFull 10.Exit");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) { puts("Invalid input; exiting."); return 0; }
        switch (choice) {
            case 1: Insertfront(); break;
            case 2: InsertRear(); break;
            case 3: Deletefront(); break;
            case 4: DeleteRear(); break;
            case 5: getRear(); break;
            case 6: getFront(); break;
            case 7: display(); break;
            case 8: puts(IsEmpty() ? "Deque is empty." : "Deque is not empty."); break;
            case 9: puts(IsFull() ? "Deque is full." : "Deque is not full."); break;
            case 10: puts("Exiting."); break;
            default: puts("Invalid menu choice.");
        }
    } while (choice != 10);
    return 0;
}
