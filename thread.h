#pragma once
#ifndef THREAD_H
#define THREAD_H

#include <QTimer>
#include <string>
#include <vector>
#include "task.hpp"

using namespace std;

class thread
{
private:
public:
    thread(vector<Task>& tasks,int numberInVector);

    int timer(int miliseconds);
    void notify(QString message);
    void paused();
};

#endif
