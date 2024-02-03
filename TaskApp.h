#pragma once

#include <QtWidgets/QWidget>
#include "ui_TaskApp.h"

class TaskApp : public QWidget
{
    Q_OBJECT

public:
    TaskApp(QWidget *parent = nullptr);
    void Run();
    void createNewTask(QString taskName);
    void StyleTask(QFrame* Hframe, QLabel* tasklabel, QPushButton* finishedButton);
    void initStyle();

private:
    Ui::TaskAppClass ui;
    int tasksTODO = 0; // Number of tasks to be done
    int tasksDONE = 0; // Number of tasks already done

public slots:
    void AddNewTask();
    void AddFinishedTaskToLog(QTimer* timer);
    void DeleteTaskFromLog(QFrame* frame);
    void updateTaskLabels();
};
