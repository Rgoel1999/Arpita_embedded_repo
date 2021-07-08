#include "my_libraries.h"
#include "std_libs.h"
usr_dtls* load_userdata(usr_dtls *head_usr)
{
      usr_dtls *temp = NULL;

      FILE *fp;
      fp = fopen("user_details.txt","r");
      
      if(fp!=NULL)
      {
            printf(" User details File opened successfully\n");
            while(!feof(fp))
            {
                  usr_dtls *new_node = NULL;
                  new_node= (usr_dtls*)malloc(sizeof(usr_dtls));
				  strcpy(new_node->password,"");
				  strcpy(new_node->username,"");
				  
                  fscanf(fp,"%[^,],%[^,],%d,%d,%d,%d\n",new_node->username,new_node->password,&new_node->PNR,&new_node->train_no,&new_node->no_of_seats,&new_node->status);
                  new_node->next = NULL;

                  if(head_usr==NULL)
                  {
                        head_usr = (usr_dtls*)malloc(sizeof(usr_dtls));
                        head_usr = new_node;
                  }
                  else
                  {
                        temp = head_usr;
                        while(temp->next!=NULL)
                              temp =temp->next;
                        temp->next= new_node;   
                  }     
            }
             fclose(fp);
      }
      else
            printf(" User details file Not open\n");
      
      return head_usr;
}