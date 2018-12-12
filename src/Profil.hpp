/**
 * \file Profil.hpp
 * \package ProgrammeClient
 * \author Groupe1
 * \version 1
 * \date 11/12/2018
 *
 * Déclaration des attributs, constrcuteurs et fonctions pour la mise en place du profil.
 *
 */

#ifndef Profil_hpp
#define Profil_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include <list>
using namespace std;

/**
 * \class Profil
 * \brief Classe representant le profil qui est important pour la synchronisation entre le serveur et le profil.
 *
 *  La classe permet d'initialiser un profil contenant des informations pour le transfert de fichier, d'ajouter des informations dans ce profil et de charger un profil.
 */
class Profil {
    string name;/*!< Nom du profil.*/
    string ipSource;/*!< Adresse de la source.*/
    string ipDestination;/*!< Adresse de la destination.*/
    string sourceRepository;/*!< Répertoire de la source.*/
    string remoteRepository;/*!< Répertoire de la destination.*/
    vector<string> extensions;/*!< Vecteur de chaine de caractère pour avoir les extensions autorisés à la synchronisation.*/
    vector<string> typeArchivable;/*!< Vecteur de chaine de caractère pour avoir les extensions autorisés à l'archivage.*/
    string extension = ".txt";/*!< Type de l'extension pour le profil.*/
    fstream profil;/*!< Fichier correspondant au profil.*/
    
public:
    
    /**
     * \fn Profil(const string& name, const string& ip)
     * \brief Constructeur
     *
     * Constructeur de la classe Profil
     *
     * \param name : Nom du profil
     * \param ip : Adresse destination du profil
     */
    Profil(const string& name, const string& ip);
    
    /**
     * \fn Profil(const string& name)
     * \brief Constructeur
     *
     * Constructeur de la classe Profil
     *
     * \param name : Nom du profil
     */
    Profil(const string& name);
    
    /**
     * \fn createFile(const string& name, const string& ipRemote)
     * \brief Définition de la fonction 'createFile'
     *
     * Cette fonction permet de créer un profil avec les différentes informations comme son nom et l'adresse destination dans un dossier prédéfini qui est le dossier 'configuration'.
     *
     * \param name : Nom du profil
     * \param ipRemote : Adresse destination du profil
     */
    void createFile(const string& name, const string& ipRemote);
    
    /**
     * \fn addInformation(const string& iPSource, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable)
     * \brief Définition de la fonction 'addInformation'
     *
     * Cette fonction permet d'ajouter des informations comme l'adresse source, le répertoire source ou les extensions qui permetteront d'enrichir le profil.
     *
     * \param iPSource : Adresse source
     * \param sourceRepository : Répertoire source
     * \param remoteRepository : Répertoire destination
     * \param extension : Liste des extensions synchronisable
     * \param typeArchivable : Liste des extension archivable
     */
    void addInformation(const string& iPSource, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable);
    
    /**
     * \fn editProfil(const string& iPSource, const string& iPRemote, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable);
     * \brief Définition de la fonction 'editProfil'
     *
     * Cette fonction permet de modifier des informations comme l'adresse source, le répertoire source ou les extensions qui permetteront d'actualiser le profil.
     *
     * \param iPSource : Adresse source
     * \param iPRemote : Adresse destination
     * \param sourceRepository : Répertoire source
     * \param remoteRepository : Répertoire destination
     * \param extension : Liste des extensions synchronisable
     * \param typeArchivable : Liste des extension archivable
     */
    void editProfil(const string& iPSource, const string& iPRemote, const string& sourceRepository, const string& remoteRepository, const vector<string>& extension, const vector<string>& typeArchivable);
    
    /**
     * \fn loadProfil();
     * \brief Définition de la fonction 'loadProfil'
     *
     * Cette fonction permet charger des données avec un profil courant.
     * Elle ira lire dans le fichier et associera ces valeurs obtenus aux attributs du profil.
     *
     */
    void loadProfil();
    
    /**
     * \fn getIPDestination();
     * \brief Définition de la fonction 'getIPDestination'
     *
     * Cette fonction permet de recupérer l'adresse destination.
     *
     * \return L'adresse destination
     */
    string getIPDestination();
};

#endif /* Profil_hpp */
