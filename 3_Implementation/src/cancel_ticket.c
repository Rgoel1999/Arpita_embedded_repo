#include "my_libraries.h"
#include "std_libs.h"
void cancel_ticket(usr_dtls *temp_usr,train_dtls *head_train)
{
      train_dtls* temp_train = NULL;
      int flag =0,can_tickets=0;
      print_Ticket(temp_usr,head_train);
      printf("Enter no. of tickets to be cancelled");
      scanf("%d",&can_tickets);
      if(head_train == NULL)
            return;
      
            temp_train = head_train;
            while(temp_train!=NULL)
            {
                  if(temp_train->train_no == temp_usr->train_no)
                        {
                              flag =1;
                              break;
                        }
                  temp_train = temp_train->next;
            }
            if(flag)
            {
                  if(can_tickets >0 && can_tickets<=(temp_usr->no_of_seats))
                  {
                        printf("Your ticket is cancelled.\n");
                        temp_usr->no_of_seats = temp_usr->no_of_seats - can_tickets;
                        temp_train->booked = temp_train->booked - can_tickets;
                        if(temp_usr->no_of_seats == 0)
                        {
                              temp_usr->PNR = 0;
                              temp_usr->train_no = 0;
                              temp_usr->status =0;
                        }
                  }
                  else
                  {
                        printf("Sorry!! Your ticket is not cancelled.\n");
                  }

            }
}