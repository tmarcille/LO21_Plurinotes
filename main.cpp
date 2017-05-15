#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "Notes.h"
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QHboxLayout>
#include <QFileDialog>
#include <iostream>
#include "ArticleEditeur.h"
#include "PluriNotes.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	PluriNotes w;
	w.show();
	return app.exec();
}