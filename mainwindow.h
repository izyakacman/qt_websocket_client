#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebSockets/QWebSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void OnConnected();
    void OnDisconnected();
    void OnMessageReceived(QString message);
    void on_bp_connect_clicked();
    void on_pb_send_clicked();

private:
    Ui::MainWindow* ui_;
    QWebSocket web_socket_;
};
#endif // MAINWINDOW_H
