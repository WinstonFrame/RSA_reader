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
 * 				main.cpp
 *
 * Author: Oleg Voevodin
 * Release date: 28th of May 2013
 *
 * ****************************************************************************
*/

#include <QApplication>
#include <QTranslator>
#include "maindialog.h"

#define RUSSIAN

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef RUSSIAN
    QTranslator translator;
    translator.load("tr_ru.qm", ".");
    a.installTranslator(&translator);
#endif

    MainDialog w;
    w.show();
    
    return a.exec();
}
