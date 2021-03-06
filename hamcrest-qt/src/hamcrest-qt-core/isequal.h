#ifndef HAMCREST_ISEQUAL_H
#define HAMCREST_ISEQUAL_H

#include "basematcher.h"
#include "description.h"

namespace Hamcrest {

template <typename T>
class IsEqual : public BaseMatcher<T>
{
public:
    explicit IsEqual(const T &equalArg) : expectedValue(equalArg) {}

    virtual bool matches(const T &actualValue) const
    {
        return areEqual(actualValue, expectedValue);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendValue(expectedValue);
    }

private:
    static bool areEqual(const T &actual, const T &expected)
    {
        // null reference?
        if (&actual == 0)
            return &expected == 0;

        return actual == expected;
    }

private:
    T expectedValue;
};

template <typename T>
QSharedPointer<Matcher<T> > equalTo(const T &operand)
{
    return QSharedPointer<Matcher<T> >(new IsEqual<T>(operand));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<QString> > equalTo(const char *operand)
{
    return QSharedPointer<Matcher<QString> >(new IsEqual<QString>(QString(operand)));
}

} // namespace Hamcrest

#endif // HAMCREST_ISEQUAL_H
