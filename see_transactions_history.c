#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trans_his  // this structure made for user transactions data
{
    char trans_stut[7]; // store trans_status //send or receive
    int amt;  // amount bal
    int ac_n; // account no
    int date; // transaction time
};

void transactions_history(char u_acc_no[7],char user_name[10]) // user define function which take 2 arguments
{                                                               // 1- user account number
                                                                 //2- user name

   system("cls"); // clear console

  printf("  \n\n\t\t\t\t       ..............WELCOME TO BANK OF HACKERS............ \n");

   printf("\n\n  \t\t\t\t                  ......$$$$$MONEY$$$$$......   \n\n");

   printf("\n\n\n ACCOUNT HOLDER NAME:%s",user_name);  // print acc holder name

   FILE *p;  // create file type pointer
   struct trans_his u_trans_his; // create object for store user transaction data
    char f_name [25]; // store user all_transactions.txt file path

    int dd,mm,yy; // store date
    int hh,mins;    // time
    int filedata;

    strcpy(f_name,u_acc_no); // make file path
    strcat(f_name,"\\all transactions.txt");
    p=fopen(f_name,"r"); // open file in read mode
    if(p==NULL)
        printf("file not exist");

          printf(" \n\n  ALL TRANSACTIONS \n\n ");
          printf(" \n \t  DEBIT/CREDIT  \t\t AMOUNT \t\t AC_NO \t\t         DATE       \t\t \n");


          int count=0; // for checking transactions history have or not

        while(1)
        {
                             // fetch all user transactions data from all transactions.txt file
            filedata=fscanf(p,"\n\t%s\t\t%d\t\t%d\t\t\t%d/%d/%d\t\t%d:%d\n",&u_trans_his.trans_stut,&u_trans_his.amt,&u_trans_his.ac_n,&dd,&mm,&yy,&hh,&mins);


                  if(filedata>=8)
                  {
                        printf(" \n \t      %s        \t\t  %d     \t\t  %d   \t\t  %d/%d/%d  %d:%d \t\t ",u_trans_his.trans_stut,u_trans_his.amt,u_trans_his.ac_n,dd,mm,yy,hh,mins);
                         // print all transaction on console
                         count++;
                  }





             if(feof(p)) // check file empty or not
               {

                   if(count==0) // check count value change or not
                    printf("\n\n you have not any transactions History");
                     if(count>=1)
                        printf("\n\n this is your all transactions history");

                    break; // if empty then stop
               }

        }

        fclose(p);

    printf("\n\n\n\n\n press Enter key if you want to go back "); // this instruction for user to go to user_menu
       if(getch()==13)
          user_menu(u_acc_no,user_name);
          else
            main(); // main menu

}
