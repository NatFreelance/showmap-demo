#ifndef MAPWIDGETTOOL_H
#define MAPWIDGETTOOL_H

#include <QWidget>
#include <QQuickView>
#include "markermodel.h"
#include <QStatusBar>
#include <QLabel>
#include <QToolBar>
#include <QProgressBar>
#include <QSettings>
#include <QTimer>
#include <QtPositioning/QGeoCoordinate>
#include <QNetworkAccessManager>

#include "addobjectform.h"
#include "settingsform.h"
#include "slippymap.h"

namespace Ui {
class MapWidgetTool;
}

class QMLReceiver : public QObject
{
private:
    Q_OBJECT

public:
    Q_INVOKABLE void centerChanged(double latitude, double longitude)
    {
        emit centerChangedSignal(latitude, longitude);
    }
    Q_INVOKABLE void zoomLevelChanged(int zlevel)
    {
        emit zoomLevelChangedSignal(zlevel);
    }
    Q_INVOKABLE void markerClicked(const int& identifier, const QString& name, double latitude, double longitude)
    {
        emit markerClickedSignal(identifier, name, latitude, longitude);
    }
    Q_INVOKABLE void markerDelete(const int& identifier)
    {
        emit markerDeleteSignal(identifier);
    }
    Q_INVOKABLE void mouseMoved(double latitude, double longitude)
    {
        emit mouseMovedSignal(latitude, longitude);
    }
    Q_INVOKABLE void changedCopPosition(const int& identifier, double latitude, double longitude)
    {
        emit changedCopPositionSignal(identifier, latitude, longitude);
    }

signals:
    void centerChangedSignal(double lat, double lon);
    void zoomLevelChangedSignal(int zlevel);
    void markerClickedSignal(const int& identifier, const QString& name, double lat, double lon);
    void markerDeleteSignal(const int& identifier);
    void mouseMovedSignal(double lat, double lon);
    void changedCopPositionSignal(const int& identifier, double latitude, double longitude);
};

class MapWidgetTool : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidgetTool(QWidget *parent = nullptr);
    ~MapWidgetTool();
public slots:
    void addStationOnMap(double lat, double lon, double radius, bool status);
    void addQuadOnMap(double lat, double lon, double alt, int id, bool status);
    void addRemoteControllerOnMap(double lat, double lon, int id_cop, bool status);
    void delMarker(int identifier);
    void onCenterChangedByForm(double lat, double lon, int zoom);
    void closeEvent(QCloseEvent *event);
    double getmap_center_lat();
    double getmap_center_lon();
    int getmap_zoom();
    QList<MapMarker> getCopterList();
    QList<MapMarker> getStationList();
    void redrawLine(const int &identifier, double latitude, double longitude);
    QString load_path();
    void set_load_path(QString path);
    QString imagePath();

//protected:
//    virtual bool eventFilter(QObject* obj, QEvent* event) override;
private:
    enum class TextType
    {
        MouseCoord,
        CenterCoord,
        MarkerInfo
    };
    void setInformationText(TextType type, const QString& text);
    std::tuple<double, double> getMouseCoordinates();


private slots:
    void on_closeButton_clicked();
    void onCenterChanged(double lat, double lon);
    void onMarkerClicked(const int &identifier, const QString& name, double lat, double lon);
    void onMouseMoved(double lat, double lon);
    void onZoomLevelChanged(int z);
    void on_addButton_clicked();

    void on_optionButton_clicked();
 //   void mouseMoveEvent(QMouseEvent *event);

    void on_clearAllButton_clicked();

    void on_playButton_clicked();
    void moveAllCopters();

    void on_stopButton_clicked();

    void on_savemapButton_clicked();
    void onNetworkRequestFinished(QNetworkReply *reply);

private:
    Ui::MapWidgetTool *ui;
    QStatusBar       *bar;
    QToolBar         *toolbar;
    QLabel           *information;
    QProgressBar *progress;
    QQuickView*     _qml_view;
    QMLReceiver*    _qml_receiver;
    MarkerModel*    _model;
    int curObjIndex;

    QSettings _settings;
    double map_center_lat;
    double map_center_lon;
    int map_zoom;
    QTimer *_timer;
    QString _load_path;
    QHash<QPoint, QUrl> url_hash;
    int request_count;

    QNetworkAccessManager m_manager;

};

#endif // MAPWIDGETTOOL_H
