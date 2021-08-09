#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Create variables to iterate//
int i,j;
//create an integer varable called exit, to help exit out of a function//
int main_exit;
//Prototype functions//
//Menu will display the options//
void menu();
//Create a class that holds the date//
struct date {
    int month, day, year;
};
struct {
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    
}add, upd, check, rem, transaction;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate*t*amount) /100.0;
    return (SI);

}
//Delay the request when a option is selected//
void fordelay();
///When someone want to make a new account//
void new_acc();
//Create a new list for the 
void new_list();
//Edit anyt changes to the system//
void edit();
///Have a transaction history for the user//
void transact(void);
//delete option if a client has been removed fromt he system//
void delete(void);
//View option to see how many users we chave//
void view(void);
///close out of any statement//
void close(void);

int main(void)
{
    ///store a password with a length of 10 characters//
    char pass[10], password[10] = "potatoes";
    //integer set to 0//
    int i = 0;
    ///User enters the password and it gets stored into pass//
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s", pass);
//use strcmp to comapre the password if it matches, we are goign to load the password, and use
//the fordelay function to delay it by a couple of seconds, then show the menu////
    if(strcmp(pass,password) == 0)
    {
        printf("\n\nPassword Match!\nLOADING");
        for(i =0; i <=6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    } 
    else 
    ///else wrong password and try again by pressing 1 to validate yourself or 0 to exit///
    {
        printf("\n\nWrong password! \a\a\a");
        //try to login again///
        printf("\nEnter 1 to rtry again and 0 to exit:");
        scanf("%d", &main_exit);
        if(main_exit == 1)
        {
            system("cls");
            main();
        }
        else if (main_exit == 0)
        {
            system("cls");
            close();
        }
        else 
        ///if the user enters 0, then exit//
        {
            printf("\nInvalid!");
            fordelay(100000000);
            system("cls");
            
        }
        return 0;
    }
}


///Delay when the user enters a option///
void fordelay(int j)
{
    int i,k;
    for(i=0; i <j; i++)
        k=i;
}

void new_acc()
{
    //Have a variable called choice based on the User's option//
    int choice;
    //Create a pointer to the File
    FILE *ptr;

    ptr=fopen("record.dat", "a+");
    ///Here Going to use the goto statement where the the user is goign to enter in their information for creating their account//
    account_no:
    system("cls");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d", &check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name, &add.dob.month, &add.dob.day,&add.dob.year,&add.age,add.address, add.citizenship, &add.phone,add.acc_type, &add.amt,&add.deposit.month,&add.deposit.day, &add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
        {
            printf("Account no. Already in use!");
            fordelay(100000000);
            goto account_no;
        }
    }
    add.acc_no==check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day, &add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    printf("\nEnter the address: ");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship );
    printf("\nEnter the phone number");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nType of account: \nt#Saving\n\t#Current\n\t#Fixed1( for 1 year\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\tEnter your choice:");
    scanf("%s", add.acc_type); 

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1)
    menu();
    else if(main_exit == 0)
    close();
    else 
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

//View List//
void view_list()
{
    FILE *view;
    view=fopen("record.dat", "r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
        test++;
    }
    fclose(view);
    if(test ==0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }
    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==1)
    menu();
    else if(main_exit==0)
    close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}

void edit(void)
{
    int choice, test=0;
    FILE *old,*newrec;
    old=fopen("record.dat", "r");
    newrec=fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose infro ytou want to change: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==upd.acc_no){
            test = 1;
            printf("\nWhich information do you want to change?\n1.Address\n2. Phone\n\nEnter your choice(1 for address and 2 for phone:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            printf("Enter the new address:");
            scanf("%s", upd.address);
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            system("cls");
            printf("Changes saved!");
        }
        else if(choice==2)
        {
            printf("Enter the new Phone Number");
            scanf("%lf",&upd.phone);
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            system("cls");
            printf("Changes saved!");

        }
        else 
        fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if(test!=1)
    {
        system("cls");
        printf("\nRecord Not found!! \a\a\a");
        edit_invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit");
        scanf("%d", &main_exit);
        system("cls");
        if(main_exit ==1)
        menu();
        else if(main_exit ==2)
        close();
        else if (main_exit == 0)
        edit();
        else {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else 
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if(main_exit==1)
        menu();
        else 
        close();
    }
}

void transact(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old=fopen("record.dat", "r");
    newrec=fopen("new.dat","w");

    printf("Enter the account no.of the customer");
    scanf("%d",&transaction.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==transaction.acc_no)
        {
            test=1;
            if(strcmp(add.acc_type, "fixed1") == 0|| strcmpi(add.acc_type, "fixed2") ==0 || strcmpi(add.acc_type, "fixed3") ==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS");
                fordelay(100000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to \n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);
            if(choice == 1);
            {
                printf("Enter the amount you want to desposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nWithdrawn Sucessfully");
            }
        }
        else
        {
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test!=1)
    {
        printf("\n\nRecord not found!!");
        transact_invalid:
        printf("\n\n\nEnter 0 to try again, 1 to return to main menu or 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");
        if(main_exit==0)
        transact();
        else if(main_exit ==1)
        menu();
        else if(main_exit ==2)
        close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if(main_exit == 1)
        menu();
        else
        close();
    }
}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}
void erase(void)
{
    FILE *old, *newrec;
    int test = 0;
    old=fopen("record.dat", "r");
    newrec=fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want to delete: ");
    scanf("%d", &rem.acc_no);
     while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
    fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }


}

void menu(void)
{   int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }



}
