/** @mainpage PIC 10C hw10
@author Justin Wang
@id 604219879
@date 6/2/15

Naruto Tower Defense Game

The MainWindow sets up the user interface menu and contains function definitions for buttons, when clicked.
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Game.h"

Game* game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}



//void MainWindow::easy_game_begin() {
//    //board = new GameBoard(this,5,100);
//    game = new Game();
//    this->setCentralWidget(game);
//}





MainWindow::~MainWindow()
{
    delete ui;
}

// instructions
//void MainWindow::on_pushButton_3_clicked()
//{
//    MyPopUpWindow* popUp= new MyPopUpWindow();
//    popUp->show();
//}

void MainWindow::on_pushButton_clicked()
{
    //game = new Game();
    //game->show();
    //board = new GameBoard(this,5,100);
    game = new Game();
    game->show();
    this->setCentralWidget(game);

}
