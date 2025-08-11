#include "addobjectform.h"
#include "ui_addobjectform.h"
#include <QValidator>
#include <QMessageBox>

AddObjectForm::AddObjectForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddObjectForm)
{
    ui->setupUi(this);

    ui->altitude_lineEdit->hide();
    ui->label_5->hide();
    ui->id_checkBox->hide();
    ui->copter_comboBox->hide();
    ui->copter_comboBox->setEnabled(false);
    ui->station_comboBox->hide();
    ui->station_comboBox->setEnabled(false);
    ui->id_checkBox_3->hide();

    QLocale locale(QLocale::English);


    QDoubleValidator *val1 = new QDoubleValidator(-90.0, 90.0, 4);
    val1->setNotation(QDoubleValidator::StandardNotation);
    val1->setLocale(locale);
    QDoubleValidator *val2 = new QDoubleValidator(-90.0, 90.0, 4);
    val2->setNotation(QDoubleValidator::StandardNotation);
    val2->setLocale(locale);
    QDoubleValidator *val3 = new QDoubleValidator(0.0, 200.0, 2);
    val3->setNotation(QDoubleValidator::StandardNotation);
    val3->setLocale(locale);
    QDoubleValidator *val4 = new QDoubleValidator(0.0, 1000.0, 2);
    val4->setNotation(QDoubleValidator::StandardNotation);
    val4->setLocale(locale);

    ui->latitude_lineEdit->setValidator(val1);
    ui->longitude_lineEdit->setValidator(val2);
    ui->radius_lineEdit->setValidator(val3);
    ui->altitude_lineEdit->setValidator(val4);
}

AddObjectForm::~AddObjectForm()
{
    delete ui;
}

void AddObjectForm::setMaster(MapWidgetTool *m)
{
    _master = m;
    QObject::connect (this, &AddObjectForm::addStationToMap, _master, &MapWidgetTool::addStationOnMap);
    QObject::connect (this, &AddObjectForm::addQuadToMap, _master, &MapWidgetTool::addQuadOnMap);
    QObject::connect (this, &AddObjectForm::addRemoteToMap, _master, &MapWidgetTool::addRemoteControllerOnMap);
}

void AddObjectForm::initCopterComboBox()
{
     QList <MapMarker> copters = _master->getCopterList();
     QStringList combo_names;
     QString str;
     for(int i=0; i<copters.size(); i++)
     {
         str = QString("%1 %2 (%3 %4)").arg(copters[i].id()).arg(copters[i].name()).arg(copters[i].coord().latitude()).arg(copters[i].coord().longitude());
         combo_names.push_back(str);
     }

     ui->copter_comboBox->addItems(combo_names);
}

void AddObjectForm::initStationComboBox()
{
    QList <MapMarker> stations = _master->getStationList();
    QStringList combo_names;
    QString str;
    for(int i=0; i<stations.size(); i++)
    {
        str = QString("%1 %2 (%3 %4)").arg(stations[i].id()).arg(stations[i].name()).arg(stations[i].coord().latitude()).arg(stations[i].coord().longitude());
        combo_names.push_back(str);
    }

    ui->station_comboBox->addItems(combo_names);
}

void AddObjectForm::on_closeButton_clicked()
{
    close();
}


void AddObjectForm::on_saveButton_clicked()
{
    if(!ui->latitude_lineEdit->hasAcceptableInput() || !ui->longitude_lineEdit->hasAcceptableInput()
            || !ui->altitude_lineEdit->hasAcceptableInput() || !ui->radius_lineEdit->hasAcceptableInput())
    {
        QMessageBox::information(this, "Добавление объекта", "Введенные значения не допустимы");
        return;
    }
    auto type = ui->type_comboBox->currentIndex();
    QString tt = ui->latitude_lineEdit->text();
    auto lat = ui->latitude_lineEdit->text().replace(',','.').toDouble(); //ui->latitude_SpinBox->value();
    auto lon = ui->longitude_lineEdit->text().replace(',','.').toDouble();//ui->longitude_SpinBox->value();

    if(type==0) //стационарный объект
    {
        auto radius = ui->radius_lineEdit->text().replace(',','.').toDouble();  //ui->radius_SpinBox->value();
        emit addStationToMap(lat, lon, radius, ui->status_checkBox->isChecked());
    }
    else if(type==1)
    {
        auto alt = ui->altitude_lineEdit->text().replace(',','.').toDouble(); //ui->altitude_SpinBox->value();
        if(!ui->id_checkBox_3->isChecked())
            emit addQuadToMap(lat, lon, alt, -1,  ui->status_checkBox->isChecked());
        else
        {
            auto ind = ui->station_comboBox->currentIndex();
            QList <MapMarker> stations = _master->getStationList();
            if(ind>=0 && stations.size() >0)
                emit addQuadToMap(lat, lon, alt, stations[ind].id(), ui->status_checkBox->isChecked());
            else emit addQuadToMap(lat, lon, alt, -1,  ui->status_checkBox->isChecked());
        }
    }
    else if(type==2)
    {
        if(!ui->id_checkBox->isChecked())
            emit addRemoteToMap(lat, lon, -1, ui->status_checkBox->isChecked());
        else
        {
            auto ind = ui->copter_comboBox->currentIndex();
            QList <MapMarker> copters = _master->getCopterList();
            if(ind>=0 &&  copters.size()>0)
                emit addRemoteToMap(lat, lon, copters[ind].id(), ui->status_checkBox->isChecked());
            else emit addRemoteToMap(lat, lon, -1, ui->status_checkBox->isChecked());
        }
    }

    close();
}


void AddObjectForm::on_type_comboBox_currentIndexChanged(int index)
{
    if (index ==0)
    {

        ui->altitude_lineEdit->hide();
        ui->label_5->hide();
        ui->id_checkBox->hide();
        ui->copter_comboBox->hide();

        ui->label_4->show();

        ui->radius_lineEdit->show();
        ui->station_comboBox->hide();
        ui->id_checkBox_3->hide();

    }
    else if(index==1)
    {

        ui->altitude_lineEdit->show();
        ui->label_5->show();

        ui->label_4->hide();

        ui->radius_lineEdit->hide();
        ui->id_checkBox->hide();
        ui->copter_comboBox->hide();
        ui->station_comboBox->show();
        ui->id_checkBox_3->show();

        initStationComboBox();

    }

    else if(index==2) //пульт
    {
        ui->altitude_lineEdit->hide();
        ui->radius_lineEdit->hide();
        ui->label_4->hide();
        ui->label_5->hide();

        ui->id_checkBox->show();
        ui->copter_comboBox->show();
        ui->station_comboBox->hide();
        ui->id_checkBox_3->hide();

        initCopterComboBox();

    }
}


void AddObjectForm::on_latitude_lineEdit_textEdited(const QString &arg1)
{
    if (!ui->latitude_lineEdit->hasAcceptableInput() && arg1.length()>1)
    {
        ui->latitude_lineEdit->setStyleSheet("background-color: rgb(251, 201, 201);");
        ui->latitude_lineEdit->setToolTip("Допустим ввод значений [-90;90]");
        return;
    }
    else
    {
        ui->latitude_lineEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->latitude_lineEdit->setToolTip("");
        return;
    }

}


void AddObjectForm::on_longitude_lineEdit_textEdited(const QString &arg1)
{
    if (!ui->longitude_lineEdit->hasAcceptableInput() && arg1.length()>1)
    {
        ui->longitude_lineEdit->setStyleSheet("background-color: rgb(251, 201, 201);");
        ui->longitude_lineEdit->setToolTip("Допустим ввод значений [-90;90]");
        return;
    }
    else
    {
        ui->longitude_lineEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->longitude_lineEdit->setToolTip("");
        return;
    }
}


void AddObjectForm::on_radius_lineEdit_textEdited(const QString &arg1)
{
    if (!ui->radius_lineEdit->hasAcceptableInput() && arg1.length()>1)
    {
        ui->radius_lineEdit->setStyleSheet("background-color: rgb(251, 201, 201);");
        ui->radius_lineEdit->setToolTip("Допустим ввод значений [0;200]");
        return;
    }
    else
    {
        ui->radius_lineEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->radius_lineEdit->setToolTip("");
        return;
    }
}


void AddObjectForm::on_altitude_lineEdit_textEdited(const QString &arg1)
{
    if (!ui->altitude_lineEdit->hasAcceptableInput() && arg1.length()>1)
    {
        ui->altitude_lineEdit->setStyleSheet("background-color: rgb(251, 201, 201);");
        ui->altitude_lineEdit->setToolTip("Допустим ввод значений [0;1000]");
        return;
    }
    else
    {
        ui->altitude_lineEdit->setStyleSheet("background-color: rgb(255, 255, 255);");
        ui->altitude_lineEdit->setToolTip("");
        return;
    }
}


void AddObjectForm::on_id_checkBox_clicked(bool checked)
{
    ui->copter_comboBox->setEnabled(checked);
}


void AddObjectForm::on_id_checkBox_3_clicked(bool checked)
{
    ui->station_comboBox->setEnabled(checked);
}

