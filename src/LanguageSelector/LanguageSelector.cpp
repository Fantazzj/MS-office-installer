#include "LanguageSelector.hpp"

#include "ui_languageSelector.h"

LanguageSelector::LanguageSelector(QMainWindow* parent, CallType callType) :
	QDialog(parent, Qt::Dialog), ui(new Ui::LanguageSelector) {
	ui->setupUi(this);
	installer = dynamic_cast<Installer*>(parent);
	this->callType = callType;

	widgetPopulator(ui->scrollArea);

	qDebug() << "langUi created";
	qDebug() << "call type:" << callType;
}

LanguageSelector::~LanguageSelector() {
	qDebug() << "langUi destroyed";
	qDebug() << SEPARATOR;
	delete ui;
}

[[maybe_unused]] void LanguageSelector::on_buttonBox_accepted() {
	qDebug() << "confirm";
	QStringList langsList;

	auto jsonObj = installer->getJsonObj();
	auto languages = jsonObj.value("languages").toArray();

	for(auto C: checkBoxLangs)
		if(C->isChecked())
			for(auto L: languages)
				if(C->text() == L.toArray().at(0).toString()) {
					langsList.append(L.toArray().at(1).toString());
					break;
				}

	qDebug() << "selected languages:";
	qDebug() << langsList;

	if(callType == CallType::Product)
		installer->installerData.productLangs = langsList;
	else if(callType == CallType::Proofing)
		installer->installerData.proofingLangs = langsList;
	delete this;
}

[[maybe_unused]] void LanguageSelector::on_buttonBox_rejected() {
	reject();
}
void LanguageSelector::reject() {
	qDebug() << "cancel";
	delete this;
}

void LanguageSelector::widgetPopulator(QScrollArea* scrollArea) {
	auto jsonObj = installer->getJsonObj();
	auto languages = jsonObj.value("languages").toArray();

	auto layout = new QGridLayout();

	int i = 0, j = 0;
	for(auto l: languages) {
		qDebug() << l.toArray().at(0) << l.toArray().at(1);
		auto checkBox = new QCheckBox(l.toArray().at(0).toString());
		checkBoxLangs.append(checkBox);
		layout->addWidget(checkBox, i, j++);
		if(j >= 3) {
			i++;
			j = 0;
		}
	}

	/*	for(int k=0; k<20; k++) {
		auto checkBox = new QCheckBox("Language " + QString::number(k));
		layout->addWidget(checkBox, i, j++);
		if(j>=3) {i++; j=0;}
	}*/

	auto widget = new QWidget();
	widget->setLayout(layout);
	scrollArea->setWidget(widget);
}
