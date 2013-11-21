#ifndef MATCHERASSERT_H
#define MATCHERASSERT_H

#include <qtestcase.h>
#include "matcher.h"
#include "stringdescription.h"

namespace Hamcrest {

class MatcherAssert
{
public:
    template <typename T>
    static bool assertThat(const T &actual, const QSharedPointer<Matcher<T> > &matcher, const char *file, int line)
    {
        return assertThat(QStringLiteral(""), actual, *matcher, file, line);
    }

    template <typename T>
    static bool assertThat(const T &actual, const Matcher<T> &matcher, const char *file, int line)
    {
        return assertThat(QStringLiteral(""), actual, matcher, file, line);
    }

    template <typename T>
    static bool assertThat(const QString &reason, const T &actual, const QSharedPointer<Matcher<T> > &matcher, const char *file, int line)
    {
        return assertThat(reason, actual, *matcher, file, line);
    }

    template <typename T>
    static bool assertThat(const QString &reason, const T &actual, const Matcher<T> &matcher, const char *file, int line)
    {
        if (!matcher.matches(actual)) {
            StringDescription description;
            description.appendText(reason)
                       .appendText("\nExpected: ")
                       .appendDescriptionOf(matcher)
                       .appendText("\n     but: ");
            matcher.describeMismatch(actual, description);

            notifyAssertListener(description.toString());
            QTest::qFail(description.toString().toLatin1(), file, line);
            return false;
        }

        return true;
    }

    static bool assertThat(const QString &reason, bool assertion, const char *file, int line)
    {
        if (!assertion) {
            notifyAssertListener(reason);
            QTest::qFail(reason.toLatin1(), file, line);
        }

        return assertion;
    }

    class AssertListener
    {
    public:
        virtual ~AssertListener() {}
        virtual void assertError(const QString &message) = 0;
    };

    static void addAssertListener(MatcherAssert::AssertListener *listener)
    {
        listeners.append(listener);
    }

private:
    static void notifyAssertListener(const QString &message)
    {
        foreach (MatcherAssert::AssertListener *listener, listeners) {
            listener->assertError(message);
        }
    }

    static QList<MatcherAssert::AssertListener*> listeners;
};

#define ASSERT_THAT(actual, matcher) \
do {\
    if (!Hamcrest::MatcherAssert::assertThat(actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)

#define ASSERT_THAT2(reason, actual, matcher) \
do {\
    if (!Hamcrest::MatcherAssert::assertThat(reason, actual, matcher, __FILE__, __LINE__))\
        return;\
} while (0)

} // namespace Hamcrest

#endif // MATCHERASSERT_H
