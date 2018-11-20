//
//  Client.hpp
//  
//
//  Created by Maxime Cousseau on 18/11/2018.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <dirent.h>//Pour le directory
#include <sys/stat.h>//Pour le directory
#include "Profil.hpp"
using namespace std;

class Client {
    list<string> extensions;
    
public:
    Client();
    void createProfil(const string& name, const string& ip);
    void editProfil(const string& name);
    void loadProfil(const string& name);
    bool existProfil(const string& name);
};

#endif /* Client_hpp */
