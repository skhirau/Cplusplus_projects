#include<iostream>
#include<conio.h>
#include"KBCDAT.cpp"

void mainMenu()
{
    KBCFILE k;
    int op ;
    do
    {
        system("cls");///given in <stdlib.h>
        std::cout<<"\n\t\t\t\tMain Menu";
        std::cout<<"\n\n\n\t\t1.Add a new Question.";
        std::cout<<"\n\t\t2.Show all Questions.";
        std::cout<<"\n\t\t3.Show a specific Question";
        std::cout<<"\n\t\t4.Edit Question.";
        std::cout<<"\n\t\t5.Delete Question";
        std::cout<<"\n\n\n\t\t6.Play K.B.C.";
        std::cout<<"\n\n7.EXIT";
        std::cout<<"\n\n\nEnter your choice number : \t";
        std::cin>>op;

        system("cls");

        switch(op)
        {
            case 1:
                k.addQuestion();
                break;
            case 2:
                k.showAllQuestions();
                break;
            case 3:
                int i ;
                i= k.checkQuestionNo();
                if (i != 0)
                    k.showSpecificQuestion(i,0);
                std::cout<<"\n\n\nPress any key.";
                getch();
                break;
            case 4:
                i= k.checkQuestionNo();
                if (i != 0)
                {
                    k.showSpecificQuestion(i,0);
                    k.editQuestion();
                }
                std::cout<<"\n\n\nPress any key.";
                getch();
                break;
            case 5:
                i= k.checkQuestionNo();
                if (i != 0)
                {
                    k.showSpecificQuestion(i,0);
                    k.deleteQuestion();
                }
                std::cout<<"\n\n\nPress any key.";
                getch();
                break;
            case 6:
                k.playKBC();
                std::cout<<"\n\n\nPress any key.";
                getch();
                break;

        }
        std::cout<<"\n\n\nPress any key.";

    }while (op >= 1  &&  op <= 6);
}
int main()
{
    mainMenu();

    getch();
    return 0;
}
