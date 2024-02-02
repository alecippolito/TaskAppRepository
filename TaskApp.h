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
    void StyleTask(QFrame* Hframe, QLabel* tasklabel, QPushButton* deleteButton);
    void initStyle();

private:
    Ui::TaskAppClass ui;

public slots:
    void AddNewTask();
    void DeleteTask(QTimer* timer);
};
