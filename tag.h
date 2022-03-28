#ifndef TAG_H
#define TAG_H

#include"game.h"
#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class tag; }
QT_END_NAMESPACE

class tag : public QMainWindow
{
    Q_OBJECT

public:
    tag(QWidget *parent = nullptr);
    ~tag();
private slots:
    void showTable();

    void on_twTag_cellClicked(int row, int column);

    void on_pbNewGame_clicked();

    void on_pbRestart_clicked();

    void updateTime();

    void createTimer();

    void stopTimer();

private:
    Ui::tag *ui;
    QTimer *tmr;
    int times, timem;
};
#endif // TAG_H
