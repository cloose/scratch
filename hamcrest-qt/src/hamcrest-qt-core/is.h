#ifndef HAMCREST_IS_H
#define HAMCREST_IS_H

#include "basematcher.h"
#include "isequal.h"

namespace Hamcrest {

template <typename T>
class Is : public BaseMatcher<T>
{
public:
    explicit Is(const QSharedPointer<Matcher<T> > &m) : matcher(m) {}

    virtual bool matches(const T &item) const
    {
        return matcher->matches(item);
    }

    virtual void describeTo(Description &description) const
    {
        description.appendText("is ").appendDescriptionOf(*matcher);
    }

    virtual void describeMismatch(const T &item, Description &description) const
    {
        matcher->describeMismatch(item, description);
    }

private:
    QSharedPointer<Matcher<T> > matcher;
};

template <typename T>
QSharedPointer<Matcher<T> > is(const T &operand)
{
    return is(equalTo(operand));
}

// template specialization for c-style string
inline QSharedPointer<Matcher<QString> > is(const char *operand)
{
    return QSharedPointer<Matcher<QString> >(new Is<QString>(equalTo(operand)));
}

template <typename T>
QSharedPointer<Matcher<T> > is(const QSharedPointer<Matcher<T> > &matcher)
{
    return QSharedPointer<Matcher<T> >(new Is<T>(matcher));
}

} // namespace Hamcrest

#endif // HAMCREST_IS_H
