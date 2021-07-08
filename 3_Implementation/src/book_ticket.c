#include "my_libraries.h"
#include "std_libs.h"
void book_ticket(usr_dtls *temp_usr,train_dtls *head_train)
{
      train_dtls* temp_train = NULL;
      int train_no =0, flag =0,no_tickets=0;
      printTrain(head_train);
      printf("Enter train no");
      scanf("%d",&train_no);
      if(head_train == NULL)
            return;
      
            temp_train = head_train;
            while(temp_train!=NULL)
            {
                  if(temp_train->train_no == train_no)
                        {
                              flag =1;
                              break;
                        }
                  temp_train = temp_train->next;
            }
            if(flag)
            {
                  printf("no of seats available = %d\n",temp_train->capacity - temp_train->booked);
                  printf("no of tickets to be booked\n");
                  scanf("%d",&no_tickets);
                  if(no_tickets<=(temp_train->capacity - temp_train->booked))
                  {
                        printf("Congratulations!! Your ticket is booked.\n");
                        temp_usr->PNR = temp_train->train_no +3000;
                        temp_usr->train_no = temp_train->train_no;
                        temp_usr->no_of_seats = no_tickets;
                        temp_train->booked = temp_train->booked+ no_tickets;
                        temp_usr->status =1;
                  }
                  else
                  {
                        printf("Sorry!! Your ticket is not booked.\n");
                  }

            }
            else
            {
                  printf("Wrong train no.\n");
                  return;
            }
}