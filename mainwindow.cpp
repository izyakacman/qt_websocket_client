#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    connect(&web_socket_, &QWebSocket::connected, this, &MainWindow::OnConnected);
    connect(&web_socket_, &QWebSocket::disconnected, this, &MainWindow::OnDisconnected);
    connect(&web_socket_, &QWebSocket::textMessageReceived, this, &MainWindow::OnMessageReceived);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::OnConnected()
{
    ui_->output->append("Connected");
    ui_->bp_connect->setText("Disconnect");
}

void MainWindow::OnDisconnected()
{
    ui_->output->append("Disconnected");
    ui_->bp_connect->setText("Connect");
}

void MainWindow::OnMessageReceived(QString message)
{
    ui_->output->append(message);
}

void MainWindow::on_bp_connect_clicked()
{
    if( web_socket_.state() != QAbstractSocket::ConnectedState )
    {
        web_socket_.open(QUrl(ui_->host->text()));
    }
    else
    {
        web_socket_.close();
    }
}

void MainWindow::on_pb_send_clicked()
{
    web_socket_.sendTextMessage(ui_->le_send_text->text());
}

