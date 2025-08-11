#ifndef ADDOBJECTFORM_H
#define ADDOBJECTFORM_H

#include <QWidget>
#include "mapwidgettool.h"
#include "markermodel.h"

namespace Ui {
class AddObjectForm;
}
class MapWidgetTool;
class MapMarker;

class AddObjectForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddObjectForm(QWidget *parent = nullptr);

    ~AddObjectForm();

    void setMaster(MapWidgetTool *m);
    void initCopterComboBox();
    void initStationComboBox();
signals:
    void addStationToMap(double latitude, double longitude, double radius, bool statusactive);
    void addQuadToMap(double latitude, double longitude, double altitude, int id, bool statusactive );
    void addRemoteToMap(double latitude, double longitude, int id, bool statusactive);
private slots:
    void on_closeButton_clicked();

    void on_saveButton_clicked();

    void on_type_comboBox_currentIndexChanged(int index);

    void on_latitude_lineEdit_textEdited(const QString &arg1);

    void on_longitude_lineEdit_textEdited(const QString &arg1);

    void on_radius_lineEdit_textEdited(const QString &arg1);

    void on_altitude_lineEdit_textEdited(const QString &arg1);

    void on_id_checkBox_clicked(bool checked);

    void on_id_checkBox_3_clicked(bool checked);

private:
    Ui::AddObjectForm *ui;
    MapWidgetTool *_master;
};

#endif // ADDOBJECTFORM_H
