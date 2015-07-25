#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // load options from a file input.txt
    // if it exists
    QFileInfo input("input.txt");
    if (input.exists() && input.isFile()) {
        loadOptionsFromFile("input.txt");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadOptionsFromFile(QString filename) {
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) return;
    QTextStream in(&file);
    QString contents = in.readAll();

    ui->optionsEdit->setPlainText(contents);

    file.close();
}

void MainWindow::on_loadFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open options file"), QString(),
                                                    tr("Text files(*.txt)"));
    loadOptionsFromFile(filename);
}

void MainWindow::on_randomiseButton_clicked()
{
    QString optionsString = ui->optionsEdit->toPlainText();
    QStringList options = optionsString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    if (options.size() != 0) {
        int index = rand() % (int)((options.size() - 1) + 1);
        ui->resultLine->setText(options.at(index));
    }
}
