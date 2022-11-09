#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <iostream>
#include <string>
#include "rsub.h"
#include <vector>
 
using namespace std;
using namespace CppUnit;


class Testdate : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(Testdate);
    CPPUNIT_TEST(testvalidDate);
    // CPPUNIT_TEST(testmm);
    // CPPUNIT_TEST(testyy);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testvalidDate(void);
  
private:
    DATE *mTestObj;
};
void
Testdate::testvalidDate(void)
{
    //Sunny Test Cases
    CPPUNIT_ASSERT(1==mTestObj->validDate("02/12/2022"));
    CPPUNIT_ASSERT(1==mTestObj->validDate("10/12/2024"));
    CPPUNIT_ASSERT(1==mTestObj->validDate("10/10/2022"));
    CPPUNIT_ASSERT(1==mTestObj->validDate("30/03/2023"));
    CPPUNIT_ASSERT(1==mTestObj->validDate("28/11/2022"));

     //Rainy Test Cases
    CPPUNIT_ASSERT(0==mTestObj->validDate("2/112/2022"));
    CPPUNIT_ASSERT(0==mTestObj->validDate("2/11/2021"));
    CPPUNIT_ASSERT(0==mTestObj->validDate("33/12/2022"));
    CPPUNIT_ASSERT(0==mTestObj->validDate("30/2/2022"));
    CPPUNIT_ASSERT(0==mTestObj->validDate("31/2/2020"));

}

void Testdate::setUp(void) {
    mTestObj = new DATE();
}

void Testdate::tearDown(void) {
    delete mTestObj;
}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( Testdate );

int main(int argc, char* argv[]) {

    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppDateResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
