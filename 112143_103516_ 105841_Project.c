                                  // Student 1 ID : 112143
                                  // Student 2 ID : 103516   
                                  // Student 3 ID : 105841
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
  void LogIn();
  void SignIn();
  void encryp_Decrypt(char pass[]);
  void data();
  void Application(char *fn,char *ln,int age);
  void LogOut();
  void password_checker(char *b,char *z);
  void change_data();

  int age_calculator(char *a);
  int menu();

  bool verify_pass(char pass[]);

  //Creating the file
    FILE * DATABASE;
    FILE * output;

int main() 
{
  int choice=0;
  data();
  choice = menu();
    switch(choice)
      {
        case 1:
          LogIn();
        break;
        case 2:
          SignIn();
        break;
      }
  return 0;
}

int menu()
{
  int choice=0;
  do
  {
            printf("\n\n\n\n\nWelcome to our application\n");
            printf("1.Log In\n2.Sign In.\nEnter what you want:\n");
            scanf("%d",&choice);
  }while(choice!=1 && choice!=2);
  return choice;
}

void LogIn()
{
  char usernames[100][5000],firstnames[100][5000],lastnames[100][5000],birthdays[100][5000],passwords[100][5000];//variables for the file
  char username[100],firstname[100],lastname[100],birthday[100],password[100];//variables for the input
  int usernames_checker=0,b=0,a=0;
  char string1[100],string2[100];

      data();
    printf("\n\nEnter your username:\n");
    scanf("%s",username);//getting username
                  //open the file with the option of w (write only)
                  DATABASE = fopen("database.txt", "r");
  for(int i=0;i<4;i++)
    {
            //getting all the data from the file
            fscanf(DATABASE,"%s%s%s%s%s",usernames[i],firstnames[i],lastnames[i],birthdays[i],passwords[i]);
    }
  for(int j=0;j<4;j++)
    {
      //checking if the username exist in the file
      if(strcmp(usernames[j],username)==0)
        {
          printf("Good!\nEnter your password:\n");
          scanf("%s",password);
          password_checker(password,&a);
          a=1;
          break;
        }
    }
  if(a!=1)
    {
      for(int j=0;j<4;j++)
        {
            //checking if the username exist in the file
            int flag=0;
              strcpy(string1,usernames[j]);
              strcpy(string2,username);
            if(strlen(string1)==strlen(string2))
              {
                for(int y=0;y<strlen(string1);y++)
                  {
                    for(int z=0;z<strlen(string2);z++)
                      {
                        if(string1[z]==string2[y])
                          flag++;
                      }
                    if(strlen(string1)*0.8<=(flag))
                      {
                          printf("You are almost right in all the characters.\nEnter your password:\n");
                          scanf("%s",password);
                          password_checker(password,&a);
                          break;
                      }
                  }
              }
          }
    }
    if(b==0 && a==0)
      {
        printf("The username is wrong.\nRe-enter the name\n");
        LogIn();
      }
}

void data()
{
  //open the file with the option of w (write only)
   DATABASE = fopen("database.txt", "w+");
  //entering all the account 
   fprintf(DATABASE, "kad_145 kaddour kaddouri 21mar2001 d14f1%c-lDFS$\n",'%');
   fprintf(DATABASE, "mohammed mohammed alami	12apr1997 dfg147SDF}[-\n");
   fprintf(DATABASE, "koriXO karim alaoui	03sep1974 df56)&DDsG2!\n");
   fprintf(DATABASE, "samirez	samira morchid 30may1984 14KJHmma_?!8\n");
  //closing the file
   fclose(DATABASE);
}
void Application(char *fn,char *ln,int age)
{
  int choice=0;
  printf("\n\nWelcome to the main page.");
  printf("\nHello %s %s\nYour age is %d",fn,ln,age);
  printf("\nFor changing the username or password click 1,or For logging out click 2: ");
  while(choice!=1 && choice !=2){
  scanf("%d",&choice);
  if(choice==1)
    change_data();
  else if(choice==2)
    LogOut();
  }
}
void password_checker(char *b,char *z)
{
  char usernames[100][5000],firstnames[100][5000],lastnames[100][5000],birthdays[100][5000],passwords[100][5000];//variables for the file
  char username[100],firstname[100],lastname[100],birthday[100],password[100];//variables for the input
  int age;
  //open the file with the option of r (read only)
   DATABASE = fopen("database.txt", "r");
  for(int i=0;i<4;i++)
  {
    //getting all the data from the file
fscanf(DATABASE,"%s%s%s%s%s",usernames[i],firstnames[i],lastnames[i],birthdays[i],passwords[i]);
  }
        for(int j=0;j<4;j++)
              {
                    if(strcmp(passwords[j],b)==0)
                    {
                      age = age_calculator(birthdays[j]);
                      Application(firstnames[j],lastnames[j],age);
                      *z=1;
                      break;
                    }
                    if(j==3)
                    {
                      printf("The password is wrong.\nRe-enter the name\n");
                      LogIn();
                    }
              }
  //closing the file
   fclose(DATABASE);
}
int age_calculator(char *a)
{
  int age;
  char stringday[]={a[0],a[1],'\0'};
  char month[]={a[2],a[3],a[4],'\0'};
  char stringyear[]={a[5],a[6],a[7],a[8],'\0'};
  int day;
  int year; 
  day = atoi (stringday);
  year = atoi (stringyear);
  age = 2022 - year;
  return age;
}

void SignIn()
{
    char Fname[10],Sname[10],birth[10],pass[12],Username[10];
          DATABASE = fopen("database.txt","a");
    printf("\nEnter an username : ");
      scanf("%s",Username);
    printf("\nEnter your first name : ");
      scanf("%s",Fname);
    printf("\nEnter your last name : ");
      scanf("%s",Sname);
    printf("\nEnter your birthday date : ");
      scanf("%s",birth);
    printf("\nFor safety concerns the password must contain 12 characters that must include 3 lowercase letters, 3 uppercase letters, 3 digits, and three other characters that are not digits and not letters");
    printf("\nEnter a password that respect our safety concerns\n");
      scanf("%s",pass);
  bool result = verify_pass(pass);
if(result)
  {
    printf("Your password is accepted");
      encryp_Decrypt(pass);//Encrepted password
    printf("\nYour password encrypted is %s",pass);
      encryp_Decrypt(pass);//decrepted password
    printf("\nYour password decrypted is %s",pass);
  }
else
  printf("\n Your password must satisfy our password policy ");

    fprintf (DATABASE,"%s %s %s %s %s",Username,Fname,Sname,birth,pass);
    fclose(DATABASE);
}

void LogOut()
{
  int min_age,age;

  output=fopen("output.txt","w");
  DATABASE=fopen("database.txt","r");
  
  char usernames[100][5000],firstnames[100][5000],lastnames[100][5000],birthdays[100][5000],passwords[100][5000];
  char COPIE_usernames[100],COPIE_firstnames[100],COPIE_lastnames[100],COPIE_birthdays[100],COPIE_passwords[100];
  char username[100],firstname[100],lastname[100],birthday[100],password[100];
  
  for(int i=0;i<4;i++)
    {
  fscanf(DATABASE,"%s%s%s%s%s",usernames[i],firstnames[i],lastnames[i],birthdays[i],passwords[i]);
    }
  
      
  for(int z=0;z<4;z++)
    {
    min_age = age_calculator(birthdays[z]);
      for(int j=0;j<4;j++)
        {
          age = age_calculator(birthdays[j]);
          if(age<min_age)
            {
            strcpy(COPIE_usernames,usernames[j]);
            strcpy(COPIE_firstnames,firstnames[j]);
            strcpy(COPIE_lastnames,lastnames[j]);
            strcpy(COPIE_birthdays,birthdays[j]);
            strcpy(COPIE_passwords,passwords[j]);
              
            strcpy(usernames[j],usernames[z]);
            strcpy(firstnames[j],firstnames[z]);
            strcpy(lastnames[j],lastnames[z]);
            strcpy(birthdays[j],birthdays[z]);
            strcpy(passwords[j],passwords[z]);
              
            strcpy(usernames[z],COPIE_usernames);
            strcpy(firstnames[z],COPIE_firstnames);
            strcpy(lastnames[z],COPIE_lastnames);
            strcpy(birthdays[z],COPIE_birthdays);
            strcpy(passwords[z],COPIE_passwords);
            }
          
        }
    }
  for(int i=0;i<4;i++)
   {
       fprintf(output, "%s %s %s %s %s\n",usernames[i],firstnames[i],lastnames[i],birthdays[i],passwords[i]);
       printf("%s %s %s %s %s\n",usernames[i],firstnames[i],lastnames[i],birthdays[i],passwords[i]);
   }
  
  fclose(DATABASE);
  fclose(output);
  main();
}
void change_data()
{
  int choice;
  char usernames[100][5000],firstnames[100][5000],lastnames[100][5000],birthdays[100][5000],passwords[100][5000];
  char username[100],firstname[100],lastname[100],birthday[100],password[100];

    //open the file with the option of w (write only)
      DATABASE = fopen("database.txt", "w+");
  printf("Do you want to change username(enter 1) or password(enter 2)? ");
  scanf("%d",&choice);
  if(choice == 1)
    {
      
    }
  else if(choice ==2)
    {
      
    }
  else 
    {
      
    }
//closing the file
   fclose(DATABASE);
}
// Function to verify the password
bool verify_pass(char pass[])
{
    int lenght = strlen(pass);
    int a=0,b=0,c=0,d=0;
      bool upper = false;
      bool lower = false;
      bool digit = false;
      bool symbol = false;
   if(lenght!=12)
      return false;
   else
    {
      for(int i=0;i<lenght;i++)
        {
            if(isupper(pass[i])) 
            {
              upper=true;
              a+=1;
            }
            if(islower(pass[i]))
            {
              lower=true;
              b+=1;
            }
            if(isdigit(pass[i]))
            {
              digit=true;
              c+=1;
            }
            if(ispunct(pass[i])) 
            {
              symbol=true;
              d+=1;
            }
        }
      if(a!=3) 
        return false;
      if(b!=3)
        return false;
      if(c!=3)
        return false;
      if(d!=3)
        return false;
      if(!upper) 
        return false;
      if(!lower) 
        return false;
      if(!digit) 
        return false;
      if(!symbol) 
        return false;

      return true; 
    }
}
// Function to encrypte and decrypte the password
void encryp_Decrypt(char pass[])
{
    int temp;
    int length = strlen(pass);
    for (int i = 0; i < length; i += 2) 
      {
        temp = pass[i];
        pass[i] = pass[i + 1];
        pass[i + 1] = temp;
      }
}
