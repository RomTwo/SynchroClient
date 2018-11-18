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
#include <dirent.h>//Pour le directory
#include <sys/stat.h>//Pour le directory
using namespace std;

class Client {
    
public:
    Client();
    void createProfil(const string& name);
    void editProfil();
    void loadProfil();
    bool existProfil(const string& name);
};

#endif /* Client_hpp */
