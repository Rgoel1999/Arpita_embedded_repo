#include "my_libraries.h"
#include "std_libs.h"
void Reload_traindata(train_dtls *head_train)
{
      if(head_train == NULL)
        return;
      train_dtls *temp = head_train;
      FILE *fp;
      fp = fopen("train_details.txt","w+");
      
      if(fp!=NULL)
      {
            printf("Train Details File opened successfully\n");
            while(temp!=NULL)
            {
                  
                  fprintf(fp,"%s,%d,%s,%s,%d,%d\n",temp->name
                                                ,temp->train_no
                                                ,temp->start_place
                                                ,temp->destination
                                                ,temp->capacity
                                                ,temp->booked
                                                );
                  temp = temp->next;
            }
             fclose(fp);
      }
      else
            printf("Train Details file Not saved\n");
      
      return;
}