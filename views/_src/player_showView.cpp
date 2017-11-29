#include <QtCore>
#include <TreeFrogView>
#include "player.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT player_showView : public TActionView
{
  Q_OBJECT
public:
  Q_INVOKABLE
  player_showView() : TActionView() { }
  QString toString();
};

QString player_showView::toString()
{
  responsebody.reserve(1705);
  responsebody += QLatin1String("<!DOCTYPE html>\n");
    tfetch(Player, player);
  responsebody += QLatin1String("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QLatin1String("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QLatin1String("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QLatin1String("</p>\n\n<h1>Showing Player</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.id());
  responsebody += QLatin1String("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.name());
  responsebody += QLatin1String("</dd><br />\n<dt>Space</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.space());
  responsebody += QLatin1String("</dd><br />\n<dt>Xp</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.xp());
  responsebody += QLatin1String("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.createdAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.updatedAt());
  responsebody += QLatin1String("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(player.lockRevision());
  responsebody += QLatin1String("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", player.id()))).toString();
  responsebody += QLatin1String(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QLatin1String("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(player_showView)

#include "player_showView.moc"
