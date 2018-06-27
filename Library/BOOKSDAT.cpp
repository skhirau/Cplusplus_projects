#pragma once

#include<iostream>
#include<conio.h>
#include"CLASSESS.CPP"
#include<fstream>
#include<stdlib.h>///for system("cls")

using namespace std;

class BookFile : public Book
{
public:
    int getbid();
    void addBook();
    void showAllBooks();
    void showSpecificBook();
    void editBook();

};

int BookFile::getbid()
{
    std::fstream fbook ;
    fbook.open("BOOKS.DAT",std::ios::in|std::ios::binary);
    if (!fbook)
    {
        return (1) ;
    }

    fbook.seekg(0,std::ios::end);
    int n;
    n = (fbook.tellg())/sizeof(*this);
    ++n;
    fbook.close();
    return (n);

}

void BookFile::addBook()
{
    char ch;
    do
    {
        this->bid = getbid();
        std::cout<<"\nBook id           : "<<this->bid;
        this->getb();
        this->availability = 'y';
        this->writeOff = 'n';

        std::cout<<"\n\n\nDo u want to save the book data ?(y/n)\n";
        fflush(stdin);
        ch = getchar();

        if(toLower(ch) == 'y')
        {
            std::fstream fbook ;
            fbook.open("BOOKS.DAT",std::ios::in|std::ios::out|std::ios::binary);
            if(!fbook)
                fbook.open("BOOKS.DAT",std::ios::out|std::ios::binary);


            fbook.seekg(0,std::ios::end);
            fbook.write((char*)this ,sizeof(*this));
            fbook.close();
        }

        std::cout<<"\nDo u want to add another book details ?(y/n) \n";
        fflush(stdin);
        ch = getchar();

    }while (toLower(ch) == 'y');
    return ;
}

void BookFile::showAllBooks()
{
    std::fstream fbook;
    int x = 0,n ;

    fbook.open("BOOKS.DAT",std::ios::in|std::ios::binary);
    if(!fbook)
    {
        std::cout<<"No book has been entered in the library yet.";
        return ;
    }

    fbook.seekg(0,std::ios::end);
    n = (fbook.tellg())/sizeof(*this);

    if (n == 0)
    {
        std::cout<<"There are currently no books in the library";
        fbook.close();
        return ;
    }

    fbook.seekg(0,std::ios::beg);
    for(x = 0; x < n ; x++)
    {
        fbook.read((char*)this,sizeof(*this));
        this->showb(this->bid);
        std::cout<<"\n\n\nPress any key to continue to next book details";
        getch();
        system("cls");
    }

    fbook.close();
    return ;

}

void BookFile::showSpecificBook()
{

    int x = 1,n;
    std::ifstream fbook;
    fbook.open("BOOKS.DAT",std::ios::in|std::ios::binary);

    if(!fbook)
    {
        std::cout<<"No book has been entered in the library yet.";
        return ;
    }

    fbook.seekg(0,std::ios::end);
    n = (fbook.tellg())/sizeof(*this);

    if (n == 0)
    {
        std::cout<<"There are currently no books in the library.";
        fbook.close();
        return ;
    }

    std::cout<<"The total number of records are "<<n;
    std::cout<<"\nWhich book record u want to see ?\n";
    int num;
    std::cout<<"\nEnter the book id : \t";
    std::cin>>num;

    if( num < 1 || num > n)
    {
        std::cout<<"\nInvalid book id entered.";
        std::cout<<"\nEnter the book id again : \t";
        std::cin>>num ;
    }
    num--;
    fbook.seekg(num*(sizeof(*this)),std::ios::beg);
    fbook.read((char*)this,sizeof(*this));
    this->showb(this->bid);

    fbook.close();
    return ;

}

void BookFile::editBook()
{
    ;
}


/**
int main()
{


    getch();
    return 0;
}
*/
