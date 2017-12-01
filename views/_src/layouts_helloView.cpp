#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_helloView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  layouts_helloView() : TActionView() { }
  QString toString();
};

QString layouts_helloView::toString()
{
  responsebody.reserve(440);
  responsebody += QLatin1String("<!DOCTYPE html>\n<html lang=\"en\" >\n<head>\n  <meta charset=\"UTF-8\">\n  <title>7 Dragons</title>\n\n\n\n      <link rel=\"stylesheet\" href=\"/css/welcome.css\">\n\n\n</head>\n\n<body>\n\n\n\n\n\n\n    ");
  responsebody += QVariant(yield()).toString();
  responsebody += QLatin1String("\n\n\n\n\n      <canvas id=\"c\"></canvas>\n\n    <script  src=\"js/welcome.js\"></script>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(layouts_helloView)

#include "layouts_helloView.moc"
