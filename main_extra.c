#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int order_number;
    int menu;
} Order;

typedef struct{
    Order *head, *tail;
    int size;
} Queue;

void enqueue(Queue *q, int order_no, int menu){
    Order *newNode = (Order*)malloc(sizeof(Order));
    newNode->order_number = order_no;
    newNode->menu = menu;
    newNode->next = NULL;

    if(q->size == 0)
        q->head = newNode;
    else
        q->tail->next = newNode;

    q->tail = newNode;
    q->size++;
}

Order* dequeue(Queue *q){
    if(q->size == 0)
        return NULL;

    Order *temp = q->head;
    q->head = temp->next;

    if(q->size == 1)
        q->tail = NULL;

    q->size--;
    return temp;
}

void clearQueue(Queue *q){
    while(q->size > 0){
        Order *temp = dequeue(q);
        free(temp);
    }
}

int getPrice(int menu){
    if(menu == 1) return 200;
    if(menu == 2) return 150;
    if(menu == 3) return 100;
    return 0;
}

void printFood(int menu){
    if(menu == 1) printf("Pizza");
    if(menu == 2) printf("Lasagna");
    if(menu == 3) printf("Ravioli");
}

void printMenu(){
    printf("\n1. Pizza (200)\n");
    printf("2. Lasagna (150)\n");
    printf("3. Ravioli (100)\n");
    printf("4. Process Order\n");
    printf("0. Close Shop\n");
}

int main(int argc, char *argv[]){

    Queue q = {NULL,NULL,0};
    int order_no = 1;
    int choice;

    for(int i=1;i<argc;i++){
        int menu = atoi(argv[i]);
        if(menu>=1 && menu<=3)
            enqueue(&q, order_no++, menu);
    }

    while(1){

        printMenu();
        printf("Select:");
        scanf("%d",&choice);

        if(choice>=1 && choice<=3){
            enqueue(&q, order_no++, choice);
        }

        else if(choice==4){

            if(q.size==0){
                printf("No customers\n");
                continue;
            }

            Order *customer = dequeue(&q);

            printf("Customer no: %d\n",customer->order_number);
            printFood(customer->menu);
            printf("\n");

            int price = getPrice(customer->menu);
            int cash;

            printf("You have to pay %d\n",price);

            while(1){
                printf(":Cash:");
                scanf("%d",&cash);

                if(cash<price)
                    printf("Not enough money\n");
                else
                    break;
            }

            printf("Thank you\n");

            if(cash>price)
                printf("Change to maic:%d\n",cash-price);

            free(customer);
        }

        else if(choice==0){
            printf("========================================\n");
            printf("    There are %d ppl left in the queue\n",q.size);
            clearQueue(&q);
            break;
        }

        else{
            printf("Invalid choice\n");
        }
    }

    return 0;
}
