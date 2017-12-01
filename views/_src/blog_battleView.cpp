#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_battleView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_battleView() : TActionView() { }
  QString toString();
};

QString blog_battleView::toString()
{
  responsebody.reserve(139);
  responsebody += QLatin1String("\n    <a href=\"#\">> Attack</a><br>\n    <a href=\"#\">> Item</a> <br>\n    <a href=\"#\">> Run</a>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_battleView)

#include "blog_battleView.moc"
