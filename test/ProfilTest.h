#ifndef PROFILTEST_H
#define PROFILTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ProfilTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( ProfilTest );
  CPPUNIT_TEST( TestCreateFile );
  CPPUNIT_TEST( TestAddInformation );
  CPPUNIT_TEST( TestEditProfil );
  CPPUNIT_TEST( TestLoadProfil );

  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp(void) {}    // I don't use setUp or tearDown yet, but let's 
  void tearDown(void) {} // leave them in so I remember their names

  void TestCreateFile(void); 
  void TestAddInformation(void);
  void TestEditProfil(void);
  void TestLoadProfil(void);
};

#endif /* CRITTERTEST_H */