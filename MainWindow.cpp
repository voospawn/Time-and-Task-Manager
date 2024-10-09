#include "MainWindow.h"
#include "TaskManager.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    TaskManager taskmanager;
    ui->setupUi(this);

  //  connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);

    for(int i = 0; i < taskmanager.getAmountOfWorkTasks(); i++){
        std::thread t(&TaskManager::startThread, &taskmanager, 0, i);
        t.detach();
        workThreads.push_back(t);
    }
    for(int i = 0; i < taskmanager.getAmountOfPrivateTasks(); i++){
        std::thread t(&TaskManager::startThread, &taskmanager, 1, i);
        t.detach();
        privateThreads.push_back(t);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    // workThreads.join();
    // privateThreads.join();
    // studyingThreads.join();
}


// void MainWindow::openSettings()
// {
//     Settings settings(this);
//     settings.exec();
// }

void MainWindow::on_TestButton_clicked(){

}
