#include "Thread.hpp"
Thread::Thread(vector<Task>& tasks,int numberInVector){
int everyMinutesNotification = tasks[numberInVector].getEveryMinutesNotification();
bool paused = tasks[numberInVector].getPausedStatus();
  
while(!paused){
  
  }
}

Thread::timer(int milliseconds){}
