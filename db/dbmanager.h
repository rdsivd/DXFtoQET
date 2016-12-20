#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QWidget>
#include <QObject>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include <QtWidgets>
#include <QTableView>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QModelIndex>
#include <QSettings>
#include <QDateTime>
#include <QPlainTextEdit>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "data.h"



class dbManager : public QWidget
{
	Q_OBJECT
	public:
	explicit dbManager(QWidget *parent = 0 );

	int x1;
	int x2;
	int x10;

	int Command_Count;
	int Max_count_lines;
	int Record_count_lines;

	int32_t dxf_line_count;
	int32_t dxf_line_count_max;
	int32_t count_input;

	QString QsqlString;
	QString QsqlString2;
	QString Qsqlstring3;
	QString dxf_section;

	QString Qsql_Block;
	QString Qsql_entitie;
	QString Qsql_List;

	QString Waarde1;
	QString Waarde2;



	QString RecordNr;

	QVariantList dxf_list1;
	QVariantList dxf_list2;
	QVariantList dxf_list3;
	QVariantList dxf_list4;
	void dbManager1(const QString &pathname);

	void dbManager_close(const QString &pathname);

	void dbManager_create_tables(const QString &pathname);

	int dbManager_added_records(const QString &pathname, int64_t *Max_lines, int64_t *Record_count, QString dxf_type);

	void dbManager_load_dxf(const QString &pathname);

	void dbManager_load_dxf_list(const QString &pathname);

	void dbManager_create_elmt_entitie(const QString &pathname, int64_t Index_count_1,QString Block_naam_1, QString Block_value_1);

	void dbManager_create_elmt_block(const QString &pathname, int64_t Index_count_2, QString Block_naam_2, QString Block_value_2);

	QString db_split_header(const QString &pathname);

	signals:



	public slots:

	private:
		QSqlDatabase m_db;
};

#endif // DBMANAGER_H
