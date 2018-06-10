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
 * 				maindialog.h
 *
 * Author: Oleg Voevodin
 * Release date: 28th of May 2013
 *
 * ****************************************************************************
*/

#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();
    
private slots:
    void encryptRadioButtonToggled(bool isChecked);
    void inputBrowseButtonClicked();
    void outputBrowseButtonClicked();
    void okButtonClicked();

private:
    Ui::MainDialog *ui;
    static const int DIGIT_COUNT;
    static const long EXPONENT;
};

#endif // MAINDIALOG_H
