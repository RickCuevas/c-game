#include <QtCore>
#include <TreeFrogView>
#include "monster.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT monster_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  monster_createView() : TActionView() { }
  QString toString();
};

QString monster_createView::toString()
{
  responsebody.reserve(1415);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, monster);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Monster</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"monster[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input name=\"monster[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Hp<br /><input name=\"monster[hp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["hp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(monster_createView)

#include "monster_createView.moc"
