#include "mainWindow.h"
#include "ChessPiece.h"
#include "board.h"
#include "ui_mainWindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainWidget(new QWidget(this))
    , chessBoard(new Board(this))
{
    ui->setupUi(this);
    QHBoxLayout * mainLayout = new QHBoxLayout();
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(chessBoard, Qt::AlignHCenter);
    chessBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCentralWidget(mainWidget);
}

void MainWindow::resizeEvent(QResizeEvent *){
    QSize size = this->size();
    int side = size.height();
    mainWidget->resize(side, side);
    qDebug() << this->x() << this->y() << this->width() << this->height();
    chessBoard->update();
    qDebug() << "board dimensions: " <<  chessBoard->x() << chessBoard->y() << chessBoard->width() << chessBoard->height();
}

MainWindow::~MainWindow()
{
    delete ui;
}

