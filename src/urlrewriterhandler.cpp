/*  This file is part of the Tufão project
    Copyright (C) 2013 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

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
 * BTUC-2604: added Tufao framework to extern (now built when running standalone extern build).
 * Pre-built dll+lib for win32 added also, still need binaries for osx.
 * Jun 5, 2013, Teemu Patja (Cisco Systems, Inc.)
 */

#include "priv/urlrewriterhandler.h"

#include "httpserverrequest.h"

namespace Tufao {

UrlRewriterHandler::UrlRewriterHandler(const QByteArray &url, QObject *parent) :
    priv(new Priv(url))
{}

void UrlRewriterHandler::setUrl(const QByteArray &url)
{
    priv->url = url;
}

QByteArray UrlRewriterHandler::url() const
{
    return priv->url;
}

UrlRewriterHandler::~UrlRewriterHandler()
{
    delete priv;
}

bool UrlRewriterHandler::handleRequest(Tufao::HttpServerRequest *request,
                                       Tufao::HttpServerResponse *,
                                       const QStringList &)
{
    request->setUrl(priv->url);
    return false;
}

} // namespace Tufao
