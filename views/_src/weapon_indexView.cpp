#include <QtCore>
#include <TreeFrogView>
#include "weapon.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT weapon_indexView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  weapon_indexView() : TActionView() { }
  QString toString();
};

QString weapon_indexView::toString()
{
  responsebody.reserve(1734);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n\n<h1>Listing Weapon</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new Weapon", urla("create"))).toString();
  responsebody += QLatin1String("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Name</th>\n    <th>Space</th>\n    <th>Attack</th>\n  </tr>\n");
  tfetch(QList<Weapon>, weaponList);
  for (const auto &i : weaponList) {
  responsebody += QLatin1String("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.space());
  responsebody += QLatin1String("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.attack());
  responsebody += QLatin1String("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.id()))).toString();
  responsebody += QLatin1String("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QLatin1String("\n    </td>\n  </tr>\n");
  };
  responsebody += QLatin1String("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(weapon_indexView)

#include "weapon_indexView.moc"
