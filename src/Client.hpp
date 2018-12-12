/**
 * \file Client.hpp
 * \package ProgrammeClient
 * \author Groupe1
 * \version 1
 * \date 11/12/2018
 *
 * Déclaration des attributs, constrcuteurs et fonctions pour la mise en place du client.
 *
 */

#ifndef Client_hpp
#define Client_hpp

#define MYPORT "12345"

#include <stdio.h>
#include <string>
#include <vector>
#include <dirent.h>//Pour le directory
#include <sys/stat.h>//Pour le directory
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include "Profil.hpp"

using namespace std;

/**
 * \class Client
 * \brief classe representant le client de la synchronisation de fichiers.
 *
 *  La classe permet d'initialiser un client, de créer un profil contenant des informations pour le transfert de fichier, de l'éditer et de le charger pour commencer la synchronisation entre le client et le serveur.
 */
class Client {
    list<string> extensions;/*!< Liste d'extensions sous format string.*/
    
public:
    
    /**
     * \fn Client()
     * \brief Constructeur
     *
     * Constructeur de la classe Client
     */
    Client();
    
    /**
     * \fn createProfil(const string& name, const string& ip)
     * \brief Définition de la fonction 'createProfil'
     *
     * Cette fonction permet de créer un profil avec les différentes informations comme son nom et l'adresse destination.
     *
     * \param name : Nom du profil
     * \param ip : Adresse destination du serveur pour la connexion
     */
    void createProfil(const string& name, const string& ip);
    
    /**
     * \fn editProfil(const string& name)
     * \brief Définition de la fonction 'editProfil'
     *
     * Cette fonction permet d'éditer un profil en le recherchant avec son nom.
     * Si le fichier existe bien avec le bon nom fourni en paramètre, le client pourra le paramètrer en saisissant plusieurs informations.
     *
     * \param name : Nom du profil à éditer
     */
    void editProfil(const string& name);
    
    /**
     * \fn loadProfil(const string& name)
     * \brief Définition de la fonction 'loadProfil'
     *
     * Cette fonction permet de charger un profil en le recherchant avec son nom.
     * Si le fichier existe bien avec le bon nom fourni en paramètre, il y aura une instanciation de la classe Profil et une association des attributs qui sera le chargement du profil côté client.
     *
     * \param name : Nom du profil à charger
     */
    void loadProfil(const string& name);
    
    /**
     * \fn existProfil(const string& name)
     * \brief Définition de la fonction 'existProfil'
     *
     * Cette fonction permet de savoir si un profil existe bien dans le répertoire de configuration.
     * Si le fichier existe, la fonction retourne un booleen qui correspond à la présence du fichier.
     *
     * \param name : Nom du profil à rechercher.
     */
    bool existProfil(const string& name);
    
    /**
     * \fn parcourirDirectory(const string& chemin)
     * \brief Définition de la fonction 'parcourirDirectory'
     *
     * Cette fonction permet de parcourir un repertoire dont le chemin est passé en paramètre.
     * Elle parcourt le repertoire récursivement
     *
     * \param name : Nom du profil à rechercher.
     */
    bool parcourirDirectory(const string& chemin);
    
    /**
     * \fn createConnection(Profil& p, const string& message)
     * \brief Définition de la fonction 'createConnection'
     *
     * Cette fonction permet de créer une connexion entre le client et le serveur.
     *
     * \param p : Profil pour la connection
     * \param message : Chaine de caractère pour un envoi de message
     */
    void createConnection(Profil& p, const string& message);
    
    /**
     * \fn sendFile(Profil& p, const string& path)
     * \brief Définition de la fonction 'sendFile'
     *
     * Cette fonction permet de parcourir un repertoire dont le chemin est passé en paramètre.
     * Elle parcourt le repertoire récursivement
     *
     * \param p : Profil pour l'envoi d'un fichier
     * \param path : Chemin du fichier 
     */
    void sendFile(Profil& p, const string& path);
};

#endif /* Client_hpp */
