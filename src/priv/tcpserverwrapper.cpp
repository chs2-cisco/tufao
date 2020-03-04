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
 * BTUC-7249: fix Tufao build errors on OSX with QT4
 * Dec 5, 2014, Teemu Patja (Cisco Systems, Inc.)
*/
/*
 * BTUC-2604: added Tufao framework to extern (now built when running standalone extern build).
 * Pre-built dll+lib for win32 added also, still need binaries for osx.
 * Jun 5, 2013, Teemu Patja (Cisco Systems, Inc.)
 */

#include "tcpserverwrapper.h"

namespace Tufao {

TcpServerWrapper::TcpServerWrapper(QObject *parent) :
    QTcpServer(parent)
{
}

#if QT_VERSION >= 0x050000
void TcpServerWrapper::incomingConnection(qintptr socketDescriptor)
#else
void TcpServerWrapper::incomingConnection(int socketDescriptor)
#endif
{
    emit newConnection(socketDescriptor);
}

} // namespace Tufao
