/* ****************************************************************************
 *
 * Copyright 2013 Oleg Voevodin
 *
 * This file is part of rsa file encryption in C++.
 *
 * rsa file encryption is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rsa file encryption is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rsa.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 				maindialog.cpp
 *
 * Author: Oleg Voevodin
 * Release date: 28th of May 2013
 *
 * ****************************************************************************
*/

#include <QFileDialog>
#include <QMessageBox>
#include "maindialog.h"
#include "ui_maindialog.h"
#include "RSA.h"

const int MainDialog::DIGIT_COUNT = 10;
const long MainDialog::EXPONENT = 65537L;

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::encryptRadioButtonToggled(bool isChecked)
{
    ui->keyEdit->setReadOnly(isChecked);
    if (isChecked)
        ui->keyEdit->clear();
}

void MainDialog::inputBrowseButtonClicked()
{
    ui->inputLineEdit->setText(QFileDialog::getOpenFileName(0, tr("Open")));
}

void MainDialog::outputBrowseButtonClicked()
{
    ui->outputLineEdit->setText(QFileDialog::getSaveFileName(0, tr("Save")));
}

void MainDialog::okButtonClicked()
{
    if (ui->inputLineEdit->text().isEmpty())
    {
        QMessageBox::warning(0, tr("Attention"), tr("No input filename entered!"));
        return;
    }

    if (ui->outputLineEdit->text().isEmpty())
    {
        QMessageBox::warning(0, tr("Attention"), tr("No output filename entered!"));
        return;
    }

    if (ui->encryptRadioButton->isChecked())
    {
        KeyPair keyPair = RSA::GenerateKeyPair(DIGIT_COUNT);
        try
        {
            RSA::Encrypt(ui->inputLineEdit->text().toStdString().c_str(), ui->outputLineEdit->text().toStdString().c_str(), keyPair.GetPrivateKey());
        }
        catch (const char* error)
        {
            QMessageBox::critical(0, tr("Error"), tr("During the operation an error occured:") + '\n' + QString(error));
            return;
        }
        ui->keyEdit->setText(keyPair.GetPublicKey().GetModulus().ToString().c_str());
        QMessageBox::information(0, tr("Attention"), tr("Operation complete! Your key is ") + QString(keyPair.GetPublicKey().GetModulus().ToString().c_str()));
    }
    else
    {
        if (ui->keyEdit->text().isEmpty())
        {
            QMessageBox::warning(0, tr("Attention"), tr("No decrypt key entered!"));
            return;
        }

        try
        {
            RSA::Decrypt(ui->inputLineEdit->text().toStdString().c_str(), ui->outputLineEdit->text().toStdString().c_str(), Key(BigInt(ui->keyEdit->text().toStdString()), BigInt(EXPONENT)));
        }
        catch (const char* error)
        {
            QMessageBox::critical(0, tr("Error"), tr("During the operation an error occured:") + '\n' + QString(error));
            return;
        }
        QMessageBox::information(0, tr("Attention"), tr("Operation complete!"));
    }
}
