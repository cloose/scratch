#ifndef HAMCREST_STRINGDESCRIPTION_H
#define HAMCREST_STRINGDESCRIPTION_H

#include "basedescription.h"

#include <QStringList>

namespace Hamcrest {

class SelfDescribing;

class StringDescription : public BaseDescription
{
public:
    StringDescription();

    virtual QString toString() const;

    static QString toString(const SelfDescribing &selfDescribing);

protected:
    virtual void append(const QString &str);
    virtual void append(const QChar &c);

private:
    QStringList out;
};

} // namespace Hamcrest

#endif // HAMCREST_STRINGDESCRIPTION_H
