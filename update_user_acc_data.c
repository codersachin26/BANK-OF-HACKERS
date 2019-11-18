#include <stdio.h>
#include <stdlib.h>
#include<string.h>






 typedef struct  //this structure contained user related data
{
 char first_name[15];
 char Last_name[10];

 int age;
 char address[20];
 int mo_no;
 char E_mail_id[20];
 int national_id;
 char relationship[10];
 char gender[7];

}user_update_data;


void update_user_acc() // user define function for user data update
{

   user_update_data user_data; // user_data object
   char Enter_acc_no[10]; // account no. as string
   int Enter_acc;  // account as int
   char Enter_name[10]; // user name
    char Enter_series_no[3];  // user choice
    int series_no; // valid choice.
   int count=0; // indexing no.
   int index=0;


  system("cls");  // clear console


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


    printf("\n\n HERE YOU CAN UPDATE YOUR ACCOUNT DETAILS\n ");

      while(1)  // checking Enter account no. int or not
    {


    printf("\n ENTER YOUR ACCOUNT NUMBER\n \t\t\t ACC NO.: ");
    gets(Enter_acc_no); // take account no.
    for(count;Enter_acc_no[count];count++); // count digits


           while(1)
            {
                if(Enter_acc_no[index]>=48&&Enter_acc_no[index]<=58)
                    index++;
                else
                    break;
            }




    if(count==0)  // user not Enter something
    {
            printf("\n\n you are not Enter anything\n try again\n\n Hit any key ");
            getch();
            continue;
    }
    else
       if(index<8) // invalid acc
       {
           printf("\n you are Enter wrong Account number\ntry Again\n");
           continue;
       }
       else
        if(index==8) // correct acc
       {
           sscanf(Enter_acc_no,"%d",&Enter_acc); // convert char to int
           break;
       }
  }



      FILE *p;
     p=fopen("users_log_in.txt","r"); // open users log in file
    if(p==NULL)
        printf("\n file not Exits");


         int validate_acc; // for validate user
         char validate_pass[15];
         char user_name[10];

        while(1) // checking in users log in file ,user Exists or not
        {

         fscanf(p,"\n%d\t\t%s\t\t%s\n",&validate_acc,&validate_pass,&user_name);//  extract data from file


         if(Enter_acc==validate_acc) // check Enter acc to valid user acc
         {
            printf("\n\n\t\t your account ready for updating your data\n ");
             break;
         }
         else
            if(feof(p)) // empty file
         {
             printf("\n\t\t you are Enter account number didn't match in database\n check it!your account number");
                printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
                getch();
                 main();
                 break;
         }
        }

    printf("\n ENTER YOUR NAME\nonly capital letter \n\n \t\t\t NAME: ");



     int enter_count=0; // attempt time

    while(1)  // check user name related to acc name or not
    {

    gets(Enter_name); // take name

    if(!strcmp(Enter_name,user_name)) // check Enter name or actual user name
        break;
    else
        if(2==enter_count) // only 2 time attempt
        {
            printf("\n you are Entered wrong user log in data\n Hit any key if you want to go MAIN MENU");
            getch();
             main();
        }
         else
         {
              printf("\n you enter wrong name\nonly capital letter\ntry again!\n\n \t\t\t NAME>> ");
              enter_count++;
              continue; // continue until 2 time attempt
         }
    }




    while(1)
    {

        update_userdata_interface();
         fflush(stdin);
        gets(Enter_series_no);

        for(index=0;Enter_series_no[index];index++);

        if(index==0)
        {
            printf("\n\n you are not Enter anything\n try again\n\n Hit any key ");
            getch();
            continue;
        }
        else
            if(index>=2)
        {
            printf("\n you are Enter wrong choice try again\n\n Hit any key ");
            getch();
            continue;
        }
        if(index==1)
        {
            sscanf(Enter_series_no,"%d",&series_no);
            break;

        }
        else
           {
                printf("\n you are Enter wrong choice try again\n\n Hit any key ");
                getch();
                 continue;
           }

    }


      char user_profile_file_name[25]; // store user file path
      char user_acc[10];
      itoa(validate_acc,user_acc,10);
      strcpy(user_profile_file_name,user_acc); // mk user profile.txt file path
      strcat(user_profile_file_name,"\\profile.txt");

    p=fopen(user_profile_file_name,"r");
    if(p==NULL)
        printf("\n file not Exits");
    fscanf(p,"%s \n %s \n %d \n %s \n %d \n %s \n %d \n %s \n %s ",&user_data.first_name,&user_data.Last_name,&user_data.age,&user_data.address,&user_data.mo_no,&user_data.E_mail_id,&user_data.national_id,&user_data.gender,&user_data.relationship);
    fclose(p);

/////////////////////////////////////////////
////////////////////////////////////////////


    switch(series_no)
    {

    case 1:

           system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

        char new_updated_name[10];
         fflush(stdin);
        printf("\n your name:%s",user_data.first_name);
        printf("\n Enter updated first name\n\n \t\t ENTER NEW FIRST NAME: ");

         int ok=1;
         while(ok)
         {
                        ok=valid_input_name(&user_data.first_name);
         }
        printf("\n\n your name successfully updated!");
        printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
        getch();

        break;




    case 2:


           system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

        char new_updated_last_name[10];
        printf("\n your name:%s",user_data.Last_name);
        printf("\n Enter updated last name\n\n \t\t ENTER NEW LAST NAME: ");
        fflush(stdin);
        ok=1;
         while(ok)
       {
         ok=valid_input_name(&user_data.Last_name);   // this function take only capital letter input
       }


         printf("\n\n your last name has been successfully updated!");
          printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
          getch();

        break;


    case 3:


          system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

        printf("\n your current Age:%d",user_data.age);
        printf("\n Enter updated Age\n\n \t\t ENTER AGE: ");
        fflush(stdin);
        user_data.age=intonly_age();
        printf("\n your Age has been successfully updated! ");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();

        break;


    case 4:


        system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

        char new_updated_address[25];
        printf("\n your current Address: %s",user_data.address);
        printf("\n Enter new updated address\n\n\t\t ENTER ADDRESS: ");
        fflush(stdin);
            ok=1;
          while(ok)
          {
               ok=valid_address(&user_data.address);  // this function take only capital letter input
           }

        printf("\n your Address has been successfully updated! ");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();

        break;


    case 5:


       system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");
        int new_updated_mo_no;
        printf("\n your current mobile number: %d",user_data.mo_no);
        printf("\n Enter new updated mobile number\n\n\t\t ENTER MOBILE NUMBER: ");
        fflush(stdin);
        user_data.mo_no=intonly_mo_no();

        printf("\n your Mobile number has been successfully updated! ");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();

        break;


    case 6:

       system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");


         char new_updated_Email[20];
        printf("\n your current E-mail: %s",user_data.E_mail_id);
        printf("\n Enter new updated Email ID\n\n\t\t ENTER E-mail ID: ");
        fflush(stdin);
            ok=1;
          while(ok)
           {
                ok=valid_Email_id(&user_data.E_mail_id); // this function take valid input E-mail ID
           }

        printf("\n your E-mail ID has been successfully updated! ");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();


        break;


    case 7:


       system("cls");


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");
        char new_updated_relationship_status[10];
        int select_relationship_status;


        printf("\n your current Relationship Status: %s",user_data.relationship);
        fflush(stdin);
        printf("\n Enter new updated relationship status\n\n\t\t SELECT RELSTIONSHIP STATUS\n1-> SINGLE\n2->MARRIED\nENTER: ");
         ok=1;
         while(ok)
        {
           ok=input_relationship_status(&user_data.relationship); // this function take only 2 choices value // 1- single // 2- married
         }
        printf("\n your Relationship status has been successfully updated! ");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();
        break;



    default:
        printf("\n you entered wrong number! check it\n");
         printf("\n\n\n\n press any key if you want to go MAIN MENU\n");
         getch();
        main();
        break;



    }


    printf("\n%s",user_data.first_name);

    p=fopen(user_profile_file_name,"w");
    if(p==NULL)
        printf("\n file not create");


    fprintf(p,"%s \n %s \n %d \n %s \n %d \n %s \n %d \n %s \n %s ",user_data.first_name,user_data.Last_name,user_data.age,user_data.address,user_data.mo_no,user_data.E_mail_id,user_data.national_id,user_data.gender,user_data.relationship);

    fclose(p);

    main();

}




void update_userdata_interface()
{


     system("cls");  // clear console


      printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

       printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");



    printf("\n WHAT DO YOU WANT TO UPDATE IN YOUR ACCOUNT?\n");  // update menu for user
    printf("\n 1-> FIRST NAME\n 2-> LAST NAME\n 3-> AGE\n 4-> ADDRESS\n 5-> MOBAILE NUMBER\n 6-> E-mail ID\n 7-> RELATIONSHIP\n");
    printf("\n Enter a no. according series\n\n \t\t\t ENTER: ");


}
