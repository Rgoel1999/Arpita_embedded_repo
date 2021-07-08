#include "my_libraries.h"
#include "std_libs.h"
train_dtls* load_traindata(train_dtls *head_train)
{
      train_dtls *temp = NULL;

      FILE *fp;
      fp = fopen("train_details.txt","r");
      
      if(fp!=NULL)
      {
            printf("Train Details File opened successfully\n");
            while(!feof(fp))
            {
                  train_dtls *new_node = NULL;
                  new_node= (train_dtls*)malloc(sizeof(train_dtls));
				  
                  fscanf(fp,"%[^,],%d,%[^,],%[^,],%d,%d\n",new_node->name,&new_node->train_no,new_node->start_place,new_node->destination,&new_node->capacity,&new_node->booked);
                  new_node->next = NULL;

                  if(head_train==NULL)
                  {
                        head_train = (train_dtls*)malloc(sizeof(train_dtls));
                        head_train = new_node;
                  }
                  else
                  {
                        temp = head_train;
                        while(temp->next!=NULL)
                              temp =temp->next;
                        temp->next= new_node;   
                  }     
            }
             fclose(fp);
      }
      else
            printf("Train Details file Not open\n");
      
      return head_train;
}