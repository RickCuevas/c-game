#include <QtCore>
#include <TreeFrogView>
#include "monster.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT monster_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  monster_saveView() : TActionView() { }
  QString toString();
};

QString monster_saveView::toString()
{
  responsebody.reserve(1812);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, monster);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Monster</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", monster["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"monster[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"monster[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input type=\"text\" name=\"monster[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Hp<br /><input type=\"text\" name=\"monster[hp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(monster["hp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", monster["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(monster_saveView)

#include "monster_saveView.moc"
