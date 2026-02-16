#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "queue.h"

void showMenu() {
    printf("\n====== MENU ======\n");
    printf("1. Pizza     (200)\n");
    printf("2. Lasagna   (150)\n");
    printf("3. Ravioli   (100)\n");
    printf("0. Exit\n");
    printf("==================\n");
}

int getPrice(int choice) {
    switch(choice) {
        case 1: return 200;
        case 2: return 150;
        case 3: return 100;
        default: return 0;
    }
}

void printFood(int choice) {
    switch(choice) {
        case 1: printf("Pizza\n"); break;
        case 2: printf("Lasagna\n"); break;
        case 3: printf("Ravioli\n"); break;
    }
}

int main() {

    Queue q = {NULL, NULL, 0};
    int choice;
    int customerNo = 1;

    while(1) {

        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Program ended.\n");
            break;
        }

        if(choice >= 1 && choice <= 3) {

            enqueue_struct(&q, choice);

            int order = dequeue_struct(&q);

            printf("\nCustomer no: %d\n", customerNo++);
            printFood(order);

            int price = getPrice(order);
            printf("You have to pay %d\n", price);

            int cash;
            do {
                printf("Cash: ");
                scanf("%d", &cash);

                if(cash < price)
                    printf("Not enough money. Try again.\n");

            } while(cash < price);

            printf("Thank you\n");

            if(cash > price)
                printf("Change is: %d\n", cash - price);

        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
