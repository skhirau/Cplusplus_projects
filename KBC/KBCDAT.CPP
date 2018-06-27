#include"Classes.cpp"
#include<fstream>

class KBCFILE : public KBC
{
public :
    void addQuestion();
    void showAllQuestions();
    int checkQuestionNo();
    void showSpecificQuestion(int qn,int z);
    void editQuestion();
    void deleteQuestion();
    void playKBC();
};

int getquestionNo()
{
    KBC k;
    int n;
    fstream fobj ;

    fobj.open("KBC.DAT",std::ios::in|std::ios::binary);

    if(!fobj)
        return 1;

    fobj.seekg(0,std::ios::end);
    n = (fobj.tellg())/sizeof(k);
    n++;
    fobj.close();
    return n;
}

void KBCFILE::addQuestion()
{
    char ch;

    do
    {
        system("cls");
        this->questionNo = getquestionNo();
        this->get();
        this->isrepeated = 'n';

        std::cout<<"\n\nDo u want to save the entered question ?(y/n)";
        fflush(stdin);
        ch = getchar();
        if (toLower(ch) != 'y')
        {
            std::cout<<"\nQuestion discarded/not added";
            std::cout<<"\n\nDo u want to add another question ?(y/n)";
            fflush(stdin);
            ch = getchar();
            continue ;
        }

        fstream fobj ;
        fobj.open("KBC.DAT",std::ios::in|std::ios::out|std::ios::binary);
        if(!fobj)
        {
            fobj.open("KBC.DAT",std::ios::out|std::ios::binary);
        }

        fobj.seekg(0,std::ios::end);
        fobj.write((char*)this,sizeof(*this));

        std::cout<<"\n\nQuestion added/saved.";
        fobj.close();
        std::cout<<"\n\nDo u want to add another question ?(y/n)";
        fflush(stdin);
        ch = getchar();

    }while(toLower(ch) == 'y');

    return ;
}

void KBCFILE::showAllQuestions()
{
    fstream fobj;
    char ch;
    fobj.open("KBC.DAT",std::ios::in|std::ios::binary);
    if(!fobj)
        std::cout<<"\nThere are no questions added yet.";

    while(fobj.read((char*)this,sizeof(*this)) != 0)
    {
        system("cls");
        this->showq();
        std::cout<<"\n\nDo u want to see the answer also ?(y/n) \t";
        fflush(stdin);
        ch = getchar();
        if (toLower(ch) != 'y')
        {
            std::cout<<"\n\nPress any key to proceed to the next question.";
            getch();
            continue;
        }
        std::cout<<"\n";
        this->showa();
        std::cout<<"\n\nPress any key to proceed to the next question.";
        getch();
    }
    fobj.close();
    return;
}

int KBCFILE::checkQuestionNo()
{
    int qsn;
    fstream fobj;
    fobj.open("KBC.DAT",std::ios::in|std::ios::binary);
    if(!fobj)
    {
        std::cout<<"There are no questions added yet.";
        return 0;
    }
    fobj.seekg(0,std::ios::end);
    int n = (fobj.tellg())/sizeof(*this);

    if (n ==0)
    {
        std::cout<<"There are currently no questions available.";
        fobj.close();
        return 0;
    }

    std::cout<<"\n\nThere are total "<<n<<" questions available";
    std::cout<<"\nWhich one u want to see ?";
    std::cout<<"\n\n\nEnter the question no.  \t";
    std::cin>>qsn;

    while (!(qsn >= 1 && qsn <= n))
    {
        std::cout<<"\nU have entered the wrong question number";
        std::cout<<"\nPlease enter again :\t" ;
        std::cin>>qsn;
    }
    fobj.close();
    return qsn;

}

void KBCFILE::showSpecificQuestion(int qn,int z)
{
    int x = qn;
    x--;
    char ch,ans;
    fstream fobj;
    fobj.open("KBC.DAT",std::ios::in|std::ios::binary);
    if(!fobj)
        return;
    fobj.seekg(x*(sizeof(*this)),std::ios::beg);
    fobj.read((char*)this,sizeof(*this));
    system("cls");
    this->showq();

    if(z == 1)
    {
        std::cout<<"\n\nFrom the above options,which choice do u think is the answer ?";
        std::cout<<"\nEnter the alphabet - a/b/c/d/A/B/C/D : \t";
        fflush(stdin);
        ans = getchar();
        while(  !(ans == 'a' || ans == 'b' || ans == 'c' || ans == 'd'||
                 ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D'))
        {
            std::cout<<"\nU have entered a wrong character";
            std::cout<<"\nPlease enter the alphabet again- a/b/c/d/A/B/C/D   :   ";
            fflush(stdin);
            ans = getchar();
        }
        if (toLower(ans) == this->answer)
        {
            std::cout<<"\n\nCongratulations,you have selected the right answer.";
            fobj.close();
            return;
        }
        else
        {
            std::cout<<"\n\nSorry,you have entered the wrong answer";
            std::cout<<"\n\nDo u want to see the correct answer ?(y/n) \t";
            fflush(stdin);
            ch = getchar();
            if (toLower(ch) == 'y')
                this->showa();
            fobj.close();

            return;
        }

    }
    std::cout<<"\n\nDo u want to see the answer ?(y/n) \t";
    fflush(stdin);
    ch = getchar();
    if (toLower(ch) == 'y')
        this->showa();
    fobj.close();

    return;

}

void KBCFILE::editQuestion()
{
    char ch;
    std::cout<<"\n\nDo u want to edit the question details ?";
    fflush(stdin);
    ch = getchar();
    if(toLower(ch) != 'y')
    {
        std::cout<<"\nQuestion details not edited";
        return ;
    }
    system("cls");
    std::cout<<"\nEnter new question details.\n\n";
    this->get();
    int x = this->questionNo;
    x--;
    fstream fobj;
    fobj.open("KBC.DAT",std::ios::in|std::ios::out|std::ios::binary);
    fobj.seekg(x*(sizeof(*this)),std::ios::beg);
    fobj.write((char*)this,sizeof(*this));
    std::cout<<"\n\nQuestion edited.";
    fobj.close();
    return ;

}

void KBCFILE::deleteQuestion()
{
    char ch;
    std::cout<<"\n\nDo u want to delete the question ?";
    fflush(stdin);
    ch = getchar();
    if(toLower(ch) != 'y')
    {
        std::cout<<"\nQuestion is not deleted.";
        return ;
    }

    fstream fobj,ftemp;
    fobj.open("KBC.DAT",std::ios::in|std::ios::out|std::ios::binary);
    ftemp.open("TEMP.DAT",std::ios::out|std::ios::binary);
    int x = this->questionNo;
    while(fobj.read((char*)this,sizeof(*this)) != 0)
    {
        if (this->questionNo == x)
            continue ;
        ftemp.write((char*)this,sizeof(*this));
    }
    fobj.close();
    ftemp.close();
    remove("KBC.DAT");
    rename("TEMP.DAT","KBC.DAT");
    std::cout<<"\n\nObject deleted.";

    return ;
}


void KBCFILE::playKBC()
{
    fstream fobj;
    fobj.open("KBC.DAT",std::ios::in|std::ios::out|std::ios::binary);
    while(fobj.read((char*)this,sizeof(*this)) != 0)
    {
        this->isrepeated = 'n';
        int x = this->questionNo;
        x--;
        fobj.seekg(x*(sizeof(*this)),std::ios::beg);
        fobj.write((char*)this,sizeof(*this));
    }
    fobj.close();

    ///Now every question is ready to be asked

    randomixe();
    int n;
    char ch,ans;
    fobj.open("KBC.DAT",std::ios::in|std::ios::out|std::ios::binary);
    fobj.seekg(0,std::ios::end);
    n = (fobj.tellg())/sizeof(*this);
    int x,y,counnt = 0;

    for (int j = 1; j <= 20 ; j++)
    {
        std::cout<<"\nOuter loop repeating";
        getch();
        counnt = 0;
        fobj.seekg(0,std::ios::beg);
        while(fobj.read((char*)this,sizeof(*this)) != 0)
        {
            getch();
            if (this->isrepeated == 'y')
                counnt++ ;
            std::cout<<"\nCounnt is "<<counnt;
        }

        if (counnt == n)
            break ;


        system("cls");
        x = y = random(n);
        x--;
        fobj.seekg(x*sizeof(*this),std::ios::beg);
        fobj.read((char*)this,sizeof(*this));
        while (this->isrepeated == 'y')
        {
            x = y = random(n);
            x--;
            fobj.seekg(x*sizeof(*this),std::ios::beg);
            fobj.read((char*)this,sizeof(*this));
            std::cout<<"\nInside the loop";
        }
        showSpecificQuestion(y,1);
        this->isrepeated = 'y';
        fobj.seekg(x*(sizeof(*this)),std::ios::beg);
        fobj.write((char*)this,sizeof(*this));

        std::cout<<"\n\nDo u want to play more ?(y/n) \t";
        fflush(stdin);
        ch = getchar();
        if (toLower(ch) != 'y')
        {
            break;
        }

    }
    fobj.close();
    system("cls");
    std::cout<<"\n\n\t\tThank you for Playing with us .";
    std::cout<<"\n\n\n\n\t\t\t\tK.B.C. OVER";
    return;
}
