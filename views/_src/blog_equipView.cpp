#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_equipView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  blog_equipView() : TActionView() { }
  QString toString();
};

QString blog_equipView::toString()
{
  responsebody.reserve(201);
  responsebody += QLatin1String("\n    <a href=\"#\"> You found a .....!</a><br>\n    <a href=\"#\">> Equip?</a> <br>\n    <a href=\"#\">>>> Yes</a> <br>\n    <a href=\"#\">>>> No </a> <br>\n    \n");

  return responsebody;
}

T_DEFINE_VIEW(blog_equipView)

#include "blog_equipView.moc"
