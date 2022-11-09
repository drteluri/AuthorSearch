#include <iostream>
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
#include "rsubmissions.h"

using namespace CppUnit;
using namespace std;

class Test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testProjId);
    CPPUNIT_TEST_SUITE_END();

    public:
    	void setUp(void);
    	void tearDown(void);

    protected:
    	void ProjId(void);
    private:
	RSub *mTestObj;
};

void Test::testProjId(void)
{
	CPPUNIT_ASSERT_EQUAL(1==mTestObj->getProjId());
	CPPUNIT_ASSERT_EQUAL(1==mTestObj->getProjId());
	CPPUNIT_ASSERT_EQUAL(1==mTestObj->getProjId());
	CPPUNIT_ASSERT_EQUAL(1==mTestObj->getProjId());

	CPPUNIT_ASSERT(0==mTestObj->getProjId());
	CPPUNIT_ASSERT(0==mTestObj->getProjId());
	CPPUNIT_ASSERT(0==mTestObj->getProjId());
	CPPUNIT_ASSERT(0==mTestObj->getProjId());

}



void Test::setUp(void)
{
	mTestObj = new Test("PRO0001");
}


void Test::tearDown(void)
{
	delete mTestObj;
}

CPPUNIT_TEST_SUITE_REGISTRATION( Test );

int main(int argc, char* argv[])
{
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
    ofstream xmlFileOut("Messages.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}


