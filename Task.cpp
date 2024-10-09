#include "Task.hpp"

//constructor

Task::Task(string name, int everyMinutesNotification, int minuteToDo, int hourToDo, int dayToDo, int monthToDo, int yearToDo, bool paused, bool notImportant, bool mediumImportance, bool important) :
    name(name), everyMinutesNotification(everyMinutesNotification), minuteToDo(minuteToDo), hourToDo(hourToDo), dayToDo(dayToDo), monthToDo(monthToDo), yearToDo(yearToDo),
    paused(paused), notImportant(notImportant), mediumImportance(mediumImportance), important(important) {}

//getters

string Task::getName() const{ return name; }
int Task::getEveryMinutesNotification() const{ return everyMinutesNotification; }
int Task::getMinuteToDo() const{ return minuteToDo; }
int Task::getHourToDo() const{ return hourToDo; }
int Task::getDayToDo() const{ return dayToDo; }
int Task::getMonthToDo() const{ return monthToDo; }
int Task::getYearToDo() const{ return yearToDo; }
bool Task::getPausedStatus() const{ return paused; }
bool Task::getNotImportant() const{ return notImportant; }
bool Task::getMediumImportance() const{ return mediumImportance; }
bool Task::getImportant() const{ return important; }

//setters

void Task::setName(string newName){ name = newName; }
void Task::setEveryMinutesNotification(int newEveryMinutesNotification){ everyMinutesNotification = newEveryMinutesNotification; }
void Task::setMinuteToDo(int newMinute){ minuteToDo = newMinute; }
void Task::setHourToDo(int newHour){ hourToDo = newHour; }
void Task::setDayToDo(int newDay){ dayToDo = newDay; }
void Task::setMonthToDo(int newMonth){ monthToDo = newMonth; }
void Task::setYearToDo(int newYear){ yearToDo = newYear;}
void Task::setPausedStatus(bool newPausedStatus){ newPausedStatus = paused; }
void Task::setNotImportant(bool newImportance){ notImportant = newImportance; }
void Task::setMediumImportance(bool newImportance){ mediumImportance = newImportance; }
void Task::setImportant(bool newImportance){ important = newImportance; }
