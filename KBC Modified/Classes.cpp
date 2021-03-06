#pragma once
#include<string.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>///for rand(),srand()
#include<time.h>///for time()
#include<stdio.h>///for gets()

using namespace std;

void randomixe()
{
    time_t t;
    time(&t);
    srand(t);
}

int random(int n)
{
    return (rand()%n);
}

char toLower(char c)
{
    if ( c >= 'A' && c <= 'Z')
        return(c + ('a' - 'A'));
    return c;
}

class KBC
{
protected:
    int questionNo ;
    char question[200] ;
    char option1[50],option2[50],option3[50],option4[50];
    char answer;
    char isrepeated;

public:
    void get();
    void showq();
    void showa();
    char retIsrepeated(){return isrepeated ;}
    void setIsrepeated(char a){ isrepeated = a;}

    char* retQuestion(){return this->question ;}
    void setQuestion(char *a){ strcpy(this->question,a);}

    char* retOp1(){return this->option1 ;}
    void setOp1(char *a){ strcpy(this->option1 ,a);}

    char* retOp2(){return this->option2 ;}
    void setOp2(char *a){ strcpy(this->option2 ,a);}

    char* retOp3(){return this->option3 ;}
    void setOp3(char *a){ strcpy(this->option3 ,a);}

    char* retOp4(){return this->option4 ;}
    void setOp4(char *a){ strcpy(this->option4 ,a);}

    char  retAns(){return this->answer ;}
    void setAns(char a){ this->answer=a;}





};

void KBC::get()
{
    std::cout<<"\nEnter the question : \n" ;
    fflush(stdin);
    gets(question);

    std::cout<<"\nEnter the choices one by one : ";
    std::cout<<"\nChoice (A) : ";
    fflush(stdin);
    gets(option1);
    std::cout<<"\nChoice (B) : ";
    fflush(stdin);
    gets(option2);
    std::cout<<"\nChoice (C) : ";
    fflush(stdin);
    gets(option3);
    std::cout<<"\nChoice (D) : ";
    fflush(stdin);
    gets(option4);

    std::cout<<"\nFrom the above options,which choice is the answer ?";
    std::cout<<"\nEnter the alphabet - a/b/c/d/A/B/C/D : \t";
    fflush(stdin);
    answer = getchar();
    while(  !(answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd'||
             answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D'))
    {
        std::cout<<"\nU have entered a wrong character";
        std::cout<<"\nPlease enter the alphabet again- a/b/c/d/A/B/C/D   :   ";
        fflush(stdin);
        answer = getchar();
    }
    return;
}

void KBC::showq()
{
    std::cout<<"QUESTION :\n\n";
    std::cout<<question<<"\n\n";
    std::cout<<"\nChoice (A) : "<<option1;
    std::cout<<"\nChoice (B) : "<<option2;
    std::cout<<"\nChoice (C) : "<<option3;
    std::cout<<"\nChoice (D) : "<<option4;
}

void KBC::showa()
{
    std::cout<<"\nThe answer is \n";
    switch (answer)
    {
        case 'a' :
            std::cout<<"\nChoice (A) : "<<option1;
            break;
        case 'A' :
            std::cout<<"\nChoice (A) : "<<option1;
            break;
        case 'b' :
            std::cout<<"\nChoice (B) : "<<option2;
            break;
        case 'B' :
            std::cout<<"\nChoice (B) : "<<option2;
            break;
        case 'c' :
            std::cout<<"\nChoice (C) : "<<option3;
            break;
        case 'C' :
            std::cout<<"\nChoice (C) : "<<option3;
            break;
        case 'd' :
            std::cout<<"\nChoice (D) : "<<option4;
            break;
        case 'D' :
            std::cout<<"\nChoice (D) : "<<option4;
            break;
    }
    return;
}
