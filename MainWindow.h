#pragma once

#include <QMainWindow>
#include <thread>

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
    void on_TestButton_clicked();

private:
    std::vector<std::thread> workThreads;
    std::vector<std::thread> privateThreads;
    std::vector<std::thread> studyingThreads;
    Ui::MainWindow *ui;
};
