#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<stack.h>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInsert_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonRemove_clicked();

    void on_pushButtonSet_clicked();

private:
    Ui::MainWindow *ui;
    Stack<int> *IntStack=0;
    Stack<QString> *StringStack=0;

};
#endif // MAINWINDOW_H
