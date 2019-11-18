#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void see_amt_bal(char u_name[10],char user_name[25]) // this function show user total amount balance
{

    system("cls");

  printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");



     printf("\nACCOUNT HOLDER NAME: %s",user_name); // print Account holder name


    int u_amt; // store user amount bal


     char amt_file[25]; // store user amount file path
        strcpy(amt_file,u_name); // make file path
        strcat(amt_file,"\\amount.txt");

         FILE *p; // create file type pointer

    p=fopen(amt_file,"r"); // open file
    if(p==NULL)
        printf("\namount file not exits");

    fscanf(p,"%d",&u_amt); // extract amount from file

    fclose(p); // close file

      printf("\n\n\n\n\t\t your current amount balance\n");
     printf("\n\n\t\t\t\t\t AMOUNT:$ %d",u_amt); // show user amount bal


     printf("\n\n\n\n press any key if you want to go USER MENU");
     getch();

      user_menu(u_name,user_name); // call user menu function

}
