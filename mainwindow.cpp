#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   settings = new QSettings(this);      // Создаем обьект класса настроек

}

MainWindow::~MainWindow()
{
    delete ui;
}

