//
//  Client.cpp
//  
//
//  Created by Maxime Cousseau on 18/11/2018.
//

#include "Client.hpp"
#include <iostream>
#include <string>
using namespace std;

enum Command{
    CREATE,
    EDIT,
    LOAD
};

Client::Client(){
    
}

void Client::createProfil(const string& name){
    cout << "createProfil avec le nom " << name << endl;
    if(this->existProfil(name)){
        cout << "Yes" << endl;
    }else{
        cout << "Nop" << endl;
    }
}

void Client::editProfil(){
    cout << "editProfil\n";
}

void Client::loadProfil(){
    cout << "loadProfil\n";
}

bool Client::existProfil(const string& name){
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    bool reponse;
    
    dir = opendir("../configuration");
    if(!dir){
        cout << "Le dossier n'est pas existant" << endl;
        return false;
    }
    
    cout << "Le dossier existe bien.\nRecherche du fichier en cours" << endl;
    while ((entry = readdir(dir)) != NULL) {
        if((entry->d_name) == name){
            reponse = true;
        }else{
            reponse = false;
        }
        printf ("%s\n", entry->d_name);
    }
    closedir (dir);
    return reponse;
}

int main() {
    string command = "", name, ip;
    Client client;
    while(command != "EXIT"){
        cin >> command >> name;
        if(command == "CREATE"){
            client.createProfil(name);
        }else if(command == "EDIT"){
            client.editProfil();
        }else if(command == "LOAD"){
            client.loadProfil();
        }else{
            cout << "Commande non existante" << endl;
        }
    }
    return 0;
}
