//zarządza wszystkimi zadaniami i innymi rzeczami oprócz konfiguracji i zapisywania zadań
#pragma once
#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP


#include <string>
#include <vector>
#include "Task.hpp"
#include "thread.hpp"

using namespace std;

class TaskManager {
private:                    // vector Numbers:
    vector<Task> workTasks; // 0
    vector<Task> privateTasks; // 1
    vector<Task> studyingTasks;  // 2
public:
    void AddTask(Task task, int vectorNum);
    void deleteTask(string name, int vectorNum);
    void pauseTask(string name, int vectorNum);   // może kiedyś złączę voidy pauseTask i unPauseTask
    void unPauseTask(string name, int vectorNum); //
    void setNotImportant(string name, int vectorNum);
    void setMediumImportance(string name, int vectorNum);
    void setImportant(string name, int vectorNum);
    void setEveryMinutesNotification(string name, int vectorNum, int everyMinutesNotification);
    void startThread(int vectorNum, int numberInVector);

    const vector<Task>& getWorkTasks() const { return workTasks; }
    const vector<Task>& getPrivateTasks() const { return privateTasks; }
    const vector<Task>& getStudyingTasks() const { return studyingTasks; }
    int getAmountOfWorkTasks() const { return workTasks.size(); }
    int getAmountOfPrivateTasks() const { return privateTasks.size(); }
    int getAmountOfStudyingTasks() const { return studyingTasks.size(); }
};
#endif
