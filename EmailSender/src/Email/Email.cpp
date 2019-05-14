#include "Email.hpp"

namespace ssl {
    Email::Email() = default;
    Email::~Email() = default;


    void Email::SetSender(const std::string& sender) {
        m_Sender = sender;
    }


    void Email::SetReceiver(const std::string& receiver) {
        m_Receiver = receiver;
    }


    void Email::SetPassword(const std::string& password) {
        m_Password = password;
    }


    void Email::SetSubject(const std::string& subject) {
        m_Subject = subject;
    }


    void Email::SetMessage(const std::string& msg) {
        m_Message = msg;
    }


    void Email::Send(bool init) {
        if (init) {
            this->Init();
        }

        if (m_Mail != nullptr) {
            try {
                m_Mail->Send();
            }
            catch (ECSmtp e) {
                if (m_Error != nullptr) {
                    m_Error->push_back(e.GetErrorText().c_str());
                }
                else {
                    m_Error = std::make_shared<std::vector<std::string>>();
                    m_Error->push_back(e.GetErrorText().c_str());
                }
            }
        }
    }


    std::string Email::ErrorStr(ErrorHandle error) {
        std::string buff = "";
        for (const std::string& i : *error.get())
            buff += i;

        return buff;
    }


    void Email::Init() {
        try {
            m_Mail = std::make_unique<CSmtp>();

            m_Mail->SetSMTPServer(CLIENT.c_str(), PORT);
            m_Mail->SetSecurityType(USE_SSL);

            m_Mail->SetLogin(m_Sender.c_str());
            m_Mail->SetPassword(m_Password.c_str());

            m_Mail->SetSenderName(m_Sender.c_str());
            m_Mail->SetSenderMail(m_Sender.c_str());

            m_Mail->SetSubject(m_Subject.c_str());
            m_Mail->AddRecipient(m_Receiver.c_str());
            m_Mail->AddMsgLine(m_Message.c_str());
        }
        catch (ECSmtp e) {
            if (m_Error != nullptr) {
                m_Error->push_back(e.GetErrorText().c_str());
            }
            else {
                m_Error = std::make_shared<std::vector<std::string>>();
                m_Error->push_back(e.GetErrorText().c_str());
            }
        }
    }
}
