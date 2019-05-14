#pragma once

#ifndef EMAIL_HPP
#define EMAIL_HPP

#include "CSmtp.h"
#include <string>
#include <vector>
#include <memory>


namespace ssl {
	typedef std::shared_ptr<std::vector<std::string>>(ErrorHandle);
	typedef std::string(Iterator);


	class Email {
		public:
			Email();
			~Email();

			/* --- Non copyable --- */
			Email(const Email&) = delete;
			Email& operator=(const Email&) = delete;

			/* --- Setters --- */
			void SetSender(const std::string& sender);
			void SetReceiver(const std::string& receiver);
			void SetPassword(const std::string& password);
			void SetSubject(const std::string& subject);
			void SetMessage(const std::string& msg);

			void Send(bool init = true);

			/* --- Getter --- */
			inline ErrorHandle GetError() const { return m_Error; }

		private: /* --- Functions --- */
			void Init();

		private: /* --- Variables --- */
			std::string m_Sender;
			std::string m_Receiver;
			std::string m_Password;

			std::string m_Subject;
			std::string m_Message;

			ErrorHandle m_Error = nullptr;
			std::unique_ptr<CSmtp> m_Mail = nullptr;


		private: /* --- Constants --- */
			const std::string CLIENT = "smtp.gmail.com";
			const unsigned short PORT = 465;
	};
}


#endif // !EMAIL_HPP