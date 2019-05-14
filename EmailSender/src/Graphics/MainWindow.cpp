#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent), ui(new Ui::MainWindow), m_LoginEvent(nullptr) {

    ui->setupUi(this);
    setFixedSize(width(), height());
}


MainWindow::~MainWindow() {
    delete ui;
}


Collector MainWindow::getData() const {
    return {
        ui->recEdit->text().toStdString(),
        ui->sendEdit->text().toStdString(),
        ui->pwEdit->text().toStdString(),
        ui->subEdit->text().toStdString(),
        ui->msgEdit->toPlainText().toStdString()
    };
}


void MainWindow::setSendEvent(const logic::EventHandle& lambda) {
    m_LoginEvent = std::make_shared<logic::Event>(lambda);
}


void MainWindow::setStatus(const std::string &status, const std::string& color) {
    const std::string styleStr = "QLabel { color: " + color + ";}";

    ui->statusLabel->setStyleSheet(QString(styleStr.c_str()));

    ui->statusLabel->setText("Status: " + QString(status.c_str()));
}


void MainWindow::on_sendBtn_clicked() {
    if (m_LoginEvent != nullptr) {
        if (!m_LoginEvent->Exec()) {
            std::abort();
        }
    }
}
