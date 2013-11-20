#include "stringdescription.h"

#include "selfdescribing.h"

namespace Hamcrest {

StringDescription::StringDescription()
{
}

QString StringDescription::toString() const
{
    return out.join(QString());
}

QString StringDescription::toString(const SelfDescribing &selfDescribing)
{
    StringDescription *description = new StringDescription();
    return description->appendDescriptionOf(selfDescribing).toString();
}

void StringDescription::append(const QString &str)
{
    out.append(str);
}

void StringDescription::append(const QChar &c)
{
    out.append(c);
}

} // namespace Hamcrest
