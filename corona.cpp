#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node *next;
};

class linked_list{
private:
    node *head, *tail;
    int ssize;
public:
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    void add_node(string n){
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        ssize++;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display(){
        int cnt = 0;
        node *tmp = head;
        while(true){
            cnt++;
            if(cnt == ssize){
                cout << tmp -> data << endl << endl;
                break;
            }
            else cout << tmp -> data << ", ";

            tmp = tmp -> next;
        }
    }
    bool ssearch(string d){
        node *tmp = head;
        while(tmp != NULL){
            if(tmp->data == d) return true;
            tmp = tmp -> next;
        }
        return false;
    }
};

typedef struct patient{

    int id;
    string name;
    string address;
    string covid_19_report_date;
    linked_list disease;

    patient *next;
} patient;

patient *head_new = NULL;

void add_patient(){

    patient *new_patient = (patient*)malloc(sizeof(patient));

    cout << "Id: ";
    int iid;
    cin >> iid;
    cin.ignore();
    new_patient -> id = iid;

    cout << "Name: ";
    string temp;
    getline(cin, temp);
    new_patient -> name = temp;


    cout << "Address: ";
    getline(cin, temp);
    new_patient -> address = temp;

    cout << "Covid - 19 Report Date: ";
    getline(cin, temp);
    new_patient -> covid_19_report_date = temp;

    cout << "Previous Diseases (Please enter a blank line when end of diseases):" << endl;
    while(getline(cin, temp)){
        if(temp.size() == 0) break;
        (new_patient -> disease).add_node(temp);
    }

    new_patient -> next = NULL;
    if(head_new == NULL) head_new = new_patient;
    else{
        new_patient -> next = head_new;
        head_new = new_patient;
    }

    cout << "\aData Recorded!" << endl << endl;
}

void search_by_id(){

    cout << "Id: ";
    int x;
    cin >> x;
    bool flag = false;
    patient *temp = head_new;

    int cnt = 0;
    while(temp != NULL){
        if(temp->id == x){

            cout << endl;
            cout << "Searched Information " << ++cnt << endl;

            flag = true;
            cout << "Id: " << temp -> id << endl;
            cout << "Name: " << temp -> name << endl;
            cout << "Address: " << temp -> address << endl;
            cout << "covid - 19 Report Date: " << temp -> covid_19_report_date << endl;
            cout << "Disease: ";
            (temp->disease).display();
            cout << endl;
        }
        temp = temp -> next;
    }
    if(!flag) cout << "\aNot Found!" << endl << endl;
}

void search_by_name(){

    cin.ignore();
    cout << "Name: ";
    string x;
    getline(cin, x);

    int cnt = 0;
    bool flag = false;
    patient *temp = head_new;
    while(temp != NULL){
        if(temp->name == x){

            cout << endl;
            cout << "Searched Information " << ++cnt << endl;

            flag = true;
            cout << "Id: " << temp -> id << endl;
            cout << "Name: " << temp -> name << endl;
            cout << "Address: " << temp -> address << endl;
            cout << "covid - 19 Report Date: " << temp -> covid_19_report_date << endl;
            cout << "Disease: ";
            (temp->disease).display();
            cout << endl;
        }
        temp = temp -> next;
    }
    if(!flag) cout << "\aNot Found!" << endl << endl;
}

void search_by_disease(){

    cout << "Disease: ";
    cin.ignore();
    string x;
    getline(cin, x);

    int cnt = 0;
    bool flag = false;
    patient *temp = head_new;
    while(temp != NULL){
        if((temp->disease).ssearch(x) == true){

            cout << endl;
            cout << "Searched Information " << ++cnt << endl;

            flag = true;
            cout << "Id: " << temp -> id << endl;
            cout << "Name: " << temp -> name << endl;
            cout << "Address: " << temp -> address << endl;
            cout << "covid - 19 Report Date: " << temp -> covid_19_report_date << endl;
            cout << "Disease: ";
            (temp->disease).display();
            cout << endl;
        }
        temp = temp -> next;
    }
    if(!flag) cout << "\aNot Found!" << endl << endl;
}

void search_patient(){
    cout << endl;
    cout << "1. Search by id" << endl;
    cout << "2. Search by name" << endl;
    cout << "3. Search by disease" << endl;
    cout << "4. Go Back" << endl;

    cout << "Please Select Your Option (1-4): ";

again:
    int option;
    cin >> option;

    if(option >= 1 and option <= 4){
        if(option == 1) search_by_id();
        else if(option == 2) search_by_name();
        else if(option == 3) search_by_disease();
        else{
            cout << endl;
            return;
        }
    }
    else{
        cout << "\aInvalid Input! " << "Please Select Your Option (1-4): ";
        goto again;
    }
}

void delete_patient(){

    cout << endl;
    cin.ignore();
    cout << "Patient name that you want to delete: ";
    string x;
    getline(cin, x);

    if(head_new->name == x){
        patient *out = head_new;
        head_new = head_new->next;
        free(out);

        cout << "\aDeleted!" << endl << endl;

        return;
    }

    bool flag = false;
    patient *temp = head_new;
    while(temp -> next != NULL){
        if(temp -> next -> name == x){
            flag = true;
            patient *out = temp -> next;
            temp -> next = temp -> next -> next;
            free(out);

            cout << "\aDeleted!" << endl << endl;

            return;
        }
        temp = temp -> next;
    }
    if(!flag) cout << "\aNot Found!" << endl << endl;
}

void update_patient(){
    cout << endl;

    cout << "Enter id of the patient that you want to update: ";
    int x;
    cin >> x;
    cin.ignore();

    bool flag = false;
    patient *temp = head_new;
    int cnt = 0;
    while(temp != NULL){
        if(temp->id == x){

            flag = true;

            string y, z;

            cout << "Updated Adress: ";
            getline(cin, y);
            cout << "Updated Covid - 19 Report Date: ";
            getline(cin, z);

            temp -> address = y;
            temp -> covid_19_report_date = z;

            cout << endl <<  "\aDone!" << endl;
            return;
        }
        temp = temp -> next;
    }
    if(!flag) cout << "\aNot Found!" << endl << endl;
}

void display_patient(){
    cout << endl;
    patient *temp = head_new;
    int cnt = 0;
    bool flag = false;
    while(temp != NULL){

        flag = true;
        cout << "Patient " << ++cnt << ":" << endl;

        cout << "Id: " << temp -> id << endl;
        cout << "Name: " << temp -> name << endl;
        cout << "Address: " << temp -> address << endl;
        cout << "covid - 19 Report Date: " << temp -> covid_19_report_date << endl;
        cout << "Disease: ";
        (temp->disease).display();

        temp = temp -> next;
    }

    if(!flag) cout << "No Patient!" << endl << endl;
}

int main(){

    cout << "Covid - 19 Patient Management System" << endl;

    start:

    cout << "1. Add a patient" << endl;
    cout << "2. Search a patient" << endl;
    cout << "3. Delete a patient" << endl;
    cout << "4. Update a patient" << endl;
    cout << "5. Disply all patient" << endl;
    cout << "6. Exit" << endl;

    cout << "Please Select Your Option (1-6): ";

again:
    int option;
    cin >> option;

    if(option >= 1 and option <= 6){
        if(option == 1) {
            add_patient();
            goto start;
        }
        else if(option == 2){
            search_patient();
            goto start;
        }
        else if(option == 3){
            delete_patient();
            goto start;
        }
        else if(option == 4){
            update_patient();
            goto start;
        }
        else if(option == 5) {
            display_patient();
            goto start;
        }
        else return 0;
    }
    else{
        cout << "\aInvalid Input! " << "Please Select Your Option (1-6): ";
        goto again;
    }
}

