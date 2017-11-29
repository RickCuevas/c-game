#include <QtCore>
#include <TreeFrogView>
#include "player.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT player_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  player_createView() : TActionView() { }
  QString toString();
};

QString player_createView::toString()
{
  responsebody.reserve(1407);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, player);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Player</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"player[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input name=\"player[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Xp<br /><input name=\"player[xp]\" value=\"");
  responsebody += THttpUtility::htmlEscape(player["xp"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(player_createView)

#include "player_createView.moc"
