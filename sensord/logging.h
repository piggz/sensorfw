/**
   @file logging.h
   @brief Syslog utility

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Ustun Ergenoglu <ext-ustun.ergenoglu@nokia.com>
   @author Antti Virtanen <antti.i.virtanen@nokia.com>

   This file is part of Sensord.

   Sensord is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Sensord is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Sensord.  If not, see <http://www.gnu.org/licenses/>.
   </p>
 */

#ifndef LOGGING_H
#define LOGGING_H

#include <sstream>
#include <QString>
#include <QStringList>
#include <QMutex>
#include <QMutexLocker>
#include <QFile>
#include <QTextStream>

enum SensordLogLevel {
    SensordLogTest = 1,
    SensordLogDebug,
    SensordLogWarning,
    SensordLogCritical,
    SensordLogN
};

class SensordLogger
{
public:
    SensordLogger(const char *func, const char *file, int line, SensordLogLevel level);
    ~SensordLogger();

    SensordLogger& operator<<(const QStringList& item)
    {
        return this->operator<<(item.join(", "));
    }

    SensordLogger& operator<<(const QString& item)
    {
        oss << item.toStdString();
        return *this;
    }

    template <typename T>
    SensordLogger& operator<<(const T& item)
    {
        oss << item;
        return *this;
    }


public:

    static void setOutputLevel(SensordLogLevel level);
    static SensordLogLevel getOutputLevel();
    static void init();
    static void initTarget();
    static void close();
    static int m_target;

private:
    std::ostringstream oss;
    SensordLogLevel currentLevel;
    static SensordLogLevel outputLevel;
    static bool initialized;
    static void printToTarget(QString data);
    static QFile* m_file;
    static QMutex m_mutex;
    static QMutexLocker m_locker;
    int logPriority(int currentLevel);
    QString logLevelToText(int level);
};

#define sensordLogT() (SensordLogger(__PRETTY_FUNCTION__, __FILE__, __LINE__, SensordLogTest))
#define sensordLogD() (SensordLogger(__PRETTY_FUNCTION__, __FILE__, __LINE__, SensordLogDebug))
#define sensordLogW() (SensordLogger(__PRETTY_FUNCTION__, __FILE__, __LINE__, SensordLogWarning))
#define sensordLogC() (SensordLogger(__PRETTY_FUNCTION__, __FILE__, __LINE__, SensordLogCritical))
#define sensordLog() (SensordLogger(__PRETTY_FUNCTION__, __FILE__, __LINE__, SensordLogTest))

#endif //LOGGING_H
