#include "cpptest.h"


CPPTEST_CONTEXT("/UTProject/api/n51fs/N51FS_File.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/N51FS_File.c");

CPPTEST_TEST_SUITE(Test_N51FS_File); //test file
CPPTEST_TEST(Test_N51FS_File_test_N51FS_File_CloseFileRecord); // test function

CPPTEST_TEST(Test_N51FS_File_test_N51FS_FileRead_NonResidented_Compress);
CPPTEST_TEST(Test_N51FS_File_test_N51FS_File_GetDataAttributeXDataMIUAddress);

CPPTEST_TEST_SUITE_END();
        

void Test_N51FS_File_test_N51FS_File_CloseFileRecord(); // to be run test funciton declar
void Test_N51FS_File_test_N51FS_FileRead_NonResidented_Compress();
void Test_N51FS_File_test_N51FS_File_GetDataAttributeXDataMIUAddress();

CPPTEST_TEST_SUITE_REGISTRATION(Test_N51FS_File);

void Test_N51FS_File_setUp()
{
}

void Test_N51FS_File_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_File_CloseFileRecord */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_File_CloseFileRecord(U8) */
void Test_N51FS_File_test_N51FS_File_CloseFileRecord()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fhid) */ 
    U8 _fhid  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_File_CloseFileRecord(_fhid);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( TRUE , ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_File_CloseFileRecord */



/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRead_NonResidented_Compress */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_FileRead_NonResidented_Compress(U8, U32, U32) */
void Test_N51FS_File_test_N51FS_FileRead_NonResidented_Compress()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fhid) */ 
    U8 _fhid  = 0;
    /* Initializing argument 2 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 3 (len) */ 
    U32 _len  = 0ul;
    {
        /* Tested function call */
        U32 _return  = N51FS_FileRead_NonResidented_Compress(_fhid, _destMIUAddr, _len);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL( 0 , ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRead_NonResidented_Compress */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_File_GetDataAttributeXDataMIUAddress */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_File_GetDataAttributeXDataMIUAddress(U8) */
void Test_N51FS_File_test_N51FS_File_GetDataAttributeXDataMIUAddress()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileHandleID) */ 
    U8 _fileHandleID  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_File_GetDataAttributeXDataMIUAddress(_fileHandleID);
        /* Post-condition check */
       // CPPTEST_ASSERT_EQUAL(( 0x1000 ), ( _return ));
        CPPTEST_ASSERT_EQUAL(( 0x400 ), ( _return ));//20131204 ryan-zy.huang fixed

    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_File_GetDataAttributeXDataMIUAddress */


