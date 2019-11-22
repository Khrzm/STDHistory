#include "header.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<"= = = WELCOME TO OUR WEBSITE = = = \n";
    cout<<"\n";
    cout<<"Kelompok :\n";
    cout<<"Deril Apririaldi Fasya (1301180504)\n";
    cout<<"M. Febiansyah (1301180293) \n";
    cout<<"Clara Gracilyn (1301184474)\n";
    cout<<"Imam Ilham Khawarizma (1301180436) \n";
    cout<<"\n";
    cout<<"Enjoykeun\n";
    getch();
    system("cls");

    //DEKLARASI LIST
    listBookmark LBookmark;
    listWebsite LWebsite;
    listDate LDate;
    first(LBookmark)=NULL;
    first(LWebsite)=NULL;
    first(LDate)=NULL;
    char key;

    //MENU UTAMA
    do{
        cout<<"= = = Barokah Browser = = =\n";
        cout<<"1 : Open New Tab \n";
        cout<<"2 : History\n";
        cout<<"3 : Bookmark\n";
        cout<<"\n";
        cout<<"(Press 0 to exit program) \n";
        key=_getch();
        switch (key){
            case '0':
                    break;
            case '1':
                    system("cls");
                    openTab(LWebsite,LBookmark);
                    cout<<"\n";
                    break;
            case '2':
                    system("cls");
                    viewHistory(LWebsite);
                    getch();
                    break;
            case '3':
                    system("cls");
                    openBookmark(LBookmark);
                    getch();
                    break;
            default :
                    cout << "Input Salah" <<endl;
        }
        system("cls");
    }while(key!='0');
    cout<<" Hatur Nuhun Sadayana... \n";
    cout<<"\n";
    system("PAUSE");
    return 0;
}


