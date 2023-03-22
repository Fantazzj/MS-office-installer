#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "src/installer.hpp"

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for(const QString& locale: uiLanguages) {
		const QString baseName = "MS-office-installer_" + QLocale(locale).name();
		if(translator.load(":/i18n/" + baseName)) {
			a.installTranslator(&translator);
			break;
		}
	}

	QTranslator basic;
	if(basic.load("translations/qt_it"))
		a.installTranslator(&basic);

	Installer w;
	w.show();
	return a.exec();
}
