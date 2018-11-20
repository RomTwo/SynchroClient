//
//  Profil.hpp
//  
//
//  Created by Maxime Cousseau on 19/11/2018.
//

#ifndef Profil_hpp
#define Profil_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream> 
#include <list>
using namespace std;

class Profil {
    string name;
    string ipSource;
    string ipRemote;
    string extension = ".txt";
    ofstream profil;
    
public:
    Profil(const string& name, const string& ip);
    
    void createFile(const string& name, const string& ipRemote);
    void addInformation(const string& iPRemote, const string& sourceRepository, const string& remoteRepository, const string extension[], const string typeArchivable[]);
};

#endif /* Profil_hpp */
