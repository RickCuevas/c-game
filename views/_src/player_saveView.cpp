#include <QtCore>
#include <TreeFrogView>
#include "player.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT player_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  player_saveView() : TActionView() { }
  QString toString();
};

QString player_saveView::toString()
{
  responsebody.reserve(1800);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, player);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Player</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", player["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"player[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"player[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input type=\"text\" name=\"player[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Xp<br /><input type=\"text\" name=\"player[xp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["xp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", player["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(player_saveView)

#include "player_saveView.moc"
