#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "ChessPiece.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameWidget(new QWidget())
    , chessBoard(new QWidget(gameWidget))
{
    ui->setupUi(this);
    this->setCentralWidget(gameWidget);
    this->setContentsMargins(20, 20, 20, 20);
    QHBoxLayout * gameAndOptions = new QHBoxLayout();
    gameWidget->setLayout(gameAndOptions);
    gameWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    chessBoard->setMinimumSize(this->width()/2, this->height()/2);
    chessBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QGridLayout * chessBoardLayout = new QGridLayout(gameWidget);
    chessBoard->setLayout(chessBoardLayout);

    gameAndOptions->addWidget(chessBoard);



    setupBoard(new QColor("Black"), new QColor("White"));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupBoard(QColor * lightColor, QColor *  darkColor){

    QGridLayout * boardLayout = qobject_cast<QGridLayout*>(chessBoard->layout());

    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            ChessPiece * piece = new ChessPiece(chessBoard);
            QString * styleSheet = new QString("QWidget{background-color: white ;");
            if(row + col % 2 == 0){
                piece->setStyleSheet("background-color: white ;");
                boardLayout->addWidget(new ChessPiece);
            }
            else{
                styleSheet = new QString("background-color: black ;");
                piece->setStyleSheet(*styleSheet);
                boardLayout->addWidget(new ChessPiece);
            }
        }
    }




}
