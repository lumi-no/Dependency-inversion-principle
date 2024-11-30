#include <iostream>
#include <memory>
#include <string>


class MessageSender {
public:
    virtual void sendMessage(const std::string& message) const = 0;
    virtual ~MessageSender() = default;
};


class EmailSender : public MessageSender {
public:
    void sendMessage(const std::string& message) const override {
        std::cout << "Sending Email: " << message << std::endl;
    }
};


class SmsSender : public MessageSender {
public:
    void sendMessage(const std::string& message) const override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};


class Notification {
private:
    std::shared_ptr<MessageSender> sender;

public:
    Notification(std::shared_ptr<MessageSender> sender) : sender(sender) {}

    void notify(const std::string& message) const {
        sender->sendMessage(message);
    }
};

int main() {
   
    auto emailSender = std::make_shared<EmailSender>();
    Notification emailNotification(emailSender);
    emailNotification.notify("This is an email notification!");

    auto smsSender = std::make_shared<SmsSender>();
    Notification smsNotification(smsSender);
    smsNotification.notify("This is an SMS notification!");

    return 0;
}
