include<stdio.h>
#include<stdlib.h>

 typedef struct node{
        struct node* prev;
        int data;
        struct node* next;
 } node;

 struct node* head=NULL;

int main(){
        int ch;
        void insertf(),insertr(),display(),insertx(),deletef(),deleter(),deletex();

        do{
                printf("\n **MENU**\n 1.insert to front \n 2.insert at the end \n 3.insert to a specific position\n 4.display list \n 5.delete from front\n 6.delete from rear\n 7.delete a specific position \n 8.exit program \n \n * * *\n");
                printf("enter your choice  : ");
                scanf("%d", &ch);

                switch(ch){

                        case 1 :insertf();
                                break;
                        case 2 :insertr();
                                break;
                        case 3 :insertx();
                                break;
                        case 4 :display();
                                break;
                        case 5 :deletef();
                                break;
                        case 6 :deleter();
                                break;
                        case 7 :deletex();
                                break;
                        case 8 :printf("\n program exited");
                                break;
                        default:printf("invalid entry");
                }

        }while(ch!=8);
}

void insertf(){
                struct node *newnode=(struct node*)malloc(sizeof(newnode));
                printf("enter value to insert :");
                scanf("%d",&newnode->data);
                newnode->prev=NULL;

                if(head==NULL){
                        newnode->next=NULL;
                        head=newnode;
                        printf(" %d, inserted to front", head->data);
                }
                else{
                        newnode->next=head;
                        head->prev=newnode;
                        head=newnode;
                        printf(" %d, inserted to front", head->data);
                }
}

void insertr(){
                struct node *newnode=(struct node*)malloc(sizeof(newnode));
                printf("enter value to insert :");
                scanf("%d",&newnode->data);
                newnode->next=NULL;

                if(head==NULL){
                        newnode->prev=NULL;
                        head=newnode;
                }
                else{
                        struct node *temp;
                        temp=head;

                        while(temp->next!=NULL){
                                temp=temp->next;
                        }
                        temp->next=newnode;
                        newnode->prev=temp;
                        printf(" %d, inserted to end", newnode->data);
                }
}

void insertx(){
                int  position;
                struct node *newnode=(struct node*)malloc(sizeof(newnode));
                printf("enter value to insert :");
                scanf("%d",&newnode->data);

                printf("enter position :\n");
                scanf("%d", &position);
                position;

                if(position-1==0){
                        newnode->prev=NULL;
                        newnode->next=head;
                        head=newnode;
                        printf(" %d, inserted to front", head->data);
                }

                else{
                        struct node *temp;
                        temp=head;

                        for(int i=0; i<position-1 && temp!=NULL; i++){
                                temp=temp->next;
                        }

                        if (temp == NULL){
                                printf("Position out of bounds for the list.\n");
                                free(newnode);
                        }
                        else{
                                newnode->next=temp;
                                newnode->prev=temp->prev;
                                temp->prev->next=newnode;
                                temp->prev=newnode;
                                printf(" %d, inserted at position: %d", newnode->data, position++);
                        }
                }
}

void display(){
                struct node *temp;
                temp=head;
                if(temp==NULL)
                        printf("empty list");
                else{printf("NULL<->");
                        while(temp!=NULL){
                                printf(" %d <-> ",temp->data);
                                temp=temp->next;
                        }printf("NULL");
                }
}

void deletef(){
                if(head==NULL){
                        printf("list empty");
                }
                else{
                        struct node* temp;
                        temp=head;
                        head=head->next;
                        if(head!=NULL)
                        head->prev=NULL;
                        printf(" %d , removed ",temp->data);
                        free(temp);
                }
}
void deletex() {
    int position;
    printf("Enter position to delete :");
    scanf("%d", &position);

    if (position < 1) {
        printf("Position should be greater than 0.\n");
        return;
    }

    struct node *temp = head;

    if (position == 1) {
        if (head == NULL) {
            printf("List is empty.\n");
            return;
        }
        head = head->next;
        if (head != NULL) {
            head->prev = NULL; 
        }
        printf("%d deleted\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds for the list.\n");
        return;
    }

    if (temp->next == NULL) {
        temp->prev->next = NULL; 
    } else {
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev; 
    }

    printf("%d deleted\n", temp->data);
    free(temp);
}

