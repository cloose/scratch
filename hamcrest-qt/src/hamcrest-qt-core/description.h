#ifndef HAMCREST_DESCRIPTION_H
#define HAMCREST_DESCRIPTION_H

#include <QString>
#include <QTextStream>

namespace Hamcrest {

class SelfDescribing;

template <typename T>
QString ToString(const T &value)
{
    QString result;

    QTextStream out(&result);
    out << value;

    return result;
}

inline QString ToString(bool value)
{
    return value ? "true" : "false";
}

class Description
{
public:
    /**
     * Appends some plain text to the description.
     */
    virtual Description &appendText(const QString &text) = 0;

    /**
     * Appends the description of a {@link SelfDescribing} value to this description.
     */
    virtual Description &appendDescriptionOf(const SelfDescribing &value) = 0;

    /**
     * Appends an arbitrary value to the description.
     */
    template <typename T>
    Description &appendValue(const T &value)
    {
        appendString("<");
        appendString(ToString(value));
        appendString(">");
        return *this;
    }

    Description &appendValue(const QString &value)
    {
        toCppSyntax(value);
        return *this;
    }

    Description &appendValue(short value)
    {
        QString s;
        s.setNum(value);

        appendString("<");
        appendString(s);
        appendString("s>");
        return *this;
    }

    Description &appendValue(long value)
    {
        QString s;
        s.setNum(value);

        appendString("<");
        appendString(s);
        appendString("L>");
        return *this;
    }

    Description &appendValue(float value)
    {
        QString s;
        s.setNum(value);

        appendString("<");
        appendString(s);
        appendString("F>");
        return *this;
    }

    virtual QString toString() const = 0;

protected:
    virtual void appendString(const QString &str) = 0;
    virtual void append(const QChar &c) = 0;

    virtual void toCppSyntax(const QString &unformatted);
    virtual void toCppSyntaxChar(const QChar &ch);
};

} // namespace Hamcrest

#endif // HAMCREST_DESCRIPTION_H
