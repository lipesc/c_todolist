#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *color1="\e[92m";
const char *color2="\e[93m";
const char *color3="\e[91m";
const char *defaultColor="\e[0m\e[39m";
const char *boldColor="\e[1m";

struct Task {
    char description[100];
    int completed;
    struct Task* next;
};

struct Task* createTask(const char* description) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    snprintf(newTask->description, sizeof(newTask->description), "%s", description);
    newTask->completed = 0;  // 0 for false, 1 for true
    newTask->next = NULL;
    return newTask;
}

void addTask(struct Task** head, const char* description) {
    struct Task* newTask = createTask(description);
    newTask->next = *head;
    *head = newTask;
    printf("Task added: %s", description,printf("%s",color2));
}

void displayTasks(const struct Task* head) {
    if (head == NULL) {
        printf("To-do list is empty.");
        return;
    }
    printf("To-Do List:");
    while (head != NULL) {
        printf("\n%s - %s", head->completed ? "[ √ ]" : "[   ]", head->description,printf("%s",color1));
        head = head->next;
    }
}

void markCompleted(struct Task* head, const char* description) {
    while (head != NULL) {
        if (strcmp(head->description, description) == 0) {
            head->completed = 1;  // Mark as completed
            printf("Task marked as completed: %s", description,printf("%s",color3));
            return;
        }
        head = head->next;
          }
    printf("Task not found: %s", description);

    }


void freeToList(struct Task* head) {
    while (head != NULL) {
        struct Task* temp = head;
        head = head->next;
        free(temp);
    }
}

void todo(){
     struct Task* todoList = NULL;
    int choice;
    char description[100];
    do {
        printf("\n=====================================================\n");
        printf("To-Do List Menu!!!");
        printf("\n=====================================================\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n=====================================================\n");
                printf("Enter task description: \n");
                scanf(" %[^\n]", description);
                addTask(&todoList, description);
                break;
            case 2:
                printf("\n=====================================================\n");
                displayTasks(todoList);
                break;
            case 3:
                printf("\n=====================================================\n");
                printf("Enter task description to mark as completed: \n");
                scanf(" %[^\n]", description);
                markCompleted(todoList, description);
                break;
            case 4:
                printf("\n=====================================================\n");
                printf("Quitting the to-do list app.");
                break;
            default:
                printf("\n=====================================================\n");
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 4);
    freeToList(todoList);
}

int main() {
    int c = 0;
    do{
        printf("\n=====================================================\n");
        printf("Todo list");
        printf("\n=====================================================\n");
        printf("1. Start \n2. Exit \nEnter your choice:");
        scanf("%d", &c);
        switch(c){
            case 1:
                todo();
                break;
            case 2:
                printf("Exited!");
                break;
            default:
                printf("Enter valid input!");
        }
    } while (c != 2);
}