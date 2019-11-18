#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>



struct mk_user_trans_his // store user transactions data
{
     char trans_status[6];
      int amt;
      int ac_n;


};

struct mk_reciver_trans_his  // store receiver transactions data
{

     char trans_status[9];
        int amt;
        int ac_n;

};


void mk_trans_his(char user_acc[10],char receiver_acc[10],int amt) // user define function which take 3 arguments
{                                                                   //  1- user account no.
                                                                    // 2- receiver account no.
                                                                    // 3- transactions amount

       int re_acc;  // store receiver acc no.
      int sender_acc;   // store user acc no.


    struct mk_user_trans_his u_trans_data; // create  object for user trans_his
    struct mk_reciver_trans_his re_trans_data; // create object for receiver trans_his


     SYSTEMTIME time;  // create time object
     GetSystemTime(&time); // store date_time in time object

     int day,month,year; // store date
     int hour,min;       // time

     day=time.wDay;  // assign all date_Time value in primitive data type
     month=time.wMonth;
     year=time.wYear;
     hour=time.wHour;
     min=time.wMinute;


   char u_file_name[25]; // store user all transactions file path
   char re_file_name[25];  // store receiver all transactions file path

    strcpy(u_file_name,user_acc); // make user all_transactions file path
    strcat(u_file_name,"\\all transactions.txt");

    FILE *p;  // create FILE pointer
    p=fopen(u_file_name,"a");   //  open all transactions file in append mode
    if(p==NULL)
        printf("\n All Transaction file not Exits");


        sscanf(user_acc,"%d",&sender_acc); //  convert user account no. char to int
        sscanf(receiver_acc,"%d",&re_acc); // convert receiver account no. char to int


         strcpy(u_trans_data.trans_status,"send"); // store All
        u_trans_data.amt=amt;                      //   data in user object
        u_trans_data.ac_n=re_acc;                   //  related to user transaction history


                                                  // store user_transactions_history data in All_transactions file
    fprintf(p,"\n\t%s\t\t%d\t\t%d\t\t\t%d/%d/%d\t\t%d:%d\n",u_trans_data.trans_status,u_trans_data.amt,re_acc,day,month,year,hour,min);

    fclose(p);              // close file



    strcpy(re_file_name,receiver_acc);  // make receiver all_transactions file path
    strcat(re_file_name,"\\all transactions.txt");

    p=fopen(re_file_name,"a"); // open receiver all_transactions file
    if(p==NULL)
        printf("\n file not Exits");


        strcpy(re_trans_data.trans_status,"receive"); // store data related to receiver transactions
        re_trans_data.amt=amt;  // amount data
        re_trans_data.ac_n=sender_acc;  // sender acc no.


                                      // store all data into receiver all_transactions file
    fprintf(p,"\n\t%s\t\t%d\t\t%d\t\t\t%d/%d/%d\t\t%d:%d",re_trans_data.trans_status,re_trans_data.amt,re_trans_data.ac_n,day,month,year,hour,min);
    fclose(p);  // close file

}
