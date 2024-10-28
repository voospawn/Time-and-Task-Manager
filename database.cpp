#include "database.h"

database::database(TaskManager &taskmanager) : taskmanager(taskmanager) {}

bool database::getDatabaseFunction(){ return databaseFunction; }

string database::replaceSpaces(string word){
    string result;
    for(char x : word){
        if(x == ' '){
            x = '_';
            result.push_back(x);
        }else{
            result.push_back(x);
        }
    }
    return result;
}

string database::replaceUnderscores(string word){
    string result;
    for(char x : word){
        if(x == '_'){
            x = ' ';
            result.push_back(x);
        }else{
            result.push_back(x);
        }
    }
    return result;
}

void database::writeDB(){
    ofstream file("db.txt");
    workTasks = taskmanager.getWorkTasks();
    privateTasks = taskmanager.getPrivateTasks();
    studyingTasks = taskmanager.getStudyingTasks();

    if(!file.is_open()){
        databaseFunction = false;
        return;
    }else{
        databaseFunction = true;
    }

    file << "workTasks:" << endl;
    for(const auto task : workTasks){
        string name = replaceSpaces(task.getName());
        file << name << " " << task.getEveryMinutesNotification() << " " << task.getMinuteToDo() << " " << task.getHourToDo() << " "
             << task.getDayToDo() << " " << task.getMonthToDo() << " " << task.getYearToDo() << " " << task.getPausedStatus() << endl;
    }

    file << "privateTasks:" << endl;
    for(const auto task : privateTasks){
        string name = replaceSpaces(task.getName());
        file << name << " " << task.getEveryMinutesNotification() << " " << task.getMinuteToDo() << " " << task.getHourToDo() << " "
             << task.getDayToDo() << " " << task.getMonthToDo() << " " << task.getYearToDo() << " " << task.getPausedStatus() << endl;
    }

    file << "studyingTasks:" << endl;
    for(const auto task : studyingTasks){
        string name = replaceSpaces(task.getName());
        file << name << " " << task.getEveryMinutesNotification() << " " << task.getMinuteToDo() << " " << task.getHourToDo() << " "
             << task.getDayToDo() << " " << task.getMonthToDo() << " " << task.getYearToDo() << " " << task.getPausedStatus() << endl;
    }
}

void database::readDB(){
    ifstream file("db.txt");

    if(!file.is_open()){
        databaseFunction = false;
        return;
    }else{
        databaseFunction = true;
    }

    string line, section;
    while(getline(file, line)){
        istringstream iss(line);
        string word;
        iss >> word;

        if(word == "workTasks:"){
            section = "workTasks";
        }else if(word == "privateTasks:"){
            section = "privateTasks";
        }else if(word == "studyingTasks:"){
            section = "studyingTasks";
        }else if(section == "workTasks"){
            string name;
            int everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo;
            bool paused;
            iss >> name >> everyMinutesNotification >> minuteToDo >> hourToDo >> dayToDo >> monthToDo >> yearToDo >> paused;
            Task task(replaceUnderscores(name), everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo, paused, true, false, false);
            taskmanager.AddTask(task, 0);
        }else if(section == "privateTasks"){
            string name;
            int everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo;
            bool paused;
            iss >> name >> everyMinutesNotification >> minuteToDo >> hourToDo >> dayToDo >> monthToDo >> yearToDo >> paused;
            Task task(replaceUnderscores(name), everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo, paused, true, false, false);
            taskmanager.AddTask(task, 1);
        }else if(section == "studyingTasks"){
            string name;
            int everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo;
            bool paused;
            iss >> name >> everyMinutesNotification >> minuteToDo >> hourToDo >> dayToDo >> monthToDo >> yearToDo >> paused;
            Task task(replaceUnderscores(name), everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo, paused, true, false, false);
            taskmanager.AddTask(task, 2);
        }
    }
}



