/*  This file is part of the Tufão project
    Copyright (C) 2011 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any
    later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * BTUC-13170: Use QSsl::SecureProtocols
 * Use QSsl::SecureProtocols instead of TLS 1.0 for listening SSL socket
 * protocol. This should be the best option as Qt will select the available
 * protocols known to be secure.
 * Oct 25, 2016, Teemu Patja (Cisco Systems, Inc.)
 */
/*
 * BTUC-13170: Do not request client SSL cert
 * Modify Tufao not to request client SSL certificate in SSL Server Hello.
 * Oct 25, 2016, Teemu Patja (Cisco Systems, Inc.)
 */
/*
 * BTUC-13170: HTTPS support for API provider
 * Now the API provider serves plain http + ws on port 5505 and https + wss
 * on port 5506. An SSL certificate is built in that uses CN=api.12bar.net
 * and that host assumed to point to localhost.
 * Oct 20, 2016, Teemu Patja (Cisco Systems, Inc.)
 */
/*
 * BTUC-1392: Port  uses of QSsl::TlsV1 to TlsV1_0
 * Dec 23, 2013, Juho Frits (Cisco Systems, Inc.)
 */
/*
 * BTUC-2604: added Tufao framework to extern (now built when running standalone extern build).
 * Pre-built dll+lib for win32 added also, still need binaries for osx.
 * Jun 5, 2013, Teemu Patja (Cisco Systems, Inc.)
 */

#include "priv/httpsserver.h"
#include <QtNetwork/QSslSocket>

namespace Tufao {

HttpsServer::HttpsServer(QObject *parent) :
    HttpServer(parent),
    priv(new Priv)
{
}

HttpsServer::~HttpsServer()
{
    delete priv;
}

void HttpsServer::setLocalCertificate(const QSslCertificate &certificate)
{
    priv->localCertificate = certificate;
}

void HttpsServer::setLocalCertificateChain(const QList<QSslCertificate> &localChain)
{
    priv->localCertificateChain = localChain;
}


void HttpsServer::setPrivateKey(const QSslKey &key)
{
    priv->privateKey = key;
}

#if QT_VERSION >= 0x050000
void HttpsServer::incomingConnection(qintptr socketDescriptor)
#else
void HttpsServer::incomingConnection(int socketDescriptor)
#endif
{
    QSslSocket *socket = new QSslSocket;
    socket->setProtocol(QSsl::SecureProtocols);
    socket->setLocalCertificate(priv->localCertificate);
    if(priv->localCertificateChain.count() > 0)
      socket->setLocalCertificateChain(priv->localCertificateChain);
    socket->setPrivateKey(priv->privateKey);
    socket->setPeerVerifyMode(QSslSocket::VerifyNone);

    if (!socket->setSocketDescriptor(socketDescriptor)) {
        delete socket;
        return;
    }

    socket->startServerEncryption();
    handleConnection(socket);
}

} // namespace Tufao
