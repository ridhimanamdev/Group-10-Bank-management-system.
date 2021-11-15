// OOP PROJECT
// BANK MANAGMENT SYSTEM!!!
// PRESENTERS(Priyanshi Jain,Rashmeet Chugga,Ridhima Namdev)

#include <iostream>
#include <stdio.h> //gets() and puts()
using namespace std;
class banking
{

    int amount, ac_number;
    char cust_name[100], ac_type;

public:
    void get_record();
    friend void show_record(banking);
    int re_amount();
    int re_account();
    int deposit();
    int withdraw();
};

// storing data from user
void banking::get_record()
{

    cout << "Enter Account No: ";
    cin >> ac_number;
    cout << "Enter the Name: ";
    cin >> cust_name;
    cout << "Enter the Account type(C/S): ";
    cin >> ac_type;
    cout << "Enter the Amount: ";
    cin >> amount;
}

// return amount of a specific customer
int banking::re_amount()
{
    return (amount);
}

void show_record(banking obj)
{
    // obj can access private member of same class
    cout << "Account No : " << obj.ac_number << "\n";
    cout << "Name : ";
    puts(obj.cust_name);
    cout << "Account Type : " << obj.ac_type << "\n";
    cout << "Amount : " << obj.amount << "\n";
}
// return account of a customer
int banking::re_account()
{
    return (ac_number);
}

int banking::deposit()
{
    system("CLS");

    int d;
    cout << "Enter the ammount to be deposit: ";
    cin >> d;
    amount = amount + d;
    return amount; // return total deposit in account
}
int banking::withdraw()
{
    system("CLS");

    int w;
    if (amount < 500)
    {
        cout << endl;
        cout << "Sorry! Insuficient Balance transection not available";
    }
    else
    {
        cout << "\nEnter the ammount to be withdraw: \n";
        cin >> w;
        amount = amount - w;
        if (amount < 0)
        {
            cout << "!!!Insuficient amount!!!";
        }
        else
            cout << "!!!Amount successfully withdraw!!!";
    }
    return amount; // return withdraw amount
}

int main()
{
    system("CLS");

    banking x[10]; // that means we can store 10 customer at a time.
    int ch, count, account, amount;
    do
    {
    start:
        cout << "\n\n\n\t\t\t\t***BANKING***\n\n";
        cout << "\t\t\t\t1.CREATE ACCOUNT\n\n";
        cout << "\t\t\t\t2.DEPOSIT\n\n";
        cout << "\t\t\t\t3.WITHDRAW\n\n";
        cout << "\t\t\t\t4.DISPLAY ALL ACCOUNT\n\n";
        cout << "\t\t\t\t5.SEARCH\n\n";
        cout << "\t\t\t\t0.EXIT\n\n";
        cout << "________________________________________________________________________________________\n";

        cout << "\t\t\t\t Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int cust;
            cout << "\nHow Many Customer Record you want to Store:- ";
            cin >> cust;
            for (count = 0; count < cust; count++)
            {
                cout << count + 1 << ". ACCOUNT\n";
                x[count].get_record(); // get_record function calling
                cout << "\n\n";
                cout << "!!!Account Created Successfully!!!\n\n";
            }
            break;

        case 2:

            cout << "\nEnter the Account No:";
            cin >> account;
            for (count = 0; count < cust; count++)
            {
                if (account == x[count].re_account())
                {
                    x[count].deposit(); // deposit function calling
                    cout << "!!!Amount Successfully Deposit!!!\n\n";
                }
            }
            break;

        case 3:

            cout << "\nEnter the account No:";
            cin >> account;
            for (count = 0; count < cust; count++)
            {
                if (account == x[count].re_account()) // checking account matches or not
                {
                    x[count].withdraw();
                }
            }

            break;

        case 4:

            cout << "\tALL ACCOUNT DISPLAY:\n";
            cout << "==================================\n";
            for (count = 0; count < cust; count++)
            {
                if (x[count].re_account() == 0)
                    return 0;
                cout << count + 1 << ". ACCOUNT\n";
                cout << "======================================\n";
                show_record(x[count]); // display all account record
                cout << "=====================================\n";
            }
            break;

        case 5:
            int search;
            cout << "\nEnter account No. to be search: ";
            cin >> search;
            for (count = 0; count < cust; count++)
            {
                if (search == x[count].re_account())
                {
                    cout << endl << count + 1 << ". ACCOUNT\n";
                    show_record(x[count]); // display search account detail
                }
              
            }
            break;

        case 0:
            exit(0);
            break;

        default:
            cout << "!!!*Invalid Choice*!!!";
            goto start;
        }
    } while (ch != 0);
}