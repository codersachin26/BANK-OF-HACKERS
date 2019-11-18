#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>




 typedef struct
{
    char first_name[15];
    char last_name[10];     /* this is a structure for user
                                 registrations for store user data*/
    char gender[7];
    int dd,mm,yy;
    int age;
    char address[40];
    int mo_no;
    char E_mail_id[20];
    int national_id;
    char relationship[9];

}user_reg_data;

 void  user_registration_form()  // user define function for new users
{                                // its take all data related to a valid user from new user

     system("cls"); // clear console



   printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


       user_reg_data user_data; //create a object for storing new user data

         fflush(stdin); // it take fresh input from keyboard
                     // some time buffer not empty for user input and it took random data from buffer which is unpredictable
                      //so use it! before input


    printf("\n PART-1\n");  // this is 1st part for new user registration


    printf("\n 1. ENTER YOUR FIRST NAME");   // user first name
      int ok=1; // its sign for while statement
      while(ok)
        {
               printf("\n only capital letter\n>>FIRST NAME: ");
           ok=valid_input_name(&user_data.first_name);  // this function take only capital letter input
        }


    printf("\n 2. ENTER YOUR LAST NAME");
       ok=1;
      while(ok)
       {
            printf("\n only capital letter\n>>LAST NAME: ");
         ok=valid_input_name(&user_data.last_name);   // this function take only capital letter input
       }


    printf("\n 3. HOW OLD ARE YOU\n>>AGE: ");    // user AGE
    user_data.age=intonly_age(); // this function take only 2 digit int value
    fflush(stdin);


    printf("\n 4. ENTER YOUR ADDRESS");  // user Address
    printf("\n only capital letter\n>>ENTER ADDRESS: ");
     ok=1;
     while(ok)
     {
          ok=valid_address(&user_data.address);  // this function take only capital letter input
     }
    fflush(stdin);


    printf("\n 5. ENTER YOUR MOBILE NUMBER\n>>MOBILE NUMBER: "); // mobile number
    user_data.mo_no=intonly_mo_no(); // this function take only 9 digits int value
    fflush(stdin);


    printf("\n 6. ENTER YOUR E-MAIL ID\n>>Email-ID: "); //Email ID
    ok=1;
    while(ok)
    {
    ok=valid_Email_id(&user_data.E_mail_id); // this function take valid input E-mail ID
    }
    fflush(stdin);


    printf("\n 7. ENTER YOUR NATIONAL ID\n>>NATIONAL ID: "); // National ID
    user_data.national_id=valid_National_id(); // this function take only 6 digits int value
    fflush(stdin);


    printf("\n 8. ENTER YOUR GENDER\n\t1->MALE\n\t2->FEMALE\n\npress 1 if you male\nor\npress 2 if you female\n\n>>ENTER: ");   // gender
    ok=1;
         while(ok)
        {
        ok=valid_gender_input(&user_data.gender); // this function take only 2 choices value // 1- male // 2- female
        }
       fflush(stdin);


    printf("\n 9. ENTER YOUR RELATIONSHIP STATUS\n\t1->SINGLE\n\t2->MARRIED\n\npress 1 if you single \nor\n press 2 if you married\n\n ENTER: "); // Relationship
       ok=1;
       while(ok)
       {
           ok=input_relationship_status(&user_data.relationship); // this function take only 2 choices value // 1- single // 2- married
       }

    // end user registrations form PART-1



    char user_acc[10]; // this variable store user account number as string format for file opening
    int user_acc_no; // this variable store user account number as integer format for storing in users_log_in file


    user_acc_no=create_ac_no(); // this function generate new user account number

    itoa(user_acc_no,user_acc,10); // this function convert int to char format


    mkdir(user_acc,0777);   // open  directory with user account number name



      char f_name[25];    // store user profile file name

    strcpy(f_name,user_acc);
    strcat(f_name,"\\profile.txt");


    FILE *p;            // create FILE pointer
    p=fopen(f_name,"w"); // open file
    if(p==NULL)  // this statement true when fopen function not create file
        printf("\n file not create \n");
                                             // store user all data in profile file
    fprintf(p,"%s\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%s",user_data.first_name,user_data.last_name,user_data.age,user_data.address,user_data.mo_no,user_data.E_mail_id,user_data.national_id,user_data.gender,user_data.relationship);
    fclose(p);         // close file

      char user_acc_file[13];
      strcpy(user_acc_file,user_acc);
    strcpy(f_name,user_acc);
    strcat(f_name,"\\all transactions.txt"); // again open user another file called transactions file
     p=fopen(f_name,"w");
    if(p==NULL)
        printf("\n file not create \n");
        fclose(p); // close file





        char amt_file[30]; // store user amount file path

         strcpy(amt_file,user_acc_file);
        strcat(amt_file,"\\amount.txt");

     p=fopen(amt_file,"w");  //open amount file
    if(p==NULL)
        printf("\n AMOUNT file not create \n");

        int user_amt_bal=0; // default balance
        fprintf(p,"%d",user_amt_bal); // store balance in user amount file
        fclose(p);  // close amt file


        char user_pincode_file[30];    //  variable for  store pin code file path
        strcpy(user_pincode_file,user_acc_file);
        strcat(user_pincode_file,"\\user_pin.txt");

        p=fopen(user_pincode_file,"w");   // open pin code file
        if(p==NULL)
            printf("\n user pincode file not create");
        fclose(p); //  close file



      // part 2 for new user registration as a log_in

         sign_up(user_acc_no,user_data.first_name); // this is a sign up function for user account

                                // it take two arguments called user account number and user name



}
