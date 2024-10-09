#include "thread.hpp"


thread::thread(vector<Task>& tasks,int numberInVector) {
    int milisecondsEveryNotificaton = tasks[numberInVector].getEveryMinutesNotification() * 60;
    milisecondsEveryNotificaton *= 1000;
    bool paused = tasks[numberInVector].getPausedStatus();

    while(!paused){
    // timer
    timer(milisecondsEveryNotificaton);
    //notify
    QString message = "Your task " + QString::fromStdString(tasks[numberInVector].getName()) +
                      " is due on " + QString::number(tasks[numberInVector].getHourToDo()) + ":" +
                      QString::number(tasks[numberInVector].getMinuteToDo()) + "  " +
                      QString::number(tasks[numberInVector].getDayToDo()) + "." +
                      QString::number(tasks[numberInVector].getMonthToDo()) + "." +
                      QString::number(tasks[numberInVector].getYearToDo());
    QString windowName = QString::fromStdString(tasks[numberInVector].getName());
    notify(message, windowName);
    //update values
    milisecondsEveryNotificaton = tasks[numberInVector].getEveryMinutesNotification() * 60;
    milisecondsEveryNotificaton *= 1000;
    paused = tasks[numberInVector].getPausedStatus();
    }
}

void thread::timer(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void thread::notify(QString message, QString windowName){
    QMessageBox::information(nullptr, windowName, message);
}
