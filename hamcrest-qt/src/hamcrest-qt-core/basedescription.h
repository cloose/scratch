#ifndef HAMCREST_BASEDESCRIPTION_H
#define HAMCREST_BASEDESCRIPTION_H

#include "description.h"

namespace Hamcrest {

class BaseDescription : public Description
{
public:
    virtual Description &appendText(const QString &text);
    virtual Description &appendDescriptionOf(const SelfDescribing &value);

    virtual QString toString() const;

protected:
    virtual void appendString(const QString &str);
};

} // namespace Hamcrest

#endif // HAMCREST_BASEDESCRIPTION_H
