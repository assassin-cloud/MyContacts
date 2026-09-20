#include "function.h"
#include<iostream>
using namespace std;
int main(){
    int numberofcontact {};
    while(true){
        welcome();
        int userinput { getinput() };
        if(cin.fail()){
            bugfix();
        }

        else{

            if(userinput == 1){
                listcontact(numberofcontact);
                goback();
            }

            else if(userinput == 2){
                addcontact(numberofcontact);
                goback();
            }

            else if(userinput == 3){
                deletecontact(numberofcontact);
                goback();
            }

            else if(userinput == 4){
                break;
            
            }
            else{
                cout << "Invalid input" << endl;
            }
        }
    }
}
