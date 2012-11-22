/*
 * Copyright (c) 2012 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
 *
 * GL shader based on BSD licensed code from Peter Bengtsson:
 * http://www.fourcc.org/source/YUV420P-OpenGL-GLSLang.c
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MELTEDUNITSMODEL_H
#define MELTEDUNITSMODEL_H

#include <QAbstractTableModel>
#include "mvcpthread.h"

class QTimer;

class MeltedUnitsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MeltedUnitsModel(QObject *parent = 0);
    ~MeltedUnitsModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

signals:
    void disconnected();

public slots:
    void onConnected(MvcpThread*);
    void onDisconnected();
    void onTimeout();

private:
    MvcpThread* m_mvcp;
    QObjectList m_units;
    QTimer* m_timer;

private slots:
    void onUlsResult(QStringList);
    void onUstaResult(QObject*);
};

#endif // MELTEDUNITSMODEL_H