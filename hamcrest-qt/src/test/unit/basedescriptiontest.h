#ifndef BASEDESCRIPTIONTEST_H
#define BASEDESCRIPTIONTEST_H

#include <QObject>

namespace Hamcrest {
class BaseDescription;
}

class BaseDescriptionTest : public QObject
{
    Q_OBJECT
    
private slots:
    void quotesAppendedStringValue();
    void bracketsAppendedShortValue();
    void bracketsAppendedLongValue();
    void bracketsAppendedFloatValue();

private:
    Hamcrest::BaseDescription *baseDescription;
};

#endif // BASEDESCRIPTIONTEST_H
