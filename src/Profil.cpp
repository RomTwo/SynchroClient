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

void Profil::addInformation(const string& iPSource, const string& sourceRepository, const string& remoteRepository, const string extension[], const string typeArchivable[]){
    this->profil.open("../configuration/"+this->name+this->extension, std::ios_base::app);
    this->profil << iPSource;
    this->profil << sourceRepository;
    this->profil << remoteRepository;
}
