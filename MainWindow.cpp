#include "MainWindow.h"
#include "TaskManager.hpp"
#include "notification.hpp"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    TaskManager taskmanager;
    ui->setupUi(this);

  //  connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);

    for(int i = 0; i < taskmanager.getAmountOfWorkTasks(); i++){
        std::thread t(taskmanager.startThread(0, i));
        t.detach();
        workThreads.push_back(std::move(t));
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
    Notification("test");
}
