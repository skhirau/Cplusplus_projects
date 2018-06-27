#pragma once

#include<iostream>
#include<conio.h>
#include"Classess.cpp"
#include"BOOKSDAT.CPP"
#include"MEMBERSDAT.CPP"

using namespace std;

class IssueFile : public Issue
{
public:
    void issueBook();
    void returnBook();
};

void IssueFile::issueBook()
{
    BookFile b;
    MemberFile m;
    char ch;

    do
    {
        int bd,md ;
        std::cout<<"Enter the book id ";
        std::cin>>bd;

        int j = b.show_sp_b(bd);

        while (j == -1)
        {
            std::cout<<"\nInvalid book id entered.";
            std::cout<<"\nEnter the book id again : \t";
            std::cin>>bd ;
            j = b.show_sp_b(bd);
        }

        if(j == 0)
            return ;

        std::cout<<"\n\nEnter the member id ";
        std::cin>>md;

        j = m.show_sp_m(md);

        while (j == -1)
        {
            std::cout<<"\nInvalid member id entered.";
            std::cout<<"\nEnter the member id again : \t";
            std::cin>>md ;
            j = m.show_sp_m(md);
        }

        if(j == 0)
            return ;

        ///Yahan aa gaye matlab bd,md sahi dale hain

        this->bid = bd;
        this->mid = md;

        if (toLower(b.availability) != 'y')
        {
            std::cout<<"\nBook is already issued/not available.";
            std::cout<<"\nBook cannot be issued.";
            return ;
        }

        if (toLower(m.isMember) != 'y')
        {
            std::cout<<"\nYou are currently not a member of library/your membership expired.";
            std::cout<<"\nYou cannot issue a book.";
            return ;
        }

        if (m.totalBooksIssued == 3)
        {
            std::cout<<"\nYou have reached the limit of issuing maximum books.";
            std::cout<<"\nYou cannot issue another book.";
            return ;
        }

        ///yahan aa gaye matlab book issue ho sakti hai.

        std::cout<<"\n\nDo u want to issue the book ?(y/n) \n";
        fflush(stdin);
        ch = getchar();

        if(toLower(ch) != 'y')
        {
            std::cout<<"\n\nDo u want to issue another book ?(y/n) \n";
            fflush(stdin);
            ch = getchar();
            continue ;
        }



        ///maine specific book aur specific member show kiya tha so,
        ///b amd m objects mein sahi values stored hai.so,
        ///just edit it before overwriting in the file.

        b.availability = 'n';
        m.totalBooksIssued++ ;

    ///BOOKS.DAT and MEMBERS.DAT are opened here.

        std::fstream fbook,fmember,fissue ;
        fbook.open("BOOKS.DAT",std::ios::in|std::ios::out|std::ios::binary);
        fmember.open("MEMBERS.DAT",std::ios::in|std::ios::out|std::ios::binary);
        int x,y;

        x = bd;
        y = md;
        x--;
        y--;

        fbook.seekg(x*(sizeof(b)),std::ios::beg);
        fbook.write((char*)&b,sizeof(b)); ///overwritten in BOOKS.DAT file

        fmember.seekg(y*(sizeof(m)),std::ios::beg);
        fmember.write((char*)&m,sizeof(m)); ///overwritten in MEMBERS.DAT file

        fbook.close();
        fmember.close();
    ///BOOKS.DAT and MEMBERS.DAT file are closed here.

    ///ISSUE.DAT file is opened here
        fissue.open("ISSUE.DAT",std::ios::in|std::ios::out|std::ios::binary);
        fissue.seekg(0,std::ios::end);

        this->geti();

        fissue.write((char*)this,sizeof(*this));

        fissue.close();
    ///ISSUE.DAT is closed here.

        b.show_sp_b(bd);
        std::cout<<"\n\n";
        m.show_sp_m(md);
        std::cout<<"\n\nBook issued.";

        std::cout<<"\n\nDo u want to issue more book ?(y/n) \n";
        fflush(stdin);
        ch = getchar();

    } while (toLower(ch) == 'y');
    return ;

}

void IssueFile::returnBook()
{
    fstream fbook,fmember,fissue,fhistory ;
    BookFile b;
    MemberFile m;
    History h;
    int bd,md;
    std::cout<<"\nEnter the member id:\t";
    std::cin>>md;
    int j = m.show_sp_m(md);

    while(j == -1)
    {
        std::cout<<"\nInvalid member id entered.";
        std::cout<<"\nEnter the member id again : \t";
        std::cin>>md ;
        j = m.show_sp_m(md);
    }

    std::cout<<"\n\nEnter the book id";
    std::cin>>bd;

    j = b.show_sp_b(bd);

    while (j == -1)
    {
        std::cout<<"\nInvalid book id entered.";
        std::cout<<"\nEnter the book id again : \t";
        std::cin>>bd ;
        j = b.show_sp_b(bd);
    }

    /// id sahi mil gayi
    ///b aur m objects mein sahi value already aa chuki hai.

    if (toLower(b.availability) == 'y')
    {
        std::cout<<"\nThis book is not issued to anyone.";
        std::cout<<"\nU cannot return this book.";
        return ;
    }

    b.availability = 'y';
    m.totalBooksIssued-- ;



///ISSUE.DAT is opened here to read the issue and due dates
///HISTORY.DAT is opened here.
///TEMP.DAT is opened here.

    fissue.open("ISSUE.DAT",std::ios::in|std::ios::out|std::ios::binary);
    fhistory.open("HISTORY.DAT",std::ios::in|std::ios::out|std::ios::binary);

    if(!fhistory)
    {
        fhistory.open("HISTORY.DAT",std::ios::out|std::ios::binary);
    }

    fhistory.seekg(0,std::ios::end);
    fissue.seekg(0,std::ios::end);

    fstream ftemp;
    ftemp.open("TEMP.DAT",std::ios::out|std::ios::binary);

    int n = (fissue.tellg())/sizeof(*this);
    fissue.seekg(0,std::ios::beg);

    int i = 1;
    for(i = 1;i <= n ;i++)
    {
        fissue.read((char*)this,sizeof(*this));
        if (this->bid == bd)
        {
            h.bid = bd;
            h.mid = md;
            strcpy(h.bookName,b.bookName);
            strcpy(h.memberName,m.memberName);
            h.issueDate = this->issueDate ;
            h.dueDate = this->dueDate ;
            h.geth();

            h.fine = ( 2*(h.returnDate.d - h.dueDate.d) + 50*(h.returnDate.m - h.dueDate.m));
            fhistory.write((char*)&h,sizeof(h));
            continue ;
        }

        ftemp.write((char*)this,sizeof(*this));
    }

    fissue.close();
    ftemp.close();
    fhistory.close();
///ISSUE.DAT,TEMP.DAT,HISTORY.DAT are closed here.
    std::remove("ISSUE.DAT");
    rename("TEMP.DAT","ISSUE.DAT");

    m.fine = h.fine;

///BOOKS.DAT and MEMBERS.DAT are opened here.

    fbook.open("BOOKS.DAT",std::ios::in|std::ios::out|std::ios::binary);
    fmember.open("MEMBERS.DAT",std::ios::in|std::ios::out|std::ios::binary);

    int x = bd,y = md;
    x--;
    y--;

    fbook.seekg(x*(sizeof(b)),std::ios::beg);
    fmember.seekg(y*(sizeof(m)),std::ios::beg);

    fbook.write((char*)&b,sizeof(b));
    fmember.write((char*)&m,sizeof(m));

    fbook.close();
    fmember.close();

///BOOKS.DAT and MEMBERS.DAT files are closed here.

    std::cout<<"\n\nBook Returned.";

    return;

}
/**
int main()
{


    getch();
    return 0;
}
*/
