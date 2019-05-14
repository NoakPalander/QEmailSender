#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <functional>
#include <memory>
#include <string>
#include "../Event.hpp"


struct Collector {
    std::string rec;
    std::string usr;
    std::string pw;
    std::string sub;
    std::string msg;
};


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


        /* --- Getter --- */
        Collector getData() const;

        /* --- Setters --- */
        void setSendEvent(const logic::EventHandle& lambda);
        void setViewEvent(const logic::EventHandle& lambda);
        void setStatus(const std::string& status, const std::string& color);


    private slots:
        void on_sendBtn_clicked();

    private:
        Ui::MainWindow *ui;

        event::handle m_LoginEvent;
        event::handle m_ViewEvent;
};

#endif // !MAINWINDOW_HPP
