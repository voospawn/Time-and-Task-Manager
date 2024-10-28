#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    TaskManager taskmanager;
  //  connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings);

    for(int i = 0; i < taskmanager.getAmountOfWorkTasks(); i++){
        std::thread t(&TaskManager::startThread, &taskmanager, 0, i);
        t.detach();
        workThreads.push_back(t);
    }
    for(int i = 0; i < taskmanager.getAmountOfPrivateTasks(); i++){
        std::thread t(&TaskManager::startThread, &taskmanager, 1, i);
        t.detach();
        privateThreads.push_back(t);
    }
    for(int i = 0; i < taskmanager.getAmountOfStudyingTasks(); i++){
        std::thread t(&TaskManager::startThread, &taskmanager, 2, i);
        t.detach();
        studyingThreads.push_back(t);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    for(int i = 0; i < taskmanager.getAmountOfWorkTasks(); i++){
        workThreads[i].~thread();
    }
    for(int i = 0; i < taskmanager.getAmountOfPrivateTasks(); i++){
        privateThreads[i].~thread();
    }
    for(int i = 0; i < taskmanager.getAmountOfStudyingTasks(); i++){
        studyingThreads[i].~thread();
    }
    return;
}

void MainWindow::on_CreateTaskButton_clicked(){
    QMessageBox::information(nullptr, "informacja", "są trzy grupy dostępne. \n w następnym okienku wpisz jedną z nich: \n praca \n nauka \n prywatne \n pisz małymi literami i bez spacji*");
    QString categoryString = QInputDialog::getText(this, "Podaj kategorię", "kategoria:");
    int category = 0;
    if (categoryString == "praca" || categoryString == "praca " || categoryString == " praca"){
    category = 0;
    }else if(categoryString == "nauka" || categoryString == "nauka " || categoryString == " nauka"){
    category = 2;
    }else{
    category = 1;
    }
    QString name = QInputDialog::getText(this, "Nazwa Zadania", "nazwa:");
    int everyMinutesNotification = QInputDialog::getInt(this, "Powiadomienia", "co ile minut ma się wyświetlać przypomnienie o zadaniu:");
    int minuteToDo = QInputDialog::getInt(this, "czas do zrobienia", "Tu musisz wpisać datę do której musisz zrobić zadanie *minuty, domyślne to 00");
    int hourToDo = QInputDialog::getInt(this, "czas do zrobienia", "Tu musisz wpisać datę do której musisz zrobić zadanie *godziny, domyślne to 00");
    int dayToDo = QInputDialog::getInt(this, "czas do zrobienia", "Tu musisz wpisać datę do której musisz zrobić zadanie *dni, domyślne to 1");
    int monthToDo = QInputDialog::getInt(this, "czas do zrobienia", "Tu musisz wpisać datę do której musisz zrobić zadanie *miesiące, domyślne to 11");
    int yearToDo = QInputDialog::getInt(this, "czas do zrobienia", "Tu musisz wpisać datę do której musisz zrobić zadanie *lata, domyślne to 2024");
    QString powiadomienia = QInputDialog::getText(this, "włączone powiadomienia", "Czy powiadomienia mają być wyłączone wpisz 'tak' lub 'nie' *domyślnie są włączone\n *pisz bez spacji dużych znaków lub znaków specjalnych");
    bool paused;
    if(powiadomienia == "nie" ||powiadomienia == " nie"||powiadomienia == "nie "){
      paused = true;
    }else{
      paused = false;
    }
    Task newTask(name.toStdString(), everyMinutesNotification, minuteToDo, hourToDo, dayToDo, monthToDo, yearToDo, paused, true, false, false);
    taskmanager.AddTask(newTask, category);

    if(category == 0){
    std::thread t(&TaskManager::startThread, &taskmanager, category, taskmanager.getWorkTasks());
    t.detach();
    workThreads.push_back(t);
    }else if(category == 1){
    std::thread t(&TaskManager::startThread, &taskmanager, category, taskmanager.getPrivateTasks());
    t.detach();
    privateThreads.push_back(t);
    }else{
    std::thread t(&TaskManager::startThread, &taskmanager, category, taskmanager.getStudyingTasks());
    t.detach();
    studyingThreads.push_back(t);
    }

    QMessageBox::information(nullptr, "sukces", "Udało się utworzyć nowe zadanie");
}

void MainWindow::on_EditTaskButton_clicked(){
  QString name = QInputDialog::getText(this, "Nazwa Zadania", "nazwa:");
  QString categoryString = QInputDialog::getText(this, "Podaj kategorię", "kategoria:");
  int category = 0;
  if (categoryString == "praca" || categoryString == "praca " || categoryString == " praca"){
  category = 0;
  }else if(categoryString == "nauka" || categoryString == "nauka " || categoryString == " nauka"){
  category = 2;
  }else{
  category = 1;
  }

  int everyMinutesNotification = QInputDialog::getInt(this, "Powiadomienia", "co ile minut ma się wyświetlać przypomnienie o zadaniu:");
  taskmanager.setEveryMinutesNotification(name.toStdString(), category, everyMinutesNotification);
  QString powiadomienia = QInputDialog::getText(this, "włączone powiadomienia", "Czy powiadomienia mają być wyłączone wpisz 'tak' lub 'nie' *domyślnie są włączone\n *pisz bez spacji dużych znaków lub znaków specjalnych");
  if(powiadomienia == "nie" ||powiadomienia == " nie"||powiadomienia == "nie "){
    taskmanager.pauseTask(name.toStdString(), category);
  }else{
    taskmanager.unPauseTask(name.toStdString(), category);
  }

  QMessageBox::information(nullptr, "sukces", "Udało się edytować zadanie");
}
void MainWindow::on_DeleteTaskButton_clicked(){

}
void MainWindow::on_FinishTaskButton_clicked(){

}
void MainWindow::on_ChangeTaskImportanceButton_clicked(){

}
void MainWindow::on_PauseTaskButton_clicked(){

}
void MainWindow::on_DeleteFinishedTasksButton_clicked(){

}
void MainWindow::on_ExitButton_clicked(){

}
