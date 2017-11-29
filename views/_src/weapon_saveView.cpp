#include <QtCore>
#include <TreeFrogView>
#include "weapon.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT weapon_saveView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  weapon_saveView() : TActionView() { }
  QString toString();
};

QString weapon_saveView::toString()
{
  responsebody.reserve(1812);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(QVariantMap, weapon);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Editing Weapon</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", weapon["id"]), Tf::Post)).toString();
  responsebody += QLatin1String("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"weapon[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["id"]);
  responsebody += QLatin1String("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"weapon[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["name"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Space<br /><input type=\"text\" name=\"weapon[space]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["space"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <label>Attack<br /><input type=\"text\" name=\"weapon[attack]\" value=\"");
  responsebody += THttpUtility::htmlEscape(weapon["attack"]);
  responsebody += QLatin1String("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", weapon["id"]))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(weapon_saveView)

#include "weapon_saveView.moc"
