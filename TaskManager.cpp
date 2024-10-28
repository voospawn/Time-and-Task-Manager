#include <TaskManager.hpp>

void TaskManager::AddTask(Task task, int vectorNum){
    if(vectorNum == 0){
        workTasks.push_back(task);
    }else if(vectorNum == 1){
        privateTasks.push_back(task);
    }else{
        studyingTasks.push_back(task);
    }
}

void TaskManager::deleteTask(string name, int vectorNum){
    if(vectorNum == 0){
        for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
            if(task->getName() == name){
                workTasks.erase(task);
                return;
            }
        }
    }else if(vectorNum == 1){
        for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
            if(task->getName() == name){
                privateTasks.erase(task);
                return;
            }
        }
    }else{
        for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
            if(task->getName() == name){
                studyingTasks.erase(task);
                return;
            }
        }
    }
}

void TaskManager::pauseTask(string name, int vectorNum){
    if(vectorNum == 0){
        for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(true);
                return;
            }
        }
    }else if(vectorNum == 1){
        for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(true);
                return;
            }
        }
    }else{
        for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(true);
                return;
            }
        }
    }
}

void TaskManager::unPauseTask(string name, int vectorNum){
    if(vectorNum == 0){
        for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(false);
                return;
            }
        }
    }else if(vectorNum == 1){
        for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(false);
                return;
            }
        }
    }else{
        for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
            if(task->getName() == name){
                task->setPausedStatus(false);
                return;
            }
        }
    }
}

void TaskManager::setNotImportant(string name, int vectorNum){
    if(vectorNum == 0){
        for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(true);
                task->setMediumImportance(false);
                task->setImportant(false);
                return;
            }
        }
    }else if(vectorNum == 1){
        for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(true);
                task->setMediumImportance(false);
                task->setImportant(false);
                return;
            }
        }
    }else{
        for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(true);
                task->setMediumImportance(false);
                task->setImportant(false);
                return;
            }
        }
    }
}

void TaskManager::setMediumImportance(string name, int vectorNum){
    if(vectorNum == 0){
        for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(false);
                task->setMediumImportance(true);
                task->setImportant(false);
                return;
            }
        }
    }else if(vectorNum == 1){
        for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(false);
                task->setMediumImportance(true);
                task->setImportant(false);
                return;
            }
        }
    }else{
        for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
            if(task->getName() == name){
                task->setNotImportant(false);
                task->setMediumImportance(true);
                task->setImportant(false);
                return;
            }
        }
    }
}
void TaskManager::setEveryMinutesNotification(string name, int vectorNum, int everyMinutesNotification){
  if(vectorNum == 0){
      for(auto task = workTasks.begin(); task != workTasks.end(); ++task){
          if(task->getName() == name){
              task->setEveryMinutesNotification(everyMinutesNotification);
              return;
          }
      }
  }else if(vectorNum == 1){
      for(auto task = privateTasks.begin(); task != privateTasks.end(); ++task){
        if(task->getName() == name){
            task->setEveryMinutesNotification(everyMinutesNotification);
            return;
        }
      }
  }else{
      for(auto task = studyingTasks.begin(); task != studyingTasks.end(); ++task){
        if(task->getName() == name){
            task->setEveryMinutesNotification(everyMinutesNotification);
            return;
        }
      }
  }
}

void TaskManager::startThread(int vectorNum, int numberInVector){
    if(vectorNum == 0){
        thread(workTasks, numberInVector);
    }else if(vectorNum == 1){
        thread(privateTasks, numberInVector);
    }else{
        thread(studyingTasks, numberInVector);
    }
}
