#ifndef APP_HPP
#define APP_HPP


#include "Email/Email.hpp"
#include <memory>

namespace Sender {
class App : public ssl::Email {
    public:
        App();
        ~App();

        static int Run(int argc, char** argv);

        private:
            int RunMain(int argc, char** argv);
    };
}


#endif // APP_HPP
