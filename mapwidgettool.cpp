#include "mapwidgettool.h"
#include "ui_mapwidgettool.h"

#include <QQuickItem>
#include <QQmlContext>
#include <QEvent>
#include <QTimer>
#include <QGeoCoordinate>
#include <QGeoRectangle>
#include <QGeoShape>
#include <QApplication>
#include <QDesktopWidget>
#include <QNetworkReply>
#include <QImageReader>
#include <QDir>

class QGeoCoordinate;

MapWidgetTool::MapWidgetTool(QWidget *parent) :
    QWidget(parent), curObjIndex(0), _settings("showmap.conf", QSettings::IniFormat), _timer(new QTimer(this)),
    ui(new Ui::MapWidgetTool)
{

    ui->setupUi(this);

    toolbar = new QToolBar(this);
    toolbar->setOrientation(Qt::Vertical);
    ui->tool_layout->addWidget(toolbar);

    QToolBar * toolbar2 = new QToolBar(this);
    toolbar2->setOrientation(Qt::Vertical);
    ui->del_layout->addWidget(toolbar2);

    toolbar->addWidget(ui->optionButton);
    toolbar->addWidget(ui->addButton);
    toolbar->addWidget(ui->playButton);
    toolbar->addWidget(ui->stopButton);
    toolbar2->addWidget(ui->savemapButton);
    toolbar2->addWidget(ui->clearAllButton);


    ui->optionButton->setIcon(QIcon(":/image/settings2.png"));
    ui->clearAllButton->setIcon(QIcon(":/image/clear_all.png"));
    ui->playButton->setIcon(QIcon(":/image/play.png"));
    ui->stopButton->setIcon(QIcon(":/image/stop.png"));
    ui->savemapButton->setIcon(QIcon(":/image/savemap.png"));

    bar = new QStatusBar(this);
    ui->status_layout->addWidget(bar);
    information = new QLabel(bar);
    bar->addWidget(information);
    progress = new QProgressBar(this);
    bar->addWidget(progress);
    progress->hide();

     qRegisterMetaType<MapMarker>();
    //setup qml map
    _qml_view = new QQuickView();
    QWidget* container = QWidget::createWindowContainer(_qml_view, this);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->qml_canvas_layout->addWidget(container);
    //_qml_view->setSource(QUrl::fromLocalFile(":/mymap.qml")); // старый вариант со структурой
    _qml_view->setSource(QUrl::fromLocalFile(":/mymap2.qml"));


    //test get/set qml object properties
    {
        auto map_view = _qml_view->rootObject()->findChild<QQuickItem*>("mapView");
//        auto center_latitude = map_view->property("center_latitude").value<double>();
//        auto center_longitude = map_view->property("center_longitude").value<double>();
//        auto zoom = map_view->property("zoom").value<int>();
       // coordinates.setLatitude(coordinates.latitude() + 0.02);

//        center_latitude=59.9386;
//        center_longitude =30.3141;

        _settings.beginGroup("Map");
        map_center_lat = _settings.value("MapCenter_latitude", 0.0).toDouble();
        map_center_lon = _settings.value("MapCenter_longitude", 0.0).toDouble();
        map_zoom = _settings.value("MapZoomLevel", 1).toInt();
        _settings.endGroup();



        map_view->setProperty("center_latitude", QVariant::fromValue<double>(map_center_lat));
        map_view->setProperty("center_longitude", QVariant::fromValue<double>(map_center_lon));
        map_view->setProperty("zoomLevel", QVariant::fromValue<int>(map_zoom));

        _settings.beginGroup("LoadFolder");
        _load_path = _settings.value("LoadMapFolder", "/home").toString();

        _settings.endGroup();

//        QVariant ret;


//        bool ok = QMetaObject::invokeMethod( map_view, "bbox",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, ret ) );
//        if ( !ok ){
//            qWarning( "Fail to call qml method" );
//        }
//        QGeoRectangle rect = qvariant_cast<QGeoRectangle>( ret );

//        auto mNorth = rect.topLeft().latitude();
//        auto mSouth = rect.bottomLeft().latitude();
//        auto mWest  = rect.topLeft().longitude();
//        auto mEast  = rect.topRight().longitude();
    }

    //add filter for mouse coordinates
   // _qml_view->installEventFilter(this);

   // auto mapItemView = _qml_view->rootContext()->findChild<QQuickItem*>("delegateGroup");
   // mapItemView->setC

    //connect QML object and C++ object - message receiver
    _qml_receiver = new QMLReceiver();
    _qml_view->rootContext()->setContextProperty("qmlReceiver", _qml_receiver);
     QObject::connect(_qml_receiver, &QMLReceiver::centerChangedSignal, this, &MapWidgetTool::onCenterChanged);
     QObject::connect(_qml_receiver, &QMLReceiver::markerDeleteSignal, this, &MapWidgetTool::delMarker);
     QObject::connect(_qml_receiver, &QMLReceiver::mouseMovedSignal, this, &MapWidgetTool::onMouseMoved);
     QObject::connect(_qml_receiver, &QMLReceiver::zoomLevelChangedSignal, this, &MapWidgetTool::onZoomLevelChanged);
     QObject::connect(_qml_receiver, &QMLReceiver::changedCopPositionSignal, this, &MapWidgetTool::redrawLine);

    _qml_view->rootContext()->setContextProperty("loadPath", _load_path);

    //connect QML object and C++ object - map items model
    _model = new MarkerModel();
    _qml_view->rootContext()->setContextProperty("markerModel", _model);
     QObject::connect(_qml_receiver, &QMLReceiver::markerClickedSignal, this, &MapWidgetTool::onMarkerClicked);


    //add several markers
//    _model->addMarker("1", "Car Red",  59.9569, 30.3135,0.0, "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png");
//    _model->addMarker("2", "Car Blue",  59.9566, 30.32015,0.0, "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_blue.png");
//    _model->addMarker("3", "Car Blue",  59.8566, 30.32015,0.0, "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_blue.png");

       QObject::connect(_timer, &QTimer::timeout, _model, &MarkerModel::updateData);
       QObject::connect( &m_manager, &QNetworkAccessManager::finished, this,  &MapWidgetTool::onNetworkRequestFinished );

}

MapWidgetTool::~MapWidgetTool()
{

    delete information;
    delete bar;
    delete ui;
    delete _qml_receiver;
    delete _model;

}

void MapWidgetTool::addStationOnMap(double lat, double lon, double radius, bool status)
{
   // QIcon s_icon("./station.png");

    //_model->addMarker("4", "Station", lat, lon, 0.0,"http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png");
   // _model->addMarker("3", "Car Blue",  59.8566, 30.32015,0.0, "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_blue.png");
    curObjIndex++;
    QString icon_path = imagePath();
//    if (status) icon_path+="/station32.png";
//    else icon_path+="/stationnotactive.png";
    _model->addMarker(curObjIndex, "Станция",  lat, lon,0.0, icon_path+"/station32.png", icon_path+"/stationnotactive.png", 0, radius, -1, status);

    //    _model->setMarkerType(QString::number(curObjIndex), 0);
//    _model->setStationRadius(QString::number(curObjIndex), radius);
}

void MapWidgetTool::addQuadOnMap(double lat, double lon, double alt, int id,  bool status)
{
    curObjIndex++;
    _model->addMarker(curObjIndex, "Беспилотник",  lat, lon,alt, imagePath()+"/copter32.png",imagePath()+"/copternotactive.png",  1, 0.0, id, status);
    //_model->setMarkerType(QString::number(curObjIndex), 1);
}

void MapWidgetTool::addRemoteControllerOnMap(double lat, double lon, int id_cop, bool status)
{
    curObjIndex++;
    _model->addMarker(curObjIndex, "Пульт",  lat, lon,0.0, imagePath()+"/remote32.png",imagePath()+"/remotenotactive.png", 2, 0.0, id_cop, status);
}

void MapWidgetTool::delMarker(int identifier)
{
    _model->delMarker(identifier);
}

void MapWidgetTool::onCenterChangedByForm(double lat, double lon, int zoom)
{
    map_center_lat = lat;
    map_center_lon=lon;
    map_zoom=zoom;
    auto map_view = _qml_view->rootObject()->findChild<QQuickItem*>("mapView");

    map_view->setProperty("center_latitude", QVariant::fromValue<double>(map_center_lat));
    map_view->setProperty("center_longitude", QVariant::fromValue<double>(map_center_lon));
    map_view->setProperty("zoomValue", QVariant::fromValue<int>(map_zoom));

    onCenterChanged(lat,lon);
}

void MapWidgetTool::closeEvent(QCloseEvent *event)
{
    _settings.beginGroup("Map");
    _settings.setValue("MapCenter_latitude", map_center_lat);
    _settings.setValue("MapCenter_longitude", map_center_lon);
    _settings.setValue("MapZoomLevel", map_zoom);
    _settings.endGroup();
}

double MapWidgetTool::getmap_center_lat()
{
    return map_center_lat;
}

double MapWidgetTool::getmap_center_lon()
{
    return map_center_lon;
}

int MapWidgetTool::getmap_zoom()
{
    return map_zoom;
}

QList<MapMarker> MapWidgetTool::getCopterList()
{
    return _model->getCopterList();
}

QList<MapMarker> MapWidgetTool::getStationList()
{
    return _model->getStationList();
}

void MapWidgetTool::redrawLine(const int &identifier, double latitude, double longitude)
{

    int type = _model->getMarkerType(identifier);
    if(type!=1) return;

    _model->redrawLine(identifier, QGeoCoordinate(latitude, longitude));

}

QString MapWidgetTool::load_path()
{
    return _load_path;
}

void MapWidgetTool::set_load_path(QString path)
{
    _load_path = path;
}

QString MapWidgetTool::imagePath()
{
    QString p = QCoreApplication::applicationDirPath();
    p.replace("debug", "image");

    return p;
}


//bool MapWidgetTool::eventFilter(QObject* obj, QEvent* event)
//{
//    if(obj == _qml_view &&
//       event->type() == QEvent::MouseMove)
//    {
//        auto coord = getMouseCoordinates();

//        QString coord_string = QString("Mouse position: %1;%2").arg(std::get<0>(coord)).arg(std::get<1>(coord));
//        setInformationText(MapWidgetTool::TextType::MouseCoord, coord_string);
//    }
//    return MapWidgetTool::eventFilter(obj, event);
//}

void MapWidgetTool::setInformationText(TextType type, const QString &text)
{
//    auto plain_text = information->text();
//    if(plain_text.isEmpty())
//        plain_text = text;
//    else
//    {
//        plain_text.clear();
//        QStringList strings;

//        switch(type)
//        {
//            case MapWidgetTool::TextType::MouseCoord:
//                strings[0] = text;
//            break;
//            case MapWidgetTool::TextType::CenterCoord:
//                if(strings.size() >= 2)
//                    strings[1] = text;
//                else
//                    strings.append(text);
//            break;
//        case MapWidgetTool::TextType::MarkerInfo:
//            if(strings.size() >= 3)
//                strings[2] = text;
//            else
//                strings.append(text);
//            break;
//        }
//        plain_text = strings[0]; //;.join("\n");
//    }
    information->setText(text);
}

std::tuple<double, double> MapWidgetTool::getMouseCoordinates()
{
    auto map_view = _qml_view->rootObject()->findChild<QQuickItem*>("mapView");
    QVariant result_lat, result_lon;
    bool invoke_result_lat = QMetaObject::invokeMethod(map_view, "getMousePosition_lat", Qt::DirectConnection, Q_RETURN_ARG(QVariant, result_lat));
    if(!invoke_result_lat)
        std::make_tuple(0.f, 0.f);

    bool invoke_result_lon = QMetaObject::invokeMethod(map_view, "getMousePosition_lon", Qt::DirectConnection, Q_RETURN_ARG(QVariant, result_lon));
    if(!invoke_result_lon)
        std::make_tuple(0.f, 0.f);

    //Coords coordinates = result.value<Coords>();
    double lat = result_lat.value<double>();
    double lon = result_lon.value<double>();
    return std::make_tuple(lat, lon);
}

void MapWidgetTool::on_closeButton_clicked()
{
    close();
}

void MapWidgetTool::onCenterChanged(double lat, double lon)
{
   map_center_lat=lat;
   map_center_lon=lon;

    QString map_string = QString("Центр карты: %1;%2  Zoom: %3").arg(lat).arg(lon).arg(map_zoom);
    setInformationText(MapWidgetTool::TextType::CenterCoord, map_string);
}

void MapWidgetTool::onMarkerClicked(const int &identifier, const QString &name, double lat, double lon)
{
    QString marker_string = QString("'%1': %2;%3").arg(name).arg(lat).arg(lon);
    setInformationText(MapWidgetTool::TextType::MarkerInfo, marker_string);

    auto coords = _model->getMarkerLatLon(identifier);
    if(std::get<0>(coords)!=lat || std::get<1>(coords)!=lon)
        _model->setMarkerLatLon(identifier, lat, lon);

}

void MapWidgetTool::onMouseMoved(double lat, double lon)
{
  //  auto coord = getMouseCoordinates();

  //  QString coord_string = QString("Текущие координаты: %1;%2").arg(std::get<0>(coord)).arg(std::get<1>(coord));
    QString coord_string = QString("Текущие координаты: %1;%2").arg(lat).arg(lon);
    setInformationText(MapWidgetTool::TextType::MouseCoord, coord_string);
}

void MapWidgetTool::onZoomLevelChanged(int z)
{
    map_zoom = z;
}


void MapWidgetTool::on_addButton_clicked()
{
    AddObjectForm *form = new AddObjectForm();
    form->setMaster(this);
    form->show();


}


void MapWidgetTool::on_optionButton_clicked()
{
    SettingsForm *form = new SettingsForm();
    form->setMaster(this);
    form->show();
}



void MapWidgetTool::on_clearAllButton_clicked()
{
    _model->clear();
}


void MapWidgetTool::on_playButton_clicked()
{

//    int N=10; // points

//    for (int k = 0; k < N; k++)
//    {
//         QTimer::singleShot(1000, this, &MapWidgetTool::moveAllCopters);
//    }


    _timer->start(1000);
    _model->updateData();

//    QObject * rootQmlObject = _qml_view->rootObject();
//    QObject * entityObject = nullptr;
//                if (rootQmlObject) {
//                    if (rootQmlObject->objectName() == "main") {//Он у вас корневой, так что придется еще такую проверку сделать
//                        entityObject = rootQmlObject;
//                    } else {
//                        entityObject = rootQmlObject->findChild<QObject*>("main");
//                    }
//                }

//                if (entityObject) {
//                    QMetaObject::invokeMethod(entityObject, "newLine", Qt::QueuedConnection);
//                }

}

void MapWidgetTool::moveAllCopters()
{
    int size = _model->size();
    for (int i=1; i<=size; i++)
    {
        _model->moveCopter(i, 0.1,0.1);

    }
}


void MapWidgetTool::on_stopButton_clicked()
{
    _timer->stop();
}


void MapWidgetTool::on_savemapButton_clicked()
{
            request_count=0;
            QVariant ret, ret2, cc, ct, cb, cbox;
            auto map_view = _qml_view->rootObject()->findChild<QQuickItem*>("mapView");



            bool ok = QMetaObject::invokeMethod( map_view, "bzoom",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, ret ) );
            if ( !ok ){
                qWarning( "Fail to call qml method" );
            }
            int zoomv = qvariant_cast<int>( ret );

            ok = QMetaObject::invokeMethod( map_view, "bzoommax",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, ret2 ) );
                        if ( !ok ){
                            qWarning( "Fail to call qml method" );
                        }
                        int zoommax = qvariant_cast<int>( ret2 );
            ok = QMetaObject::invokeMethod( map_view, "bcenter",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, cc ) );
                        if ( !ok ){
                            qWarning( "Fail to call qml method" );
                        }
                        QGeoCoordinate center = qvariant_cast<QGeoCoordinate>( cc );
                        auto clat = center.latitude();
                        auto clon = center.longitude();
            ok = QMetaObject::invokeMethod( map_view, "btop",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, ct ) );
                                    if ( !ok ){
                                        qWarning( "Fail to call qml method" );
                                    }

           QGeoCoordinate top = qvariant_cast<QGeoCoordinate>( ct );
           auto top_lat = top.latitude();
           auto top_lon = top.longitude();
            ok = QMetaObject::invokeMethod( map_view, "bbottom",  Qt::DirectConnection, Q_RETURN_ARG( QVariant, cb) );
                                                if ( !ok ){
                                                    qWarning( "Fail to call qml method" );
                                                }
                                                QGeoCoordinate bottom = qvariant_cast<QGeoCoordinate>( cb );
                                                auto bot_lat = bottom.latitude();
                                                auto bot_lon = bottom.longitude();


   auto screen_width =  _qml_view->width();
   auto screen_height = _qml_view->height();

   SlippyMap loader(this);
//   loader.setOptions(screen_width, screen_height, top_lat, top_lon, bot_lat, bot_lon, _load_path);
   loader.setOptions(screen_width, screen_height, 55.8999, 34.0463, 54.5386, 38.7779, _load_path);
   int i=zoomv;
   i=8;
   QString urlText;
   url_hash.clear();
   zoommax=13;
   while(i<=zoommax)
   {
    loader.setZoom(i);
    url_hash = loader.invalidate();
    request_count+=url_hash.size();

    QHash<QPoint, QUrl>::const_iterator it = url_hash.begin();
    while(it!= url_hash.end())
    {
        auto val = it.value();
        QNetworkRequest request;
        request.setUrl(it.value());
        request.setAttribute(QNetworkRequest::User, QVariant(it.key()));
        m_manager.get( request );
       it++;
   }
    i++;
   }
   if(request_count==0)
   {
       setInformationText(MapWidgetTool::TextType::MarkerInfo, "Загрузка карты завершена");
       progress->hide();
   }
   progress->setRange(0, request_count);
   progress->show();
}

void MapWidgetTool::onNetworkRequestFinished(QNetworkReply *reply)
{
    request_count--;
    progress->setValue(progress->maximum() - request_count);
    if( reply->error() == QNetworkReply::NoError ) {
        QPoint tp = reply->request().attribute(QNetworkRequest::User).toPoint();
        QUrl url = reply->url();
        QString str = url.toString().section('/',-3,-3);
        bool ok;
        int z = str.toInt(&ok);
        if(!ok)
        {
            qDebug ("Cannot find zoom value in url", url.toString());
            return;
        }
        QByteArray response =reply->readAll()  ;

       const QString fileName = _load_path+QString("/osm_100-l-1-%1-%2-%3.png").arg(z).arg(tp.x()).arg(tp.y());// your filePath should end with a forward slash "/"
        QFile *  m_file = new QFile();
            m_file->setFileName(fileName);
            m_file->open(QIODevice::WriteOnly);
            if (!m_file->isOpen()) {
              //  m_isReady = true;
                return; // TODO: permission check?
            }

            if (!m_file->isWritable()) {
           //         m_isReady = true;
                    return; // TODO: error check
                }

                m_file->write(response);
                m_file->close(); // TODO: delete the file from the system later on

    } else {
       // ui->lbStatus->setText( reply->errorString() );
        qDebug ("UrlReply Error ", reply->errorString());
    }

    reply->deleteLater();
    if(request_count<1)
    {
        setInformationText(MapWidgetTool::TextType::MarkerInfo, "Загрузка карты завершена");
        progress->hide();
    }
}

