#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/result.h"
#include "../header/result_suite.h"


int result_Valid(int x)
{
    int maxsize=10;
    if(x==maxsize-1)
    return 1;
    else
    return 0;
}