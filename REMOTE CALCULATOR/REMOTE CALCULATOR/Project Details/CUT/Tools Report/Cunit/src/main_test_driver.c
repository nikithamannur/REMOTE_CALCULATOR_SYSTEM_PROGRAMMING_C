#include "../header/valid.h"
#include "../header/valid_suite.h"
#include "CUnit/Basic.h"
#include "../header/result.h"
#include "../header/result_suite.h"
#include "result.c"
#include "result_suite.c"
#include "valid.c"
#include "valid_suite.c"



int main()
{
CU_pSuite pSuite1 = NULL;
/* initialize the CUnit test registry */


if (CUE_SUCCESS != CU_initialize_registry())
return CU_get_error();

/* add a suite to the registry */
pSuite1 = CU_add_suite("Suite Valid file", init_suite_valid, clean_suite_valid);

if (NULL == pSuite1)
{
   CU_cleanup_registry();
   return CU_get_error();
}

CU_pSuite pSuite2 = NULL;

pSuite2 = CU_add_suite("Suite Valid file", init_suite_result, clean_suite_result);


if (NULL == pSuite2)
{
   CU_cleanup_registry();
   return CU_get_error();
}




/* Add the tests to the suite */

if ((NULL == CU_add_test(pSuite1,"test of validation() in Sunny cases", testSunnyCases1)) || (NULL == CU_add_test(pSuite1,
"test of validation() in Rainy cases", testRainyCases1)))
{
    CU_cleanup_registry();
    return CU_get_error();
}


/* Add the tests to the suite */

if ((NULL == CU_add_test(pSuite2,"test of result_Valid() in Sunny cases", testSunnyCases2)) || (NULL == CU_add_test(pSuite2,
"test of result_Valid() in Rainy cases", testRainyCases2)))
{
    CU_cleanup_registry();
    return CU_get_error();
}




/* Run all tests using the CUnit Basic interface */
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();
return CU_get_error();

}