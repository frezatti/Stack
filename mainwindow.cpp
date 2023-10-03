#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete IntStack;
    delete StringStack;
}

void MainWindow::on_pushButtonSet_clicked()
{
    try {
        bool ok;
        int size=ui->lineEditSize->text().toInt(&ok);
        if(ok){
            IntStack=new Stack<int>(size);
            StringStack=new Stack<QString>(size);
        }

    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }

}


void MainWindow::on_pushButtonInsert_clicked()
{
    try {
        if(!IntStack) throw QString("Must input a size");
        if(!StringStack)throw QString("Must input a size");
        bool ok;
        int Number=ui->lineEditValue->text().toInt(&ok);

        if(ok){
            IntStack->push(Number);
            ui->textEditExit->setText(QString::number(IntStack->top()));
        }
        else{
            StringStack->push(ui->lineEditValue->text());
            ui->textEditExit->setText(StringStack->top());
        }
        ui->lineEditValue->setFocus();
        ui->lineEditValue->clear();
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }


}


void MainWindow::on_pushButtonClear_clicked()
{
    try {
        if(!IntStack) throw QString("Must input a size");
        if(!StringStack)throw QString("Must input a size");
        QString exit="";
        int size=IntStack->size();
        for(int i=0;i<size;i++){
            exit+=QString::number(IntStack->pop())+"\n";
        }
        size=StringStack->size();
        for(int i=0;i<size;i++){
            exit+=StringStack->pop()+"\n ";
        }
        ui->textEditExit->setText(exit);
        ui->lineEditValue->setFocus();
        ui->lineEditValue->clear();
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    };
}


void MainWindow::on_pushButtonRemove_clicked()
{
    try {
        if(!IntStack) throw QString("Must input a size");
        if(!StringStack)throw QString("Must input a size");
        QString exit="";
        if(IntStack->size()){
             exit=QString::number(IntStack->pop())+" ";
        }
        if(StringStack->size()){
             exit+=StringStack->pop();
         }

        ui->textEditExit->setText(exit);
        ui->lineEditValue->setFocus();
    } catch(QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    };
}



