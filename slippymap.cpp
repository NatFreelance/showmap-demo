/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <math.h>

#include <QtWidgets>
#include <QtNetwork>
#include <QNetworkReply>
#include "slippymap.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define API_KEY "dc668929b4de416495a039ff340c77a6"
uint qHash(const QPoint& p)
{
    return p.x() * 17 ^ p.y();
}

// tile size in pixels
const int tdim = 256;

QPointF tileForCoordinate(double lat, double lng, int zoom)
{
    double zn = static_cast<double>(1 << zoom);
    double tx = (lng + 180.0) / 360.0;
    double ty = (1.0 - log(tan(lat * M_PI / 180.0) +
                          1.0 / cos(lat * M_PI / 180.0)) / M_PI) / 2.0;
    return QPointF(tx * zn, ty * zn);
}

qreal longitudeFromTile(double tx, int zoom)
{
    double zn = static_cast<double>(1 << zoom);
    double lat = tx / zn * 360.0 - 180.0;
    return lat;
}

qreal latitudeFromTile(double ty, int zoom)
{
    double zn = static_cast<double>(1 << zoom);
    double n = M_PI - 2 * M_PI * ty / zn;
    double lng = 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
    return lng;
}


SlippyMap::SlippyMap(QObject *parent)
    : QObject(parent)/*, width(width), height(height), zoom(zoom),
         latitude(latitude), longitude(longitude)*/
{
    m_emptyTile = QPixmap(tdim, tdim);
    m_emptyTile.fill(Qt::lightGray);

//    QNetworkDiskCache *cache = new QNetworkDiskCache;
//    cache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
//    m_manager.setCache(cache);
//    QObject::connect(&m_manager, &QNetworkAccessManager::finished,
//            this, &SlippyMap::handleNetworkData);

    connect( &m_manager, SIGNAL( finished( QNetworkReply* ) ), SLOT( handleNetworkData( QNetworkReply* ) ) );
}

QHash<QPoint, QUrl> SlippyMap::invalidate()
{
    if (width <= 0 || height <= 0)
    {
        m_url.clear();
        return m_url;
    }
    m_url.clear();

    QPointF ct = tileForCoordinate(top_latitude, top_longitude, zoom);
    double tx1 = floor(ct.x());// верхний левый тайл
    double ty1 = floor(ct.y());

    QPointF cb = tileForCoordinate(bot_latitude, bot_longitude, zoom);
    double tx2 = floor(cb.x());// нижний правый тайл
    double ty2 = floor(cb.y());

    for(int ix=tx1; ix<=tx2; ix++)
    {
        for(int iy=ty1; iy<=ty2; iy++)
        {
            QPoint p(ix,iy);
            QUrl t_url(make_path(ix,iy,zoom));
            if(!check_path(ix,iy, zoom))
                 m_url[p] = t_url;
        }
    }


//    // top-left corner of the center tile
//    int xp = width / 2 - (tx - floor(tx)) * tdim;
//    int yp = height / 2 - (ty - floor(ty)) * tdim;

//    // first tile vertical and horizontal
//    int xa = (xp + tdim - 1) / tdim;
//    int ya = (yp + tdim - 1) / tdim;
//    int xs = static_cast<int>(tx) - xa;
//    int ys = static_cast<int>(ty) - ya;

//    // offset for top-left tile
//    m_offset = QPoint(xp - xa * tdim, yp - ya * tdim);

//    // last tile vertical and horizontal
//    int xe = static_cast<int>(tx) + (width - xp - 1) / tdim;
//    int ye = static_cast<int>(ty) + (height - yp - 1) / tdim;

//    // build a rect
//    m_tilesRect = QRect(xs, ys, xe - xs + 1, ye - ys + 1);

// //   if (m_url.isEmpty())

//    QString path = download();
//    m_url = QUrl(path);


   // emit updated(QRect(0, 0, width, height));
    return m_url;
}

void SlippyMap::render(QPainter *p, const QRect &rect)
{
//    int mx = 0, my = 0; // x and y for marker
//        qreal latdiff, lngdiff; // storing reminder
//        QPointF center = tileForCoordinate(latitude, longitude, zoom); // getting tile points for real gps point
//        int cx = qFloor(center.x());
//        int cy = qFloor(center.y());

//        for (int x = 0; x <= m_tilesRect.width(); ++x)
//            for (int y = 0; y <= m_tilesRect.height(); ++y) {
//                QPoint tp(x + m_tilesRect.left(), y + m_tilesRect.top());
//                QRect box = tileRect(tp);

//                if (tp.x() == cx && tp.y() == cy) {
//                mx = box.x();
//                my = box.y();
//                latdiff = qAbs(tp.x() - center.x());
//                lngdiff = qAbs(tp.y() - center.y());
//                }

//                if (rect.intersects(box)) {
//                    if (m_tilePixmaps.contains(tp))
//                        p->drawPixmap(box, m_tilePixmaps.value(tp));
//                    else
//                        p->drawPixmap(box, m_emptyTile);
//                }
//            }
//        // marker
//        if (mx != 0 && my != 0) {
//        QIcon marker = QIcon(":/icons/map.png");
//       // int dx= (mx+(latdiff*256.0)-40);
//       // int dy= (my+(lngdiff*256.0)-40);
////        for(int i=0;i<=100;i++)
//     //   {
//        p->drawPixmap((mx+(latdiff*256.0)-40), (my+(lngdiff*256.0)-40), marker.pixmap(40,40));
//       // p->drawPixmap((dx+100), (dy+100), marker.pixmap(40,40));
//       // p->drawPixmap((dx+50), (dy+50), marker.pixmap(40,40));

//       // }
//        }
}

void SlippyMap::pan(const QPoint &delta)
{
//    QPointF dx = QPointF(delta) / qreal(tdim);
//    QPointF center = tileForCoordinate(latitude, longitude, zoom) - dx;
//    latitude = latitudeFromTile(center.y(), zoom);
//    longitude = longitudeFromTile(center.x(), zoom);
//    invalidate();
}

void SlippyMap::setOptions(int _width, int _height, double top_lat, double top_lon, double bot_lat, double bot_lon, QString path)
{
    width = _width;
    height = _height;
    top_latitude = top_lat;
    top_longitude = top_lon;
    bot_latitude=bot_lat;
    bot_longitude=bot_lon;
    _load_path=path;
}

void SlippyMap::setZoom(int z)
{
    zoom =z;
}

QString SlippyMap::make_path(int x, int y, int z)
{
    QString path = QString("http://a.tile.thunderforest.com/cycle/%1/%2/%3.png?apikey="+QString(API_KEY)).arg(z).arg(x).arg(y); //?apikey="+QString(API_KEY)
    return path;
}

bool SlippyMap::check_path(int x, int y, int z)
{
    QString file = QString( _load_path+QString("/osm_100-l-1-%1-%2-%3.png").arg(z).arg(x).arg(y));
    return QFile::exists(file);
}

void SlippyMap::handleNetworkData(QNetworkReply *reply)
{
    printf("Reply\n");

    QImage img;
    QPoint tp = reply->request().attribute(QNetworkRequest::User).toPoint();
    QUrl url = reply->url();
//    if (!reply->error())
//        if (!img.load(reply, 0))
//            img = QImage();
    reply->deleteLater();
//    m_tilePixmaps[tp] = QPixmap::fromImage(img);
//    if (img.isNull())
//        m_tilePixmaps[tp] = m_emptyTile;
//    emit updated(tileRect(tp));

//    // purge unused spaces
//    QRect bound = m_tilesRect.adjusted(-2, -2, 2, 2);
//    foreach(QPoint tp, m_tilePixmaps.keys())
//    if (!bound.contains(tp))
//        m_tilePixmaps.remove(tp);

//    download();
}

QString SlippyMap::download()
{
    QPoint grab(0, 0);
    for (int x = 0; x <= m_tilesRect.width(); ++x)
        for (int y = 0; y <= m_tilesRect.height(); ++y) {
            QPoint tp = m_tilesRect.topLeft() + QPoint(x, y);
            if (!m_tilePixmaps.contains(tp)) {
                grab = tp;
                break;
            }
        }
    if (grab == QPoint(0, 0)) {
    //    m_url = QUrl();
        return "";
    }

//    The content of such an offline directory is read only, for QtLocation, meaning that the engine will not add, delete or update tiles present therein. Tile filenames have to follow the osm plugin filename pattern,
//    meaning osm_100-<l|h>-<map_id>-<z>-<x>-<y>.<extension>.

//    The field map_id goes from 1 to 7 (or 8, if a custom map type is specified), referring to the map types street, satellite, cycle, transit, night-transit, terrain and hiking, in this order.
//    The field before has to contain an l or an h, which stands low-dpi and high-dpi tiles, respectively.

    QString path = QString("http://a.tile.thunderforest.com/cycle/%1/%2/%3.png?apikey=dc668929b4de416495a039ff340c77a6").arg(zoom).arg(grab.x()).arg(grab.y());  //"file:///D:/Software/RFmail/tiles/%1/%2/%3.png";
    return path;
    // m_url = QUrl(path.arg(zoom).arg(grab.x()).arg(grab.y()));


//    QString filename = _load_path+QString("/osm_100-l-1-%1-%2-%3.png").arg(zoom).arg(grab.x()).arg(grab.y());
//    QNetworkRequest request;
//    request.setUrl(m_url);
//    request.setRawHeader("User-Agent", "The Qt Company (Qt) Graphics Dojo 1.0");
//    request.setAttribute(QNetworkRequest::User, QVariant(grab));
//    //m_manager.get(request);
//    QString urlText = "http://a.tile.thunderforest.com/cycle/10/617/338.png";
//   // urlText = urlText.trimmed();
//     m_manager.get( QNetworkRequest( QUrl( urlText ) ) );

//    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
//    QByteArray response = reply->readAll();
//    QImageReader imageReader(response);
//    imageReader.setAutoDetectImageFormat(false);
//    QImage _img = imageReader.read();
//    if (_img.isNull())
//    {
//        qDebug() << imageReader.errorString();
//    }
//    _img.save(filename,nullptr, 100);

//    QFile tile_file(filename);
//    if(!tile_file.open(QIODevice::ReadWrite))
//            {
//                /* handle error */
//            }
//            tile_file.write(reply->readAll());
//            tile_file.close();
//    connect(reply, &QNetworkReply::finished, [=]() {

//        if(reply->error() == QNetworkReply::NoError)
//        {
//            QByteArray response = reply->readAll();
//            // do something with the data...
//        }
//        else // handle error
//        {
//         // qDebug(reply->errorString());
//            int error;
//        }
//    });
}

QRect SlippyMap::tileRect(const QPoint &tp)
{
    QPoint t = tp - m_tilesRect.topLeft();
    int x = t.x() * tdim + m_offset.x();
    int y = t.y() * tdim + m_offset.y();
    return QRect(x, y, tdim, tdim);
}
