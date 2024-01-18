#include "mailing.h"
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QHostInfo>
#include <iostream>
void sendEmailViaGmail() {
    // Create an instance of QSslSocket
    QSslSocket* socket = new QSslSocket();

    // Connect to Gmail's SMTP server
    socket->connectToHostEncrypted("smtp.gmail.com", 465);

    if (!socket->waitForConnected()) {
        qDebug() << "Error connecting to Gmail server:" << socket->errorString();
        return;
    }

    // Set up SSL configuration
    socket->startClientEncryption();
    if (!socket->waitForEncrypted()) {
        qDebug() << "Error establishing SSL connection:" << socket->errorString();
        return;
    }
     std::cout<<"Git";
    // Log in to Gmail (replace 'your_email@gmail.com' and 'your_password' with your Gmail credentials)
    QByteArray loginCommand = "AUTH LOGIN\r\n";
    socket->write(loginCommand);
    socket->waitForBytesWritten();

    QByteArray username = QByteArray("amazon424626@gmail.com").toBase64() + "\r\n";
    socket->write(username);
    socket->waitForBytesWritten();

    QByteArray password = QByteArray("FilipKing123").toBase64() + "\r\n";
    socket->write(password);
    socket->waitForBytesWritten();

    // Compose and send email
    // (Replace 'from_address', 'to_address', 'subject', and 'body' with your actual email details)
    QByteArray mailFrom = "MAIL FROM:<amzon424626@gmail.com>\r\n";
    socket->write(mailFrom);
    socket->waitForBytesWritten();

    QByteArray rcptTo = "RCPT TO:<szkudlarek4filip@gmail.com>\r\n";
    socket->write(rcptTo);
    socket->waitForBytesWritten();

    QByteArray data = "DATA\r\n";
    socket->write(data);
    socket->waitForBytesWritten();

    QByteArray subject = "Subject: subject\r\n";
    QByteArray body = "Your email body here.\r\n";
    QByteArray messageEnd = "\r\n.\r\n";

    socket->write(subject);
    socket->waitForBytesWritten();
    socket->write(body);
    socket->waitForBytesWritten();
    socket->write(messageEnd);
    socket->waitForBytesWritten();

    // Quit and close connection
    QByteArray quit = "QUIT\r\n";
    socket->write(quit);
    socket->waitForBytesWritten();
    socket->close();
}
