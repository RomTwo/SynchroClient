#include <cppunit/extensions/HelperMacros.h>
#include "../src/Profil.hpp"
#include "ClientTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION( ClientTest );


void ClientTest::TestCreateProfil(void){
  CPPUNIT_ASSERT( true );
  
  //test que chaque paramètre a bien été ajouté 
  //test que le fichier existe bien à la fin 
  //test dans le cas ou le nom de fichier est spécial
  //test dans le cas ou les paramètres on un format incorrect
}

void ClientTest::TestEditProfil(void){
  CPPUNIT_ASSERT( true );
  //test dans le cas ou le profil n'existe pas 
  //test dans le cas ou les paramètres on un format incorrect
  //test ou tout s'est bien passé
}

void ClientTest::TestLoadProfil(void){
  CPPUNIT_ASSERT( true );
  //test dans le cas ou le profil n'existe pas 
  //test ou tout s'est bien passé
}

void ClientTest::TestExistProfil(void){
  CPPUNIT_ASSERT( true );
  //test dans le cas ou le profil n'existe pas 
  //test ou tout s'est bien passé

}

void ClientTest::TestParcourirDirectory(void){
  CPPUNIT_ASSERT( true );
  //test si le parcours se fini bien

}

void ClientTest::TestCreateConnection(void){
  CPPUNIT_ASSERT( true );
  //test si la connexion a été effectuée
  //testsi la connexion a échouée

}

void ClientTest::TestSendFile(void){
	//test si le fichier a bien été envoyer
	//test si il y a une interruption
  CPPUNIT_ASSERT( true );
}
