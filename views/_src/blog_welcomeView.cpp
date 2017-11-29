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
  responsebody.reserve(324);
  responsebody += QLatin1String("<!DOCTYPE html>\n<html lang=\"en\" >\n<head>\n  <meta charset=\"UTF-8\">\n  <title>7 Dragons</title>\n\n\n\n      <link rel=\"stylesheet\" href=\"css/welcome.css\">\n\n\n</head>\n\n<body>\n  <canvas id=\"c\"></canvas>\n\n    <script  src=\"js/welcome.js\"></script>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_welcomeView)

#include "blog_welcomeView.moc"
