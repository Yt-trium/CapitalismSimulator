#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "../CSCommon/types.h"

void MainWindow::on_launch_PB_clicked()
{
    Boolean coordinatedActions      = (Boolean)ui->COORD_CB->isChecked();
    Boolean exhaustibleResource     = (Boolean)ui->EXHAUST_CB->isChecked();
    Boolean allowObservation        = (Boolean)ui->OBS_CB->isChecked();
    Boolean Robbery                 = (Boolean)ui->ROBBERY_CB->isChecked();
    unsigned int maxGet             = (unsigned int)ui->MAXGET_SB->value();
    unsigned int endCondition       = (unsigned int)ui->ENDCOND_SB->value();

    unsigned int R1InitialQuantity  = (unsigned int)ui->R1I_SB->value();
    unsigned int R1NumberOfProducer = (unsigned int)ui->R1N_SB->value();
    unsigned int R2InitialQuantity  = (unsigned int)ui->R2I_SB->value();
    unsigned int R2NumberOfProducer = (unsigned int)ui->R2N_SB->value();
    unsigned int R3InitialQuantity  = (unsigned int)ui->R3I_SB->value();
    unsigned int R3NumberOfProducer = (unsigned int)ui->R3N_SB->value();
    unsigned int R4InitialQuantity  = (unsigned int)ui->R4I_SB->value();
    unsigned int R4NumberOfProducer = (unsigned int)ui->R4N_SB->value();
    unsigned int R5InitialQuantity  = (unsigned int)ui->R5I_SB->value();
    unsigned int R5NumberOfProducer = (unsigned int)ui->R5N_SB->value();

    unsigned int cooperative        = (unsigned int)ui->AGENTC_SB->value();
    unsigned int individualistic    = (unsigned int)ui->AGENTI_SB->value();
    unsigned int humans             = (unsigned int)ui->AGENTH_SB->value();

    // Create CSProducer
    unsigned int i, z = 0;
    for(i=0;i<R1NumberOfProducer;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer";
        QStringList arguments;
        arguments.push_back(QString::number(i+z*5));
        arguments.push_back(QString::number(exhaustibleResource));
        arguments.push_back(QString::number(R1InitialQuantity));
        process->start(program, arguments);
    }
    z++;
    for(i=0;i<R2NumberOfProducer;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer";
        QStringList arguments;
        arguments.push_back(QString::number(i+z*5));
        arguments.push_back(QString::number(exhaustibleResource));
        arguments.push_back(QString::number(R2InitialQuantity));
        process->start(program, arguments);
    }
    z++;
    for(i=0;i<R3NumberOfProducer;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer";
        QStringList arguments;
        arguments.push_back(QString::number(i+z*5));
        arguments.push_back(QString::number(exhaustibleResource));
        arguments.push_back(QString::number(R3InitialQuantity));
        process->start(program, arguments);
    }
    z++;
    for(i=0;i<R4NumberOfProducer;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer";
        QStringList arguments;
        arguments.push_back(QString::number(i+z*5));
        arguments.push_back(QString::number(exhaustibleResource));
        arguments.push_back(QString::number(R4InitialQuantity));
        process->start(program, arguments);
    }
    z++;
    for(i=0;i<R5NumberOfProducer;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSProducer/CSProducer";
        QStringList arguments;
        arguments.push_back(QString::number(i+z*5));
        arguments.push_back(QString::number(exhaustibleResource));
        arguments.push_back(QString::number(R5InitialQuantity));
        process->start(program, arguments);
    }

    // Create CSAgent
    z=0;
    // Cooperative
    for(i=0;i<cooperative;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent";
        QStringList arguments;
        arguments.push_back("1");
        process->start(program, arguments);
    }

    // Individualistic
    for(i=0;i<individualistic;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent";
        QStringList arguments;
        arguments.push_back("2");
        process->start(program, arguments);
    }

    // Humans
    for(i=0;i<humans;i++)
    {
        QProcess *process = new QProcess(this);
        QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSAgent/CSAgent";
        QStringList arguments;
        arguments.push_back("0");
        process->start(program, arguments);
    }

    // Create CSCoordinator
    QProcess *process = new QProcess(this);
    QString program = "/home/yttrium/Documents/Cours/CapitalismSimulator/build-CapitalismSimulator-Desktop-Debug/CSCoordinator/CSCoordinator";
    QStringList arguments;
    arguments.push_back(QString::number(coordinatedActions));
    arguments.push_back(QString::number(exhaustibleResource));
    arguments.push_back(QString::number(allowObservation));
    arguments.push_back(QString::number(Robbery));
    arguments.push_back(QString::number(maxGet));
    arguments.push_back(QString::number(endCondition));

    arguments.push_back(QString::number(R1InitialQuantity));
    arguments.push_back(QString::number(R1NumberOfProducer));
    arguments.push_back(QString::number(R2InitialQuantity));
    arguments.push_back(QString::number(R2NumberOfProducer));
    arguments.push_back(QString::number(R3InitialQuantity));
    arguments.push_back(QString::number(R3NumberOfProducer));
    arguments.push_back(QString::number(R4InitialQuantity));
    arguments.push_back(QString::number(R4NumberOfProducer));
    arguments.push_back(QString::number(R5InitialQuantity));
    arguments.push_back(QString::number(R5NumberOfProducer));

    arguments.push_back(QString::number(cooperative));
    arguments.push_back(QString::number(individualistic));
    arguments.push_back(QString::number(humans));

    // BP
    // process->start(program, arguments);
}
