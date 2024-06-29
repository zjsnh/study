#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_newGameButton_clicked();
    void on_undoButton_clicked();
    void on_playerVsPlayerButton_clicked();
    void on_playerVsComputerButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QVector<int>> board;//棋盘
    QVector<QPair<int, int>> moveHistory;//悔棋 记录下棋每一步的位置

    QLabel* playerViews;  //旁边标签提示player
    QVector<QPair<int,QString>> playerView; //记录该谁下棋
    int currentPlayer;
    bool isPlayerVsComputer;  //判断是不是complter

    void initGame();  //重绘
    bool checkWin(int x, int y);
    void computerMove();
    bool checkDirection(int x, int y, int dx, int dy);  //获取鼠标位置，查看下棋的位置
};

#endif // MAINWINDOW_H
