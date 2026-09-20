#include<iostream>
#include <string>
using namespace std;

void welcome(){
    cout << "==================" << endl;
    cout << "   CONTACT APP    " << endl;
    cout << "==================" << endl;
    cout << endl;
    cout << "1. List" << endl;
    cout << "2. Add" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Input: " << endl;
}

struct contact{
    string name,number;
};
contact add[1000];

int getinput(){
    int x {};
    cin >> x;
    return x;
}

void listcontact(int numberofcontact){
    for(int i=0;i<numberofcontact;i++){
        cout << "Contact " << i + 1 << endl;
        cout << "Name: " << endl;
        cout << add[i].name << endl;
        cout << "Number: " << endl;
        cout << add[i].number << endl;
        cout << endl;
    }
    cout << "Number of contacts: " << numberofcontact << endl;
}

void addcontact(int&numberofcontact){
    cout << "How many contacts to add: ";
    int size { getinput() };
    cout << endl;
    if(size + numberofcontact > 1000 || size < 1){
        cout << "Can't add contacts" << endl;
        goback();
    }
    else{
        cin.ignore();
        for(int i=numberofcontact;i<size+numberofcontact;i++){
            cout << "Name: ";
            getline(cin,add[i].name);
            cout << endl;
            cout << "Number: ";
            getline(cin,add[i].number);
            cout << endl;
        }
        cout << "Contact has been added" << endl;
        numberofcontact += size;
    }
}

void deletecontact(int numberofcontact){
     cout << "Enter contact number to delete: " << endl;
    int remove {};
    cin >> remove;
    remove--;
    if(remove >=0 && remove < numberofcontact){
        for(int i=remove;i<numberofcontact-1;i++){
            add[i] = add[i+1];
        }
        numberofcontact--;
        cout << "Succesfully deleted" << endl;
    }
    else{
        cout << "Invalid Contact" << endl;
    }
}
void bugfix(){
    cout << "Invalid input" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
}

void goback(){
    cout << "Type anything to back:" << endl;
    string x;
    cin >> x;
}

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
