#include "CUnit/Basic.h"
#include "../header/result_suite.h"
#include "../header/result.h"

int init_suite_result(void)
{
return 0;
}

int clean_suite_result(void)
{
return 0;
}

void testSunnyCases2(void)
{
CU_ASSERT_EQUAL(result_Valid(9),1);
}
void testRainyCases2(void)
{
 CU_ASSERT_EQUAL(result_Valid(3),0);
CU_ASSERT_EQUAL(result_Valid(4),0);
CU_ASSERT_EQUAL(result_Valid(7),0);
}