#include "basematchertest.h"

#include <QtTest/QtTest>

#include <basematcher.h>
#include <description.h>
using namespace Hamcrest;

class MatcherMock : public BaseMatcher<int>
{
public:
    virtual bool matches(const int &item) const
    {
        QWARN("Unsupported Operation");
        return false;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("SOME DESCRIPTION");
    }
};

void BaseMatcherTest::describesItselfWithToStringMethod()
{
    MatcherMock *someMatcher = new MatcherMock();
    QCOMPARE(someMatcher->toString(), QStringLiteral("SOME DESCRIPTION"));
}
