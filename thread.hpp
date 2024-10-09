#pragma once
#ifndef THREAD_HPP
#define THREAD_HPP

#include <QTimer>
#include <QString>
#include <vector>
#include "task.hpp"
#include <QMessageBox>
#include <QEventLoop>

using namespace std;

class thread
{
private:
public:
    thread(vector<Task>& tasks,int numberInVector);

    void timer(int miliseconds);
    void notify(QString message, QString windowName);
};

#endif
