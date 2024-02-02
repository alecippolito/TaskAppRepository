/********************************************************************************
** Form generated from reading UI file 'TaskApp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKAPP_H
#define UI_TASKAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskAppClass
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *TitleBarFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *TittleText;
    QSpacerItem *horizontalSpacer_2;
    QFrame *ContentFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *AddToDoList;
    QHBoxLayout *horizontalLayout_2;
    QFrame *AddLeft;
    QVBoxLayout *verticalLayout_3;
    QLabel *NewTaskText;
    QLineEdit *NewTaskLineEdit;
    QLabel *NewDateText;
    QFrame *AddRight;
    QVBoxLayout *verticalLayout_5;
    QPushButton *AddNewButton;
    QScrollArea *AllNewTasks;
    QWidget *AllNewTasksContents;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TaskAppClass)
    {
        if (TaskAppClass->objectName().isEmpty())
            TaskAppClass->setObjectName(QString::fromUtf8("TaskAppClass"));
        TaskAppClass->resize(249, 325);
        verticalLayout = new QVBoxLayout(TaskAppClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TitleBarFrame = new QFrame(TaskAppClass);
        TitleBarFrame->setObjectName(QString::fromUtf8("TitleBarFrame"));
        TitleBarFrame->setFrameShape(QFrame::StyledPanel);
        TitleBarFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TitleBarFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        TittleText = new QLabel(TitleBarFrame);
        TittleText->setObjectName(QString::fromUtf8("TittleText"));

        horizontalLayout->addWidget(TittleText);

        horizontalSpacer_2 = new QSpacerItem(91, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(TitleBarFrame);

        ContentFrame = new QFrame(TaskAppClass);
        ContentFrame->setObjectName(QString::fromUtf8("ContentFrame"));
        ContentFrame->setFrameShape(QFrame::StyledPanel);
        ContentFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(ContentFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        AddToDoList = new QFrame(ContentFrame);
        AddToDoList->setObjectName(QString::fromUtf8("AddToDoList"));
        AddToDoList->setFrameShape(QFrame::StyledPanel);
        AddToDoList->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(AddToDoList);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        AddLeft = new QFrame(AddToDoList);
        AddLeft->setObjectName(QString::fromUtf8("AddLeft"));
        AddLeft->setFrameShape(QFrame::StyledPanel);
        AddLeft->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(AddLeft);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        NewTaskText = new QLabel(AddLeft);
        NewTaskText->setObjectName(QString::fromUtf8("NewTaskText"));

        verticalLayout_3->addWidget(NewTaskText);

        NewTaskLineEdit = new QLineEdit(AddLeft);
        NewTaskLineEdit->setObjectName(QString::fromUtf8("NewTaskLineEdit"));

        verticalLayout_3->addWidget(NewTaskLineEdit);

        NewDateText = new QLabel(AddLeft);
        NewDateText->setObjectName(QString::fromUtf8("NewDateText"));

        verticalLayout_3->addWidget(NewDateText);


        horizontalLayout_2->addWidget(AddLeft);

        AddRight = new QFrame(AddToDoList);
        AddRight->setObjectName(QString::fromUtf8("AddRight"));
        AddRight->setFrameShape(QFrame::StyledPanel);
        AddRight->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(AddRight);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        AddNewButton = new QPushButton(AddRight);
        AddNewButton->setObjectName(QString::fromUtf8("AddNewButton"));

        verticalLayout_5->addWidget(AddNewButton);


        horizontalLayout_2->addWidget(AddRight);


        verticalLayout_2->addWidget(AddToDoList);

        AllNewTasks = new QScrollArea(ContentFrame);
        AllNewTasks->setObjectName(QString::fromUtf8("AllNewTasks"));
        AllNewTasks->setWidgetResizable(true);
        AllNewTasksContents = new QWidget();
        AllNewTasksContents->setObjectName(QString::fromUtf8("AllNewTasksContents"));
        AllNewTasksContents->setGeometry(QRect(0, 0, 209, 134));
        verticalLayout_4 = new QVBoxLayout(AllNewTasksContents);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 194, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        AllNewTasks->setWidget(AllNewTasksContents);

        verticalLayout_2->addWidget(AllNewTasks);


        verticalLayout->addWidget(ContentFrame);


        retranslateUi(TaskAppClass);

        QMetaObject::connectSlotsByName(TaskAppClass);
    } // setupUi

    void retranslateUi(QWidget *TaskAppClass)
    {
        TaskAppClass->setWindowTitle(QCoreApplication::translate("TaskAppClass", "TaskApp", nullptr));
        TittleText->setText(QCoreApplication::translate("TaskAppClass", "AJ's To-Do List", nullptr));
        NewTaskText->setText(QCoreApplication::translate("TaskAppClass", "Add New Task", nullptr));
        NewTaskLineEdit->setPlaceholderText(QCoreApplication::translate("TaskAppClass", "Today, I need to...", nullptr));
        NewDateText->setText(QCoreApplication::translate("TaskAppClass", "Date Created", nullptr));
        AddNewButton->setText(QCoreApplication::translate("TaskAppClass", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskAppClass: public Ui_TaskAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKAPP_H
