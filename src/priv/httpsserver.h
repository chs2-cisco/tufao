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
 * BTUC-13170: HTTPS support for API provider
 * Now the API provider serves plain http + ws on port 5505 and https + wss
 * on port 5506. An SSL certificate is built in that uses CN=api.12bar.net
 * and that host assumed to point to localhost.
 * Oct 20, 2016, Teemu Patja (Cisco Systems, Inc.)
 */
/*
 * BTUC-2604: added Tufao framework to extern (now built when running standalone extern build).
 * Pre-built dll+lib for win32 added also, still need binaries for osx.
 * Jun 5, 2013, Teemu Patja (Cisco Systems, Inc.)
 */

#ifndef TUFAO_PRIV_HTTPSSERVER_H
#define TUFAO_PRIV_HTTPSSERVER_H

#include "../httpsserver.h"
#include "../tufao_global.h"

#include <QtNetwork/QSslCertificate>
#include <QtNetwork/QSslKey>

namespace Tufao {

struct HttpsServer::Priv
{
    QSslCertificate localCertificate;
    QList<QSslCertificate> localCertificateChain;
    QSslKey privateKey;
};

} // namespace Tufao

#endif // TUFAO_PRIV_HTTPSSERVER_H
