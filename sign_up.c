#include<stdio.h>
#include<stdlib.h>



void sign_up(int user_acc_no,char user_name[10])
{

   system("cls");  // clear console screen

     printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

           printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


   printf("\n PART-2\n"); // this is 2nd part for user registration

   printf("\n\n part-2 Registrations for log in into your Bank Account\n");
    printf(" \n REGISTRATE YOUR PASSWORD FOR LOG IN YOUR BANK Account\n ");

    char pas_word[9];        // first Enter password
    char re_pas_word[9];     // Re-Enter password
    char validate_password[9];   // first and Re-Enter password are same then validate_password variable store Re-Enter password
    int pin;            //  user pin
    int re_pin;           // Re-Enter user pin

    int validate; // store password validation
    int count=0;


    printf("\n ENTER YOUR PASSWORD\n \t\t\t PASSWORD: "); // take to user password
    fflush(stdin);

     while(1)
        {
            fflush(stdin);
             gets(pas_word);
            if(pas_word[count]==NULL)
            {
                printf("\n you are not Enter anything\ntry Again");
                printf("\n ENTER YOUR PASSWORD\n \t\t\t PASSWORD: ");
                continue;
            }
            else
                break;
        }

    printf(" \n RE-ENTER YOUR PASSWORD\n \t\t\t  RE-PASSWORD: ");  // take to user same password

   while(1)
   {

        while(1)
     {
            gets(re_pas_word);
            if(re_pas_word[count]==NULL)
            {
                printf("\n you are not Enter anything\ntry Again");
                printf(" \n RE-ENTER YOUR PASSWORD\n \t\t\t  RE-PASSWORD: ");
                continue;
            }
            else
                break;
        }
    validate=strcmp(pas_word,re_pas_word);   // both are same then strcmp() return o if  not then return 0>ASCII or 0<ASCII value
    if(validate==0)
        {
            printf("\n your password matched\n");    // if both password are same then validate_password store data from re_password
            strcpy(validate_password,re_pas_word);
            break;


        }


        else
       {

             printf("\n Enter password mismatch \n check it\n\n ");  // if password mismatch then this statement execute
             printf("\n press A if you want to go MAIN MENU \n and \npress any key if you try one Again\n");
             if(65==getch())
                main();
             else
             {
                printf("\n\n RE-PASSWORD: ");   // if password mismatch then this statement execute
                continue;
             }

       }
   }

  /////////////////////////////////
  /////////////////////////////////


       while(1)
       {


        printf("\n ENTER YOUR NEW PIN \nPIN: ");  // take user pin
         pin=input_valid_pin();



         count=0;

         printf("\n RE-ENTER PIN:  \n");  // take Re-pin for validation
              re_pin=input_valid_pin();


              if(pin==re_pin)
                    {

                        printf("\n your pin code match");
                        break;
                    }
             else
               {
                    printf("\n you pin code not match\ntry again\n");
                    continue;
               }

       }



      char user_pincode_file[30];  // this variable store pin code file path
     itoa(user_acc_no,user_pincode_file,10);  // convert int to char account number for opening user pin code file

     strcat(user_pincode_file,"\\user_pin.txt");

      FILE *p;


      p=fopen(user_pincode_file,"w");   // open user pin code file
      if(p==NULL)
            printf("\n user pincode file not create\n");

      fprintf(p,"%d",re_pin);  // save user pin into user pin code file
      fclose(p); // close user pin code file

      system("cls");  // clear console


           printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

           printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


      printf("\n\n\t\t Hurray ! you got $500 bonus Balance\n\n $500 has been successfully transfer into your account\n"); // user bonus
      int user_bonus=500;
      char user_amt_file[25];  // user amt file path container
      itoa(user_acc_no,user_amt_file,10); // converter int to char
      strcat(user_amt_file,"\\amount.txt");

      p=fopen(user_amt_file,"w"); // open user amt file
      if(p==NULL)
        printf("\n Amount file open\n");
      fprintf(p,"%d",user_bonus); // store user bonus into user amount file
      fclose(p);  // close file



       int user_acc_bal;        //  print user bonus amount on console
       p=fopen(user_amt_file,"r");
      if(p==NULL)
        printf("\n Amount file not open\n");
      fscanf(p,"%d",&user_acc_bal);
      fclose(p);
      printf("\n\n your current Account Balance\n\t\t\t\t\t ACCOUNT BALANCE:$%d",user_acc_bal);





    p=fopen("users_log_in.txt","a");  // open users log_in file for storing new user log_in credential into users log_in file
    if(p==NULL)
        printf(" \n users log in file not exits\n");

        fprintf(p,"\n%d\t\t%s\t\t%s\n",user_acc_no,validate_password,user_name); // store new user log_in credential data into file
        fclose(p);  // close file

         printf("\n\n\n\ncongratulation your bank account open \nRemember your account number carefully\n\n\n \t\t\t\t\t\t\t ACCOUNT NUMBER :%d ",user_acc_no);

       printf("\n\n\n\t\t\t\t your Bank Account successfully completed\n GO TO MAIN MENU\n and LOG IN ");
        printf("\n press any key if you want to go MAIN MENU");  // go to main menu
        getch();
        system("cls");
        main();




}
