#pragma once

#include <QMainWindow>
#include <thread>
#include <QInputDialog>
#include "TaskManager.hpp"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CreateTaskButton_clicked();
    void on_EditTaskButton_clicked();
    void on_DeleteTaskButton_clicked();
    void on_FinishTaskButton_clicked();
    void on_ChangeTaskImportanceButton_clicked();
    void on_PauseTaskButton_clicked();
    void on_DeleteFinishedTasksButton_clicked();
    void on_ExitButton_clicked();

private:
    TaskManager taskmanager;
    vector<std::thread> workThreads;
    vector<std::thread> privateThreads;
    vector<std::thread> studyingThreads;
    Ui::MainWindow *ui;
};
