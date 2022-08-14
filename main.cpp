#include <iostream>
//202120246-MTHETHWA, MONGEZI NZUZO
using namespace std;
struct node{
    int info;
    node *Next;
};
struct node *Head, *Tail, *Current, *newNode;
bool listCreated=false;
void createNewList(){
    char flag='y';
    int value;

    cout << "Prepariong for a new list..." << endl;
    cout << "Do you want to create a new list 'Y/n'?: ";
    cin >> flag;
    if ((flag=='Y')  || (flag=='y')){
        listCreated=true;
        Tail=new node();
        cout << "Enter a value: ";
        cin >> value;
        Tail->info=value;
        Head=new node();
        Head->Next=Tail;
        Tail->Next=NULL;
        Current=Tail;
        while ((flag=='Y')  || (flag=='y')){
            cout << "Enter a value: ";
            cin >> value;
            if (value>=Tail->info){
                Tail=new node();
                Tail->info=value;
                Tail->Next=NULL;
                Current->Next=Tail;
                Current=Tail;
            }else{
                Current=Head;
                while(Current->Next->info<value){
                    Current=Current->Next;
                }
                newNode=new node();
                newNode->info=value;
                newNode->Next=Current->Next;
                Current->Next=newNode;
                Current=Tail;
            }
            cout << "Do you want to add another value 'Y/n'?: ";
            cin >> flag;
        }
        cout << "Completing a new list.." << endl;
        cout << "New list was created successful" << endl;
    }else cout << "New list creation cancelled" << endl;
}

void printList(){
    Current=Head->Next;
    while (Current!=NULL){
        cout << Current->info << "  ";
        Current=Current->Next;
    }
    cout << endl;
}

void insertValue(int input){
    cout << "inserting value " << input << "..." << endl;
    Current=Tail;
    if (input>=Tail->info){
        Tail=new node();
        Tail->info=input;
        Tail->Next=NULL;
        Current->Next=Tail;
        Current=Tail;
    }else{
        Current=Head;
        while(input>Current->Next->info){
            Current=Current->Next;
        }
        newNode=new node();
        newNode->info=input;
        newNode->Next=Current->Next;
        Current->Next=newNode;
        Current=Tail;
        //Current->Next=NULL;
    }
    cout << input << " was inserted successfully" << endl;
}

void searchListItem(int searchvalue){
    Current=Head->Next;
    while(Current->info<searchvalue){
        if (searchvalue==Current->Next->info){
            cout << "Value " << searchvalue << " is present in the list" << endl;
            Current=Tail;
            return;
        }else if (searchvalue>Tail->info){
            cout << "Value " << searchvalue << " was not found in the list" << endl;
            Current=Tail;
            return;
        }else Current=Current->Next;
    }
    Current=Tail;
    cout << "Value " << searchvalue << " was not found in the list" << endl;
}

void deleteListItem(int delValue){
    Current=Head;
    while(delValue<=Tail->info){
        if (Current->Next->info==delValue){
            if (Current->Next==Tail){    //Tail have to move back before deleting it's item
                newNode=Tail;
                Tail=Current;
                delete(newNode);
                Tail->Next=NULL;
                cout << "Value " << delValue << " was deleted successfully" << endl;
                return;
            }else{
                newNode=Current->Next;
                Current->Next=newNode->Next;
                delete(newNode);
                cout << "Value " << delValue << " was deleted successfully" << endl;
                Current=Tail;
                return;
            }

        }else if (Current->Next->info>delValue){
            cout << "Can't delete, value is not present in the list" << endl;
            return;
        }
        Current=Current->Next;
    }
    cout << "Can't delete, value is not present in the list" << endl;
}

void deleteList(){
    Current=Head;
    newNode=Head->Next;
    do{
        delete(Current);
        Current=newNode;
        newNode=newNode->Next;
    }while(Current!=Tail);
}

int main()
{
    int input, searchvalue, delValue, option;
    bool listExist=false;
    char bcreatenewlist;

    cout << "***Welcome***" << endl;
    createNewList();
    if (listCreated==true){
        do{
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
            cout << "Press a number corresponding to an action you want to perform(press '0' to end the program" << endl;
            cout << "1. Create a new list    2. Insert new item to the list    3. Search for an item in the list\n4. Delete an item from the list    5. Print the whole list    6. Clear screen" << endl;
            cout << "Option: ";
            cin >> option;
            switch (option){
                case 1:{
                    if (listExist==false){
                        createNewList();
                        listExist=true;
                    }else{
                        cout << "You have a list open, creating a new list will terminate the existing one.\nDo you wish to continue(Y/n)?: " << endl;
                        cin >> bcreatenewlist;
                        if ((bcreatenewlist=='Y') || (bcreatenewlist=='y')){
                            deleteList();
                            createNewList();
                        }
                    }
                }break;

                case 2: {
                    cout << "Enter a value you want to add: ";
                    cin >> input;
                    insertValue(input);
                }break;

                case 3: {
                    cout << "Enter a value you want to search for: ";
                    cin >> searchvalue;
                    searchListItem(searchvalue);
                }break;

                case 4: {
                    cout << "Enter a value you want to delete from the list: ";
                    cin >> delValue;
                    deleteListItem(delValue);
                }break;

                case 5: {
                    cout << "Your list displays: ";
                    printList();
                }break;

                case 6:{
                    system("CLS");
                    cout << "***Welcome***" << endl;
                }break;
            }
        }while(option!=0);
    }
    return 0;
}
