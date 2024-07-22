#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

    string alpha = " \n\nA B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n ";
    string game();
    string intro();
    string start();
    string x,y,ans;
    char z;
    int lives=3;
    int go;
    string letter;
    int main();

int main()
{
    intro();
    do
    {
    if (go=1)
    {
        start();
    }
    if (y == x)
    {
        break;
    }
    }
    while(lives > 0);
    if (lives <= 0)
    {
        cout<< "You Lost! The word is "<<x<< "\nSorry. Better luck next time!" << endl;
    }
    else if (y==x)
    {
        cout<< "You Won! " << "The right answer is: \n" << y << "!\n";
        cout<< "Manifesting lahat ng kaswertehan sayo!!"<<endl;
        cout<<"Congratulations!!! SLEIGHH! <3" << endl;
    }
    system("pause");
    system("cls");
    return 0;
}

string intro()
{
    int others=0;
    cout << " -------------------------------- " << endl;
    cout << " WELCOME TO HANGMAN GAME!! :)) " << endl;
    cout << " -------------------------------- " << endl;
    cout << " Directions: One Person will choose a word and draw the hangman.";
    cout << " Others will guess the chosen word by the player. " << endl;
    cout << " Please Enter your Word (IN CAPITAL LETTERS ONLY): ";
    getline (cin,x);
    for(int i=0;i<x.length();i++)
    {
        if(x[0]==' ')
        {
            continue;
        }
        if(int(x[i])<65||int(x[i])>90)
        {
            others = 1;
            break;
        }
    }
    if(others==0)
    {
        y.assign(x.length(),'_');
        for(int i=0;i<y.length();i++)
        {
            if (x[i]==' ') /*if the word has space, it will remain as space and does not count*/
            {
                y.replace(x.find(" ",i),1," ");
            }
        }
    system("pause");
    system("cls");
    go=1;
    }
    else if (others>0)
    {
        cout<<"Invalid input. Please enter word in CAPITAL LETTERS.\n";
        system("pause");
        system("cls");
        intro();
    }

}
    string start()
    {
        cout << "HERE ARE YOUR AVAILABLE CHARACTERS: "<< alpha <<endl;
        cout << "LIVES: " << lives<<endl;
        cout << "GUESS THE WORD: " << y << endl;
        cout << "ONE LETTER GUESS: ";
        z = getch();
        cout << z<<endl;
        while(true)
        {
            if (int(z)<65||int(z)>90)
            {
                cout<<"Invalid\n";
                system("pause");
                system("cls");
                break;
            }
            else
            {
                game();
                break;
            }
        }
    }
    string game()
    {
        int pos = x.find(z);
        int pos2 = alpha.find(z);
        if(pos2==std::string::npos)
        {
            cout << "You already entered it\n";
        }
        else if(pos!=std::string::npos)
        {
            alpha.replace(alpha.find(z),1,"-");
            for(int i=0; i<x.length();i++)
            {
            if(x[i]==z)
            {
                y[i]=x[i];
            }
            }
            y[pos]=x[pos];
            ans[pos]=z;
        }
        else
        {
            cout << "Wrong! Try another one; Just keep on guessing!\n" ;
            alpha.replace(alpha.find(z),1,"-");
            lives--;
        }
    system("pause");
    system("cls");
    }
