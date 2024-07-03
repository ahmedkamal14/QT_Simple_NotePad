#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Note Pad");
    setWindowIcon(QIcon(":/rescources/images/main_icon.png"));
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setFontPointSize(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose a File to Open");
    QFile file(fileName);
    filePath = fileName;
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "Error", "Couldn't Open File");
    }

    else {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        file.close();
    }
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Error", "Couldn't Open File");
    }

    else {
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out  << text;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose a File to Open");
    filePath = fileName;
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Error", "Couldn't Open File");
    }

    else {
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out  << text;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionAbout_NotePad_triggered()
{
    QString about_text;
    about_text  = "Author: Ahmed Kamal\n\nDate: 3rd July 2024\n\nDescription:\n\nThis notepad application is a simple yet powerful tool for creating, editing, and managing text documents.\nDesigned with a user-friendly interface, it provides a seamless experience for all your note-taking and writing needs.";

    QMessageBox::about(this, "Notepad Application", about_text);
}


void MainWindow::on_actionEdit_Font_triggered()
{
    bool selected;
    QFont font = QFontDialog::getFont(&selected, this);
    if (selected) {
        ui->textEdit->setFont(font);
    }
    else return;
}


void MainWindow::on_actionFont_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose text Color");
    ui->textEdit->setTextColor(color);

}


void MainWindow::on_actionHighlight_Text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose text Color");
    ui->textEdit->setTextBackgroundColor(color);
    // ui->textEdit->setStyleSheet("");
}


void MainWindow::on_actionBackGround_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose text Color");
    QPalette palette;
    palette.setColor(QPalette::Base,color);
    if(color.isValid())
        ui->textEdit->setPalette(palette);
}

