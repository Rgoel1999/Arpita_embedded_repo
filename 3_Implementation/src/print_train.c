#include "my_libraries.h"
#include "std_libs.h"
void printTrain(train_dtls* head){
      if(head == NULL)
            return;
      train_dtls* temp = head;

      printf("Train Name\tTrain No\tSource\tDestination\tCapacity\tAvailiable\n");
      while(temp!=NULL){
            
            printf("%-15s\t%-15d\t%s\t%s\t\t%d\t\t%d\n",temp->name
                                                ,temp->train_no
                                                ,temp->start_place
                                                ,temp->destination
                                                ,temp->capacity
                                                ,(temp->capacity - temp->booked)
                                             );
      
            temp = temp->next;
      }
}