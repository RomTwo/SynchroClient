//
//  Profil.cpp
//  
//
//  Created by Maxime Cousseau on 19/11/2018.
//

#include "Profil.hpp"

Profil::Profil(const string& name, const string& iPRemote){
    this->name = name;
    this->ipDestination = iPRemote;
}

Profil::Profil(const string& name){
    this->name = name;
}

void Profil::createFile(const string& name, const string& ipRemote){
    this->profil.open("../configuration/"+this->name+this->extension, ostream::out);
    this->profil << name << endl;
    this->profil << ipRemote << endl;
    this->profil.close();
}

void Profil::addInformation(const string& iPSource, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable){
    this->profil.open("../configuration/"+this->name+this->extension, std::ios_base::app | ostream::out);
    this->profil << iPSource << endl;
    this->profil << sourceRepository << endl;
    this->profil << remoteRepository << endl;
    this->profil << extension.size() << endl;//Permet de savoir combien d'extensions se situe dans le profil
    for(string e : extension){
        this->profil << e << endl;
    }
    this->profil << typeArchivable.size() << endl;//Permet de savoir combien de type archivable se situe dans le profil
    for(string ta : typeArchivable){
        this->profil << ta << endl;
    }
    this->profil.close();
}

void Profil::editProfil(const string& iPSource, const string& iPRemote, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable){
    this->profil.open("../configuration/"+this->name+this->extension, ostream::out);
    this->profil << this->name << endl;
    this->profil << iPRemote << endl;
    this->profil << iPSource << endl;
    this->profil << sourceRepository << endl;
    this->profil << remoteRepository << endl;
    this->profil << extension.size() << endl;//Permet de savoir combien d'extensions se situe dans le profil
    for(string e : extension){
        this->profil << e << endl;
    }
    this->profil << typeArchivable.size() << endl;//Permet de savoir combien de type archivable se situe dans le profil
    for(string ta : typeArchivable){
        this->profil << ta << endl;
    }
}

void Profil::loadProfil(){
    string str;
    this->profil.open("../configuration/"+this->name+this->extension, istream::in);
    getline(this->profil, str);
    this->name = str;
    getline(this->profil, str);
    this->ipDestination = str;
    getline(this->profil, str);
    this->ipSource = str;
    getline(this->profil, str);
    this->sourceRepository = str;
    getline(this->profil, str);
    this->remoteRepository = str;
    getline(this->profil, str);
    int nbrex = stoi(str);
    for(int i = 0; i < nbrex; i++){
        getline(this->profil, str);
        this->extensions.push_back(str);
    }
    getline(this->profil, str);
    int nbrta = stoi(str);
    for(int i = 0; i < nbrta; i++){
        getline(this->profil, str);
        this->typeArchivable.push_back(str);
    }
}

string Profil::getIPDestination(){
    return this->ipDestination;
}
