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
        if(rawname == name){
            return true;
        }else{
            reponse = false;
        }
    }
    closedir (dir);
    return reponse;
}

bool Client::parcourirDirectory(const string& chemin){
    DIR *dir;
    struct dirent *entry;
    
    stringstream ss1;
    ss1 << chemin;
    
    dir = opendir(ss1.str().c_str());
    
    if(!dir){
        cout << "Le dossier n'est pas existant" << endl;
        return false;
    }
    while ((entry = readdir(dir)) != NULL) {
        string nameFileFils = entry->d_name;
        
        if(nameFileFils.compare(".") ==0  || nameFileFils.compare("..") ==0 ){
            
        }else{
            std::stringstream ssFinal;
            ssFinal << chemin <<"/" <<nameFileFils;
            
            struct stat info;
            stat(ssFinal.str().c_str(), &info);
            
            if(S_ISDIR(info.st_mode)){
                string s = ssFinal.str();
                
                parcourirDirectory(s);
                
            }else{
                time_t t = info.st_mtime;
                struct tm lt;
                localtime_r(&t, &lt);
                char timbuf[80];
                strftime(timbuf, sizeof(timbuf), "%b %d %R", &lt);
                
                cout << ssFinal.str().c_str() << " " << info.st_size<< " "<< timbuf << endl;
            }
            
        }
        
    }
    return true;
}

int main() {
    string command = "", name, ip;
    Client client;
    while(command != "BYE"){
        //cin >> command >> name >> ip;
        cin >> command;
        if(command == "CREATE"){
            cin >> name >> ip;
            client.createProfil(name, ip);
        }else if(command == "EDIT"){
            cin >> name >> ip;
            client.editProfil(name);
        }else if(command == "LOAD"){
            cin >> name;
            client.loadProfil(name);
        }else if(command == "BYE"){
            cout << "Bonsoir !" << endl;
            return 0;
        }else{
            cout << "Commande non existante" << endl;
        }
    }
//    string chemin ="/Users/coussmax/Downloads";
//    client.parcourirDirectory(chemin);
    return 0;
}
