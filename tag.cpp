#include "tag.h"
#include "ui_tag.h"
#include "game.h"
#include<algorithm>
#include<iostream>
#include<math.h>
#include<QTableWidgetItem>
#include<QMessageBox>
#include<QTimer>
game Game;
tag::tag(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tag)
{
    ui->setupUi(this);
    for (auto i = 0; i < 4; i++) {
        ui -> twTag -> setColumnWidth(i, 128);
        ui -> twTag -> setRowHeight(i, 128);
    }
    createTimer();
    showTable();
}

tag::~tag()
{
    delete ui;
}
void tag::showTable()
{
    ui->lScore->setText(QString::number(Game.getScore()));
    for (auto i = 0; i < 4; i++){
        for (auto j = 0; j < 4; j++){
            if(Game.getElement(i,j)!=0){
                ui->twTag->setItem(i, j, new QTableWidgetItem(QString::number(Game.getElement(i,j))));
            }else{
                ui->twTag->setItem(i, j, new QTableWidgetItem());
                Game.setVoid(ui->twTag->item(i,j));
            }
        }
    }
}

void tag::createTimer(){
    ui->lTimer->setText("00:00");
    tmr = new QTimer();
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start(1000);
    times= 0 ;
    timem = 0;
}

void tag::stopTimer(){
    tmr->stop();
    times = 0;
    timem = 0;
}

void tag::updateTime()
{
    times++;
    if (times == 60){
        timem +=1;
        times = 0;
    }
    if(timem<10&&times<10){
        ui->lTimer->setText("0"+ QString::number(timem)+":0"+QString::number(times));
    }else if(timem < 10 && times>=10){
        ui->lTimer->setText("0"+ QString::number(timem)+":"+QString::number(times));
    }else if(timem>=10 && times<10){
        ui->lTimer->setText(QString::number(timem)+":0"+QString::number(times));
    }else{
        ui->lTimer->setText(QString::number(timem)+":"+QString::number(times));
    }
}

void tag::on_twTag_cellClicked(int i, int j)
{
    if((std::abs(i - Game.getVoidi()) == 1 && j-Game.getVoidj() ==0)||(std::abs(j-Game.getVoidj())==1 && i-Game.getVoidi() == 0)){
        Game.reCalc(i,j);
        Game.setVoid(ui->twTag->item(i,j));
        Game.addScore();
        showTable();
        if(Game.isFinished()){
            stopTimer();
            if (QMessageBox::question(this, "Игра закончена!", "Победа! Желаете сыграть снова?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
                QApplication::quit();
            else {
                Game.start_game();
                createTimer();
                showTable();
            }
        }
    }
}

void tag::on_pbNewGame_clicked()
{
    stopTimer();
    Game.start_game();
    createTimer();
    showTable();
}


void tag::on_pbRestart_clicked()
{
    stopTimer();
    Game.restart_game();
    createTimer();
    showTable();
}
