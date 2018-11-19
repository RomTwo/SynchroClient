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

void Client::createProfil(const string& name, const string& ip){
    string sourceRepository, remoteRepository, extension, archivable, iPSource;
    cout << "createProfil avec le nom " << name << endl;
    if(this->existProfil(name)){
        cout << "Désolé, le nom de profil donné existe déjà..." << endl;
    }else{
        cout << "La création du fichier est en cours" << endl;
        Profil p(name, ip);
        p.createFile(name, ip);
        cout << "La création du fichier est terminée" << endl;
        cout << "Veuillez saisir votre addresse IP : " << endl;
        cin >> iPSource;
        cout << "Veuillez saisir le répertoire de source : " << endl;
        cin >> sourceRepository;
        cout << "Veuillez saisir le répertoire destination : " << endl;
        cin >> remoteRepository;
        cout << "Veuillez saisir les extensions acceptées lors la synchronisatio. 'STOP' pour stopper : " << endl;
        cin >> extension;
        string array[100], array2[100];
        int i = 0;
        while((extension != "STOP") && (i < 100))
        {
            array[i] = extension;
            i++;
            cin >> extension;
        }
        cout << "Veuillez saisir les extensions archivables acceptées lors la synchronisation. 'STOP' pour stopper : " << endl;
        cin >> archivable;
        i = 0;
        while((archivable != "STOP") && (i < 100))
        {
            array2[i] = archivable;
            i++;
            cin >> archivable;
        }
        cout << "Ajout des informations dans le fichier effectué." << endl;
        p.addInformation(iPSource, sourceRepository, remoteRepository, array, array2);
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
        string file = entry->d_name;
        string rawname = file.substr(0, file.find_last_of("."));
        if(rawname == name){
            reponse = true;
        }else{
            reponse = false;
        }
    }
    closedir (dir);
    return reponse;
}

int main() {
    string command = "", name, ip;
    Client client;
    while(command != "EXIT"){
        cin >> command >> name >> ip;
        if(command == "CREATE"){
            client.createProfil(name, ip);
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
