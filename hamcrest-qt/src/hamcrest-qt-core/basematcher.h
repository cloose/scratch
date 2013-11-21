#ifndef HAMCREST_BASEMATCHER_H
#define HAMCREST_BASEMATCHER_H

#include "matcher.h"

#include "description.h"
#include "stringdescription.h"

namespace Hamcrest {

template <typename T>
class BaseMatcher : public Matcher<T>
{
public:
    virtual void describeMismatch(const T &item, Description &description) const;

    virtual QString toString() const;
};

template <typename T>
void BaseMatcher<T>::describeMismatch(const T &item, Description &description) const
{
    description.appendText(QStringLiteral("was ")).appendValue(item);
}

template <typename T>
QString BaseMatcher<T>::toString() const
{
    return StringDescription::toString(*this);
}

} // namespace Hamcrest

#endif // HAMCREST_BASEMATCHER_H
