// Sufiyan Mohammad Salman
// B202103065
// Project is on Email management
// How accounts are stored (I have stored in Hash Table)
// How emails are stored for a particular account , Although we can also use doublyll, but  I have stored Emails in linkedlist with inseertion from start always(not at last node) ..
// How Emails sent and recieved , I have used qeue for this.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Account
{
    // isme ham age and password bhi dalskte hen but it wiill tKE time and men new cheezen nai seekh paunga so sorry for that
    int Email_no;                   // is se no generate hoga jo k phir email k emailno ko assign hoga
    char nameofAccountholder[25];   // full name
    char EmailID[25];               // EmailID of account
    struct Email_details *EmailLog; // start of email log ka pointerr hai ye , isme latest email ka pointer hoga , due to insertion from top
    struct Account *Next_account;   // next account
};
struct start_Account
{
    struct Account *account_Start; // pointer of struct Account(first account)
};
struct Email_details
{
    
    char senderName[20];
    char RecieverName[20];
    int Email_no; // email id smjhlo jis se ye uniquely identify hoga
    char text[30];
    struct Email_details *next_email
};
// struct start_Email_details
// {
//     struct Email_details *Email_list;
//     // char senderName[20];
//     // char RecieverName[20];
//     // char text[20];
// };
//======================================
// Functions related to Que linnkedlist with insertion at the start always
//Dynamic qeue//

struct qeue *Front = NULL, *rear = NULL;
struct qeue
{
    struct Email_details *SendingEmail; // start of email log ka pointerr hai ye , isme latest email ka pointer hoga , due to insertion from top
    // int data;
    struct qeue*next;
};
void Enqeue(struct Account *reciever_account, char sendername[]); // func prototype
void printlist();
void Enqeue(struct Account *reciever_account, char sendername[]) // func Declaration
{
//     struct qeue
    struct Email_details *New_Email_tobequed = (struct Email_details *)malloc(sizeof(struct Email_details));
    strcpy(New_Email_tobequed->RecieverName, reciever_account->EmailID);
    strcpy(New_Email_tobequed->senderName, sendername);

    printf("Start writing(max 30 words): ");
    gets(New_Email_tobequed->text);// ism email ka material ayega pura
    gets(New_Email_tobequed->text);// ism email ka material ayega pura
 struct qeue*tmp = (struct qeue*)malloc(sizeof(struct qeue));
  tmp->SendingEmail = New_Email_tobequed;
    // printf("%d intput value:",tmp->data);
    // tmp->next = NULL;
    if (Front == NULL)
    {
        Front = tmp;
        rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = rear->next;
    }
}

struct Email_details* Deqeue()
{
    if (Front == NULL)
    {
        printf("Stack underflow ,can't Deqeue\n");
    }
    else
    {

        struct qeue*curr = Front;
        Front = Front->next;
        // printf("Email: %d , dequed\n", curr->SendingEmail->Email_no);
        struct Email_details * sendingEmail= curr->SendingEmail;
        free(curr);
        return(sendingEmail);
    }
}
void printlist()
{
    if (Front == NULL)
    {
        printf("Sorry!,Qeue is empty\n");
    }
    else
    {
        printf("Dynamic qeue is:\n");
        printf("[");
        struct qeue*curr = Front;
        while (curr != NULL)
        {
            printf("Email NO qued: %d  ", curr->SendingEmail);
            curr = curr->next;
        }
        printf("]\n");
    }
}


//Function related to que ends here
//======================================
// Functions related to linnkedlist with insertion at the start always
void SendEmail(struct Account *reciever_account, char sendername[]) // inserting email node , same as inserting a node in linked list
{
    // struct Email_details *tmp = (struct Email_details *)malloc(sizeof(struct Email_details));
    // strcpy(tmp->RecieverName, reciever_account->EmailID);
    // strcpy(tmp->senderName, sendername);

    // printf("Start writing(max 30 words): ");
    // gets(tmp->text);// ism email ka material ayega pura
    // gets(tmp->text);// ism email ka material ayega pura
    Enqeue(reciever_account, sendername);
    // strcpy(tmp->text, "hemlo barathers"); // ism email ka material ayega pura
    printf("Email has been sent successfully\n");
    struct Email_details *tmp= Deqeue();
    // printf("%s\n",tmp->RecieverName);
    // printf("%s\n",tmp->senderName);
    // printf("%s\n",tmp->text);

    // printf("");
    // tmp->RecieverName = input;
    // tmp->senderName=;
    // tmp->text=;
    // printf("%d intput value:",tmp->data);

    if (reciever_account->EmailLog == NULL)
    {
        tmp->next_email = NULL;
        reciever_account->EmailLog = tmp;
        reciever_account->Email_no = 1;             // is account ki first email
        tmp->Email_no = reciever_account->Email_no; // first email ka emamilno assign krdia
    }
    else
    {
        // printf("hi");
        reciever_account->Email_no++;               // ek aur email add hui account me to no of emails incresed in this account
        tmp->Email_no = reciever_account->Email_no; // jo Emailno_tobe_searched bana hoga upr wali line me woh isko assign krdia
        tmp->next_email = reciever_account->EmailLog;
        reciever_account->EmailLog = tmp;
        // struct Email_details *curr = reciever_account->EmailLog;
        // while (curr->next_email!= NULL)
        // {
        //     curr = curr->next;
        //     // printf("%d",curr->next);
        // }
        // curr->next = tmp;
    }
}
void printEmail_list(struct Account *reciever_account)
{
    // printf("reciver");
    struct Email_details *curr = reciever_account->EmailLog;
    if (curr == NULL)
    {
        printf("Sorry, no Emails are there!\n");
    }
    else
    {
        /* code */

        while (curr != NULL)
        {
            // char EmailID[]="ji";
                printf("==================================\n");

            printf("EmailNO: %d \n", curr->Email_no);
            printf("Sender: %s  \n", curr->senderName);
            printf("Reciever: %s  \n",  curr->RecieverName);
            printf("Email Content is: %s \n", curr->text);
            curr = curr->next_email;
            // curr->RecieverNam;
        }
    }
    // printf("Value is: %d",curr->data);
}
void search_Email(int Emailno_tobe_searched, struct Account *reciever_account)
{
    struct Email_details *curr = reciever_account->EmailLog;
    int index = 1, flag = 0;
    while (curr != NULL)
    {
        if (Emailno_tobe_searched == curr->Email_no)
        {

            printf("Email is found in node no: %d of linked list \n", index);
            flag = 1;
        }
        curr = curr->next_email;
        index++;
    }
    if (flag == 0)
    {
        printf("Email Not found in this account\n");
    }
}
void delete_Email(int Emailno_tobe_deleted, struct Account *reciever_account)
{
    int flag = 0;
    struct Email_details *curr = reciever_account->EmailLog, *prev = reciever_account->EmailLog; // latest(first in linked list) email curr me agae
    if (curr == NULL)
    {
        printf("Sorry, no Emails are there!\n");
        // return;
    }
    else
    {
        if (Emailno_tobe_deleted == reciever_account->EmailLog->Email_no)
        {
            reciever_account->EmailLog = reciever_account->EmailLog->next_email;
            printf("Email has been deleted successfully\n");
            prev = NULL;
            flag = 1;
            free(prev);
        }
        else
        {
            curr = curr->next_email; // taake start se nai uske aage se start ho, second agae ab isem
            while (curr != NULL)
            {
                if (Emailno_tobe_deleted == curr->Email_no)
                {
                    prev->next_email = curr->next_email;
                    free(curr);
            printf("Email has been deleted successfully\n");
                    flag = 1;
                    break;
                }
                prev = prev->next_email;
                curr = curr->next_email;
            }
        }
        if (flag == 0)
        {
            printf("Email Not found in this account\n");
        }
    }
}

// Functions related to lilnnkedlist with insertion at the start always
//======================================
//  Functions related to Hash table for accounts
void array_nullmaker(struct start_Account Accounts_table[], int size)
{
    // yeh array ke saare starts ko null krdega
    int i = 0;
    while (i < size)
    {
        Accounts_table[i].account_Start = NULL;
        i++;
    }
}
unsigned int string_to_ascii(char *string)
{
    unsigned int Total_Ascii = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        Total_Ascii += (int)(string[i]);
        i++;
    }
    return (Total_Ascii);
}
void same_indexinsert(int size, struct start_Account Accounts_table[]) // func Declaration
{
    int node_no = 0;
    // when struct char is pointer below two lines were used
    //  unsigned int Ascii_of_string=string_to_ascii(String_tobe_inserted);
    //  int index_of_valuetobe_inserted = Ascii_of_string % size;
    // printf("%d\n",Ascii_of_string);//Shows Ascii code

    struct Account *new_account = (struct Account *)malloc(sizeof(struct Account));
    printf("Enter Account EmailID: ");
    gets(new_account->EmailID); // 2 times islie q k yeh ek dafa me input leta hi nai hai
    gets(new_account->EmailID);
    // strcpy(new_account->EmailID,gets(new_account->EmailID));
    printf("Enter Your Name max(20 letters): ");
    gets(new_account->nameofAccountholder);


    unsigned int Ascii_of_string = string_to_ascii(new_account->EmailID); // ye email ko ascii code me convert kr k ek single integer value dega jis k hisab se hashin krdi jayegi
    int index_of_valuetobe_inserted = Ascii_of_string % size;
    new_account->EmailLog = NULL;
    new_account->Next_account = NULL;
    new_account->Email_no=0;
    if (Accounts_table[index_of_valuetobe_inserted].account_Start == NULL)
    {
        node_no++;
        Accounts_table[index_of_valuetobe_inserted].account_Start = new_account;
    }
    else
    {
        node_no++;
        struct Account *curr_account = Accounts_table[index_of_valuetobe_inserted].account_Start;
        // printf("%s\n", Accounts_table[index_of_valuetobe_inserted].account_Start->EmailID);//checking purpose
        while (curr_account->Next_account != NULL)
        {
            // printf("%s\n", Accounts_table[index_of_valuetobe_inserted].account_Start->Next_account->EmailID);//checking purpose
            // printf("value %d , %s\n",node_no,curr_account->EmailID);
            node_no++;
            curr_account = curr_account->Next_account;
        }
        // printf("loop se bahar\n");
        node_no++;
        curr_account->Next_account = new_account;
    }
    printf("Account added at index :%d and node: %d \n", index_of_valuetobe_inserted, node_no);
    //}
}

void Accounts_print(/*int index_tobe_printed*/ char *account_tobe_Printed, int size, struct start_Account Accounts_table[]) // prints account which have same index in hashtable
{                                                                                                                           /// Prints all values of a particular index. index should be given but I think we should just take single account email and print details regarding that account only
    // int index_tobe_printed; //=value_tobe_printed % size;
    // if (Accounts_table[index_tobe_printed].account_Start == NULL)
    // {
    //     printf("Sorry! The list is empty at this index\n");
    // }
    // else
    // {
    //     struct Account *curr_account = Accounts_table[index_tobe_printed].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
    //     while (curr_account != NULL)
    //     {
    //         printf("Accounts are: %s \n", curr_account->EmailID);
    //         curr_account = curr_account->Next_account;
    //         // printf("%d",curr->next);
    //     }
    // }// uncomment every commented line of above code to print accounts of a specififc index
    //=====================================
    //  printf("Account to be searched  %s\n", account_tobe_Printed);
    int flag = 0, node_no = 0;
    unsigned int Asciiof_String = string_to_ascii(account_tobe_Printed); // Acii code of the given string
    int index_ofvalue_tobeSearched = Asciiof_String % size;              //=value_tobe_printed % size;
    if (Accounts_table[index_ofvalue_tobeSearched].account_Start == NULL)
    {
        //    Accounts_table[index_ofvalue_tobeSearched].account_Start=new_account ;
        printf("Sorry! , Account not found\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_ofvalue_tobeSearched].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        while (curr_account != NULL)
        {
            if (string_to_ascii(curr_account->EmailID) == string_to_ascii(account_tobe_Printed))
            {
                printf("==================================\n");
                printf("Email ID : %s \n", curr_account->EmailID);
                printf("Name: %s \n", curr_account->nameofAccountholder);
                printf("Total Emails Received : %d\n", curr_account->Email_no);

                flag = 1;
                break;
            }

            node_no++;
            curr_account = curr_account->Next_account;
        }
        if (flag == 0)
        {
            printf("Sorry! , Account not found\n");
        }

        // curr_account->Next_account = new_account;
    }
}

// void same_indexvalue_update(char* account_tobe_searched, int value_tobe_updated, int size, struct start_Account Accounts_table[], int update_value)
// {//update me hashing kharab hojayegi, so it is useless
//     int flag = 0, node_no = 0;
//     /// update a value
//     int index_ofvalue_tobeupdated = value_tobe_updated % size; //=value_tobe_printed % size;
//     if (Accounts_table[index_ofvalue_tobeupdated].account_Start == NULL)
//     {
//         //    Accounts_table[index_ofvalue_tobeupdated].account_Start=new_account ;
//         printf("Sorry! The list is empty at this index\n");
//     }
//     else
//     {
//         struct Account *curr_account = Accounts_table[index_ofvalue_tobeupdated].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
//         while (curr_account != NULL)
//         {
//             node_no++;
//             if (curr_account->value == value_tobe_updated)
//             {
//                 curr_account->value = update_value;
//                 printf("Value '%d ', updated at index: %d and Email_details: %d with '%d'\n", value_tobe_updated, index_ofvalue_tobeupdated, node_no, update_value);
//                 flag = 1;
//                 break;
//             }
//             curr_account = curr_account->Next_account;
//         }
//     }
//     if (flag == 0)
//     {
//         printf("Sorry! , Value not found\n");
//     }
// }

void Delete_Account(char *account_tobe_searched, int size, struct start_Account Accounts_table[]) // deletes an account
{
    int flag = 0, node_no = 0;
    unsigned int Asciiof_String = string_to_ascii(account_tobe_searched); // Acii code of the given string
    int index_ofvalue_tobeSearched = Asciiof_String % size;               //=value_tobe_printed % size;
    int index_ofvalue_tobedeleted = index_ofvalue_tobeSearched % size;    //=value_tobe_printed % size;
    if (Accounts_table[index_ofvalue_tobedeleted].account_Start == NULL)
    {
            printf("Sorry! , Account not found\n");
            flag=0;
        // printf("Sorry! The list is empty at this index\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_ofvalue_tobedeleted].account_Start->Next_account, *prev = Accounts_table[index_ofvalue_tobedeleted].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        if (strcmp(Accounts_table[index_ofvalue_tobedeleted].account_Start->EmailID, account_tobe_searched) == 0)
        {
            node_no++;
            Accounts_table[index_ofvalue_tobedeleted].account_Start = Accounts_table[index_ofvalue_tobedeleted].account_Start->Next_account;
            printf("Account having Email ID: '%s ', Deleted from index: %d and node: %d of hash table\n", account_tobe_searched, index_ofvalue_tobedeleted, node_no);
            flag = 1;
            free(prev);
        }
        else
        {
            node_no++; // node ko 1 isle kia kyun k current bhi start k aage se shuru hota hai aur 1 na kren to inndexing me ans me no ek kam aata hai
            while (curr_account != NULL)
            {
                node_no++;
                if (strcmp(curr_account->EmailID, account_tobe_searched) == 0)
                {
                    prev->Next_account = curr_account->Next_account;
                    printf("Account having Email ID: '%s ', Deleted from index: %d and node: %d of hash table\n", account_tobe_searched, index_ofvalue_tobedeleted, node_no);
                    free(curr_account);
                    flag = 1;
                    break;
                }
                prev = curr_account;
                curr_account = curr_account->Next_account;
            }
        }
        if (flag == 0)
        {
            printf("Sorry! , Account not found\n");
        }
        // curr_account->Next_account = new_account;
    }
}
struct Account *Account_search(char *account_tobe_searched, int size, struct start_Account Accounts_table[])
{
    // printf("Account to be searched  %s\n", account_tobe_searched);
    int flag = 0, node_no = 0;
    unsigned int Asciiof_String = string_to_ascii(account_tobe_searched); // Acii code of the given string
    int index_ofvalue_tobeSearched = Asciiof_String % size;               //=value_tobe_printed % size;
    if (Accounts_table[index_ofvalue_tobeSearched].account_Start == NULL)
    {
        //    Accounts_table[index_ofvalue_tobeSearched].account_Start=new_account ;
            printf("Sorry! , Account not found\n");
            return NULL;
            //wese to is condition ki zarurt nai hai q k curr neechebhi null hoga aur loop chalegi hi nai
        // printf("Sorry! The list is empty at this index\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_ofvalue_tobeSearched].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        while (curr_account != NULL)
        {
            if (string_to_ascii(curr_account->EmailID) == string_to_ascii(account_tobe_searched))
            {
                printf("Account having EmailID: '%s ', Found at index: %d and node: %d of hash table\n", curr_account->EmailID, index_ofvalue_tobeSearched, node_no);
                // curr_account->value=update_value;

                flag = 1;
                return curr_account;
                break;
            }

            node_no++;
            curr_account = curr_account->Next_account;
        }
        if (flag == 0)
        {
            printf("Sorry! , Account not found\n");
            return NULL;
        }

        // curr_account->Next_account = new_account;
    }
}
//==================================================
// Functions related to Hash table end here
// other functions
void loginAccount(struct Account *LoggedinAccount, struct start_Account Accounts_table[]) // removed pointer
{
    int asked_service, input, search_value, insert_value, update_value, delete_value, size = 10;
   
    printf("\n=============Logged into account: %s=============\n", LoggedinAccount->EmailID);
    while (asked_service != 5)
    {
        printf("==================================\n");
        printf("Enter what do you wish to do?\n1.See Recieved Emails of this account\n2.Send an Email to another account\n3.Delete an Email\n4.To Search an Email\n5.Log out\n");//7.\n8.\n9.\n10.\n");
        scanf("%d", &asked_service);
        if (asked_service == 1) // For insert account in hash
        {
            char string[25];
            printf("==================================\n");
            printEmail_list(LoggedinAccount);
        }
        else if (asked_service == 2) // To send email to another account
        {                            // we can take input here as well but to avoid any bug , i have taken input in function of emailinsert
            printf("==================================\n");
            char string[25];
            printf("Enter EmailID of account you want to send email to: ");
            scanf("%s", &string);
            struct Account *Email_reciever = Account_search(string, size, Accounts_table);
            if (Email_reciever != NULL)
            {
                // printf("Sorry no such account exists to Send Email\n"); // 2 cheezenprint horhi hen , ek to ye line aur ek no lists
           
                SendEmail(Email_reciever, LoggedinAccount->EmailID); // email sender ka naame bhi jayga isme
            }
        }
        else if (asked_service == 3) // To Delete an email of loggin in account
        {                            // we can take input here as well but to avoid any bug , i have taken input in function of emailinsert
            printf("==================================\n");
            // char string[25];
            printf("Enter Emailno of Email you want to Delete: ");
            scanf("%d", &delete_value);
            delete_Email(delete_value, LoggedinAccount);
        }
        else if (asked_service == 4) // To Search an email of loggin in account
        {                            // we can take input here as well but to avoid any bug , i have taken input in function of emailinsert
            printf("==================================\n");
            printf("Enter Emailno of Email you want to search: ");
            scanf("%d", &search_value);
            search_Email(search_value, LoggedinAccount);
        }
        else // if (asked_service==6)//Useless currently
        {
            break;
        }
    }
    printf("\n=============Logged out of account: %s=============\n", LoggedinAccount->EmailID);
}

int main()
{
    int asked_service, input, search_value, insert_value, update_value, size;
    char todelete[20];
    printf("\nEnter the size for hash table\t:\t");
    scanf("%d", &size);

    struct start_Account Accounts_table[size]; // hash table
    array_nullmaker(Accounts_table, size);     // maKes null all the indexes of hash arrray, so that comparison is efficient and easier
    // inputArray(array, size);
    while (asked_service != 6)
    {
        printf("==================================\n");
        printf("Enter what do you wish to do?\n1.Create an Account\n2.Print Account Details\n3.Delete an account\n4.Update a value(Upcoming feature)\n6.To exit\n7.To Search an account\n8.Log in to account to send, see recieved, delete and search Emails of that account\n");//9.\n10.\n");
        scanf("%d", &asked_service);
        if (asked_service == 1) // For insert account in hash
        {
            printf("==================================\n");
            printf("EmailID example: example@gmail.com , please dont add same email twice\n");
            //We can also add function where it will first check if inserted email already exists or not
            same_indexinsert(size, Accounts_table);
        }
        else if (asked_service == 2) // To print all accounts of a particular index
        {
            char string[25];
            printf("==================================\n");
            // printf("Enter index you want to print all accounts of:");
            // scanf("%d", &insert_value);
            printf("Enter EmailID of the account to print details of it: ");
            scanf("%s", &string);
            Accounts_print(string, size, Accounts_table);
        }
        else if (asked_service == 3) // To Delete a account from node
        {
            printf("==================================\n");
            printf("Enter EmailID account you want to delete: ");
            scanf("%s", &todelete);
            Delete_Account(todelete, size, Accounts_table);
        }
        else if (asked_service == 4) // To update a value in node
        {                            // use less currently
            printf("==================================\n");
            printf("In progress\n");
                                     //  printf("==================================\n");
                                     //  printf("Enter account you want to update:");
                                     //  scanf("%d", &insert_value);
                                     //  printf("==================================\n");
                                     //  printf("Enter new value:");
                                     //  scanf("%d", &update_value);
                                     //  same_indexvalue_update(insert_value, size, Accounts_table, update_value);
        }
        else if (asked_service == 7) // For search
        {
            char string[25];
            printf("==================================\n");
            printf("Enter account holder EmailID you want to search: ");
            scanf("%s", &string);
            // scanf("%d", &search_value);
            Account_search(string, size, Accounts_table);
        }
        else if (asked_service == 8) // For Login Account
        {
            char string[25];
            printf("==================================\n");
            printf("Enter account email you want to Login: ");
            scanf("%s", &string);
            struct Account *AccounttoLogin = Account_search(string, size, Accounts_table);
            if (AccounttoLogin != NULL)
            {
           
                loginAccount(AccounttoLogin, Accounts_table); // accout table islie pass krrhe hen q k email send krte waqt searching ki zarurat parhti hai and wo hash table me hi hen accounts so that is required
            }

            // scanf("%d", &search_value);
        }
        else if (asked_service == 9) // For Delete Account
        {
        }
        else if (asked_service == 10) // For DElete start_ofsameindex
        {
        }
        else // if (asked_service==6)//Useless currently
        {
            break;
        }
    }

    printf("==================================\n");
    printf("Have a nice day :)\n");

    return 0;
}
//=======================================
/* yeh hai priority qeue wala
//Sufiyan Mohammad Salman
//B202103065
//Project is on Email management
//How accounts are stored (I have stored in Hash Table)
//How emails are stored for a particular account , I have stored Emails in priority que as I found it appropiate.
//How Emails sent and recieved , I have used qeue for this.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Account
{
    char EmailID[25] ;// EmailID of account , or wee can add email
    struct start_Email_details *EmailLog[10];//start islie dala q k is struct me sirf ek field hai and it will take less space
    struct Account *Next_account;// next account

};
struct start_Account
{
    struct Account *account_Start; // pointer of struct Account(first account)
};
struct Email_details
{
    char senderName[20];
    char RecieverName[20];
    char text[20];
   // struct Email_details *next_email
};
struct start_Email_details
{
    struct Email_details *Email_list;
    int Email_no;
    // char senderName[20];
    // char RecieverName[20];
    // char text[20];
};
//======================================
//Functions related to priority que
//max heap is priority que
//chlid to parent
//int((childnode_index-1)/2)
//parent to leftchild
//int(2(parentnode)+1)
//parent to rightchild
//int(2(parentnode)+2)
struct start_Email_details *EmailLog[10];// Email limit is 10
int parentNode=0;
// EmailLog[0]=123;
int flag=0;
// int leafNode=0;
// void swap()
// {
// }
void MaxheapInsert(int value, char sendername[], struct Account* reciever_account )
{//first email directly insert krwayenge
    struct Email_details* tmp = (struct Email_details*)malloc(sizeof(struct Email_details));//EMail ka structure generate hojayega
    // tmp->RecieverName=;
    // tmp->senderName=;
    // tmp->text=;
    if (reciever_account->EmailLog[0]==NULL)
    {
        reciever_account->EmailLog[0]->Email_list=tmp;
        reciever_account->EmailLog[0]->Email_no=1;
    }

    if (flag==2)//jab parent node k dono childs occupied hon to ek node aage krenge array me index ++
    {
        parentNode++;
        flag=0;//0 q k ab naya node hai aur iske dono childs khaali honge
    }
    int leftchild=2*(parentNode)+1;//ye agaya leftchild ka index of new parent
    int rightchild=2*(parentNode)+2;//ye agaya right child ka index of  new parent
    // int leafNode;
    if (flag==0)//matlab dono childs khaali
    {

       reciever_account->EmailLog[leftchild]->Email_list=tmp;
       reciever_account->EmailLog[leftchild]->Email_no=leftchild+1;

       while (reciever_account->EmailLog[leftchild]->Email_no  >   reciever_account->EmailLog[(int) (leftchild-1)/2]->Email_no)//child to paretn conversion//email no comparsion, the higher the Emailno_tobe_searched the top it would go
       {
           //swap
           struct start_Email_details *temp=EmailLog[leftchild];
           EmailLog[leftchild]=EmailLog[(int) (leftchild-1)/2];
           EmailLog[(int) (leftchild-1)/2]=temp;
           leftchild=(int) (leftchild-1)/2; //ab leftchild parent ban gaya
       }

       flag++;
    }
    else if (flag==1)//matlab left child is occupied and right child me node aygea
    {
       reciever_account->EmailLog[rightchild]->Email_list=tmp;
       reciever_account->EmailLog[rightchild]->Email_no=rightchild+1;
    //    EmailLog[rightchild]=value;
        // while (EmailLog[rightchild]>EmailLog[(int) (rightchild-1)/2])//child to paretn conversion
       while (reciever_account->EmailLog[rightchild]->Email_no  >   reciever_account->EmailLog[(int) (rightchild-1)/2]->Email_no)//child to paretn conversion//email no comparsion, the higher the Emailno_tobe_searched the top it would go
       {
           //swap
           struct start_Email_details * temp=EmailLog[rightchild];
           EmailLog[rightchild]=EmailLog[(int) (rightchild-1)/2];
           EmailLog[(int) (rightchild-1)/2]=temp;
           rightchild=(int) (rightchild-1)/2; //ab rightchild parent ban gaya
       }
       flag++;
    }


}

void heapyfi(struct Account* _accountof_email_tobedeleted, int valuetobeheaped_index, int last_index )
{

    int leftchild = 2 * (valuetobeheaped_index) + 1;
    int rightchild = 2 * (valuetobeheaped_index) + 2;
    //Print_array(_accountof_email_tobedeleted->EmailLog, 10);
    if (leftchild >= last_index && rightchild < last_index)
    { // jab node me sirf right child ho
    //directly swapping islie ki q k max tree h to swappe k baad child lazmi bara hi hoga
    //kia isme ek aur condition ayegi k parent value child se value bari ho to hi swapping ho
        printf("\nonly right child present: %d\n", _accountof_email_tobedeleted->EmailLog[rightchild]);
        int T = _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index];
        _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] = _accountof_email_tobedeleted->EmailLog[rightchild];
        _accountof_email_tobedeleted->EmailLog[rightchild] = T;
        printf("\nswapping values %d , %d :\n", _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index], _accountof_email_tobedeleted->EmailLog[rightchild]);
        heapyfi(_accountof_email_tobedeleted->EmailLog, rightchild, last_index); // jis value ko heap krna tha ab wo child ki jaga pe agaya hai
    }
    else if (rightchild >= last_index && leftchild < last_index)
    { // jab node me sirff left child ho
    //kia isme ek aur condition ayegi k parent value child se value bari ho to hi swapping ho
        printf("\nonly right child present: %d\n", _accountof_email_tobedeleted->EmailLog[leftchild]);
        int T = _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index];
        _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] = _accountof_email_tobedeleted->EmailLog[leftchild];
        _accountof_email_tobedeleted->EmailLog[leftchild] = T;
        printf("\nswapping values %d , %d :\n", _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index], _accountof_email_tobedeleted->EmailLog[leftchild]);
        heapyfi(_accountof_email_tobedeleted->EmailLog, leftchild, last_index); // jis value ko heap krna tha ab wo child ki jaga pe agaya hai
    }
    else if (leftchild < last_index && rightchild < last_index)
    {
        //agar lc bara hai rc se aur jis value se swap krna hai(parent) us se bhi bara hai to swap krdo
        if (_accountof_email_tobedeleted->EmailLog[leftchild] > _accountof_email_tobedeleted->EmailLog[rightchild]  &&  _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index]<_accountof_email_tobedeleted->EmailLog[leftchild] )
        {
            //if (_accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] < _accountof_email_tobedeleted->EmailLog[leftchild]) // agar parent se child bara hai to parent kijaga child ajaye
            //{  //ya to ye condition use krlo ya upr && k sath likhdo                                               // swapping
                int T = _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index];
                _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] = _accountof_email_tobedeleted->EmailLog[leftchild];
                _accountof_email_tobedeleted->EmailLog[leftchild] = T;
                printf("\nswapping values %d , %d :\n", _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index], _accountof_email_tobedeleted->EmailLog[leftchild]);
                heapyfi(_accountof_email_tobedeleted->EmailLog, leftchild, last_index); // jis value ko heap krna tha ab wo child ki jaga pe agaya hai
            //}
        }//agar rc bara hai lc se aur jis value se swap krna hai(parent) us se bhi bara hai to swap krdo
        else if (_accountof_email_tobedeleted->EmailLog[leftchild] < _accountof_email_tobedeleted->EmailLog[rightchild]  && _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] < _accountof_email_tobedeleted->EmailLog[rightchild]) // agar right bara hai
        {
            //if (_accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] < _accountof_email_tobedeleted->EmailLog[rightchild]) // agar parent se child bara hai to parent kijaga child ajaye
            //{  //ya to ye condition use krlo ya upr && k sath likhdo                                          // swapping
                int T = _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index];
                _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index] = _accountof_email_tobedeleted->EmailLog[rightchild];
                _accountof_email_tobedeleted->EmailLog[rightchild] = T;
                printf("\nswapping values %d , %d :\n", _accountof_email_tobedeleted->EmailLog[valuetobeheaped_index], _accountof_email_tobedeleted->EmailLog[rightchild]);
                heapyfi(_accountof_email_tobedeleted->EmailLog, rightchild, last_index); // jis value ko heap krna tha ab wo child ki jaga pe agaya hai
            //}
        }
    }
}

void deletefrom_heap( int arraysize, int Emailno_ofemail_tobe_deleted,struct Account* _accountof_email_tobedeleted )
{
  for (int i = 0; i <= arraysize - 1; i++) // first value ko last se swap krega
    {//SWAPPING
        if (_accountof_email_tobedeleted->EmailLog[i]->Email_no==Emailno_ofemail_tobe_deleted)
        {//last non zero elemnt of array se swap krna hai, agar ye khud last leaf ho to khair hai kuch nai krna
            int last_leafnode=0;
            while (last_leafnode<arraysize)//aray is is kept 10
            {
                if (_accountof_email_tobedeleted->EmailLog[last_leafnode]==NULL)
                {//iska matlab jese hi null mile to matlab us se pehle wala last leaf node hai
                    last_leafnode--;
                    break;
                }else if (last_leafnode==arraysize-1)
                {//array ka lasst element pe pohounch jaye agr
                    break;
                }
                last_leafnode++;


            }
            //swpping with last node
            printf("last email  is : %d\n", _accountof_email_tobedeleted->EmailLog[last_leafnode]->Email_no);
            struct start_Email_details * T =  _accountof_email_tobedeleted->EmailLog[i];// Email to be deleted goes to T
             _accountof_email_tobedeleted->EmailLog[i] = _accountof_email_tobedeleted->EmailLog[last_leafnode];//last leaf node gets swapped with index of Email to be dleted
            _accountof_email_tobedeleted->EmailLog[last_leafnode] = T;//Email to be delted goes leaf node
            free(_accountof_email_tobedeleted->EmailLog[last_leafnode]);
            _accountof_email_tobedeleted->EmailLog[last_leafnode] = NULL;//consider it as ddeleted
            //i is index of value to be deleted, abb= value to be deleted last leaf node me pari hai
             //is me jo i hamne pass kia hai,wo emailno hai of that emaill jisko heapify krna hia aur uski actual position pe ohounchana hai
            heapyfi(_accountof_email_tobedeleted , i , last_leafnode-1 );

            break;


        }


    }
}

void Print_array(int list[], int lengthofarray)
{
    for (int i = 0; i < lengthofarray; i++) // for viewing list
    {
        if (list[i]==NULL)
        {
            break;
        }

        printf(" %d ", list[i]);
    }
}

//Functions related to priority que end here
//======================================
// Functions related to Hash table for accounts
void array_nullmaker(struct start_Account Accounts_table[], int size)
{
    // yeh array ke saare starts ko null krdega
    int i = 0;
    while (i < size)
    {
        Accounts_table[i].account_Start = NULL;
        i++;
    }
}
unsigned int string_to_ascii(char* string)
{
    unsigned int Total_Ascii=0;
    int i=0;
    while (string[i]!='\0')
    {
        Total_Ascii+=(int) (string[i]);
        i++;
    }
    return(Total_Ascii);

}
void same_indexinsert(/*char * String_tobe_inserted,** int size, struct start_Account Accounts_table[]) // func Declaration
{
    int node_no = 0;
    //when struct char is pointer below two lines were used
    // unsigned int Ascii_of_string=string_to_ascii(String_tobe_inserted);
    // int index_of_valuetobe_inserted = Ascii_of_string % size;
    //printf("%d\n",Ascii_of_string);//Shows Ascii code

    struct Account *new_account = (struct Account *)malloc(sizeof(struct Account));
    printf("Enter String EmailID:");
    scanf("%s", new_account->EmailID);// These 2 lines have issues and code doesnt run if uncommented
    // fflsuh(stdout);// To get whole line input , but it is not working
    // fgets(new_account->EmailID,25,stdin);
    unsigned int Ascii_of_string=string_to_ascii(new_account->EmailID);
    int index_of_valuetobe_inserted = Ascii_of_string % size;
    //new_account->EmailID= strcpy(String_tobe_inserted,String_tobe_inserted);//when array
    //new_account->EmailID= String_tobe_inserted;//when is string is pointer
    new_account->Next_account = NULL;
    if (Accounts_table[index_of_valuetobe_inserted].account_Start == NULL)
    {
       // printf("fg");
        node_no++;
        Accounts_table[index_of_valuetobe_inserted].account_Start = new_account;
    }
    else
    {
        node_no++;
        struct Account *curr_account = Accounts_table[index_of_valuetobe_inserted].account_Start;
            printf("%s\n",Accounts_table[index_of_valuetobe_inserted].account_Start->EmailID);
        while (curr_account->Next_account != NULL)
        {
            printf("%s\n",Accounts_table[index_of_valuetobe_inserted].account_Start->Next_account->EmailID);
            // printf("gi\n");
            // printf("value %d , %s\n",node_no,curr_account->EmailID);
            node_no++;
            curr_account = curr_account->Next_account;
        }
        printf("loop se bahar\n");
        node_no++;
        curr_account->Next_account = new_account;
    }
    printf("Value added at index :%d and node: %d \n", index_of_valuetobe_inserted, node_no);
    //}
}

void Accounts_print(int index_tobe_printed, int size, struct start_Account Accounts_table[])
{ /// Print all values of a particular index
    // int index_tobe_printed; //=value_tobe_printed % size;
    if (Accounts_table[index_tobe_printed].account_Start == NULL)
    {
        printf("Sorry! The list is empty at this index\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_tobe_printed].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        while (curr_account != NULL)
        {
            printf("Strings are: %s \n", curr_account->EmailID);
            curr_account = curr_account->Next_account;
            // printf("%d",curr->next);
        }
    }
    // }
}

// void same_indexvalue_update(char* account_tobe_searched, int value_tobe_updated, int size, struct start_Account Accounts_table[], int update_value)
// {//update me hashing kharab hojayegi, so it is useless
//     int flag = 0, node_no = 0;
//     /// update a value
//     int index_ofvalue_tobeupdated = value_tobe_updated % size; //=value_tobe_printed % size;
//     if (Accounts_table[index_ofvalue_tobeupdated].account_Start == NULL)
//     {
//         //    Accounts_table[index_ofvalue_tobeupdated].account_Start=new_account ;
//         printf("Sorry! The list is empty at this index\n");
//     }
//     else
//     {
//         struct Account *curr_account = Accounts_table[index_ofvalue_tobeupdated].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
//         while (curr_account != NULL)
//         {
//             node_no++;
//             if (curr_account->value == value_tobe_updated)
//             {
//                 curr_account->value = update_value;
//                 printf("Value '%d ', updated at index: %d and Email_details: %d with '%d'\n", value_tobe_updated, index_ofvalue_tobeupdated, node_no, update_value);
//                 flag = 1;
//                 break;
//             }
//             curr_account = curr_account->Next_account;
//         }
//     }
//     if (flag == 0)
//     {
//         printf("Sorry! , Value not found\n");
//     }
// }

//==================================================

void Delete_Account(char* account_tobe_searched, int size, struct start_Account Accounts_table[])
{
    int flag = 0, node_no = 0;
    unsigned int Asciiof_String=string_to_ascii(account_tobe_searched);//Acii code of the given string
    int index_ofvalue_tobeSearched = Asciiof_String % size; //=value_tobe_printed % size;
    int index_ofvalue_tobedeleted = index_ofvalue_tobeSearched % size; //=value_tobe_printed % size;
    if (Accounts_table[index_ofvalue_tobedeleted].account_Start == NULL)
    {
        printf("Sorry! The list is empty at this index\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_ofvalue_tobedeleted].account_Start->Next_account, *prev = Accounts_table[index_ofvalue_tobedeleted].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        if (strcmp(Accounts_table[index_ofvalue_tobedeleted].account_Start->EmailID , account_tobe_searched)==0)
        {
            node_no++;
            Accounts_table[index_ofvalue_tobedeleted].account_Start = Accounts_table[index_ofvalue_tobedeleted].account_Start->Next_account;
            printf("Account '%s ', Deleted at index: %d and Email_details: %d\n", account_tobe_searched, index_ofvalue_tobedeleted, node_no);
            flag = 1;
            free(prev);
        }
        else
        {
            node_no++; // node ko 1 isle kia kyun k current bhi start k aage se shuru hota hai aur 1 na kren to inndexing me ans me no ek kam aata hai
            while (curr_account != NULL)
            {
                node_no++;
                if (strcmp(curr_account->EmailID , account_tobe_searched)==0)
                {
                    prev->Next_account = curr_account->Next_account;
                    printf("Account '%s ', Deleted at index: %d and Email_details: %d\n", account_tobe_searched, index_ofvalue_tobedeleted, node_no);
                    free(curr_account);
                    flag = 1;
                    // curr_account->value=update_value;
                    break;
                }
                // printf("Values are: %d \n", curr_account->value);
                prev = curr_account;
                curr_account = curr_account->Next_account;
                // printf("%d",curr->next);
            }
        }
        if (flag == 0)
        {
            printf("Sorry! , Value not found\n");
        }
        // curr_account->Next_account = new_account;
    }
}
void Account_search(char* account_tobe_searched, int size, struct start_Account Accounts_table[])
{
    /// update a value
    int flag = 0, node_no = 0;
    unsigned int Asciiof_String=string_to_ascii(account_tobe_searched);//Acii code of the given string
    int index_ofvalue_tobeSearched = Asciiof_String % size; //=value_tobe_printed % size;
    if (Accounts_table[index_ofvalue_tobeSearched].account_Start == NULL)
    {
        //    Accounts_table[index_ofvalue_tobeSearched].account_Start=new_account ;
        printf("Sorry! The list is empty at this index\n");
    }
    else
    {
        struct Account *curr_account = Accounts_table[index_ofvalue_tobeSearched].account_Start; // required index ka start isme daldia taake is index ki sari values print krsken
        while (curr_account != NULL)
        {
            if (string_to_ascii(curr_account->EmailID) == string_to_ascii(account_tobe_searched))
            {
                printf("String '%s ', Found at index: %d and Email_details: %d\n", account_tobe_searched, index_ofvalue_tobeSearched, node_no);
                // curr_account->value=update_value;
                flag = 1;
                break;
            }

            // printf("Values are: %d \n", curr_account->value);
            node_no++;
            curr_account = curr_account->Next_account;
            // printf("%d",curr->next);
        }
        if (flag == 0)
        {
            printf("Sorry! , Value not found\n");
        }

        // curr_account->Next_account = new_account;
    }
}
//Functions related to Hash table end here
int main()
{
    int asked_service, input, search_value, insert_value, update_value, size;
    char todelete[20];
    printf("\nEnter the size\t:\t");
    scanf("%d", &size);

    struct start_Account Accounts_table[size];
    array_nullmaker(Accounts_table, size);
    // inputArray(array, size);
    while (asked_service != 6)
    {
        printf("==================================\n");
        printf("Enter what do you wish to do?\n1.Create an Account\n2.Print accounts in a index\n3.Delete an account\n4.update a value\n6.To exit\n7.To Search an account\n8.\n9.\n10.\n");
        scanf("%d", &asked_service);
        if (asked_service == 1) // For insert in hash
        {
            char string[25];
            printf("==================================\n");
            //Below 3 lines when string is pointer
            // printf("Enter String : ");
            // scanf("%s", &string);
            // printf("value inserted %s\n",string);
            same_indexinsert( size, Accounts_table);

            // printf("Enter no of values,you want to input:");
            // scanf("%d", &no_of_elements);
            // for (int i = 0; i != no_of_elements; i++)
            // {
            //     printf("Enter value %d to input:", i + 1);
            //     scanf("%d", &insert_value);
            //     same_indexinsert(insert_value , size , Accounts_table);
            // }
        }
        else if (asked_service == 2) // To print all values of a particular index
        {
            printf("==================================\n");
            printf("Enter index you want to print all accounts of:");
            scanf("%d", &insert_value);
            Accounts_print(insert_value, size, Accounts_table);
        }
        else if (asked_service == 3) // To Delete a account from node
        {
            printf("==================================\n");
            printf("Enter EmailID account you want to delete:");
            scanf("%s", &todelete);
            Delete_Account(todelete, size, Accounts_table);
        }
        else if (asked_service == 4) // To update a value in node
        {//use less
            printf("==================================\n");
            printf("Enter value you want to update:");
            scanf("%d", &insert_value);
            printf("==================================\n");
            printf("Enter new value:");
            scanf("%d", &update_value);
            // same_indexvalue_update(insert_value, size, Accounts_table, update_value);

        }
        else if (asked_service == 7) // For search
        {
            char string[25];
            printf("==================================\n");
            printf("Enter account holder EmailID you want to search: ");
            scanf("%s", &string);
            // scanf("%d", &search_value);
            Account_search(string, size, Accounts_table);
        }
        else if (asked_service == 8) // For update Account
        {
        }
        else if (asked_service == 9) // For Delete Account
        {
        }
        else if (asked_service == 10) // For DElete start_ofsameindex
        {
        }
        else // if (asked_service==6)//Useless currently
        {
            break;
        }
    }

    printf("==================================\n");
    printf("Have a nice day :)\n");

    return 0;
}

*/