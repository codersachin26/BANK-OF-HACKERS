
#include<stdio.h>
#include<stdlib.h>

int valid_input_name(char *p)  // it's validate user input name
{                              // it take one argument called char type pointer
                                // which store user_name variable address


    int count=0; // for array indexing
    char validated_name[11]; // store validate name
    int index;




      gets(validated_name);

      for(index=0;validated_name[index];index++);


       if(validated_name[count]==NULL)
       {
                   printf("\n ERROR:you are not Enter anything\ntry Again");
                   return(1);
       }

       if(index>9)
       {
           printf("ERROR: long name not accept\n try short\n ");
           return(1);
       }

    while(!validated_name[count]==NULL) // check valid name or not
    {

    if(validated_name[count]>=65&&validated_name[count]<=90) // it's range A-Z
       count++;

    else
        {
        printf("\n ERROR:only capital letter accept\ntry Again\n\n");
         return(1); // in array not all A-Z then return 1
                    // means again this function call

       }

    }



    int store_count=0; // user name store into user data
    while(validated_name[store_count]!=NULL) // store user name 1 by 1 character
    {

    *(p+store_count)=validated_name[store_count];
        store_count++; // increment index no.


    }


    *(p+store_count)=NULL; // store NULL end the last index no



   return(0); // everything OK

}


int intonly_mo_no() // it valid integer mobile number or not
{
    char Enter_mo_num[10]; // for user Enter variable
    int count=0; // check how many digits user Enter
                 // it's store digits no

   int valid_mo_no;

   while(1) // check how many digits in mo_no
    {


            int index=0;

              fflush(stdin);
            gets(Enter_mo_num); // take mo. no.
            for(count=0;Enter_mo_num[count];count++); // count them

            while(1)
           {
               if(Enter_mo_num[index]>=48&&Enter_mo_num[index]<=57)
                index++;
               else
                break;
               if(Enter_mo_num[index]==NULL)
                break;
           }



          if(count==0)  // empty
           {
           printf("\nERROR: you are not Enter anything");
           printf("\n try again\n>>");
           continue;

             }
               else
             if(count<=8) // greater than 9 is not allowed
              {
                printf("\n ERROR:wrong mobile number");
                printf("\n only 9 ditigs  accept\ntry Again\n>>");
               continue;
              }
                else
                      if(count==9&&index==9) // only 9 digits
                         {

                           sscanf(Enter_mo_num,"%d",&valid_mo_no);// convert char to int
                            return(valid_mo_no);
                           }else
                           {
                                    printf("\n ERROR:wrong mobile number");
                                    printf("\n (only 9 ditigs  accept)\ntry Again\n>>");
                                    continue;
                           }



     }


}





int intonly_age() //  check valid user age
{


    char E_age[4]; // store age
    int valid_age; // user valid age
     int index=0;

   while(1)
   {

            int count=0; // check digits
            fflush(stdin);

            gets(E_age); // take age

           while(1)
           {
               if(E_age[count]>=48&&E_age[count]<=57)
                count++;
               else
                break;
               if(E_age[count]==NULL)
                break;
           }



          if(E_age[index]==NULL)
          {
           printf("\nERROR: you are not Enter anything");
           printf("\n try again\n>>AGE: ");
           continue;

             }
             else
              if(count>=3)
                {
                      printf("\n ERROR: wrong age");
                      printf("\n 'only 2 ditigs  accept'\ntry Again\n>>AGE: ");
                    continue;
                       }
                      else
                         if(count==2)
                             {

                                sscanf(E_age,"%d",&valid_age);// convert char to int
                                 return(valid_age);
                                }
                                else
                                {
                                   printf("\n ERROR: wrong age");
                                    printf("\n 'only 2 ditigs  accept'\ntry Again\n>>AGE: ");
                                     continue;

                                   }

   }




}





int valid_address(char *p)  //it's take capital letter and numbers
{

    char Enter_address[30]; // store user address

    int count=0; // array indexing
    int ok=0; // its a sign for address valid or not

    gets(Enter_address); // take input from the user

   while(1) // check capital letter or not
     {
     if(Enter_address[count]==32||Enter_address[count]>=45&&Enter_address[count]<=90)
     {                                                   // its range A-Z
                                                        // space ASCII code 32
         count++; // increment in array index no.

         if(Enter_address[count]==NULL)// all string ok
         {
              ok=1; // ok convert o to 1
               break; // stop loop
         }

     }

            else // user Enter invalid input
               {
                 printf("\n ERROR:only capital letter accept\ntry Again\n>>");
                 return(1); // return 1 where this function call
                }

     }



     int store_count=0; //  array index no
   if(ok) // when everything is ok then exe this statements
   {
        do
    {

    *(p+store_count)=Enter_address[store_count]; // store user_address into user_address variable through pointer
        store_count++;


    }while(Enter_address[store_count]!=NULL); // check end string point
   }


     *(p+store_count)=NULL; // store NULL at the last index no.

   return(0); // its means everything is ok


}


int valid_Email_id(char *p) // user define function for valid E-mail
{
    char Enter_Email_id[15]; // store user Enter E-mail id


    int count=0; // for array index no.
    int store_count=0;  // for index
    int ok=0; // its sign for function

    gets(Enter_Email_id); // take Email id


    if(Enter_Email_id[count]>=48&&Enter_Email_id[count]<=57||Enter_Email_id[count]>=65&&Enter_Email_id[count]<=90)
      {                                                              //checking E-mail first character valid or not
          printf("\n  ERROR:you Enter wrong E-mail ID\n try Again\n>>");
    
          return(1);
      }

        while(1)
        {
                // checking valid E-mail ID or not

        if(Enter_Email_id[count]==46||Enter_Email_id[count]==64||Enter_Email_id[count]>=48&&Enter_Email_id[count]<=57||Enter_Email_id[count]>=97&&Enter_Email_id[count]<=122)
          {
            count++; // increment

             if(Enter_Email_id[count]==NULL) // when E-mail id is ok
             {                                // then jump in this statements

                 Enter_Email_id[count]=NULL; // assign NULL at the last index no.
                  ok=1; // change ok value o to 1 which mean E-mail ID is ok
                  break; // stop this loop
             }

          }
          else
               {                                                      // this statement for wrong E-mail ID
              printf("\n ERROR: you Enter wrong E-mail ID\ncapital letter not allowed\n try Again\n>>");
              return(1);
               }
        }



   if(ok)
   {
        do              // store valid E-mail id into user_data object through pointer
    {

    *(p+store_count)=Enter_Email_id[store_count]; // one by one
        store_count++;

     }while(Enter_Email_id[store_count]!=NULL); // check NULL character


   }

  *(p+store_count)=NULL;

     return(0); // simply return o which means everything is ok

}


int valid_National_id(void) // user define function for checking valid national id or not
{



      char Enter_National_id[10];

while(1)
{
          int count=0;
       fflush(stdin);
       int index=0;

     gets(Enter_National_id);
     for(count;Enter_National_id[count];count++);

                 while(1)
              {
               if(Enter_National_id[index]>=48&&Enter_National_id[index]<=57)
                index++;
               else
                break;
               if(Enter_National_id[index]==NULL)
                break;
           }


    if(count==0)
    {
        printf("\n ERROR: you are not Enter anything\ntry Again");
        printf("\n>>NATIONAL ID: ");
        continue;
    }

     if(count==6&&index==6) // if user Enter 6 valid digits then true this condition
     {
         int valid_National_id;
         sscanf(Enter_National_id,"%d",&valid_National_id); // convert char to int
         return(valid_National_id); // return valid National id where it call
     }
     else // user Enter invalid id then exe this statements
     {
         printf("\n ERROR: you are Enter wrong valid ID \ntry again\n(only 6 digits accept)\n");
         printf("\n>>NATIONAL ID: ");
         continue;
     }

}

}



int valid_gender_input(char *p)  // for gender input
{

    char Enter_user_choice[3]; // store user choice
    int count=0; // for indexing no.
    int user_choice;
    int index=0;

    char male[5]="MALE";  // assign string for user choice // choice 1
    char female[7]="FEMALE"; // choice 2


    while(1)
    {

       gets(Enter_user_choice);

       for(index=0;Enter_user_choice[index];index++);

       if(index==0)
       {
            printf("\n  ERROR:you are not Enter anything\ntry Again");
            printf("\n\n>>ENTER: ");
            continue;

       }
       if(Enter_user_choice[0]==49||Enter_user_choice[0]==50)
       {
            sscanf(Enter_user_choice,"%d",&user_choice);
            break;

       }
       else
       {
           printf("\n ERROR:you are Enter wrong choice\ntry Again");
            printf("\n\n>>ENTER: ");
            continue;
       }
    }



        if(user_choice==1)  // choice 1
           {
             while(1)
             {
             *(p+count)=male[count]; // store choice 1 data into user_data
              count++;
              if(male[count]==NULL) // check NULL
              {
                  *(p+count)=NULL;  //  assign NULL at the last index no. in string
                   break;
              }
           }

           }
           else
            if(user_choice==2) // choice 2
           {

            while(1)
             {
             *(p+count)=female[count]; //  store choice 2 data into user_data
              count++;
              if(female[count]==NULL)  //   check NULL
               {

                    *(p+count)=NULL;  //  assign  NULL character at the last index no.
                   break;
               }
           }
           }

           return(0);     // its sign for other function
                         // its means everything is OK
                         // simply end function return 0
}


int input_relationship_status(char *p)  // its user define function which take user Relationship status
{
    int count=0; // index no.
    char Enter_user_choice[3];
    int user_choice;// store user choice
    int index=0;

    char single[8]="SINGLE";  // assign string for user choice // choice 1
    char married[9]="MARRIED";  // choice 2





     while(1)
    {

       gets(Enter_user_choice);

       for(index=0;Enter_user_choice[index];index++);

       if(index==0)
       {
            printf("\n ERROR:you are not Enter anything\ntry Again");
            printf("\n\n>>ENTER: ");
            continue;

       }
       if(Enter_user_choice[0]==49||Enter_user_choice[0]==50)
       {
            sscanf(Enter_user_choice,"%d",&user_choice);
            break;

       }
       else
       {
           printf("\nERROR: you are Enter wrong choice\ntry Again");
            printf("\n\n>>ENTER: ");
            continue;
       }
    }

    if(user_choice<=2)  // check user choice
        {
            if(user_choice==1)  // choice 1 statements
            {
                while(1)
               {
                   *(p+count)=single[count]; // assign choice 1 string one by  one character
                   count++;
                   if(single[count]==NULL)
                   {
                       *(p+count)=NULL;
                       break;
                   }
               }
            }
            else
                if(user_choice==2)  //    choice 2 statements
            {
                   while(1)
                    {
                *(p+count)=married[count]; //   assign choice 2 string one by  one character
                 count++;
                 if(married[count]==NULL) // check NULL character
                 {
                   *(p+count)=NULL;  // assign  NULL character at the last index no.
                   break;
                 }
                    }
            }


        }
        else   //  wrong choice statements
           {
                printf("\n ERROR: you do something wrong\ntry Again\n>> ");
                return(1);
           }



            return(0);    // its sign for other function
                         // its means everything is OK
                         // simply end function return 0
}




int valid_user_input_acc() // it take valid account no.
{

    int valid_acc_no; // acc no. as int
    char Enter_acc_no[10]; // acc no. as char



     while(1)
     {


          int characters=0;
          int index=0;
           int acc_digits=0;


               printf("\n      USER A/C NO.:  ");
              fflush(stdin);
             gets(Enter_acc_no);

        for(characters=0;Enter_acc_no[characters];characters++); // how many characters in Enter_acc_no

     while(Enter_acc_no[acc_digits])
     {
         if(Enter_acc_no[acc_digits]>=48&&Enter_acc_no[acc_digits]<=57)
            acc_digits++;
          else
            break;

     }




     if(acc_digits==8&&characters==8) // valid acc
     {
         sscanf(Enter_acc_no,"%d",&valid_acc_no);
         return(valid_acc_no);
          break;
     }
     else
        if(Enter_acc_no[index]==NULL) // user not Entered something
     {
            printf("\n\n ERROR:you are not Enter anything\n try again\n\n Hit any key ");
                getch();
               continue;
     }
     else  // invalid user acc no.
     {
         printf("\n ERROR:you are not Enter valid user account number\ntry Again\n\n Hit any key");
         getch();
         continue;
     }



     }
}




int user_input_amt() //its take 5 digits amt bal
{

         char Enter_amt[7]; // store amt as a string
         int valid_amt; // store valid amt
         int index=0; // for index no.

         while(1)
         {
             gets(Enter_amt); // take amt bal as a string

             while(1)
               {
                 if(Enter_amt[index]>=48&&Enter_amt[index]<=57) // count int values
                    index++;
                 else
                    break;
               }

               if(index==0) // empty
               {
                   printf("\n\nERROR: you are not Enter anything\ntry Again\n\n\t\t ENTER AMOUNT:$ ");
                   continue;
               }
               if(index>=6) // greater than 6 is not allow
               {
                   printf("\n\nERROR: big amount not allow\nonly 5 digits accepts\ntry Again\n\n\t\t ENTER AMOUNT:$ ");
                   continue;

               }
               else
                if(index==5) // perfect valid amt
               {
                   sscanf(Enter_amt,"%d",&valid_amt); // convert char to int
                   return(valid_amt); // return amt value
                   break;
               }

         }

}



int input_valid_pin()
{

      char Enter_pin[6]; // store pin code as a string
         int valid_pin; // store valid pin code


         while(1)
         {

               int index=0; // for index no.
               fflush(stdin);
              gets(Enter_pin); // take pin code as a string

             while(1)
               {
                 if(Enter_pin[index]>=48&&Enter_pin[index]<=57) // count int values
                    index++;
                 else
                    break;
               }

               if(Enter_pin[0]==NULL) // empty
               {
                   printf("\n\n ERROR:you are not Enter anything\ntry Again\n\n\t\t  PIN CODE:  ");
                   continue;
               }
               if(index>=5) // greater than 5 is not allow
               {
                   printf("\n\nERROR: big pin not allow\nonly 4 digits accepts\ntry Again\n\n\t\t  PIN CODE:  ");
                   continue;

               }
               else
                if(index==4) // perfect valid pin code
               {
                   sscanf(Enter_pin,"%d",&valid_pin); // convert char to int
                   return(valid_pin); // return pin code value
                   break;
               }
               else
               {
                   printf("\nERROR: only 4 digits accepts\ntry Again\n\n\t\t  PIN CODE:   ");
                   continue;
               }

         }



}



