#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString name)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   settings = new QSettings("/settings.ini", QSettings::IniFormat, this);        // Создаем обьект класса настроек (установим формат .ini)
   setObjectName(name);                                                          // Установим имя для настроек
   setWindowTitle(name);                                                         // Устоновим отоброжаемое название формы
   loadSettings();                      // Загружаем настройки

}

MainWindow::~MainWindow()
{
    saveSettings();                     // Сохраняем настройки
    delete ui;
}

void MainWindow::saveSettings()
{
    settings->beginGroup("forms");                      // Создадим подпункт (папку либо папку для реестра) с название настроек
    settings->beginGroup(objectName());                 // Подпункт (подпапка) для конкретного таблицы
    settings->setValue("geometryWindow", geometry());   // сохраним размеры и положение окна
    settings->endGroup();
    settings->endGroup();
}

void MainWindow::loadSettings()
{
    settings->beginGroup("forms");
    settings->beginGroup(objectName());
    setGeometry(settings->value("geometryWindow", QRect(300,200,600,300)).toRect()); // загрузим размеры и приведем их в типу Rect
    settings->endGroup();
    settings->endGroup();
}

