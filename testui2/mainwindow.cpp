#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "freqampdialog.h"
#include "../ResourceParameter.h"
#include <QDebug>
#include <QColorDialog>
#include <QVectorIterator>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator( new QIntValidator(1, 100, this) );
    ui->lineEdit_2->setValidator( new QIntValidator(0, 100, this) );
    ui->lineEdit_3->setValidator( new QIntValidator(1, 429496729, this) ); //quick fix, need to set max value to 2^32
    params = new std::ResourceParameter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   
    if(ui->lineEdit != NULL)
    {        
        float radius = ui->lineEdit->text().toFloat();
        params->setRadius(radius);
    }
	
    if(ui->lineEdit_2 != NULL)
    {       
        float waterfraction = (ui->lineEdit_2->text().toFloat())/100;
        params->setWaterFraction(waterfraction);
        if(ui->pushButton_2->text() != "Color")
        {            
            params->setWaterFirstColor(ui->pushButton_2->text().toUtf8().constData());
        }
        if(ui->pushButton_3->text() != "Color")
        {            
            params->setWaterSecondColor(ui->pushButton_3->text().toUtf8().constData());
        }
    }
    if(ui->lineEdit_3 != NULL)
    {
        int seed = ui->lineEdit_3->text().toInt();
        params->setSeed(seed);
    }
	    
    if(ui->pushButton_4->text() != "Color")
    {        
        params->setTerrainFirstColor(ui->pushButton_4->text().toUtf8().constData());
    }
    if(ui->pushButton_5->text() != "Color")
    {        
        params->setTerrainSecondColor(ui->pushButton_5->text().toUtf8().constData());
    }
	
	if(ui->pushButton_6->text() != "Color")
    {        
        params->setMountainFirstColor(ui->pushButton_6->text().toUtf8().constData());
    }
    if(ui->pushButton_7->text() != "Color")
    {        
        params->setMountainSecondColor(ui->pushButton_7->text().toUtf8().constData());
    }
		
    //debug messages
    qDebug() << params->getRadius();
    qDebug() << params->getWaterFraction();
    qDebug() << params->getSeed();
	qDebug() << QString::fromStdString(params->getWaterFirstColor());
	qDebug() << QString::fromStdString(params->getWaterSecondColor());
	qDebug() << QString::fromStdString(params->getTerrainFirstColor());
	qDebug() << QString::fromStdString(params->getTerrainSecondColor());
	qDebug() << QString::fromStdString(params->getMountainFirstColor());
	qDebug() << QString::fromStdString(params->getMountainSecondColor());
	
	for (std::vector<std::pair <float, float> >::const_iterator iter = params->getFrequencyAmplitude().begin(); iter != params->getFrequencyAmplitude().end(); ++iter)
	{
		qDebug() << iter->first <<", " << iter->second;
    }

    for (std::vector<std::pair <std::string, int> >::const_iterator iter = params->getMeshLocObjAmount().begin(); iter != params->getMeshLocObjAmount().end(); ++iter)
    {
        qDebug() << QString::fromStdString(iter->first) <<", " << iter->second;
    }
 /*   for (std::vector<std::string>::const_iterator iter = params->getMeshLocations().begin(); iter != params->getMeshLocations().end(); ++iter)
    {
        qDebug() << "Mesh path:" << QString::fromStdString(*iter);
    }
    for (std::vector<int>::const_iterator iter = params->getObjectAmount().begin(); iter != params->getObjectAmount().end(); ++iter)
    {
        qDebug() << "Amount: " << *iter;
    }*/
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_2->setStyleSheet(qss);
    ui->pushButton_2->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_3_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_3->setStyleSheet(qss);
    ui->pushButton_3->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_4_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_4->setStyleSheet(qss);
    ui->pushButton_4->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_5_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_5->setStyleSheet(qss);
    ui->pushButton_5->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_6_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_6->setStyleSheet(qss);
    ui->pushButton_6->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_7_clicked()
{
    QColor rg = QColorDialog::getColor(Qt::white,this, "Text Color",  QColorDialog::DontUseNativeDialog);
    QString qss = QString("background-color: %1").arg(rg.name());
    ui->pushButton_7->setStyleSheet(qss);
    ui->pushButton_7->setText(""+rg.name());
    qDebug() << "Color chosen: "+rg.name();
}

void MainWindow::on_pushButton_8_clicked()
{
    openNewWindow();
}

void MainWindow::openNewWindow()
{
    dialog = new FreqAmpDialog();
    //add items from ResourceParameter vector to listwidget
    dialog->instantiateList(params->getFrequencyAmplitude());
	if(dialog->exec())
    {
        //clear ResourceParameter vector
        params->emptyFrequencyAmplitude();
		for(int i=0; i<dialog->getThem()->count(); i++)
		{			
			QStringList values = dialog->getThem()->item(i)->text().split(",");
            //put values to ResourceParameter vector
            setAmps( values.value(0).toFloat(),  values.value(1).toFloat());
		}		
	}	
}

void MainWindow::setAmps(float p_val1, float p_val2)
{
    params->setFrequencyAmplitude(p_val1, p_val2);

    //alternate way:
    //params->setFrequency(p_val1);
    //params->setAmplitude(p_val2);
}

void MainWindow::on_pushButton_9_clicked()
{
    meshdialog = new MeshDialog();
    //add items from ResourceParameter vector to listwidget
    meshdialog->instantiateList(params->getMeshLocObjAmount());
    if(meshdialog->exec())
    {
        //clear ResourceParameter vector
        params->emptyMeshLocObjAmount();
        for(int i=0; i<meshdialog->getMeshes()->count(); i++)
        {
            QStringList values = meshdialog->getMeshes()->item(i)->text().split(",");

            //put values to ResourceParameter vector
            setMeshes( values.value(0),  values.value(1).toInt());
        }
    }
}

void MainWindow::setMeshes(QString p_path, int p_count)
{
    params->setMeshLocObjAmount(p_path.toStdString(), p_count);

    //alternate way:
    //params->setMeshLocation(p_path.toStdString());
    //params->setObjectAmount(p_count);
}
