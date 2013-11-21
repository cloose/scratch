#include "isequaltest.h"

#include <QtTest/QtTest>

#include <isequal.h>
#include <matcher.h>
using namespace Hamcrest;

#include "abstractmatcher.h"

//template <typename T>
//void assertDescription(const QString &expected, const QSharedPointer<Matcher<T> > &matcher)
//{
//    Description *description = new StringDescription();
//    description->appendDescriptionOf(*matcher);
//    QCOMPARE(description->toString(), expected);
//}

void IsEqualTest::comparesObjectsUsingEqualsMethod()
{
    QString *null1 = 0;

    const QSharedPointer<Matcher<QString> > matcher1 = equalTo(QStringLiteral("hi"));
    QVERIFY(matcher1->matches(QStringLiteral("hi")));
    QVERIFY(!matcher1->matches(QStringLiteral("bye")));
    QVERIFY(!matcher1->matches(*null1));

    int *null2 = 0;

    const QSharedPointer<Matcher<int> > matcher2 = equalTo(1);
    QVERIFY(matcher2->matches(1));
    QVERIFY(!matcher2->matches(2));
    QVERIFY(!matcher2->matches(*null2));
}

class ObjectMock
{
};


inline QString ToString(ObjectMock *)
{
    return "ARGUMENT DESCRIPTION";
}

void IsEqualTest::includesTheResultOfCallingToStringOnItsArgumentInTheDescription()
{
    const QString argumentDescription = "ARGUMENT DESCRIPTION";

    ObjectMock *argument = new ObjectMock();
    assertDescription("<" + argumentDescription + ">", equalTo(argument));
}

