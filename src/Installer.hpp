#ifndef INSTALLER_HPP
#define INSTALLER_HPP

#include <QMainWindow>
#include "ConfigGenerator.hpp"
#include "OfficeDeploymentTool.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Installer;
}
QT_END_NAMESPACE

class Installer : public QMainWindow {
    Q_OBJECT

public:
    Installer(QWidget* parent = nullptr);
    ~Installer();

private slots:
    void on_startInstall_clicked();

private:
    Ui::Installer* ui;
    ConfigGenerator xml;
    OfficeDeploymentTool office;

};
#endif// INSTALLER_HPP