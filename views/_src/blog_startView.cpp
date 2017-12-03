#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_startView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_startView() : TActionView() { }
  QString toString();
};

QString blog_startView::toString()
{
  responsebody.reserve(170);
  tfetch(int, bar);
  responsebody += QLatin1String("\n<a href=\"#\"> ");
  responsebody += THttpUtility::htmlEscape(bar);
  responsebody += QLatin1String("</a><br>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_startView)

#include "blog_startView.moc"
