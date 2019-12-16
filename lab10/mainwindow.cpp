#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

#include <QStateMachine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TODO: Create state machine
    auto stateMachine = new QStateMachine(this);


    /*
    // TODO: Create states
    auto greenState = new QState(stateMachine);
    auto yellowState = new QState(stateMachine);
    auto redState = new QState(stateMachine);
    auto logState = new QState(stateMachine);
    auto enteredState = new QState(stateMachine);
    // TODO: Set appropriate 'assignProperty'
    greenState->assignProperty(ui->pbToggle, "text", "GREEN");
    yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
    redState->assignProperty(ui->pbToggle, "text", "RED");
    // TODO: Set state transitions including this class events and slots
    greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState); //co ma byc triggerem
    redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState);
    yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);
    logState->addTransition(ui->pbToggle, SIGNAL(clicked()), greenState);
    connect(logState, SIGNAL(entered()), this, SLOT(log())); //wywolanie funkcji log po wejsciu do stanu logState
    stateMachine->setInitialState(greenState);
    stateMachine->start();
    */
    auto unlockedState = new QState(stateMachine);
    auto lockedState = new QState(stateMachine);

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
    lockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), unlockedState);

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
    qDebug() << "I am inside open()... :3 " ;
    // TODO: Show file dialog
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    // TODO: Set text and emit 'opened' if suceeded
    emit opened();
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    qDebug() << "I am inside save()... :3 " ;
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
    emit saved();
}

void MainWindow::log()
{
    qDebug() << "I am inside log()... :> " ;
    emit done();
}

