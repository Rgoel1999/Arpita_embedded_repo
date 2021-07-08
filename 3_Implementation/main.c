#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct users_details
{
      char username[100];
      char password[100];
      int PNR;
      int train_no;
      int no_of_seats;
      int status;
      struct users_details *next;
}usr_dtls;
typedef struct train_details
{
      char name[100];
      int train_no;
      char start_place[100];
      char destination[100];
      int capacity;
      int booked;
      struct train_details *next;
}train_dtls;

void user(usr_dtls*, train_dtls*);
train_dtls* admin(train_dtls*);
void book_ticket(usr_dtls*,train_dtls*);
void cancel_ticket(usr_dtls*,train_dtls*);
train_dtls* create_train(train_dtls*);
void printTrain(train_dtls*);
void print_Ticket(usr_dtls*,train_dtls*);

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
train_dtls* admin_login(train_dtls* head_train)
{
      char username[]="a",un[100];
      char password[]="s",pw[100];

      printf("Enter Admin username\n");
      scanf("%s",un);

      printf("Enter Admin password\n");
      scanf("%s",pw);

      if(strcmp(un,username)==0 && strcmp(pw,password)==0)
            {
                  printf("admin Logged In\n");
                  head_train= admin(head_train);
            }
      else
            printf("Enter proper username or password\n");
      return head_train;
}
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
train_dtls* admin(train_dtls* head_train)
{
     int ch;
      printf("\t \tWelcome to Berhampur Railways\n");
      printf("1. create Train \n2. View Trains\n");
      printf("Enter choice\n");
      scanf("%d",&ch);

      switch(ch)
      {
            case 1:
              head_train = create_train(head_train);
            break;

            case 2:
                  printTrain(head_train);

      }
      return head_train;
}
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
int main ()
{
      usr_dtls *head_usr = NULL;
      train_dtls *head_train = NULL; 
      int k;
      head_usr = load_userdata(head_usr);
      head_train = load_traindata(head_train);
      
      int ch;
      printf("\nEnter Choice\n");
      printf("1 New User Signup\n2 Admin Login\n3 User Login\n");
      scanf("%d",&ch);
      switch(ch)
      {
            case 1:
                  head_usr = new_user_signup(head_usr);
            break;

            case 2:
                  head_train = admin_login(head_train);
            break;

            case 3:
            {
                  k = user_login(head_usr,head_train);
                  if(k == 1)
                        printf("user logged in ");
                  else
                        printf("Username or password mismatch");
            }
            break;
      }

      Reload_traindata(head_train);
      Reload_userdata(head_usr);
     
      while(head_usr!=NULL){
            usr_dtls* temp = head_usr;
            head_usr=head_usr->next;
            free(temp);
      }

      while(head_train!=NULL){
            train_dtls* temp = head_train;
            head_train=head_train->next;
            free(temp);
      }
}