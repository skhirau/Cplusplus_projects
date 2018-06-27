#include<iostream>
#include<conio.h>
#include"Booksdat.cpp"
#include"Membersdat.cpp"
#include"ISSUEDAT.CPP"
#include<stdlib.h>///for system("cls")

void newEntriesMenu()
{
    int op ;

    system("cls");
    std::cout<<"\n\t\t\t\tNew Entries Menu";
    std::cout<<"\n\n";
    std::cout<<"\n\t\t1.Add Book.";
    std::cout<<"\n\t\t2.Add Member.";
    std::cout<<"\n3.EXIT";

    std::cout<<"\n\nEnter your choice number :\t";
    std::cin>>op;

    system("cls");
    switch (op)
    {
        case 1:
            BookFile b;
            b.addBook();
            break;
        case 2:
            MemberFile m;
            m.addMember();
            break;

    }
};

void showAllRecordsMenu()
{
    int op;

    system("cls");
    std::cout<<"\n\t\t\t\tShow Records Menu";
    std::cout<<"\n\n";
    std::cout<<"\n\t\t1.Show All Books";
    std::cout<<"\n\t\t2.Show All Members";
    std::cout<<"\n\t\t3.Show All Transactions";
    std::cout<<"\n\t\t4.Show History.";
    std::cout<<"\n5.EXIT";

    std::cout<<"\n\nEnter your choice number :\t";
    std::cin>>op;

    system("cls");
    switch (op)
    {
        case 1:
            BookFile b;
            b.showAllBooks();
            break;
        case 2:
            MemberFile m;
            m.showAllMembers();
            break;
        case 3:
            break;
        case 4:
            break;

    }

}

void showSpecificRecordMenu()
{
    int op;
    system("cls");
    std::cout<<"\n\t\t\t\tShow Specific Record Menu";
    std::cout<<"\n\n";
    std::cout<<"\n\t\t1.Show Specific Book.";
    std::cout<<"\n\t\t2.Show Specific Member.";
    std::cout<<"\n3.EXIT";

    std::cout<<"\n\nEnter your choice number :\t";
    std::cin>>op;

    system("cls");
    switch (op)
    {
        case 1:
            BookFile b;
            b.showSpecificBook();
            break;
        case 2:
            MemberFile m;
            m.showSpecificMember();
            break;

    }

}

void showRecordsMenu()
{
    int op;
    do
    {
        system("cls");
        std::cout<<"\n\t\t\t\tShow Records Menu";
        std::cout<<"\n\n";
        std::cout<<"\n\t\t1.Show All Records.";
        std::cout<<"\n\t\t2.Show Specific Records.";
        std::cout<<"\n3.EXIT";

        std::cout<<"\n\nEnter your choice number :\t";
        std::cin>>op;

        system("cls");
        switch (op)
        {
            case 1:
                showAllRecordsMenu();
                std::cout<<"\n\n\nPress any key to return to the Show Records Menu";
                fflush(stdin);
                getch();
                break;
            case 2:
                showSpecificRecordMenu();
                std::cout<<"\n\n\nPress any key to return to the Main Menu.";
                getch();
                break;

        }

    }while (op >= 1 && op<= 2);

    return ;
}

void TransactionsMenu()
{
    int op ;

    system("cls");
    std::cout<<"\n\t\t\t\tTransactions Menu";
    std::cout<<"\n\n";
    std::cout<<"\n\t\t1.Issue books";
    std::cout<<"\n\t\t2.Return books";
    std::cout<<"\n\t\t3.Show All Transactions";
    std::cout<<"\n\t\t4.Show History.";
    std::cout<<"\n5.EXIT";

    std::cout<<"\n\nEnter your choice number :\t";
    std::cin>>op;

    system("cls");
    switch (op)
    {
        case 1:
            IssueFile i;
            i.issueBook();
            break;
        case 2:
            i.returnBook();
            break;
        case 3:
            break;
        case 4:
            break;

    }
    return ;
}

void MainMenu()
{
    int op ;
    do
    {
        system("cls");
        std::cout<<"\n\t\t\t\tMain Menu";
        std::cout<<"\n\n";
        std::cout<<"\n\t\t1.Make new entries.";
        std::cout<<"\n\t\t2.Show Records.";
        std::cout<<"\n\t\t3.Transactions.";
        std::cout<<"\n\t\t4.Edit any Record.";
        std::cout<<"\n\t\t5.Delete any Record.";
        std::cout<<"\n6.EXIT";

        std::cout<<"\n\nEnter your choice number :\t";
        std::cin>>op;

        system("cls");
        switch(op)
        {
            case 1:
                newEntriesMenu();
                std::cout<<"\n\n\nPress any key to return to the Main Menu.";
                fflush(stdin);
                getch();
                break;
            case 2:
                showRecordsMenu();
                std::cout<<"\n\n\nPress any key to return to the Main Menu.";
                fflush(stdin);
                getch();
                break;
            case 3:
                TransactionsMenu();
                std::cout<<"\n\n\nPress any key to return to the Main Menu.";
                fflush(stdin);
                getch();
                break;


        }


    }while (op >= 1 && op <= 5);
};


int main()
{
    MainMenu();

    getch();
    return 0;
}
