//
//  Profil.cpp
//  
//
//  Created by Maxime Cousseau on 19/11/2018.
//

#include "Profil.hpp"

Profil::Profil(const string& name, const string& iPRemote){
    this->name = name;
    this->ipRemote = iPRemote;
}

void Profil::createFile(const string& name, const string& ipRemote){
    this->profil.open("../configuration/"+this->name+this->extension);
    this->profil << name << endl;
    this->profil << ipRemote << endl;
    this->profil.close();
}

void Profil::addInformation(const string& iPSource, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable){
    this->profil.open("../configuration/"+this->name+this->extension, std::ios_base::app);
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
