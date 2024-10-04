#pragma once
#ifndef TASK_HPP
#define TASK_HPP

#include <string>

using namespace std;

class Task{
private:
    string name;
    int everyMinutesNotification;
    int minuteToDo;
    int hourToDo;
    int dayToDo;
    int monthToDo;
    int yearToDo;
    bool paused = false;
    bool notImportant = true; // deafult setting for imporance is not important
    bool mediumImportance = false; // for now there are only three importance levels, it may chcange in the future
    bool important = false;
public:
    //constructor
    Task(string name, int everyMinutesNotification, int minuteToDo, int hourToDo, int dayToDo, int monthToDo, int yearToDo, bool paused, bool notImportant, bool mediumImportance, bool important);

    // getters
    string getName() const;
    int getEveryMinutesNotification() const;
    int getMinuteToDo() const;
    int getHourToDo() const;
    int getDayToDo() const;
    int getMonthToDo() const;
    int getYearToDo() const;
    bool getPausedStatus() const;
    bool getNotImportant() const;
    bool getMediumImportance() const;
    bool getImportant() const;

    // setters
    void setName(string newName);
    void setEveryMinutesNotification(int newEveryMinutesNotification);
    void setMinuteToDo(int newMinute);
    void setHourToDo(int newHour);
    void setDayToDo(int newDay);
    void setMonthToDo(int newMonth);
    void setYearToDo(int newYear);
    void setPausedStatus(bool newPausedStatus);
    void setNotImportant(bool newImportance);
    void setMediumImportance(bool newImportance);
    void setImportant(bool newImportance);
};
#endif
