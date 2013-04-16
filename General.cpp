
// Rsa
#include "General.h"

// Qt
#include <QTextStream>
#include <QCoreApplication>

// C++ std lib
#include <complex>

using namespace RsaToolbox;

// Enum Conversions
double RsaToolbox::ToDouble(SiPrefix prefix) {
    switch(prefix) {
    case TERA:
        return(10E12);
        break;
    case GIGA:
        return(10E9);
        break;
    case MEGA:
        return(10E6);
        break;
    case KILO:
        return(10E3);
        break;
    case NO_PREFIX:
        return(10E0);
        break;
    case MILLI:
        return(10E-3);
        break;
    case MICRO:
        return(10E-6);
        break;
    case NANO:
        return(10E-9);
        break;
    case PICO:
        return(10E-12);
        break;
    case FEMTO:
        return(10E-15);
        break;
    }
}
QString RsaToolbox::ToString(SiPrefix prefix) {
    switch(prefix) {
    case TERA:
        return("T");
        break;
    case GIGA:
        return("G");
        break;
    case MEGA:
        return("M");
        break;
    case KILO:
        return("K");
        break;
    case NO_PREFIX:
        return("");
        break;
    case MILLI:
        return("m");
        break;
    case MICRO:
        return("u");
        break;
    case NANO:
        return("n");
        break;
    case PICO:
        return("p");
        break;
    case FEMTO:
        return("f");
        break;
    }
}
QString RsaToolbox::ToString(Units units) {
    switch(units) {
    case UNITLESS:
        return("");
        break;
    case SECONDS:
        return("S");
        break;
    case HERTZ:
        return("Hz");
        break;
    case RADIANS:
        return("Rad");
        break;
    case DEGREES:
        return("Deg");
        break;
    case WATTS:
        return("W");
        break;
    case DECIBELS:
        return("dB");
        break;
    case DECIBEL_WATTS:
        return("dBW");
        break;
    case DECIBEL_MILLIWATTS:
        return("dBm");
        break;
    }
}
QString RsaToolbox::ToString(ComplexFormat format) {
    switch(format) {
    case DB_DEGREES:
        return("dB");
        break;
    case MAGNITUDE_DEGREES:
        return("MA");
        break;
    case REAL_IMAGINARY:
        return("RI");
        break;
    }
}
QString RsaToolbox::ToString(NetworkParameter parameter) {
    switch(parameter) {
    case S_PARAMETER:
        return("S");
        break;
    case Y_PARAMETER:
        return("Y");
        break;
    case Z_PARAMETER:
        return("Z");
        break;
    case H_PARAMETER:
        return("H");
        break;
    case G_PARAMETER:
        return("G");
        break;
    }
}
const char* RsaToolbox::ToScpi(ColorScheme scheme) {
    switch(scheme) {
    case DARK_BACKGROUND:
        return("DBAC");
        break;
    case LIGHT_BACKGROUND:
        return("LBAC");
        break;
    case BLACK_WHITE_OUTLINE:
        return("BWLS");
        break;
    case BLACK_WHITE_SOLID:
        return("BWS");
        break;
    }
}
const char* RsaToolbox::ToScpi(TraceFormat format) {
    switch(format) {
    case DB_MAGNITUDE:
        return("MLOG");
        break;
    case PHASE_DEG:
        return("PHAS");
        break;
    case SMITH_CHART:
        return("SMIT");
        break;
    case POLAR_CHART:
        return("POL");
        break;
    case SWR:
        return("SWR");
        break;
    case UNWRAP_PHASE_DEG:
        return("UPH");
        break;
    case LINEAR_MAGNITUDE:
        return("MLIN");
        break;
    case INVERSE_SMITH_CHART:
        return("ISM");
        break;
    case REAL_PART:
        return("REAL");
        break;
    case IMAGINARY_PART:
        return("IMAG");
        break;
    case DELAY:
        return("GDE");
        break;
    }
}
TraceFormat Scpi_To_TraceFormat(QString scpi) {
    if (scpi == "MLOG")
        return(DB_MAGNITUDE);
    if (scpi == "PHAS")
        return(PHASE_DEG);
    if (scpi == "SMIT")
        return(SMITH_CHART);
    if (scpi == "POL")
        return(POLAR_CHART);
    if (scpi == "SWR")
        return(SWR);
    if (scpi == "UPH")
        return(UNWRAP_PHASE_DEG);
    if (scpi == "MLIN")
        return(LINEAR_MAGNITUDE);
    if (scpi == "ISM")
        return(INVERSE_SMITH_CHART);
    if (scpi == "REAL")
        return(REAL_PART);
    if (scpi == "IMAG")
        return(IMAGINARY_PART);
    if (scpi == "GDE")
        return(DELAY);
}

ColorScheme RsaToolbox::Scpi_To_ColorScheme(QString scpi) {
    if(scpi == "DBAC")
        return(DARK_BACKGROUND);
    if(scpi == "LBAC")
        return(LIGHT_BACKGROUND);
    if(scpi == "BWLS")
        return(BLACK_WHITE_OUTLINE);
    if(scpi == "BWS")
        return(BLACK_WHITE_SOLID);
}
NetworkParameter RsaToolbox::Scpi_To_NetworkParameter(QString scpi) {
    if (scpi == "S")
        return(S_PARAMETER);
    if (scpi == "Y")
        return(Y_PARAMETER);
    if (scpi == "Z")
        return(Z_PARAMETER);
    if (scpi == "H")
        return(H_PARAMETER);
    if (scpi == "G")
        return(G_PARAMETER);
}

// File system
QString RsaToolbox::AppendPath(QDir path, QString filename) {
    return(path.path() + "/" + filename);
}
QString RsaToolbox::AppendCurrentDirectory(QString filename) {
    return(QCoreApplication::applicationDirPath() + "/" + filename);
}

// Formatting
QString RsaToolbox::FormatValue(double value, int decimalPlaces, Units units, SiPrefix prefix) {
    QString formatted_value;
    QTextStream text_stream(&formatted_value);
    text_stream.setRealNumberPrecision(decimalPlaces);
    text_stream.setRealNumberNotation(QTextStream::FixedNotation);

    const int count = 10;
    SiPrefix prefixes[count] = { FEMTO, PICO, NANO, MICRO, MILLI, NO_PREFIX, KILO, MEGA, GIGA, TERA };

    double magnitude = abs(value * ToDouble(prefix));
    for (int i = 0; i < count; i++) {
        double bound = (1 - 0.5 * pow(10.0, (double)(-3 - decimalPlaces))) * ToDouble(prefixes[i + 1]);
        if (magnitude < bound) {
            text_stream << (value / ToDouble(prefixes[i])) << " ";
            text_stream << ToString(prefixes[i]) << ToString(units);
            text_stream.flush();
            return(formatted_value);
        }
    }

    // else Tera or bigger
    text_stream << (value / (double)prefixes[count]);
    text_stream << (QString)prefixes[count] << (QString)units;
    text_stream.flush();
    return(formatted_value);
}

// Math
double RsaToolbox::ToDb(double value) {
    return(20 * log10(value));
}
double RsaToolbox::ToDb(std::complex<double> value) {
    return(ToDb(abs(value)));
}
double RsaToolbox::ToMagnitude(double decibels) {
    return(pow(10.0, decibels / 20.0));
}
