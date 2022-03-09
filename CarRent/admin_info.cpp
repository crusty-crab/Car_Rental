#include "admin_info.h"
#include "ui_admin_info.h"
#include "account.h"

extern sql admin;

admin_info::admin_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_info)
{
    ui->setupUi(this);
    if(admin.db.isOpen()){
        qDebug()<<"Connected...";

    }else{

        /*display error if cannot connect to the database*/
        qDebug()<<"Cannot connect to database";
        QMessageBox::critical(this, "Error", "Cannot connect to the database.");
        QCoreApplication::exit();
    }
}

admin_info::~admin_info()
{
    delete ui;
}

void admin_info::on_pushButton_clicked()
{
    admin_account.keyGenerator();
    admin_account.f_name = ui->lineEdit_fname->text();
    admin_account.l_name = ui->lineEdit_Lname->text();
    admin_account.username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString confirm_password = ui->lineEdit_confirm_password->text();
    // checks existing username in database.
    if (admin.usernameExists(admin_account.username))
    {
        ui->label_username_check->setText("invalid username");
    }

    // confirms the password
    if (confirm_password != password)
    {
        ui->label_password_check->setText("password doesn't match");
    }
    else
    {
        int key;
        key = admin_account.getKey();
        password = admin_account.encrypt(password,key);
        admin_account.setPassword(password);
    }
    admin.exportAccount(admin_account);
    admin.deleteDefault();

}


void admin_info::on_checkBox_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        /*hides password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        ui->lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
        break;
    case 2:
        /*shows password*/
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_confirm_password->setEchoMode(QLineEdit::Normal);
        break;
    }
}
