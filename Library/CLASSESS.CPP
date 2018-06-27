#pragma once

#include<iostream>
#include<conio.h>
#include<stdio.h> ///for gets()
#include<fstream>

using namespace std;

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' -'A'));
    return c;
}

void strcpy(char *,char *);

class Book
{
public:
    int bid ;
    char bookName[50];
    char authorName[50];
    int price;
    char availability ;
    char writeOff;
public:
    void getb();
    void showb(int id);
    int show_sp_b(int id);

};

void Book::getb()
{
    std::cout<<"\nEnter book name   : ";
    fflush(stdin);
    gets(bookName);
    std::cout<<"\nEnter author name : ";
    fflush(stdin);
    gets(authorName);
    std::cout<<"\nEnter price       : ";
    fflush(stdin);
    std::cin>>price ;

}

void Book::showb(int id)
{
    std::cout<<"\nBook id       : "<<bid;
    std::cout<<"\nBook name     : "<<bookName;
    std::cout<<"\nAuthor name   : "<<authorName;
    std::cout<<"\nPrice         : "<<price;
    if (toLower(availability) == 'y')
        std::cout<<"\nBook status   : Available";
    else
        std::cout<<"\nBook status   : NOT-Available";

    if (toLower(writeOff) == 'y')
        std::cout<<"\nWrittenOff    : yes";
    else
        std::cout<<"\nWrittenOff    : no";
}

int Book::show_sp_b(int id)
{
    int n ;
    ifstream fbook ;
    fbook.open("BOOKS.DAT",std::ios::in|std::ios::binary);

    if(!fbook)
    {
        std::cout<<"No book has been entered in the library yet.";
        return 0;
    }

    fbook.seekg(0,std::ios::end);
    n = (fbook.tellg()/sizeof(*this));

    if (n == 0)
    {
        std::cout<<"There are currently no books in the library";
        fbook.close();
        return 0;
    }

    if (id < 1 || id > n)
    {
        fbook.close();
        return (-1);
    }

    id--;
    fbook.seekg(id*(sizeof(*this)),std::ios::beg);
    fbook.read((char*)this,sizeof(*this));
    showb(this->bid);
    fbook.close();
    return 1;
}

class Member
{
public:
    int mid;
    char memberName[100];
    char isMember ;
    int totalBooksIssued ;
    int fine ;
public:
    void getm();
    void showm(int );
    int show_sp_m(int id);
};

void Member::getm()
{
    std::cout<<"\nEnter the member name :\n";
    fflush(stdin);
    gets(memberName);
    return ;
}

void Member::showm(int id)
{
    std::cout<<"\nMember id          : "<<mid;
    std::cout<<"\nMember name        : "<<memberName;
    if (toLower(isMember) == 'y')
        std::cout<<"\nMembership         : Member";
    else
        std::cout<<"\nMembership         : NOT a Member/Membership Expired";
    if (toLower(isMember) == 'y')
        std::cout<<"\nTotal Books Issued : "<<totalBooksIssued;
    std::cout<<"\nFine               : "<<fine;
    return ;
}

int Member::show_sp_m(int id)
{
    int n ;
    ifstream fmember ;
    fmember.open("MEMBERS.DAT",std::ios::in|std::ios::binary);

    if(!fmember)
    {
        std::cout<<"Currently there are no members of the library.";
        return 0;
    }

    fmember.seekg(0,std::ios::end);
    n = (fmember.tellg()/sizeof(*this));

    if (n == 0)
    {
        std::cout<<"Currently there are no members of the library.";
        fmember.close();
        return 0;
    }

    if (id < 1 || id > n)
    {
        fmember.close();
        return (-1);
    }

    id--;
    fmember.seekg(id*(sizeof(*this)),std::ios::beg);
    fmember.read((char*)this,sizeof(*this));
    showm(this->mid);
    fmember.close();
    return 1;
}


class Date
{
public:
    int d,m,y;
};

class Issue
{
public:
    int bid,mid;
    Date issueDate,dueDate ;

    void geti();
    void showi(int,int);
};
void Issue::geti()
{
    std::cout<<"\nEnter issue date :  ";
    std::cout<<"\nDay      :   ";
    std::cin>>issueDate.d;
    std::cout<<"\nMonth    :   ";
    std::cin>>issueDate.m;
    std::cout<<"\nYear     :   ";
    std::cout<<issueDate.y;
    std::cout<<"\n";

    std::cout<<"\nEnter due date   :  ";
    std::cout<<"\nDay      :   ";
    std::cin>>dueDate.d;
    std::cout<<"\nMonth    :   ";
    std::cin>>dueDate.m;
    std::cout<<"\nYear     :   ";
    std::cin>>dueDate.y;
    return ;
}

void Issue::showi(int bid,int mid)
{
    std::cout<<"\nBook id    :  "<<bid;
    std::cout<<"\nMember id  :  "<<mid;

    std::cout<<"\nIssue date :  ";
    std::cout<<"\nDay      :   "<<issueDate.d;
    std::cout<<"\nMonth    :   "<<issueDate.m;
    std::cout<<"\nYear     :   "<<issueDate.y;
    std::cout<<"\n";

    std::cout<<"\nDue date   :  ";
    std::cout<<"\nDay      :   "<<dueDate.d;
    std::cout<<"\nMonth    :   "<<dueDate.m;
    std::cout<<"\nYear     :   "<<dueDate.y;
    return ;
}


class History
{
public:
    int bid,mid ;
    char bookName[50],memberName[100];
    Date issueDate,dueDate,returnDate ;
    int fine ;

    void geth();
    void showh(int,int);
};

void History::geth()
{
    std::cout<<"Enter return date :";
    std::cout<<"Day       :  ";
    std::cin>>returnDate.d ;
    std::cout<<"Month     :  ";
    std::cin>>returnDate.m;
    std::cout<<"Year      :  ";
    std::cin>>returnDate.y;
}

void History::showh(int bid,int mid)
{
    std::cout<<"\nbid         :  "<<bid;
    std::cout<<"\nmid         :  "<<mid;
    std::cout<<"\nBook name   :  "<<bookName;
    std::cout<<"\nMember name :  "<<memberName;

    std::cout<<"\nIssue date  :  ";
    std::cout<<"\nDay      :   "<<issueDate.d;
    std::cout<<"\nMonth    :   "<<issueDate.m;
    std::cout<<"\nYear     :   "<<issueDate.y;
    std::cout<<"\n";

    std::cout<<"\nDue date    :  ";
    std::cout<<"\nDay      :   "<<dueDate.d;
    std::cout<<"\nMonth    :   "<<dueDate.m;
    std::cout<<"\nYear     :   "<<dueDate.y;

    std::cout<<"Return date   :  ";
    std::cout<<"Day        :   "<<returnDate.d;
    std::cout<<"Month      :   "<<returnDate.m;
    std::cout<<"Year       :   "<<returnDate.y;
}

void strcpy(char *a,char *b)
{
    int i = 0;
    for(i = 0 ; b[i] != '\0' ; i++)
    {
        a[i] = b[i] ;
    }
    a[i] = '\0';
    return ;
}

/**
int main()
{
    ;
    return 0;
}
*/
