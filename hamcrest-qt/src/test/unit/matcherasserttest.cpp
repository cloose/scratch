#include "matcherasserttest.h"

#include <QtTest/QtTest>

#include <basematcher.h>
#include <isequal.h>
#include <matcherassert.h>
using namespace Hamcrest;

class AssertionError : public std::exception
{
public:
    AssertionError(const char *msg) : message(msg) {}

    virtual const char *what() const throw() { return message; }

private:
    const char *message;
};

class MatcherAssertTest::TestAssertListener : public MatcherAssert::AssertListener
{
public:
    virtual void assertError(const QString &message) throw(AssertionError&)
    {
        throw AssertionError(message.toLatin1());
    }
};

void MatcherAssertTest::initTestCase()
{
    listener = new TestAssertListener();
    MatcherAssert::addAssertListener(listener);
}

void MatcherAssertTest::includesDescriptionOfTestedValueInErrorMessage()
{
    QString expected = "expected";
    QString actual = "actual";

    QString expectedMessage = "identifier\nExpected: \"expected\"\n     but: was \"actual\"";

    try {
        ASSERT_THAT2("identifier", actual, equalTo(expected));
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()).startsWith(expectedMessage));
        return;
    }

    QFAIL("should have failed");
}

void MatcherAssertTest::descriptionCanBeElided()
{
    QString expected = "expected";
    QString actual = "actual";

    QString expectedMessage = "\nExpected: \"expected\"\n     but: was \"actual\"";

    try {
        ASSERT_THAT(actual, equalTo(expected));
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()).startsWith(expectedMessage));
        return;
    }

    QFAIL("should have failed");
}

void MatcherAssertTest::canTestBooleanDirectly()
{
    ASSERT_THAT("success reason message", true);

    try {
        ASSERT_THAT("failing reason message", false);
    } catch (const AssertionError &e) {
        QVERIFY(QString(e.what()) == QStringLiteral("failing reason message"));
        return;
    }

    QFAIL("should have failed");
}

namespace {
class MatcherMock : public BaseMatcher<QString>
{
public:
    virtual bool matches(const QString &) const
    {
        return false;
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("Something cool");
    }

    virtual void describeMismatch(const QString &, Description &description) const
    {
        description.appendText("Not cool");
    }
};
}

void MatcherAssertTest::includesMismatchDescription()
{
    QScopedPointer<Matcher<QString> > matcherWithCustomMismatchDescription(new MatcherMock());

    QString expectedMessage = "\nExpected: Something cool\n     but: Not cool";

    try {
        ASSERT_THAT(QStringLiteral("Value"), *matcherWithCustomMismatchDescription);
        QFAIL("should have failed");
    } catch (const AssertionError &e) {
        QCOMPARE(QString(e.what()), expectedMessage);
    }
}

void MatcherAssertTest::cleanupTestCase()
{
    delete listener;
}

