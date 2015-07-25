#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <stdlib.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadFileButton_clicked();

    void on_randomiseButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadOptionsFromFile(QString filename);
};

#endif // MAINWINDOW_H
