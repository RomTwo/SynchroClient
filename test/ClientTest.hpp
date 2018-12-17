#ifndef CLIENTTEST_H
#define CLIENTTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ClientTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( ClientTest );
  CPPUNIT_TEST( TestCreateProfil );
  CPPUNIT_TEST( TestEditProfil );
  CPPUNIT_TEST( TestLoadProfil );
  CPPUNIT_TEST( TestExistProfil );
  CPPUNIT_TEST( TestParcourirDirectory );
  CPPUNIT_TEST( TestCreateConnection );
  CPPUNIT_TEST( TestSendFile );


  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp(void) {}    // I don't use setUp or tearDown yet, but let's 
  void tearDown(void) {} // leave them in so I remember their names

  void TestCreateProfil(void);
  void TestEditProfil(void); 
  void TestLoadProfil(void); 
  void TestExistProfil(void); 
  void TestParcourirDirectory(void); 
  void TestCreateConnection(void); 
  void TestSendFile(void); 
  


};

#endif /* CLIENTTEST_H */