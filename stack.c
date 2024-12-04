                                                                                                                                                                                                                                                                                                                                             stack2.c                                                                                                                                                                                                                                                                                                                                                                                                                                                           Modified  
#include<stdio.h>
#include<stdlib.h>

//defining structure node
typedef struct node{
int data;
struct node*next;

}node;

struct node*start ;
void push();
void pop();
void top();
void search();
void display();
// search operation 
void search(){
        struct node*ptr=NULL;   
        int el;
        int flag=0;
        int loop=0;
        if(start==NULL){ 
                printf("\n stack is empty\n");  

        } 
        else
        {
        printf("\n enter element to search:");
        scanf("%d",&el);
 
        ptr=start;
        while(ptr!=NULL){
                ++loop;
                if(ptr->data ==el){
                flag=1;
                printf("\n element %d found at pos: %d ",el,loop);  
                break;
                }
                ptr=ptr->next;  
      }
        if(flag==0){
                printf("\n element not found!...\n");
                }

        }



}
//push operation
void push(){
        int val;
        struct node*ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
                printf("\n--- Overflow!!\n");   
        }
        else{
                printf("\n enter a value to push:\n");
                scanf("%d",&val);
                if(start==NULL){
                ptr->data=val;
                ptr->next=NULL;
                start=ptr;

                }
                else{
                ptr->data=val;
                ptr->next=start;
                start=ptr;
                }

        }
        printf("\n item pushed \n");
}
//pop operation
void pop(){
        struct node*ptr;
        if(start==NULL){
                printf("\n underflow \n"); 

        }
        else{
        ptr=start;
        start=start->next;
        printf("\n item - %d popped \n",ptr->data);
        free(ptr);      
        }
}

//top  element
void top(){
        if(start==NULL){ 
                printf("\n stack is empty !! \n"); 

        } 
        else{ 
        printf("\n top of stack is- %d \n",start->data);      
        }//stack using linked list

}
//display stack
void display(){
   struct node*ptr;
        if(start==NULL){ 
                printf("\n stack is empty\n");  

        } 
        else{ 
        ptr=start;
        printf("\n stack is :\n");
        while(ptr!=NULL){
                printf(" %d |",ptr->data);  
                ptr=ptr->next;  
        }
        }
}
 //main program
int main(){
int ch;
do{
printf("\n\n--------stack--------");
printf("\n 1.Push \n 2.Pop \n 3.Top \n 4.Display \n 5.search  \n 6.Exit");
printf("\n\t enter option:");
scanf("%d",&ch);

  switch(ch){
        case 1:
        {
        push();
        break;
        }
         case 2:
        {
        pop();
        break;
        }
        case 3:
        {
        top();
        break;
        }
        case 4:
        {
        display();
        break;
        }
        case 5:
        {
        search();
        break;
        }
}
}
while (ch!=6);
return 0;
}
