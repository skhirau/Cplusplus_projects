#pragma once

#include<iostream>
#include<conio.h>
#include"CLASSESS.CPP"
#include<fstream>
#include<stdlib.h>///for system("cls")

using namespace std;

class MemberFile : public Member
{
public:
    int getmid();
    void addMember();
    void showAllMembers();
    void showSpecificMember();
    void editMember();

};

int MemberFile::getmid()
{
    std::fstream fmember ;
    fmember.open("MEMBERS.DAT",std::ios::in|std::ios::binary);
    if (!fmember)
    {
        return (1) ;
    }

    fmember.seekg(0,std::ios::end);
    int n;
    n = (fmember.tellg())/sizeof(*this);
    ++n;
    fmember.close();
    return (n);

}

void MemberFile::addMember()
{
    char ch;
    do
    {
        this->mid = getmid();
        std::cout<<"\nMember id           : "<<this->mid;
        this->getm();
        this->isMember = 'y';
        this->totalBooksIssued = 0;
        this->fine = 0;

        std::cout<<"\n\n\nDo u want to save the member data ?(y/n)\n";
        fflush(stdin);
        ch = getchar();

        if(toLower(ch) == 'y')
        {
            std::fstream fmember ;
            fmember.open("MEMBERS.DAT",std::ios::in|std::ios::out|std::ios::binary);
            if(!fmember)
                fmember.open("MEMBERS.DAT",std::ios::out|std::ios::binary);


            fmember.seekg(0,std::ios::end);
            fmember.write((char*)this ,sizeof(*this));
            fmember.close();
        }

        std::cout<<"\nDo u want to add another member details ?(y/n) \n";
        fflush(stdin);
        ch = getchar();

    }while (toLower(ch) == 'y');
    return ;
}

void MemberFile::showAllMembers()
{
    std::fstream fmember;
    int x = 0,n ;

    fmember.open("MEMBERS.DAT",std::ios::in|std::ios::binary);
    if(!fmember)
    {
        std::cout<<"Currently there are no members of the library.";
        return ;
    }

    fmember.seekg(0,std::ios::end);
    n = (fmember.tellg())/sizeof(*this);

    if (n == 0)
    {
        std::cout<<"Currently there are no members of the library.";
        fmember.close();
        return ;
    }

    fmember.seekg(0,std::ios::beg);
    for(x = 0; x < n ; x++)
    {
        fmember.read((char*)this,sizeof(*this));
        this->showm(this->mid);
        std::cout<<"\n\n\nPress any key to continue to next member details";
        getch();
        system("cls");
    }

    fmember.close();
    return ;

}

void MemberFile::showSpecificMember()
{

    int x = 1,n;
    std::ifstream fmember;
    fmember.open("MEMBERS.DAT",std::ios::in|std::ios::binary);

    if(!fmember)
    {
        std::cout<<"Currently there are no members of the library.";
        return ;
    }

    fmember.seekg(0,std::ios::end);
    n = (fmember.tellg())/sizeof(*this);

    if (n == 0)
    {
        std::cout<<"Currently there are no members of the library.";
        fmember.close();
        return ;
    }

    std::cout<<"The total number of records are "<<n;
    std::cout<<"\nWhich member record u want to see ?\n";
    int num;
    std::cout<<"\nEnter the member id : \t";
    std::cin>>num;
    num--;
    fmember.seekg(num*(sizeof(*this)),std::ios::beg);
    fmember.read((char*)this,sizeof(*this));
    this->showm(this->mid);

    fmember.close();
    return ;

}

void MemberFile::editMember()
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

