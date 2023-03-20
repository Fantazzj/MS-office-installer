#ifndef CONFIGGENERATOR_HPP
#define CONFIGGENERATOR_HPP

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QStandardItemModel>
#include <QVector>
#include <QXmlStreamWriter>

#include "DataModel.hpp"
#include "installer.hpp"
#include "ui_installer.h"

class Installer;

class ConfigGenerator {
public:
	ConfigGenerator(Model installerData, const QString& fileName);
	~ConfigGenerator();
	void createFile();

private:
	QFile* configFile;
	QXmlStreamWriter* configXml;
	Model installerData;
	//Ui::Installer* installerUi;
	//Installer* installer;
	//QVector<QCheckBox*> checkBoxApps;
	void _writeAddElement();
	void _writeProductOfficeElement();
	void _writeProductProofingElement();
	void _writeOfficeLangsElements();
	void _writeProofingLangsElements();
	void _writeExcludeAppElements();
	void _writeUpdatesElement();
	void _writeSaveFileType();
};

#endif//CONFIGGENERATOR_HPP
