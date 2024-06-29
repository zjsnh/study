#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , board(15, QVector<int>(15, 0))
    , playerViews(new QLabel(this))
    , playerView(0)
    , currentPlayer(1)
    , isPlayerVsComputer(false)
{
    ui->setupUi(this);

    this->setWindowTitle("五子棋");

    // 创建按钮
    QPushButton *newGameButton = new QPushButton("新游戏", this);
    newGameButton->setGeometry(600, 20, 100, 30); // 设置按钮位置和大小
    connect(newGameButton, &QPushButton::clicked, this, &MainWindow::on_newGameButton_clicked);

    QPushButton *undoButton = new QPushButton("悔步", this);
    undoButton->setGeometry(600, 50, 100, 30); // 设置按钮位置和大小
    connect(undoButton, &QPushButton::clicked, this, &MainWindow::on_undoButton_clicked);

    QPushButton *playerVsPlayerButton = new QPushButton("玩家对战", this);
    playerVsPlayerButton->setGeometry(600, 80, 150, 30); // 设置按钮位置和大小
    connect(playerVsPlayerButton, &QPushButton::clicked, this, &MainWindow::on_playerVsPlayerButton_clicked);

    QPushButton *playerVsComputerButton = new QPushButton("人机对战", this);
    playerVsComputerButton->setGeometry(600, 110, 170, 30); // 设置按钮位置和大小
    connect(playerVsComputerButton, &QPushButton::clicked, this, &MainWindow::on_playerVsComputerButton_clicked);

    playerView.push_back(QPair<int,QString>(0,"玩家"));
    playerView.push_back(QPair<int,QString>(1,"电脑"));
    playerView.push_back(QPair<int,QString>(2,"玩家1->黑棋"));
    playerView.push_back(QPair<int,QString>(3,"玩家2->白棋"));

    playerViews->setText(playerView[2].second);
    playerViews->setGeometry(600,200,170,30);

    playerViews->setAlignment(Qt::AlignCenter);

    // 设置文本颜色为红色
    playerViews->setStyleSheet("QLabel { color : red; }");

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{

    //初始化棋盘
    board = QVector<QVector<int>>(15, QVector<int>(15, 0));
    moveHistory.clear();
    currentPlayer = 1;
    if(isPlayerVsComputer)
    {
        playerViews->setText(playerView[0].second);
    }

    update();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int w = this->width();
    int h = this->height();
    int cellSize = qMin(w, h) / 15;

    //判断该谁下棋
    QString player = currentPlayer == 1 ? playerView[2].second : playerView[3].second;
    if (isPlayerVsComputer) {
        player = currentPlayer == 1 ? playerView[0].second : playerView[1].second;
    }

    playerViews->setText(player);

    // Draw board
    for (int i = 0; i < 15; ++i) {
        painter.drawLine(cellSize * i, 0, cellSize * i, cellSize * 14);
        painter.drawLine(0, cellSize * i, cellSize * 14, cellSize * i);
    }

    // Draw pieces
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (board[i][j] == 1) {
                painter.setBrush(Qt::black);
                painter.drawEllipse(cellSize * i - cellSize / 2, cellSize * j - cellSize / 2, cellSize, cellSize);
            } else if (board[i][j] == 2) {
                painter.setBrush(Qt::white);
                painter.drawEllipse(cellSize * i - cellSize / 2, cellSize * j - cellSize / 2, cellSize, cellSize);
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (isPlayerVsComputer && currentPlayer == 2) {
        return;
    }

    int w = this->width();
    int h = this->height();
    int cellSize = qMin(w, h) / 15;
    int x = event->x() / cellSize;
    int y = event->y() / cellSize;

    // 计算最接近的网格点
    int nearestX = round((double)event->x() / cellSize);
    int nearestY = round((double)event->y() / cellSize);

    if (nearestX < 0 || nearestX >= 15 || nearestY < 0 || nearestY >= 15 || board[nearestX][nearestY] != 0) {
        return;
    }

    board[nearestX][nearestY] = currentPlayer;
    moveHistory.append(qMakePair(nearestX, nearestY));

    if (checkWin(nearestX, nearestY)) {
        QString winner = currentPlayer == 1 ? playerView[2].second : playerView[3].second;
        if(isPlayerVsComputer)
        {
            winner = playerView[0].second;//电脑随机下棋，肉眼无法观察到时间 不用显示电脑
        }

        QMessageBox::information(this, "Game Over", winner + " wins!");
        initGame();
        return;
    }

    currentPlayer = 3 - currentPlayer;

    if (isPlayerVsComputer && currentPlayer == 2) {
        playerViews->setText(playerView[1].second);
        computerMove();
    }

    update();
}

bool MainWindow::checkWin(int x, int y)
{
    // Check all 8 directions
    const int directions[8][2] = {
        {1, 0}, {0, 1}, {1, 1}, {1, -1},
        {-1, 0}, {0, -1}, {-1, -1}, {-1, 1}
    };

    for (const auto& direction : directions) {
        if (checkDirection(x, y, direction[0], direction[1])) {
            return true;
        }
    }
    return false;
}

bool MainWindow::checkDirection(int x, int y, int dx, int dy)
{
    int count = 1;

    // Check in the positive direction
    for (int i = 1; i < 5; ++i) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx < 0 || nx >= 15 || ny < 0 || ny >= 15 || board[nx][ny] != currentPlayer) {
            break;
        }
        count++;
    }

    // Check in the negative direction
    for (int i = 1; i < 5; ++i) {
        int nx = x - i * dx;
        int ny = y - i * dy;
        if (nx < 0 || nx >= 15 || ny < 0 || ny >= 15 || board[nx][ny] != currentPlayer) {
            break;
        }
        count++;
    }

    return count == 5;
}

void MainWindow::computerMove()
{

    QVector<QPair<int, int>> emptyCells;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (board[i][j] == 0) {
                emptyCells.append(qMakePair(i, j));
            }
        }
    }

    if (emptyCells.isEmpty()) {
        return;
    }

    int index = QRandomGenerator::global()->bounded(emptyCells.size());
    QPair<int, int> move = emptyCells[index];
    board[move.first][move.second] = 2;
    moveHistory.append(move);

    if (checkWin(move.first, move.second)) {
        QMessageBox::information(this, "Game Over",playerView[1].second + "wins");
        initGame();
        return;
    }

    currentPlayer = 1;
    update();
}

void MainWindow::on_newGameButton_clicked()
{
    initGame();
}

void MainWindow::on_undoButton_clicked()
{
    if (moveHistory.isEmpty()) {
        return;
    }

    QPair<int, int> lastMove = moveHistory.takeLast();
    board[lastMove.first][lastMove.second] = 0;
    currentPlayer = 3 - currentPlayer;

    if (isPlayerVsComputer && currentPlayer == 2 && !moveHistory.isEmpty()) {
        lastMove = moveHistory.takeLast();
        board[lastMove.first][lastMove.second] = 0;
        currentPlayer = 1;
    }

    update();
}

void MainWindow::on_playerVsPlayerButton_clicked()
{
    isPlayerVsComputer = false;
    initGame();
}

void MainWindow::on_playerVsComputerButton_clicked()
{
    isPlayerVsComputer = true;
    initGame();
    if (isPlayerVsComputer && currentPlayer == 2) {
        computerMove();
    }
}
