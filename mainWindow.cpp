#include "mainWindow.h"
#include "ChessPiece.h"
#include "board.h"
#include "ui_mainWindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainWidget(new QWidget())
    , chessBoard(new Board(this))
{
    ui->setupUi(this);
    QHBoxLayout * mainLayout = new QHBoxLayout();
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(chessBoard);
    chessBoard->setParent(this);
    chessBoard->setMinimumSize(1000, 1000);
    this->setCentralWidget(mainWidget);



}

void MainWindow::resizeEvent(QResizeEvent *){
    mainWidget->setGeometry(this->geometry());
    //this->centralWidget()->setGeometry(0, 0, 20, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

