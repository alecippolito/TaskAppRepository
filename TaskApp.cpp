#include "TaskApp.h"
#include <QDate>
#include <QTimer>
#include <QLCDNumber>
#include <QFile>
#include <qDebug>

using namespace std;


QString date = QDate::currentDate().toString();

TaskApp::TaskApp(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
    initStyle();
    updateTaskLabels();
    Run();
}

void TaskApp::Run() {
    connect(ui.AddNewButton, &QPushButton::clicked, this, [=]() { AddNewTask();});
}

void TaskApp::AddNewTask() {
    // get task name
    QString taskName = ui.NewTaskLineEdit->text();

    //  create the task
    createNewTask(taskName);

    // update labels
    tasksTODO++;
    updateTaskLabels();
}

void TaskApp::createNewTask(QString taskName) {
    // Get the layout
    QVBoxLayout* vMainLayout = qobject_cast<QVBoxLayout*>(ui.AllNewTasksContents->layout());

    // Make frame for task
    QFrame* Hframe = new QFrame();
    Hframe->setFrameStyle(QFrame::StyledPanel);

    // Make task box
    QHBoxLayout* newTask = new QHBoxLayout(Hframe);
    Hframe->setLayout(newTask);
 
    // Make task
    QLabel* tasklabel = new QLabel(taskName);

    // Mak time details - stopwatch/date
    QFrame* Tframe = new QFrame();
    QVBoxLayout* timeDetails = new QVBoxLayout(Tframe);
    Tframe->setLayout(timeDetails);
    QLabel* dateLabel = new QLabel(date);
    QDateTime currentTime = QDateTime::currentDateTime();
    QLabel* timeLabel = new QLabel(currentTime.time().toString("hh:mm:ss AP"));
    QLabel* stopwatchLabel = new QLabel("00:00:00");
    QTimer* stopwatchTimer = new QTimer(this);

    connect(stopwatchTimer, &QTimer::timeout, this, [=]() {QTime time = QTime::fromString(stopwatchLabel->text()).addSecs(1); stopwatchLabel->setText(time.toString("hh:mm:ss"));});
  
    timeDetails->addWidget(stopwatchLabel);
    timeDetails->addWidget(timeLabel);
    timeDetails->addWidget(dateLabel);    
    newTask->insertWidget(2, Tframe);
    stopwatchTimer->start(1000);

    // Make Finishd button
    QPushButton* finishedButton = new QPushButton("Task Finished");
    finishedButton->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(Hframe)));
    finishedButton->resize(100,100);

    // Add to frames
    newTask->insertWidget(0, tasklabel);
    newTask->insertWidget(1, Tframe);
    newTask->insertWidget(2, finishedButton);

    // Insert the task into the layout
    vMainLayout->insertWidget(vMainLayout->count() - 1, Hframe);

    // Connect the finish button    
    connect(finishedButton, &QPushButton::clicked, this, [=]() { AddFinishedTaskToLog(stopwatchTimer);});

#   // Style new Buttons
    StyleTask(Hframe, tasklabel, finishedButton);

}

void TaskApp::AddFinishedTaskToLog(QTimer* timer)
{
    tasksTODO--;
    tasksDONE++;
    updateTaskLabels();

    // Stop timer
    timer->stop(); 

    // layout
    QVBoxLayout* vMainLayout = qobject_cast<QVBoxLayout*>(ui.AllFinishedTasksContents->layout());

    // button
    QPushButton* fromButton = (QPushButton*)sender();
    QVariant var = fromButton->property("CurrentTask");

    // frame
    QFrame* taskHBox = qvariant_cast<QFrame*>(var);
    qobject_cast<QVBoxLayout*>(ui.AllNewTasksContents->layout())->removeWidget(taskHBox);
    fromButton->setText("Delete"); // change name

    // add to ui
    vMainLayout->insertWidget(vMainLayout->count() - 1, taskHBox);

    // disconect and connect to delete
    disconnect(fromButton, &QPushButton::clicked, this, nullptr);
    connect(fromButton, &QPushButton::clicked, this, [=]() { DeleteTaskFromLog(taskHBox); });

    // do styling
    fromButton->setStyleSheet("#DeleteBtn { color: white; background-color: #ff0000; border-color: #b91043; }  #DeleteBtn:hover{ background-color: #b91043; border-color: #ff0000; }");
    taskHBox->setStyleSheet("background-color: #90ee90;");
    
}

void TaskApp::DeleteTaskFromLog(QFrame* frame)
{
    tasksDONE--;
    updateTaskLabels();
    // get button
    QPushButton* fromButton = (QPushButton*)sender();
    QVariant var = fromButton->property("CurrentTask");
    // get frame
    QFrame* taskHBox = qvariant_cast<QFrame*>(var);

    // delete frame
    taskHBox->deleteLater();
    delete taskHBox;
}

void TaskApp::initStyle() {
    ui.NewDateText->setText(date);
    QFile style("style_generic.css");
    bool ok = style.open(QFile::ReadOnly);
    QString s = QString::fromLatin1(style.readAll());
    setStyleSheet(s);
}

void TaskApp::StyleTask(QFrame* horizontalFrame, QLabel* task, QPushButton* button)
{
    QVector<QString> colors = { "rgba(66, 165, 245,1.0)", "rgba(41, 182, 246,1.0)", "rgba(38, 198, 218,1.0)", "rgba(38, 166, 154,1.0)", "rgba(102, 187, 106,1.0)", "rgba(156, 204, 101,1.0)", "rgba(212, 225, 87,1.0)", "rgba(255, 238, 88,1.0)", "rgba(255, 202, 40,1.0)", "rgba(255, 167, 38,1.0)" };
    int randomVal = (((rand() % 50) % 100) % (colors.size() - 1));

    horizontalFrame->setObjectName("NewTask");
    horizontalFrame->setStyleSheet("#NewTask { border-radius: 10px; border: 1px solid black;  background-color: " + colors[randomVal] + "; }");

    task->setObjectName("TaskName");
    task->setStyleSheet("#TaskName { font: bold 11pt black 'Verdana'; }");

    button->setObjectName("DeleteBtn");
    button->setStyleSheet("#DeleteBtn { color: white; background-color: #ff2264; border-color: #b91043; }  #DeleteBtn:hover{ background-color: #b91043; border-color: #ff2264; }");
}

void TaskApp::updateTaskLabels() {
    // update counter labels
    ui.NumberTaskLabel->setText("Task's To-Do: " + QString::number(tasksTODO));
    ui.NumberDoneLabel->setText("Task's Done: " + QString::number(tasksDONE));
}

