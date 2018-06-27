#pragma once

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
    return (rand()%n + 1);
}


int main()
{
    int x = 1, n = 20;
    randomixe();
    for(x = 1 ; x <= n ; x++)
    {
        std::cout<<random(n)<<"  ";
    }
    getch();
    return 0;
}
