#include    "tep70.h"

//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
void TEP70::stepEPB(double t, double dt)
{
    // Потребляемый ток в рабочей линии ЭПТ
    double evr_current = electro_air_dist->getCurrent(0);

    // Потребляемый ток в рабочей линии ЭПТ
    double epb_work_curr = 0.0;
    epb_work_curr += evr_current;
    epb_work_curr += hose_bp_fwd->getCurrent(0);
    epb_work_curr += hose_bp_bwd->getCurrent(0);

    // Преобразователь напряжения для ЭПТ
    epb_converter->setInputVoltage(Ucc);
    epb_converter->setOutputCurrent(epb_work_curr);
    epb_converter->step(t, dt);

    // Контроллер двухпроводного ЭПТ
    epb_control->setInputVoltage(epb_converter->getOutputVoltage()
                                 * static_cast<double>(azv_ept_on.getState()) );
    epb_control->setHoldState(brake_crane->isHold());
    epb_control->setBrakeState(brake_crane->isBrake());
    epb_control->setControlVoltage(  hose_bp_fwd->getVoltage(1)
                                   + hose_bp_bwd->getVoltage(1) );
    epb_control->step(t, dt);
    double epb_work_U = epb_control->getWorkVoltage();
    double epb_work_f = epb_control->getWorkFrequency();

    // Управление электровоздухораспределителем
    double evr_U = 0.0;
    double evr_f = 0.0;
    // Если не нажата кнопка "Отпуск тормозов" - управление от линий ЭПТ
    if (!button_brake_release)
    {
        evr_U = epb_work_U + hose_bp_fwd->getVoltage(0) + hose_bp_bwd->getVoltage(0);
        evr_f = epb_work_f + hose_bp_fwd->getFrequency(0) + hose_bp_bwd->getFrequency(0);
    }
    electro_air_dist->setVoltage  (0, evr_U);
    electro_air_dist->setFrequency(0, evr_f);

    // Межвагонные сигналы линий ЭПТ по рукавам тормозной магистрали
    // Рабочая линия спереди
    hose_bp_fwd->setVoltage  (0, hose_bp_bwd->getVoltage(0) + epb_work_U);
    hose_bp_fwd->setFrequency(0, hose_bp_bwd->getFrequency(0) + epb_work_f);
    hose_bp_fwd->setCurrent  (0, hose_bp_bwd->getCurrent(0) + evr_current);
    // Контрольная линия спереди
    hose_bp_fwd->setVoltage  (1, hose_bp_bwd->getVoltage(1));
    hose_bp_fwd->setFrequency(1, hose_bp_bwd->getFrequency(1));
    hose_bp_fwd->setCurrent  (1, hose_bp_bwd->getCurrent(1));

    // Рабочая линия сзади
    hose_bp_bwd->setVoltage  (0, hose_bp_fwd->getVoltage(0) + epb_work_U);
    hose_bp_bwd->setFrequency(0, hose_bp_fwd->getFrequency(0) + epb_work_f);
    hose_bp_bwd->setCurrent  (0, hose_bp_fwd->getCurrent(0) + evr_current);
    // Контрольная линия сзади
    hose_bp_bwd->setVoltage  (1, hose_bp_fwd->getVoltage(1));
    hose_bp_bwd->setFrequency(1, hose_bp_fwd->getFrequency(1));
    hose_bp_bwd->setCurrent  (1, hose_bp_fwd->getCurrent(1));
}
