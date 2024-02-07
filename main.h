
#include <iostream>
#include<ctime>
#include<cassert>
#include<queue>
#include<algorithm>
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include<unistd.h>
#include<AVLTree.h>
#include<user.h>
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/

inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,2);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/

int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+3);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,4);
    int c;
    printline("ENTER YOUR CHOICE :",false,15);
    cin >> c;
 return c;
}
int main()
{


    printline("START APPLICATION ....",1,11);
    wait_or_clear(1,1);
    cout<<"Enter first user in the application : "<<endl;
    int d = -1;
    //user u;
    //cin>>u;
  AVLTree<user>tree;
    while (d!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,15);
        d = get_menu_choise("MANAGE USERS ,MANAGE ACTIVITES",0);
        switch(d)
        {
        case 1:
        {
          string name;


           system("cls");
            printline("\n\nMAIN MENU -> MANAGE USERS ....");
             printline("\n(1)ADD A NEW USER\n(2)DELETE A USER\n(3)SEARCH FOR A USER\n(4)DISPLAY ALL USERS\n(5)DISPLAY MOST ACTIVE USER");
             int ch;
             cin>>ch;
             switch(ch){
         case 1:
             {

                 user u;
                 cin>>u;
                 tree.insert(u);
                 sleep(2);

             }
            break;
              case 2:
             {
                 string name;
                cout << "Enter user's name to delete: ";
                cin >> name;
                tree.delete_value(name);
                sleep(2);
               // break;
  }
            break;
             case 3:
             {
                 cout << "Enter user's name to Find: ";
                 cin >> name;
                tree.search_value(name);

              sleep(2);


             }
            break;
             case 4:
             {

              tree.level_order_traversal();
              sleep(3);

             }
            break;
             case 5:
             {
              cout<<"Most active user is : "<<endl;
              tree.most_active_user();
              sleep(3);

             }
            break;
        }
        }
        break;
        case 2 :{
         string name;
         string song;
        printline("\n\nMAIN MENU -> MANAGE ACTIVITIES ....");
             cout<<"\nEnter username  : "<<endl;
             cin>>name;
             tree.search_value(name);
             sleep(2);
        }
        break;
         case 0:
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            wait_or_clear(3, true);
        }
    }
    return 0;

}
