#include<iostream>
using namespace std;

void welcome(){
    cout << "===========" << endl;
    cout << "CONTACT APP" << endl;
    cout << "===========" << endl;
    cout << endl;
    cout << "1. List" << endl;
    cout << "2. Add" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Input: " << endl;
}

void bugfix(){
    cout << "Invalid input" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
}
struct contact{
    string name,number;
};
int main(){
    contact add[1000];
    int ammount = 0;
    int input,remove;
    int size = 0;
    string end = "y";
    string back;
    welcome();
    while(end == "y"){
        cin >> input;
        if(cin.fail()){
            bugfix();
            welcome();
        }
        else{
            if(input==2){
                cout << "How many contacts to add: ";
                cin >> ammount;
                cout << endl;
                if(ammount + size > 1000 || ammount < 1){
                    cout << "Can't add contacts" << endl;
                    welcome();
                }
            else{
                for(int i=size;i<ammount+size;i++){
                    cout << "Name: ";
                    cin >> add[i].name;
                    cout << endl;
                    cout << "Number: ";
                    cin >> add[i].number;
                    cout << endl;
                }
                cout << "Contact has been added" << endl;
                size += ammount;
                welcome();
            }
        }
            else if(input == 1){
                for(int i=0;i<size;i++){
                    cout << "Contact " << i + 1 << endl;
                    cout << "Name: " << endl;
                    cout << add[i].name << endl;
                    cout << "Number: " << endl;
                    cout << add[i].number << endl;
                    cout << endl;
                }
                cout << "Number of contacts: " << size << endl;
                cout << "Type anything to back" << endl;
                cin >> back;
                welcome();
            }
            else if(input == 3){
                cout << "Enter contact number to delete: " << endl;
                cin >> remove;
                if(cin.fail()){
                    bugfix();
                    welcome();
                }
                else{
                    remove--;
                    if(remove >=0 && remove < size){
                    for(int i=remove;i<size-1;i++){
                        add[i] = add[i+1];
                    }
                    size--;
                    cout << "Succesfully deleted" << endl;
                    welcome();
                    }
                    else{
                        cout << "Invalid Contact" << endl;
                        welcome();
                    }
                }
            }
            else if(input == 4){
                break;
            }
            else{
                cout << "Invalid input" << endl;
                welcome();
            }
        }
    }
}
