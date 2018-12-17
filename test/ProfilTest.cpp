#include <cppunit/extensions/HelperMacros.h>
#include "../src/Profil.hpp"
#include "ProfilTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ProfilTest );

void ProfilTest::TestCreateFile(void) {
  //test si le profil a bien été créé
 //test dans le cas ou y'a eu une erreur dans la creation
  CPPUNIT_ASSERT( true );
}

void ProfilTest::TestAddInformation(void){
	//test si le profil n'existe pas encore
	//test dans le cas ou les informations ne sont pas corrects
	//test dans le cas ou tout se passe bien
	//
	CPPUNIT_ASSERT( true );
}
 
void ProfilTest::TestEditProfil(void){
	//test si le profil n'existe pas encore
	//test dans le cas ou les informations ne sont pas corrects
	CPPUNIT_ASSERT( true );
}
 
void ProfilTest::TestLoadProfil(void){
	//test si le profil n'existe pas encore
 	CPPUNIT_ASSERT( true );
}
