#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_welcomeView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_welcomeView() : TActionView() { }
  QString toString();
};

QString blog_welcomeView::toString()
{
  responsebody.reserve(148);
  responsebody += QLatin1String("<div class=\"content\">\n    Knight Rider V II\n    <a href=\"http://localhost:8800/Blog\">Play</a>\n\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_welcomeView)

#include "blog_welcomeView.moc"
