#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_loopView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_loopView() : TActionView() { }
  QString toString();
};

QString blog_loopView::toString()
{
  responsebody.reserve(180);
  responsebody += QLatin1String("\n\n    <a href=\"http://localhost:8800/Blog/battle\">> Explore</a><br>\n    <a href=\"http://localhost:8800/Blog/equip\">> Continue</a> <br>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_loopView)

#include "blog_loopView.moc"
