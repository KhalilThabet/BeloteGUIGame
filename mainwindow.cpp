#include <QtWidgets>
#include "mainwindow.h"


MainWindow::MainWindow() {
    resize( 800, 600 );
    setWindowTitle( tr("The window title goes here") );

    createActions();
    createMenus();
}


void MainWindow::createActions() {

    //
    openAct = new QAction( tr("Open"), this );
    openAct->setShortcuts( QKeySequence::Open );
    connect( openAct, &QAction::triggered,
             this, &MainWindow::openActSlot );
    printAct = new QAction( tr("Print"), this );
    printAct->setShortcuts( QKeySequence::Print );
    connect( printAct, &QAction::triggered,
             this, &MainWindow::printActSlot );
    quitAct = new QAction( tr("Quit"), this );
    quitAct->setShortcuts( QKeySequence::Quit );
    connect( quitAct, &QAction::triggered,
             this, &MainWindow::quitActSlot );

    //
    aboutAct = new QAction( tr("About"), this );
    connect( aboutAct, &QAction::triggered,
             this, &MainWindow::aboutActSlot );
}


void MainWindow::createMenus() {

    menuBar = new QMenuBar( this );

    menuBar->setNativeMenuBar( false );
    menuBar->setMinimumWidth( 8000 );

    // main menu item #1
    fileMenu = menuBar->addMenu( tr("&File") );
    fileMenu->addAction( openAct );
    fileMenu->addAction( printAct );
    fileMenu->addSeparator();
    fileMenu->addAction( quitAct );

    // main menu item #2
    helpMenu = menuBar->addMenu( tr("&Help") );
    helpMenu->addAction( aboutAct );

}


// main menu item #1
void MainWindow::openActSlot() {
    QMessageBox::about( this, tr("Open"), tr("Mii we Open gaa-aawang") );
}


void MainWindow::printActSlot() {
    QMessageBox::about( this, tr("Print"), tr("Mii we Print gaa-aawang") );
}


void MainWindow::quitActSlot() {
    QMessageBox::StandardButton wantsToQuit;
    wantsToQuit = QMessageBox::question( this, tr("Confirmation"),
                                         tr("Do you really want to quit?"),
                                         QMessageBox::Yes|QMessageBox::No );
    if ( wantsToQuit == QMessageBox::Yes )
    {
        QApplication::quit();
    }
}


// main menu item #2
void MainWindow::aboutActSlot() {
    QMessageBox::about( this, tr("About"), tr("Mii we About gaa-aawang") );
}
