#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

#include <QStateMachine>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);

    auto unlockedState = new QState(stateMachine);
    auto lockedState = new QState(stateMachine);

    auto historyState = new QHistoryState(unlockedState);

    auto startupState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto saveState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);

    auto enteredState = new QState(openState);

    unlockedState->assignProperty(ui->pbToggle, "text", "Lock");
    unlockedState->assignProperty(ui->pbOpen, "enabled", "true");
    unlockedState->assignProperty(ui->pbSave, "enabled", "true");
    unlockedState->assignProperty(ui->teText, "enabled", "true");

    lockedState->assignProperty(ui->pbToggle, "text", "Unlock");
    lockedState->assignProperty(ui->pbOpen, "enabled", "false");
    lockedState->assignProperty(ui->pbSave, "enabled", "false");
    lockedState->assignProperty(ui->teText, "enabled", "false");

    startupState->assignProperty(ui->pbOpen, "enabled", "true");
    startupState->assignProperty(ui->pbSave, "enabled", "false");
    startupState->assignProperty(ui->teText, "enabled", "false");
    startupState->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    viewState->assignProperty(ui->pbOpen, "enabled", "true");
    viewState->assignProperty(ui->pbSave, "enabled", "false");
    viewState->assignProperty(ui->teText, "enabled", "true");

    editState->assignProperty(ui->pbOpen, "enabled", "false");
    editState->assignProperty(ui->pbSave, "enabled", "true");
    editState->assignProperty(ui->teText, "enabled", "true");

    errorState->assignProperty(ui->pbOpen, "enabled", "true");
    errorState->assignProperty(ui->pbSave, "enabled", "false");
    errorState->assignProperty(ui->teText, "enabled", "false");
    errorState->assignProperty(ui->teText, "placeholderText", "Error ocured. Open file to start editing...");

    unlockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), lockedState);
    historyState->setDefaultState(unlockedState);
    lockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), historyState);

    startupState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    connect(enteredState, SIGNAL(entered()), this, SLOT(open()));

    openState->addTransition(this, SIGNAL(opened()), viewState);
    openState->addTransition(this, SIGNAL(error()), errorState);
    errorState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);

    viewState->addTransition(ui->pbOpen, SIGNAL(clicked()), openState);
    viewState->addTransition(ui->teText, SIGNAL(textChanged()), editState);

    editState->addTransition(ui->pbSave, SIGNAL(clicked()), saveState);

    saveState->addTransition(this, SIGNAL(saved()), viewState);
    saveState->addTransition(this, SIGNAL(error()), errorState);

    openState->addTransition(ui->pbSave, SIGNAL(clicked()), saveState);
    connect(saveState, SIGNAL(entered()), this, SLOT(save()));

    stateMachine->setInitialState(unlockedState);
    unlockedState->setInitialState(startupState);
    openState->setInitialState(enteredState);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    this->fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/student", tr("Text files(*.txt)") );
    QFile file(this->fileName);

    if(!file.open(QIODevice::ReadWrite)) {
        emit error();
        return;
    }

    QTextStream in(&file);
    QString fileText = in.readAll();
    ui->teText->setText(fileText);
    emit opened();
}

void MainWindow::save()
{
    QFile file(this->fileName);
    if(!file.open(QIODevice::ReadWrite)) {
        emit error();
        return;
    }

    QString fileText = ui->teText->toPlainText();
    QTextStream out(&file);
    out << fileText;
    file.flush();
    emit saved();
}

void MainWindow::log()
{
    qDebug() << "I am inside log()... :> " ;
    emit done();
}

