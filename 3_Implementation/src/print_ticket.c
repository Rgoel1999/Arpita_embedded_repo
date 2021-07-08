#include "my_libraries.h"
#include "std_libs.h"
void print_Ticket(usr_dtls* temp_usr,train_dtls* head_train){
      
      train_dtls* temp = head_train;
      if(temp_usr == NULL)
            return;
      if(head_train == NULL)
            return;
      if(temp_usr->status == 0)
      {     
            printf("no tickets found");
            return;
      }  
      while(temp!=NULL){
            if(temp_usr->train_no == temp->train_no)
                  break;
            temp = temp->next;
      }
      
      printf("\t\tBerhampur Railways\n");
      printf("-----------------------------------------------------------------------\n");
      printf("PNR\tTrain Name\tTrain No\tSource\tDestination\tCapacity\n");
      printf("%d\t%-15s\t%-15d\t%s\t%s\t\t%d\n",temp_usr->PNR
                                                ,temp->name
                                                ,temp->train_no
                                                ,temp->start_place
                                                ,temp->destination
                                                ,temp_usr->no_of_seats
                                             );
}