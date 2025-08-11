#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>
#include <QSettings>
#include "mapwidgettool.h"

namespace Ui {
class SettingsForm;
}
class MapWidgetTool;
class SettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();
    void setMaster(MapWidgetTool *m);
signals:
 void centerChangedSignal(double lat, double lon);
private slots:
    void on_closeButton_clicked();

    void on_saveButton_clicked();

    void on_loadCatalogButton_clicked();

private:
    Ui::SettingsForm *ui;
    MapWidgetTool *_master;
    QSettings _settings;
};

#endif // SETTINGSFORM_H
