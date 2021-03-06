#include <QtTest/QtTest>

#include "basematchertest.h"
#include "basedescriptiontest.h"
#include "isequaltest.h"
#include "matcherasserttest.h"
#include "istest.h"

int main(int argc, char *argv[])
{
    int ret = 0;

    BaseMatcherTest test;
    ret += QTest::qExec(&test, argc, argv);

    BaseDescriptionTest test2;
    ret += QTest::qExec(&test2, argc, argv);

    IsEqualTest test3;
    ret += QTest::qExec(&test3, argc, argv);

    MatcherAssertTest test4;
    ret += QTest::qExec(&test4, argc, argv);

    IsTest test5;
    ret += QTest::qExec(&test5, argc, argv);

    return ret;
}
