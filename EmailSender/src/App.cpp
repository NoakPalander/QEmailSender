#include "App.hpp"

#include <QApplication>
#include <QMessageBox>
#include "Graphics/MainWindow.hpp"
#include <QIcon>


namespace Sender {
    App::App() = default;
    App::~App() = default;


    int App::Run(int argc, char** argv) {
        App app;
        return app.RunMain(argc, argv);
    }


    int App::RunMain(int argc, char** argv) {
        QApplication a(argc, argv);
        MainWindow mainWindow;

        // Creates event for send-button
        mainWindow.setSendEvent([&mainWindow](){
            auto data = mainWindow.getData();       // Gets data from gui-widgets
            ssl::Email mail;                        // Initializes ssl::Email client

            mail.SetReceiver(data.rec);             // Sets Receiver (Gmail)
            mail.SetSender(data.usr);               // Sets Sender   (Gmail)
            mail.SetPassword(data.pw);              // Sets Password (Gmail-login)
            mail.SetSubject(data.sub);              // Sets Subject  (Gmail-subject)
            mail.SetMessage(data.msg);              // Sets Message  (Gmail-message)
            mail.Send();                            // Sends the mail

            // Gets potential mail-error
            if (mail.GetError() == nullptr)
                mainWindow.setStatus("Sent!", "green");    // Success
            else {
                mainWindow.setStatus("Failed!", "red");    // Failed

                // Displays error box
                QMessageBox box;
                box.setWindowTitle("Error!");
                box.setWindowModality(Qt::NonModal);
                box.setInformativeText(mail.ErrorStr(mail.GetError()).c_str());
                box.setDefaultButton(QMessageBox::Ok);
                box.exec();
            }
        });

        mainWindow.show();
        return a.exec();
    }
}
