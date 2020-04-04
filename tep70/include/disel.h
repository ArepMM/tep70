#ifndef     DISEL_H
#define     DISEL_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class Disel : public Device
{
public:

    Disel(QObject *parent = Q_NULLPTR);

    ~Disel();

    /// Задать расход масла от электрического маслопрокачивающего насоса (ЭМН)
    void setQ_emn(double Q_emn);

    /// Задать крутящий момент от стартер-генератора
    void setStarterTorque(double M_sg);

    /// Вернуть давление в системе смазки
    double getOilPressure() const { return getY(0); }

    /// Вернуть частоту вращения привода стартер-генератора
    double getStarterOmega() const { return ip * getY(1); }

    /// Вернуть частоту вращения тягового генератора
    double getOmega() const { return getY(1); }

private:

    enum
    {
        NUM_COEFFS = 10,

        /// Давление масла
        OIL_PRESSURE = 0,

        /// Угловая скорость вращения вала
        SHAFT_OMEGA = 1,
    };

    /// Условный объем маслянного русла
    double  V_oil;

    /// Расход масла от ЭМН
    double  Q_emn;

    /// Момент от стартер-генератора
    double  M_sg;

    /// Момент сопротивления на валу
    double  Mc;

    /// Передаточное число привода стартер-генератора
    double  ip;

    /// Приведенный к коленчатому валу момент инерции (условно постоянный!)
    double  J_shaft;

    std::array<double, NUM_COEFFS>  K;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // DISEL_H