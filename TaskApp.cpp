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
    Run();
}

void TaskApp::Run() {
    connect(ui.AddNewButton, SIGNAL(clicked()), this, SLOT(AddNewTask()));
    // add functionality for a log
}


void TaskApp::initStyle() {
    ui.NewDateText->setText(date);
    QFile style("style_generic.css");
    bool ok = style.open(QFile::ReadOnly);
    QString s = QString::fromLatin1(style.readAll());
    setStyleSheet(s);
}

void TaskApp::AddNewTask() {
    QString taskName = ui.NewTaskLineEdit->text();
    createNewTask(taskName);
    // add in timer
}

void TaskApp::createNewTask(QString taskName) {
    qDebug() << "Making new task:";
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
    QLabel* stopwatchLabel = new QLabel("00:00:00");
    QTimer* stopwatchTimer = new QTimer(this);

    connect(stopwatchTimer, &QTimer::timeout, this, [=]() {QTime time = QTime::fromString(stopwatchLabel->text()).addSecs(1); stopwatchLabel->setText(time.toString("hh:mm:ss"));});
  
    timeDetails->addWidget(stopwatchLabel);
    timeDetails->addWidget(dateLabel);    
    newTask->insertWidget(2, Tframe);
    stopwatchTimer->start(1000);

    // Make delete button
    QPushButton* deleteButton = new QPushButton("Task Finished");
    deleteButton->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(Hframe)));
    deleteButton->resize(100,100);

    // Add to frames
    newTask->insertWidget(0, tasklabel);
    newTask->insertWidget(1, Tframe);
    newTask->insertWidget(2, deleteButton);

    // Insert the task into the layout
    vMainLayout->insertWidget(vMainLayout->count() - 1, Hframe);

    // Connect the delete button    
    connect(deleteButton, &QPushButton::clicked, this, [=]() { DeleteTask(stopwatchTimer);});

#   // Style new Buttons
    StyleTask(Hframe, tasklabel, deleteButton);

}

void TaskApp::StyleTask(QFrame* Hframe, QLabel* tasklabel, QPushButton* deleteButton) 
{
    QVector<QString> colors = { "rgba(66, 165, 245,1.0)", "rgba(41, 182, 246,1.0)", "rgba(38, 198, 218,1.0)", "rgba(38, 166, 154,1.0)", "rgba(102, 187, 106,1.0)", "rgba(156, 204, 101,1.0)", "rgba(212, 225, 87,1.0)", "rgba(255, 238, 88,1.0)", "rgba(255, 202, 40,1.0)", "rgba(255, 167, 38,1.0)" };
    int randomVal = (((rand() % 50) % 100) % (colors.size() - 1));

    Hframe->setObjectName("NewTask");
    Hframe->setStyleSheet("#NewTask { border-radius: 10px; border: 1px solid black;  background-color: " + colors[randomVal] + "; }");

    tasklabel->setObjectName("TaskName");
    tasklabel->setStyleSheet("#TaskName { font: bold 11pt black 'Verdana'; }");

    deleteButton->setObjectName("DeleteBtn");
    deleteButton->setStyleSheet("#DeleteBtn { color: white; background-color: #ff2264; border-color: #b91043; }  #DeleteBtn:hover{ background-color: #b91043; border-color: #ff2264; }");

}

void TaskApp::DeleteTask(QTimer* timer) {
    QPushButton* fromButton = (QPushButton*)sender();
    QVariant var = fromButton->property("CurrentTask");
    QFrame* taskHBox = qvariant_cast<QFrame*>(var);
    taskHBox->deleteLater();
    timer->stop();
    delete taskHBox;
}