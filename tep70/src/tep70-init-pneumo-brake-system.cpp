#include    "tep70.h"

#include    <QDir>

#include    "filesystem.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void TEP70::initPneumoBrakeSystem()
{
    // Главный резервуар
    main_reservoir = new Reservoir(1.0);
    main_reservoir->setAirFlow(5e-4);

    // Мотор-компрессор
    motor_compressor = new DCMotorCompressor();
    motor_compressor->read_custom_config(config_dir + QDir::separator() + "motor-compressor");
    motor_compressor->setSoundName("Motor_Compressor");

    // Регулятор давления
    press_reg = new PressureRegulator(0.75, 0.9);

    // Элементы цепи управления компрессором
    ru18 = new Relay(3);
    ru18->read_custom_config(config_dir + QDir::separator() + "rpu-3m");
    ru18->setInitContactState(0, false);
    ru18->setInitContactState(1, false);
    ru18->setInitContactState(2, false);

    rv6 = new TimeRelay(1);
    rv6->read_custom_config(config_dir + QDir::separator() + "rpu-3m");
    rv6->setInitContactState(0, false);
    rv6->setTimeout(5.0);

    ktk1 = new Relay(3);
    ktk1->read_custom_config(config_dir + QDir::separator() + "rpu-3m");
    ktk1->setInitContactState(0, false);
    ktk1->setInitContactState(1, false);
    ktk1->setInitContactState(2, false);

    ktk2 = new Relay(1);
    ktk2->read_custom_config(config_dir + QDir::separator() + "rpu-3m");
    ktk2->setInitContactState(0, false);

    azv_motor_compressor.set();

    FileSystem &fs = FileSystem::getInstance();
    QString modules_dir = QString(fs.getModulesDir().c_str());

    // Устройство блокировки тормозов
    ubt367m = new BrakeLock();
    ubt367m->read_config("ubt367m");

    // Кран машиниста
    krm = loadBrakeCrane(modules_dir + QDir::separator() + "krm395");
    krm->read_config("krm395");

    // Кран вспомогательного тормоза
    kvt = loadLocoCrane(modules_dir + QDir::separator() + "kvt254");
    kvt->read_config("kvt254");

    // Воздухораспределитель
    vr = loadAirDistributor(modules_dir + QDir::separator() + "vr242");
    vr->read_config("vr242");

    // Электровоздухораспределитель
    evr = loadElectroAirDistributor(modules_dir + QDir::separator() + "evr305");
    evr->read_config("evr305");

    // Инициализация линии управления ЭПТ
    ept_control.resize(1);
    ept_current.resize(1);

    ept_control[0] = ept_current[0];

    // Инициализайия источника питания ЭПТ (ПОЗЖЕ!!!)

    // Инициализация блока управления ЭПТ (ПОЗЖЕ!!!)

    // Переключательный клапан
    zpk = new SwitchingValve();
    zpk->read_config("zpk");
}
