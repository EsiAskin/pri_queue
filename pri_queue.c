#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    int pri;
    struct node * next;
};
struct node * start=NULL;
struct node * temp = NULL;

struct node * insert(struct node * start){
    int val, priority;
    printf("Kac eklemek istiyorsun ? \n");
    scanf("%d",&val);
    printf("Onceligi nedir ?\n");
    scanf("%d", &priority);
    struct node * new_node =(struct node *)malloc(sizeof(struct node));
    new_node->pri=priority;
    new_node->data=val;
    if(start==NULL||priority<start->pri){
        new_node->next=start;
        start=new_node;
    }else{
        temp=start;
        while(temp->next!=NULL&&priority>=temp->next->pri){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
        
    }
    return start;
}

struct node * del_element(struct node * start){
    if(start==NULL) printf("Kuyruk bos, silemeyiz.\n");
    else{
        temp=start;
        start=start->next;
        free(temp);
    }
    return start;
}
void display(struct node * start){
    if(start==NULL) printf("Kuyrugumuz bos.\n");
    else{
        temp=start;
        while(temp->next!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("%d \n", temp->data);
    }
}

int main()
{
  start=insert(start);
  start=insert(start);
  display(start);
  start=del_element(start);
  display(start);
}
