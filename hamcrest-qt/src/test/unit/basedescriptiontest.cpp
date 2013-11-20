#include "basedescriptiontest.h"

#include <QtTest/QtTest>
#include <QStringList>

#include <basedescription.h>
using namespace Hamcrest;

static QStringList result;

class BaseDescriptionMock : public BaseDescription
{
public:
    BaseDescriptionMock() { result.clear(); }

protected:
    virtual void append(const QChar &c)
    {
        result.append(c);
    }
};

void BaseDescriptionTest::quotesAppendedStringValue()
{
    BaseDescription *baseDescription = new BaseDescriptionMock();
    baseDescription->appendValue(QStringLiteral("foo\n"));
    QCOMPARE(result.join(""), QStringLiteral("\"foo\\n\""));
}

void BaseDescriptionTest::bracketsAppendedShortValue()
{
    short value = 2;

    BaseDescription *baseDescription = new BaseDescriptionMock();
    baseDescription->appendValue(value);
    QCOMPARE(result.join(""), QStringLiteral("<2s>"));
}

void BaseDescriptionTest::bracketsAppendedLongValue()
{
    long value = 2;

    BaseDescription *baseDescription = new BaseDescriptionMock();
    baseDescription->appendValue(value);
    QCOMPARE(result.join(""), QStringLiteral("<2L>"));
}

void BaseDescriptionTest::bracketsAppendedFloatValue()
{
    float value = 1.2;

    BaseDescription *baseDescription = new BaseDescriptionMock();
    baseDescription->appendValue(value);
    QCOMPARE(result.join(""), QStringLiteral("<1.2F>"));
}
