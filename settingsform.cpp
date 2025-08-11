#include "settingsform.h"
#include "ui_settingsform.h"
#include <QFileDialog>

SettingsForm::SettingsForm(QWidget *parent) :
    QWidget(parent), _settings("showmap.conf", QSettings::IniFormat),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);

    _settings.beginGroup("Map");
    auto lat = _settings.value("MapCenter_latitude", 0.0).toDouble();
    auto lon = _settings.value("MapCenter_longitude", 0.0).toDouble();
    auto zoom = _settings.value("MapZoomLevel", 1).toInt();
    _settings.endGroup();

    _settings.beginGroup("LoadFolder");
    auto folder = _settings.value("LoadMapFolder", "/home").toString();
    _settings.endGroup();

    ui->latitude_SpinBox->setValue(lat);
    ui->longitude_SpinBox->setValue(lon);
    ui->zoomlevel->setValue(zoom);
    ui->label_loadcatalog->setText(folder);

    ui->loadCatalogButton->setIcon(QIcon(":/image/catalog.png"));
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::setMaster(MapWidgetTool *m)
{
    _master = m;
    ui->latitude_SpinBox->setValue(_master->getmap_center_lat());
    ui->longitude_SpinBox->setValue(_master->getmap_center_lon());
    ui->zoomlevel->setValue(_master->getmap_zoom());
}

void SettingsForm::on_closeButton_clicked()
{
    close();
}


void SettingsForm::on_saveButton_clicked()
{
    _settings.beginGroup("Map");
    _settings.setValue("MapCenter_latitude", ui->latitude_SpinBox->value());
    _settings.setValue("MapCenter_longitude", ui->longitude_SpinBox->value());
    _settings.setValue("MapZoomLevel", ui->zoomlevel->value());
    _settings.endGroup();

    _settings.beginGroup("LoadFolder");
    _settings.setValue("LoadMapFolder", ui->label_loadcatalog->text());

    _settings.endGroup();

    _master->onCenterChangedByForm( ui->latitude_SpinBox->value(), ui->longitude_SpinBox->value(), ui->zoomlevel->value());
    _master->set_load_path(ui->label_loadcatalog->text());
    close();
}


void SettingsForm::on_loadCatalogButton_clicked()
{
    QString folder =  QFileDialog::getExistingDirectory(this,"Каталог для загрузки карт", ui->label_loadcatalog->text(), QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    ui->label_loadcatalog->setText(folder);
}

