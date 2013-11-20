#include "description.h"


namespace Hamcrest {

void Description::toCppSyntax(const QString &unformatted)
{
    append('"');
    foreach (QChar c, unformatted) {
        toCppSyntaxChar(c);
    }
    append('"');
}

void Description::toCppSyntaxChar(const QChar &ch)
{
    if (ch == '"')
        appendString("\\\"");
    else if (ch == '\n')
        appendString("\\n");
    else  if (ch == '\r')
        appendString("\\r");
    else if (ch == '\t')
        appendString("\\t");
    else
        append(ch);
}

} // namespace Hamcrest
