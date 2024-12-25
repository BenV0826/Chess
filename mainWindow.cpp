#include "mainWindow.h"
#include "ChessPiece.h"
#include "board.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainWidget(new QWidget())
    , chessBoard(new Board())
{
    ui->setupUi(this);
    // Create a layout for the central widget
    QHBoxLayout *mainLayout = new QHBoxLayout();
    //mainLayout->setAlignment(Qt::AlignRight); // Align chessboard to center

    // Set the layout for the central widget
    mainWidget->setLayout(mainLayout);

    // Add the chessboard widget to the layout
    chessBoard->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Set the central widget for the main window
    this->setCentralWidget(mainWidget);

    // Adjust initial size of the window
    mainLayout->addWidget(chessBoard, 2, Qt::AlignCenter);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    qDebug() << "Window dimensions: " << this->size();
    qDebug() << "Chessboard dimensions: " << chessBoard->size();
}

MainWindow::~MainWindow()
{
    delete ui;
}
