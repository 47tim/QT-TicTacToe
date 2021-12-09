#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QProcess>

void setupGame();
void turn();
void checkWin();
void p1Win();
void p2Win();
void tie();

// If I were to do this again, have one function which each
// button press calls and passes the necessary variables

int bstatus[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int playerTurn = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset(){  // member fnct which resets all tiles
    ui->b1->setText("");
    ui->b2->setText("");
    ui->b3->setText("");
    ui->b4->setText("");
    ui->b5->setText("");
    ui->b6->setText("");
    ui->b7->setText("");
    ui->b8->setText("");
    ui->toolButton_9->setText("");
}

void checkWin(){

    if (bstatus[0] == 1 && bstatus[1] == 1 && bstatus[2] == 1){ // checking p1 win
        p1Win();
    }
    else if (bstatus[3] == 1 && bstatus[4] == 1 && bstatus[5] == 1){
        p1Win();
    }
    else if (bstatus[6] == 1 && bstatus[7] == 1 && bstatus[8] == 1){
        p1Win();
    }
    else if (bstatus[0] == 1 && bstatus[3] == 1 && bstatus[6] == 1){
        p1Win();
    }
    else if (bstatus[1] == 1 && bstatus[4] == 1 && bstatus[7] == 1){
        p1Win();
    }
    else if (bstatus[2] == 1 && bstatus[5] == 1 && bstatus[8] == 1){
        p1Win();
    }
    else if (bstatus[0] == 1 && bstatus[4] == 1 && bstatus[8] == 1){
        p1Win();
    }
    else if (bstatus[6] == 1 && bstatus[4] == 1 && bstatus[2] == 1){
        p1Win();
    }

    if (bstatus[0]== 2 && bstatus[1]== 2 && bstatus[2]== 2){  // checking p2 win
        p2Win();
    }
    else if (bstatus[3]== 2 && bstatus[4]== 2 && bstatus[5]== 2){
        p2Win();
    }
    else if (bstatus[6]== 2 && bstatus[7]== 2 && bstatus[8]== 2){
        p2Win();
    }
    else if (bstatus[0]== 2 && bstatus[3]== 2 && bstatus[6]== 2){
        p2Win();
    }
    else if (bstatus[1]== 2 && bstatus[4]== 2 && bstatus[7]== 2){
        p2Win();
    }
    else if (bstatus[2]== 2 && bstatus[5]== 2 && bstatus[8]== 2){
        p2Win();
    }
    else if (bstatus[0]== 2 && bstatus[4]== 2 && bstatus[8]== 2){
        p2Win();
    }
    else if (bstatus[6]== 2 && bstatus[4]== 2 && bstatus[2]== 2){
        p2Win();
    }
    else if (bstatus[0] != 0 && bstatus[1] != 0 && bstatus[2] != 0 &&
             bstatus[3] != 0 && bstatus[4] != 0 && bstatus[5] != 0 &&
             bstatus[6] != 0 && bstatus[7] != 0 && bstatus[8] != 0){
        tie();
    }


}

void p1Win(){

    for (int i = 0; i < 9; i++){
        bstatus[i] = 0;
    }
    playerTurn = 1;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("Player One (X's) Wins!!");
    msgBox.exec();

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


}

void p2Win(){

    for (int i = 0; i < 9; i++){
        bstatus[i] = 0;
    }
    playerTurn = 1;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("Player Two (O's) Wins!!");
    msgBox.exec();

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void tie(){

    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText("Tie Game");
    msgBox.exec();

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


void MainWindow::on_b1_clicked()
{
    if (playerTurn == 1 && bstatus[0] == 0){         // player 1, open space
        bstatus[0] = 1;
        ui->b1->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[0] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[0] == 0){    // player 2, open space
        bstatus[0] = 2;
        ui->b1->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[0] != 0){    // player 2, no open space
    }

    checkWin();
}



void MainWindow::on_b2_clicked()
{
    if (playerTurn == 1 && bstatus[1] == 0){         // player 1, open space
        bstatus[1] = 1;
        ui->b2->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[1] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[1] == 0){    // player 2, open space
        bstatus[1] = 2;
        ui->b2->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[1] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_b3_clicked()
{
    if (playerTurn == 1 && bstatus[2] == 0){         // player 1, open space
        bstatus[2] = 1;
        ui->b3->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[2] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[2] == 0){    // player 2, open space
        bstatus[2] = 2;
        ui->b3->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[2] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_b4_clicked()
{
    if (playerTurn == 1 && bstatus[3] == 0){         // player 1, open space
        bstatus[3] = 1;
        ui->b4->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[3] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[3] == 0){    // player 2, open space
        bstatus[3] = 2;
        ui->b4->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[3] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_b5_clicked()
{
    if (playerTurn == 1 && bstatus[4] == 0){         // player 1, open space
        bstatus[4] = 1;
        ui->b5->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[4] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[4] == 0){    // player 2, open space
        bstatus[4] = 2;
        ui->b5->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[4] != 0){    // player 2, no open space
    }

    checkWin();
}




void MainWindow::on_b6_clicked()
{
    if (playerTurn == 1 && bstatus[5] == 0){         // player 1, open space
        bstatus[5] = 1;
        ui->b6->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[5] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[5] == 0){    // player 2, open space
        bstatus[5] = 2;
        ui->b6->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[5] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_b7_clicked()
{
    if (playerTurn == 1 && bstatus[6] == 0){         // player 1, open space
        bstatus[6] = 1;
        ui->b7->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[6] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[6] == 0){    // player 2, open space
        bstatus[6] = 2;
        ui->b7->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[6] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_b8_clicked()
{
    if (playerTurn == 1 && bstatus[7] == 0){         // player 1, open space
        bstatus[7] = 1;
        ui->b8->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[7] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[7] == 0){    // player 2, open space
        bstatus[7] = 2;
        ui->b8->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[7] != 0){    // player 2, no open space
    }

    checkWin();
}


void MainWindow::on_toolButton_9_clicked()
{
    if (playerTurn == 1 && bstatus[8] == 0){         // player 1, open space
        bstatus[8] = 1;
        ui->toolButton_9->setText("X");
        playerTurn = 2;
    }
    else if (playerTurn == 1 && bstatus[8] != 0){    // player 1, no open space
    }
    else if (playerTurn == 2 && bstatus[8] == 0){    // player 2, open space
        bstatus[8] = 2;
        ui->toolButton_9->setText("O");
        playerTurn = 1;
    }
    else if (playerTurn == 2 && bstatus[8] != 0){    // player 2, no open space
    }

    checkWin();
}

