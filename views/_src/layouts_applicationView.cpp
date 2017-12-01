#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  layouts_applicationView() : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(927);
  responsebody += QLatin1String("<!DOCTYPE html>\n\n\n<html lang=\"en\" >\n<head>\n  <meta charset=\"UTF-8\">\n  <title>Pokemon Battle WIP</title>\n\n\n\n      <link rel=\"stylesheet\" href=\"/css/style.css\">\n\n\n</head>\n\n<body>\n  <table>\n  <tr>\n    <td class=\"pika\"> <img src=\"http://img2.wikia.nocookie.net/__cb20101101164123/es.pokemon/images/4/44/Pikachu_espalda_G5.gif\" alt=\"\" /> </td>\n    <td class=\"chmr\"> <img src=\"http://fc02.deviantart.net/fs70/f/2011/174/0/d/charmander_by_sageraziel-d3jt9kq.gif\" alt=\"\" /> </td>\n  </tr>\n  <tr>\n    <td colspan=2 class='cnsl'><div class=\"status\"> <span></span> <br>\n    ");
  responsebody += QVariant(yield()).toString();
  responsebody += QLatin1String("\n      </div></td>\n  </tr>\n</table>\n  <script src='http://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script>\n\n    <script  src=\"js/index.js\"></script>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
