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
    LOAD,
    BYE
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
        vector<string> extensions;
        while(extension != "STOP")
        {
            extensions.push_back(extension);
            cin >> extension;
        }
        cout << "Veuillez saisir les extensions archivables acceptées lors la synchronisation. 'STOP' pour stopper : " << endl;
        cin >> archivable;
        vector<string> typeArchivable;
        while(archivable != "STOP")
        {
            typeArchivable.push_back(archivable);
            cin >> archivable;
        }
        p.addInformation(iPSource, sourceRepository, remoteRepository, extensions, typeArchivable);
        cout << "Ajout des informations dans le fichier effectué." << endl;
    }
}

void Client::editProfil(const string& name){
    string sourceRepository, remoteRepository, extension, archivable, iPSource, iPDestination;
    cout << "editProfil avec le nom " << name << endl;
    if(!this->existProfil(name)){
        cout << "Désolé, le nom de profil donné n'existe pas, il faut le créer..." << endl;
    }else{
        cout << "l'édition du profil est en cours..." << endl;
        Profil p(name);
        cout << "Veuillez saisir la nouvelle addresse IP destination: " << endl;
        cin >> iPDestination;
        cout << "Veuillez saisir la nouvelle addresse IP source: " << endl;
        cin >> iPSource;
        cout << "Veuillez saisir le nouveau répertoire de source : " << endl;
        cin >> sourceRepository;
        cout << "Veuillez saisir le nouveau répertoire destination : " << endl;
        cin >> remoteRepository;
        cout << "Veuillez saisir les nouvelles extensions acceptées lors la synchronisatio. 'STOP' pour stopper : " << endl;
        cin >> extension;
        vector<string> extensions;
        while(extension != "STOP")
        {
            extensions.push_back(extension);
            cin >> extension;
        }
        cout << "Veuillez saisir les nouvelles extensions archivables acceptées lors la synchronisation. 'STOP' pour stopper : " << endl;
        cin >> archivable;
        vector<string> typeArchivable;
        while(archivable != "STOP")
        {
            typeArchivable.push_back(archivable);
            cin >> archivable;
        }
        p.editProfil(iPSource, iPDestination, sourceRepository, remoteRepository, extensions, typeArchivable);
        cout << "Modification des informations dans le fichier effectué." << endl;
    }
}

void Client::loadProfil(const string& name){
    string sourceRepository, remoteRepository, extension, archivable, iPSource, iPDestination;
    cout << "editProfil avec le nom " << name << endl;
    if(!this->existProfil(name)){
        cout << "Désolé, le nom de profil donné n'existe pas, il faut le créer..." << endl;
    }else{
        cout << "Le chargement des données est en cours..." << endl;
        Profil p(name);
        p.loadProfil();
        cout << "Chargement des informations du fichier effectué." << endl;
    }
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
        cout << rawname << endl;
        if(rawname == name){
            return true;
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
    while(command != "BYE"){
        cin >> command >> name >> ip;
        if(command == "CREATE"){
            client.createProfil(name, ip);
        }else if(command == "EDIT"){
            client.editProfil(name);
        }else if(command == "LOAD"){
            client.loadProfil(name);
        }else{
            cout << "Commande non existante" << endl;
        }
    }
    return 0;
}
