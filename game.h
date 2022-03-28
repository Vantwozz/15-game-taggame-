#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidgetItem>

class game
{
public:
    game();
    void start_game();
    void restart_game();
    int getElement(int i, int j)const;
    int getVoidi()const{
        return voidCell->row();
    }
    int getVoidj()const{
        return voidCell->column();
    }
    void setVoid(const QTableWidgetItem *p);
    void setElement(int i, int j, int data);
    void reCalc(int i, int j);
    bool isFinished();
    int getScore()const;
    void addScore();
    bool isPossible()const;
private:
    const QTableWidgetItem *voidCell;
    int table [4][4];
    int cpytable [4][4];
    int score;
};

#endif // GAME_H
