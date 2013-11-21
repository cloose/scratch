#include "istest.h"

#include <QtTest/QtTest>

#include <is.h>
#include <isequal.h>
#include <matcher.h>
using namespace Hamcrest;

#include "abstractmatcher.h"


void IsTest::matchesTheSameWayTheUnderlyingMatcherDoes()
{
    const QSharedPointer<Matcher<bool> > matcher = is(equalTo(true));

    assertMatches(matcher, true);
    assertDoesNotMatch(matcher, false);
}

void IsTest::generatesIsPrefixInDescription()
{
    assertDescription("is <true>", is(equalTo(true)));
    assertDescription("is \"A\"", is("A"));
}

void IsTest::providesConvenientShortcutForIsEqualTo()
{
    QSharedPointer<Matcher<QString> > matcher2 = is("A");

    assertMatches(matcher, QStringLiteral("A"));
    assertDoesNotMatch(is("A"), QStringLiteral("B"));
}
