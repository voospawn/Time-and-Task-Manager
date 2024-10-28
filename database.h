#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "Task.hpp"
#include "TaskManager.hpp"
#include <fstream>
#include <sstream>

using namespace std;

class database {
private:
    vector<Task> workTasks;
    vector<Task> privateTasks;
    vector<Task> studyingTasks;
    bool databaseFunction;
    TaskManager &taskmanager;
public:
    database(TaskManager &taskmanager);

    bool getDatabaseFunction();

    void readDB();
    void writeDB();
    string replaceSpaces(string word);
    string replaceUnderscores(string word);
};

#endif
