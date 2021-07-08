#include "my_libraries.h"
#include "std_libs.h"
usr_dtls* new_user_signup(usr_dtls *head_usr)
{
      char str[100]="",pswd[100]="";usr_dtls *temp;
      int upr_case=0, lwr_case=0,digit=0, spl_char=0;
      int PNR =0,train_no =0,no_of_seats =0,status =0;
    printf("Enter valid username\n");
    scanf("%s",str);

    if(str[0]!='\0')
    {
    
      printf("Enter valid password\n");
      printf("Password must contain at max 10 characters with atleast :\n 1 uppercase Character \n 1 lower case character \n 1 digit \n 1 special character (@,$)\n");
      scanf("%s",pswd);
      if(strlen(pswd)<=10 && pswd[0]!='\0')
      {
            for (int i= 0; i < strlen(pswd); i++) 
            {
                  if (pswd[i] >= 'a' && pswd[i] <= 'z')
                        lwr_case++;
                  if (pswd[i] >= 'A' && pswd[i] <= 'Z')
                        upr_case++; 
                  if (pswd[i] >= '0' &&  pswd[i] <= '9') 
                        digit++;
                  if (pswd[i] == '@' ||  pswd[i] == '$')
                        spl_char++;
            }

            if(lwr_case >0 && upr_case >0 && digit >0 && spl_char >0)
                  printf("You have signed up successfully\n");

            else
            {
                  printf(" Invalid  password\n");
                  return head_usr;
            }
      }
      }
      else
           { 
                 printf ("Enter valid username\n");
                  return head_usr;
           }
FILE *fp;
fp = fopen("user_details.txt","a+");
fprintf(fp,"%s,%s,%d,%d,%d,%d\n",str,pswd,PNR,train_no,no_of_seats,status);
fclose(fp);

usr_dtls *new_node = NULL;
new_node= (usr_dtls*)malloc(sizeof(usr_dtls));
new_node->next= NULL;

strcpy(new_node->username,str);
strcpy(new_node->password,pswd);
new_node->PNR = PNR;
new_node->train_no = train_no;
new_node->no_of_seats = no_of_seats;
new_node->status =status;
if(head_usr==NULL)
{
      head_usr= (usr_dtls*)malloc(sizeof(usr_dtls));
        head_usr= new_node;
}
else
 {
      temp = head_usr;
      while(temp->next!=NULL)
            temp = temp->next;

      temp->next = new_node;   
 }       
return head_usr;
}

int user_login(usr_dtls *head_usr,train_dtls *head_train)
{
      usr_dtls *temp_usr = NULL; 
      char usr_name[100]="",pwd[100]="";
      printf("Enter valid username\n");
      scanf("%s",usr_name);

    if(usr_name[0]!='\0')
    {
          printf("Enter valid password\n");
          scanf("%s",pwd);
    }
    else
      return 0;

      if(head_usr==NULL)
            return 0;
      
      temp_usr = head_usr;
    while(temp_usr!=NULL)
      {
            
            if(strcmp(temp_usr->username,usr_name)==0 && strcmp(temp_usr->password,pwd)==0)
                  {
                        printf("Logged In Successfully\n");
                        user(temp_usr,head_train);
                        return 1;
                  }
           
            temp_usr = temp_usr->next;
      }
      return 0;
}

void user(usr_dtls* temp_usr, train_dtls* head_train)
{
      int choice;
      printf("\t \tWelcome to Berhampur Railways\n");
      printf("1. Book Ticket\n2. Cancel Ticket\n3. View Train Details\n4. Print My Ticket\n");
      printf("Enter choice\n");
      scanf("%d",&choice);

      switch(choice)
      {
            case 1:
                  book_ticket(temp_usr,head_train);
            break;

            case 2:
                  cancel_ticket(temp_usr,head_train);
            break;

            case 3:
                  printTrain(head_train);
            break;
            case 4:
                  print_Ticket(temp_usr,head_train);
      }

}