#include <QtCore>
#include <TreeFrogView>
#include "monster.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT monster_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  monster_showView() : TActionView() { }
  QString toString();
};

QString monster_showView::toString()
{
  responsebody.reserve(1716);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Monster, monster);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Monster</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Space</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.space());
  responsebody += QLatin1String("</dd><br />\n<dt>Hp</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.hp());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(monster.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", monster.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(monster_showView)

#include "monster_showView.moc"
