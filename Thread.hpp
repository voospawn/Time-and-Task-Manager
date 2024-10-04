#pragma once
#ifndef THREAD_HPP
#define THREAD_HPP

#include <QTimer>
#include <string>
#include <vector>
#include "task.hpp"

using namespace std;

class thread
{
private:
public:
    Thread(vector<Task>& tasks,int numberInVector);

    int timer(int miliseconds);
    void notify(QString message);
    void paused();
};

#endif
