#ifndef MSGPARTNETACCESSMANAGER_H
#define MSGPARTNETACCESSMANAGER_H

#include <QNetworkAccessManager>

namespace Imap {

namespace Mailbox {
class Model;
class TreeItemMessage;
}

namespace Network {

class MsgPartNetAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    MsgPartNetAccessManager( QObject* parent=0 );
    void setModelMessage( const Imap::Mailbox::Model* _model,
        const Imap::Mailbox::TreeItemMessage* _message );
protected:
    virtual QNetworkReply* createRequest( Operation op,
        const QNetworkRequest& req, QIODevice* outgoingData=0 );
private:
    const Imap::Mailbox::Model* model;
    const Imap::Mailbox::TreeItemMessage* message;
};

}
}
#endif // MSGPARTNETACCESSMANAGER_H
