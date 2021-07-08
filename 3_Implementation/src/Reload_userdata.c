#include "my_libraries.h"
#include "std_libs.h"
void Reload_userdata(usr_dtls *head_usr)
{
      usr_dtls *temp = head_usr;
      if(head_usr==NULL) 
        return;
      FILE *fp;
      fp = fopen("user_details.txt","w+");
      
      if(fp!=NULL)
      {
            printf(" User details File opened successfully\n");
            while(temp!=NULL)
            {
                  
                  
				  
                  fprintf(fp,"%s,%s,%d,%d,%d,%d\n",temp->username
                                                      ,temp->password
                                                      ,temp->PNR
                                                      ,temp->train_no
                                                      ,temp->no_of_seats
                                                      ,temp->status
                                                      );
                  

                  temp =temp->next;     
            }
             fclose(fp);
      }
      else
            printf(" User details file Not saved\n");
      
      return;
}