#include "CUnit/Basic.h"
#include "../header/valid.h"

int init_suite_valid()
{
return 0;
}

int clean_suite_valid()
{
return 0;
}

void testSunnyCases1()
{
CU_ASSERT_EQUAL(validation(-1),1);
}
void testRainyCases1()
{
 CU_ASSERT_EQUAL(validation(8),0);
CU_ASSERT_EQUAL(validation(9),0);
CU_ASSERT_EQUAL(validation(20),0);
}