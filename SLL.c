#include<stdio.h>
#include<stdlib.h>

struct node {
 int data;
 struct node * next;
};
typedef struct node * NODE;
NODE createNode() {
 NODE temp;
 temp = (NODE) malloc(sizeof(struct node));
 temp -> next = NULL;
 return temp;
}
NODE insertAtBegin(NODE first, int x) {
NODE newnode=createNode();
newnode->data=x;
newnode->next=first;
return newnode;
}
NODE insertAtEnd(NODE first, int x) {
NODE newnode=createNode();
newnode->data=x;
if(first==NULL)
return newnode;
NODE temp=first;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
return first;
}
void insertAfterNode(struct node * givenNode, int data) {
if(givenNode==NULL)
{
printf("Given node cannot be NULL.\n");
return;
}
NODE newnode=createNode();
newnode->data=data;
newnode->next=givenNode->next;
givenNode->next=newnode;
printf("Inserted node with data %d after the given node.\n",data);
}
NODE deleteAtBegin(NODE first) {
if(first==NULL){
printf("List is empty. Nothing to delete.\n");
return NULL;
}
NODE temp=first;
first=first->next;
printf("The deleted element from SLL : %d\n",temp->data);
free(temp);
return first;
}

NODE deleteAtEnd(NODE first) {
NODE prev,temp;
if(first==NULL){
printf("List is empty. Nothing to delete.\n");
return NULL;
}
if(first->next==NULL){
free(first);
return NULL;
}
temp=first;
while(temp->next!=NULL){
prev=temp;
temp=temp->next;
}
prev->next=NULL;
printf("The deleted item from SLL : %d\n",temp->data);
free(temp);
return first;
}
void deleteAfterNode(struct node * givenNode) {
if(givenNode==NULL||givenNode->next==NULL){
printf("Cannot delete. Given node is NULL or the next node is NULL.\n");
return;
}
NODE temp=givenNode->next;
givenNode->next=temp->next;
printf("Deleted node with data: %d\n",temp->data);
free(temp);
}
NODE deleteAtPosition(NODE first, int pos) {
if(first==NULL||pos<=0){
printf("List is empty. Nothing to delete.\n");
return NULL;
}
if(pos==1){
NODE temp=first;
first=first->next;
printf("The deleted element from SLL : %d\n",temp->data);
free(temp);
return first;
}
int count=1;
NODE current=first;
NODE prev=NULL;
while(current!=NULL&&count!=pos)
{
prev=current;
current=current->next;
count++;
}
if(current == NULL){
    printf("NO such position in SLL so deletion is not possible \n");


return first;
}
prev->next=current->next;
printf("The deleted element from SLL : %d\n",current->data);
free(current);
return first;
}
void traverseList(NODE first) {
 NODE temp = first;
 while (temp != NULL) {
 printf("%d --> ", temp -> data);
 temp = temp -> next;
 }
 printf("NULL\n");
}



void main() {
 NODE first = NULL;
 struct node * head = NULL;
 int x, pos, givenData, op;
 struct node * temp; // Declare temp variable here
 while (1) {
 printf("1.Insert At Begin\n2.Insert At End\n3.Insert node after the givennode\n");
 printf("4.Delete first node\n5.Delete last node\n6.Delete node after thegiven node\n7.Delete at position\n");
 printf("8.Traverse the List\n9.Exit\n");
 printf("Enter your option: ");
 scanf("%d", & op);
 switch (op) {
 case 1:
 printf("Enter an element: ");
 scanf("%d", & x);
 first = insertAtBegin(first, x);
 break;
 case 2:
 printf("Enter an element: ");
 scanf("%d", & x);
 first = insertAtEnd(first, x);
 break;
 case 3:
 printf("Enter the data of the given node: ");
 scanf("%d", & givenData);
 printf("Enter the data to be inserted: ");
 scanf("%d", & x);
 temp = first; // Reuse temp variable here
 while (temp != NULL && temp -> data != givenData) {
 temp = temp -> next;
 }
 if (temp == NULL) {
 printf("Given node not found in the list.\n");
 } else {
 insertAfterNode(temp, x);
 }
 break;
 case 4:
 if (first == NULL) {
 printf("Single Linked List is empty so deletion is not possible\n");
 } else {
 first = deleteAtBegin(first);
 }
 break;
 case 5:
 if (first == NULL) {
 printf("Single Linked List is empty so deletion is not possible\n");
 } else {

    first = deleteAtEnd(first);
 }

break;
 case 6:
 printf("Enter the data of the given node: ");
 scanf("%d", & givenData);
 temp = first; // Reuse temp variable here
 while (temp != NULL && temp -> data != givenData) {
 temp = temp -> next;
 }
 if (temp == NULL) {
 printf("Given node not found in the list.\n");
 } else {
 deleteAfterNode(temp);
 }
 break;
 case 7:
 if (first == NULL) {
 printf("Single Linked List is empty so deletion is not possible\n");
 } else {
 printf("Enter position: ");
 scanf("%d", & pos);
 first = deleteAtPosition(first, pos);
 }
 break;
 case 8:
 if (first == NULL) {
 printf("Single Linked List is empty\n");
 } else {
 printf("The elements in SLL are: ");
 traverseList(first);
 }
 break;
 case 9:
 exit(0);
 }
 }
}
