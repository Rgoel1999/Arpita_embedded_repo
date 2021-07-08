#include "my_libraries.h"
#include "std_libs.h"
train_dtls* create_train(train_dtls *head_train)
{
      char name[100]="",start_place[100]="",destination[100]="";
      int train_no =0, capacity =0,booked =0;
      train_dtls *temp;

    printf("Enter valid trainname\n");
    scanf("%s",name);

    printf("Enter valid start_place\n");
      scanf("%s",start_place);

      printf("Enter valid Destination\n");
      scanf("%s",destination);

      printf("Enter Train no\n");
      scanf("%d",&train_no);

      printf("Enter Capacity\n");
      scanf("%d",&capacity);

FILE *fp;
fp = fopen("train_details.txt","a+");
fprintf(fp,"%s,%d,%s,%s,%d,%d\n",name,train_no,start_place,destination,capacity,booked);
fclose(fp);

train_dtls *new_node = NULL;
new_node= (train_dtls*)malloc(sizeof(train_dtls));
new_node->next= NULL;

strcpy(new_node->name,name);
strcpy(new_node->start_place,start_place);
strcpy(new_node->destination,destination);
new_node->train_no = train_no;
new_node->capacity = capacity;
new_node->booked =0;

if(head_train==NULL)
{
      head_train= (train_dtls*)malloc(sizeof(train_dtls));
        head_train= new_node;
}
else
 {
      temp = head_train;
      while(temp->next!=NULL)
            temp = temp->next;

      temp->next = new_node;   
 }       
return head_train;
}