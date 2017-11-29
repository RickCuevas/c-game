#include <QtCore>
#include <TreeFrogView>
#include "weapon.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT weapon_createView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  weapon_createView() : TActionView() { }
  QString toString();
};

QString weapon_createView::toString()
{
  responsebody.reserve(1419);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, weapon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>New Weapon</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>Name<br /><input name=\"weapon[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input name=\"weapon[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Attack<br /><input name=\"weapon[attack]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["attack"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(weapon_createView)

#include "weapon_createView.moc"
