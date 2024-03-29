/*          Testbench GUI Main Window Header

@date 18 February 2015
*/

/****************************************************************************
 *   Copyright (C) 2015 by Ken Sarkies                                      *
 *   ksarkies@internode.on.net                                              *
 *                                                                          *
 *   This file is part of Testbench                                         *
 *                                                                          *
 *   Testbench is free software; you can redistribute it and/or             *
 *   modify it under the terms of the GNU General Public License as         *
 *   published by the Free Software Foundation; either version 2 of the     *
 *   License, or (at your option) any later version.                        *
 *                                                                          *
 *   Testbench is distributed in the hope that it will be useful,           *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with testbench.                                                  *
 *   If not, write to the Free Software Foundation, Inc.,                   *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.              *
 ***************************************************************************/

#ifndef TESTBENCH_MAIN_H
#define TESTBENCH_MAIN_H

#include "ui_testbench-main.h"
#include "testbench.h"
#include "serialport.h"
#include <QDir>
#include <QFile>
#include <QTime>
#include <QCloseEvent>

// Particular serial port to use
#define SERIAL_PORT "/dev/ttyACM0"
#define BAUDRATE1 4
#define BAUDRATE2 2

//-----------------------------------------------------------------------------
/** @brief Testbench Main Window.

*/

class TestbenchGui : public QDialog
{
    Q_OBJECT
public:
    TestbenchGui(QWidget* parent = 0);
    ~TestbenchGui();
    bool success();
    QString error();
private slots:
    void onData1Available();
    void onData2Available();
    void on_saveFileButton_clicked();
    void on_closeFileButton_clicked();
    void on_startPushButton_clicked();
    void on_connect1_clicked();
    void on_connect2_clicked();
private:
// User Interface object instance
    Ui::WatermeterTestbenchDialog TestbenchMainUi;
// Methods
    void displayErrorMessage(const QString message);
    void processResponse(const QString response);
    void saveLine(QString line);    // Save line to a file
    void setComboBoxes();
// Variables
    SerialPort* socket1;            //!< Serial port object pointer
    uint baudrate1;
    QString response1;
    SerialPort* socket2;            //!< Serial port object pointer
    uint baudrate2;
    QString response2;
    quint16 blockSize;
    QTime tick;
    QDir saveDirectory;
    QString saveFile;
    QFile* outFile;
    bool recordingActive;
    bool synchronized;
    QString errorMessage;
    char timeTick;
};

#endif
