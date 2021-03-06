#ifndef VnaCalUnit_H
#define VnaCalUnit_H


// RsaToolbox
#include "Definitions.h"
#include "Connector.h"

// Qt
#include <QMap>
#include <QObject>
#include <QScopedPointer>
#include <QVector>


namespace RsaToolbox {
class Vna;

class VnaCalUnit : public QObject
{
private: Q_OBJECT

public:
    explicit VnaCalUnit(QObject *parent = 0);
    VnaCalUnit(const VnaCalUnit &other);
    VnaCalUnit(Vna *vna, QString id, QObject *parent = 0);
    ~VnaCalUnit();

    QString id() const;
    void select();

    double minimumFrequency_Hz();
    double maximumFrequency_Hz();
    uint ports();
    QVector<uint> connectedToPorts();

    bool hasConnector(Connector connector);
    bool hasConnector(QString calName, Connector connector);
    QMap<uint, Connector> physicalConnectors();
    QMap<uint, Connector> connectorsFromLatestCal();
    QMap<uint, Connector> connectorsFrom(QString calName);
    QVector<uint> portsOfType(Connector connector);
    QVector<uint> portsOfTypeFromLatestCal(Connector connector);
    QVector<uint> portsOfType(QString calName, Connector connector);

    QStringList calibrations();
    void frequencyRange(QString calName, double &min_Hz, double &max_Hz);
    // QString calDate(QString calName);

    void exportFactoryCal(QString path);
    void exportLatestCal(QString path);
    void exportCalibration(QString calName, QString path);

    bool isWarmedUp();
    void setOpen();
    void setOpen(uint port);
    void setOpen(QVector<uint> ports);
    void setShort();
    void setShort(uint port);
    void setShort(QVector<uint> ports);
    void setMatch();
    void setMatch(uint port);
    void setMatch(QVector<uint> ports);
    void setThru(uint port1, uint port2);

    void operator=(VnaCalUnit const &other);

private:
    Vna *_vna;
    QScopedPointer<Vna> placeholder;
    QString _id;
    bool isFullyInitialized() const;
    
};
}

#endif // VnaCalUnit_H
