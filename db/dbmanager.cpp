#include "dbmanager.h"

extern struct DXF_codes DXF_code_tables[DXF_codes_set];
extern struct DXF_base DXF_main_base[DXF_base_set];

dbManager::dbManager(QWidget *parent) : QWidget(parent)
{

}

void dbManager::dbManager1(const QString &pathname)
{
	m_db=QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(pathname);



	if (!m_db.open())
	{
		/*QMessageBox::warning(this, tr("Application"),
				  tr("Error : connection with database fails"));*/
	}
	else
	{
		/*QMessageBox::warning(this, tr("Application"),
				  tr("Connection with database ok"));*/
	}
		m_db.exec("PRAGMA temp_store = MEMORY");
		m_db.exec("PRAGMA journal_mode = MEMORY");
		m_db.exec("PRAGMA page_size = 4096");
		m_db.exec("PRAGMA cache_size = 16384");
		m_db.exec("PRAGMA locking_mode = EXCLUSIVE");
		m_db.exec("PRAGMA synchronous = OFF");



}

void dbManager::dbManager_close(const QString &pathname)
{
	if (m_db.isOpen())
	{
		m_db.close();


	}
}

void dbManager::dbManager_create_tables(const QString &pathname)
{

	QsqlString="create table dxf_list (Index_count primary key, Code)";

	m_db.exec(QsqlString);

	QsqlString="create table dxf_file (Index_count primary key, Code, Waarde, Section )";

	m_db.exec(QsqlString);

	QsqlString="create table elmt_blocks (Index_count primary key,Block_Naam, Block_value)";

	m_db.exec(QsqlString);

	QsqlString="create table elmt_entities (Index_count primary key,Block_Naam, Block_value)";

	m_db.exec(QsqlString);

	QsqlString="create table dxf_header (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);


	QsqlString="create table dxf_classes (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);

	QsqlString="create table dxf_tables (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);

	QsqlString="create table dxf_blocks (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);

	QsqlString="create table dxf_entities (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);


	QsqlString="create table dxf_objects (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);

	QsqlString="create table dxf_thumbnailimage (Index_count primary key,Section";
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");


	QsqlString.append(")");

	m_db.exec(QsqlString);

	return;
}

int dbManager::dbManager_added_records(const QString &pathname, int64_t *Max_lines, int64_t *Record_count, QString dxf_type)
{
	m_db.transaction();
	QSqlQuery Query1;

	x1=0;
	//x10=0;

	QsqlString="INSERT INTO ";
	QsqlString.append(dxf_type);
	QsqlString.append(" (Index_count, Section");
	QsqlString.append(", Command, ID_instruction, Command_count");
	QsqlString.append(", dxf_m1, dxf_m2, dxf_m3, dxf_m4, dxf_m5");
	QsqlString.append(", dxf_0, dxf_1, dxf_2, dxf_3, dxf_4, dxf_5, dxf_6, dxf_7, dxf_8, dxf_9");
	QsqlString.append(", dxf_10, dxf_11, dxf_12, dxf_13, dxf_14, dxf_15, dxf_16, dxf_17, dxf_18, dxf_19");
	QsqlString.append(", dxf_20, dxf_21, dxf_22, dxf_23, dxf_24, dxf_25, dxf_26, dxf_27, dxf_28, dxf_29");
	QsqlString.append(", dxf_30, dxf_31, dxf_32, dxf_33, dxf_34, dxf_35, dxf_36, dxf_37, dxf_38, dxf_39");
	QsqlString.append(", dxf_40, dxf_41, dxf_42, dxf_43, dxf_44, dxf_45, dxf_46, dxf_47, dxf_48, dxf_49");
	QsqlString.append(", dxf_50, dxf_51, dxf_52, dxf_53, dxf_54, dxf_55, dxf_56, dxf_57, dxf_58, dxf_59");
	QsqlString.append(", dxf_60, dxf_61, dxf_62, dxf_63, dxf_64, dxf_65, dxf_66, dxf_67, dxf_68, dxf_69");
	QsqlString.append(", dxf_70, dxf_71, dxf_72, dxf_73, dxf_74, dxf_75, dxf_76, dxf_77, dxf_78, dxf_79");
	QsqlString.append(", dxf_90, dxf_91, dxf_92, dxf_93, dxf_94, dxf_95, dxf_96, dxf_97, dxf_98, dxf_99");
	QsqlString.append(", dxf_100, dxf_102, dxf_105");
	QsqlString.append(", dxf_110, dxf_111, dxf_112, dxf_113, dxf_114, dxf_115, dxf_116, dxf_117, dxf_118, dxf_119");
	QsqlString.append(", dxf_120, dxf_121, dxf_122, dxf_123, dxf_124, dxf_125, dxf_126, dxf_127, dxf_128, dxf_129");
	QsqlString.append(", dxf_130, dxf_131, dxf_132, dxf_133, dxf_134, dxf_135, dxf_136, dxf_137, dxf_138, dxf_139");
	QsqlString.append(", dxf_140, dxf_141, dxf_142, dxf_143, dxf_144, dxf_145, dxf_146, dxf_147, dxf_148, dxf_149");

	QsqlString.append(", dxf_160, dxf_161, dxf_162, dxf_163, dxf_164, dxf_165, dxf_166, dxf_167, dxf_168, dxf_169");
	QsqlString.append(", dxf_170, dxf_171, dxf_172, dxf_173, dxf_174, dxf_175, dxf_176, dxf_177, dxf_178, dxf_179");

	QsqlString.append(", dxf_210, dxf_211, dxf_212, dxf_213, dxf_214, dxf_215, dxf_216, dxf_217, dxf_218, dxf_219");
	QsqlString.append(", dxf_220, dxf_221, dxf_222, dxf_223, dxf_224, dxf_225, dxf_226, dxf_227, dxf_228, dxf_229");
	QsqlString.append(", dxf_230, dxf_231, dxf_232, dxf_233, dxf_234, dxf_235, dxf_236, dxf_237, dxf_238, dxf_239");

	QsqlString.append(", dxf_270, dxf_271, dxf_272, dxf_273, dxf_274, dxf_275, dxf_276, dxf_277, dxf_278, dxf_279");
	QsqlString.append(", dxf_280, dxf_281, dxf_282, dxf_283, dxf_284, dxf_285, dxf_286, dxf_287, dxf_288, dxf_289");
	QsqlString.append(", dxf_290, dxf_291, dxf_292, dxf_293, dxf_294, dxf_295, dxf_296, dxf_297, dxf_298, dxf_299");
	QsqlString.append(", dxf_300, dxf_301, dxf_302, dxf_303, dxf_304, dxf_305, dxf_306, dxf_307, dxf_308, dxf_309");
	QsqlString.append(", dxf_310, dxf_311, dxf_312, dxf_313, dxf_314, dxf_315, dxf_316, dxf_317, dxf_318, dxf_319");
	QsqlString.append(", dxf_320, dxf_321, dxf_322, dxf_323, dxf_324, dxf_325, dxf_326, dxf_327, dxf_328, dxf_329");
	QsqlString.append(", dxf_330, dxf_331, dxf_332, dxf_333, dxf_334, dxf_335, dxf_336, dxf_337, dxf_338, dxf_339");
	QsqlString.append(", dxf_340, dxf_341, dxf_342, dxf_343, dxf_344, dxf_345, dxf_346, dxf_347, dxf_348, dxf_349");
	QsqlString.append(", dxf_350, dxf_351, dxf_352, dxf_353, dxf_354, dxf_355, dxf_356, dxf_357, dxf_358, dxf_359");
	QsqlString.append(", dxf_360, dxf_361, dxf_362, dxf_363, dxf_364, dxf_365, dxf_366, dxf_367, dxf_368, dxf_369");
	QsqlString.append(", dxf_370, dxf_371, dxf_372, dxf_373, dxf_374, dxf_375, dxf_376, dxf_377, dxf_378, dxf_379");
	QsqlString.append(", dxf_380, dxf_381, dxf_382, dxf_383, dxf_384, dxf_385, dxf_386, dxf_387, dxf_388, dxf_389");
	QsqlString.append(", dxf_390, dxf_391, dxf_392, dxf_393, dxf_394, dxf_395, dxf_396, dxf_397, dxf_398, dxf_399");
	QsqlString.append(", dxf_400, dxf_401, dxf_402, dxf_403, dxf_404, dxf_405, dxf_406, dxf_407, dxf_408, dxf_409");
	QsqlString.append(", dxf_410, dxf_411, dxf_412, dxf_413, dxf_414, dxf_415, dxf_416, dxf_417, dxf_418, dxf_419");
	QsqlString.append(", dxf_420, dxf_421, dxf_422, dxf_423, dxf_424, dxf_425, dxf_426, dxf_427, dxf_428, dxf_429");
	QsqlString.append(", dxf_430, dxf_431, dxf_432, dxf_433, dxf_434, dxf_435, dxf_436, dxf_437, dxf_438, dxf_439");
	QsqlString.append(", dxf_440, dxf_441, dxf_442, dxf_443, dxf_444, dxf_445, dxf_446, dxf_447, dxf_448, dxf_449");
	QsqlString.append(", dxf_450, dxf_451, dxf_452, dxf_453, dxf_454, dxf_455, dxf_456, dxf_457, dxf_458, dxf_459");
	QsqlString.append(", dxf_460, dxf_461, dxf_462, dxf_463, dxf_464, dxf_465, dxf_466, dxf_467, dxf_468, dxf_469");
	QsqlString.append(", dxf_470, dxf_471, dxf_472, dxf_473, dxf_474, dxf_475, dxf_476, dxf_477, dxf_478, dxf_479");
	QsqlString.append(", dxf_480, dxf_481, dxf_482, dxf_483, dxf_484, dxf_485, dxf_486, dxf_487, dxf_488, dxf_489");
	QsqlString.append(", dxf_999");
	QsqlString.append(", dxf_1000, dxf_1001, dxf_1002, dxf_1003, dxf_1004, dxf_1005, dxf_1006, dxf_1007, dxf_1008, dxf_1009");
	QsqlString.append(", dxf_1010, dxf_1011, dxf_1012, dxf_1013, dxf_1014, dxf_1015, dxf_1016, dxf_1017, dxf_1018, dxf_1019");
	QsqlString.append(", dxf_1020, dxf_1021, dxf_1022, dxf_1023, dxf_1024, dxf_1025, dxf_1026, dxf_1027, dxf_1028, dxf_1029");
	QsqlString.append(", dxf_1030, dxf_1031, dxf_1032, dxf_1033, dxf_1034, dxf_1035, dxf_1036, dxf_1037, dxf_1038, dxf_1039");
	QsqlString.append(", dxf_1040, dxf_1041, dxf_1042, dxf_1043, dxf_1044, dxf_1045, dxf_1046, dxf_1047, dxf_1048, dxf_1049");
	QsqlString.append(", dxf_1050, dxf_1051, dxf_1052, dxf_1053, dxf_1054, dxf_1055, dxf_1056, dxf_1057, dxf_1058, dxf_1059");
	QsqlString.append(", dxf_1060, dxf_1061, dxf_1062, dxf_1063, dxf_1064, dxf_1065, dxf_1066, dxf_1067, dxf_1068, dxf_1069");
	QsqlString.append(", dxf_1070, dxf_1071");
	QsqlString.append(")");
	QsqlString.append(" VALUES (:Index_count, :Section");
	QsqlString.append(", :Command, :ID_instruction, :Command_count");
	QsqlString.append(", :dxf_m1, :dxf_m2, :dxf_m3, :dxf_m4, :dxf_m5");
	QsqlString.append(", :dxf_0, :dxf_1, :dxf_2, :dxf_3, :dxf_4, :dxf_5, :dxf_6, :dxf_7, :dxf_8, :dxf_9");//dxf_0
	QsqlString.append(", :dxf_10, :dxf_11, :dxf_12, :dxf_13, :dxf_14, :dxf_15, :dxf_16, :dxf_17, :dxf_18, :dxf_19");
	QsqlString.append(", :dxf_20, :dxf_21, :dxf_22, :dxf_23, :dxf_24, :dxf_25, :dxf_26, :dxf_27, :dxf_28, :dxf_29");
	QsqlString.append(", :dxf_30, :dxf_31, :dxf_32, :dxf_33, :dxf_34, :dxf_35, :dxf_36, :dxf_37, :dxf_38, :dxf_39");
	QsqlString.append(", :dxf_40, :dxf_41, :dxf_42, :dxf_43, :dxf_44, :dxf_45, :dxf_46, :dxf_47, :dxf_48, :dxf_49");
	QsqlString.append(", :dxf_50, :dxf_51, :dxf_52, :dxf_53, :dxf_54, :dxf_55, :dxf_56, :dxf_57, :dxf_58, :dxf_59");
	QsqlString.append(", :dxf_60, :dxf_61, :dxf_62, :dxf_63, :dxf_64, :dxf_65, :dxf_66, :dxf_67, :dxf_68, :dxf_69");
	QsqlString.append(", :dxf_70, :dxf_71, :dxf_72, :dxf_73, :dxf_74, :dxf_75, :dxf_76, :dxf_77, :dxf_78, :dxf_79");
	QsqlString.append(", :dxf_90, :dxf_91, :dxf_92, :dxf_93, :dxf_94, :dxf_95, :dxf_96, :dxf_97, :dxf_98, :dxf_99");
	QsqlString.append(", :dxf_100, :dxf_102, :dxf_105");
	QsqlString.append(", :dxf_110, :dxf_111, :dxf_112, :dxf_113, :dxf_114, :dxf_115, :dxf_116, :dxf_117, :dxf_118, :dxf_119");
	QsqlString.append(", :dxf_120, :dxf_121, :dxf_122, :dxf_123, :dxf_124, :dxf_125, :dxf_126, :dxf_127, :dxf_128, :dxf_129");
	QsqlString.append(", :dxf_130, :dxf_131, :dxf_132, :dxf_133, :dxf_134, :dxf_135, :dxf_136, :dxf_137, :dxf_138, :dxf_139");
	QsqlString.append(", :dxf_140, :dxf_141, :dxf_142, :dxf_143, :dxf_144, :dxf_145, :dxf_146, :dxf_147, :dxf_148, :dxf_149");

	QsqlString.append(", :dxf_160, :dxf_161, :dxf_162, :dxf_163, :dxf_164, :dxf_165, :dxf_166, :dxf_167, :dxf_168, :dxf_169");
	QsqlString.append(", :dxf_170, :dxf_171, :dxf_172, :dxf_173, :dxf_174, :dxf_175, :dxf_176, :dxf_177, :dxf_178, :dxf_179");


	QsqlString.append(", :dxf_210, :dxf_211, :dxf_212, :dxf_213, :dxf_214, :dxf_215, :dxf_216, :dxf_217, :dxf_218, :dxf_219");
	QsqlString.append(", :dxf_220, :dxf_221, :dxf_222, :dxf_223, :dxf_224, :dxf_225, :dxf_226, :dxf_227, :dxf_228, :dxf_229");
	QsqlString.append(", :dxf_230, :dxf_231, :dxf_232, :dxf_233, :dxf_234, :dxf_235, :dxf_236, :dxf_237, :dxf_238, :dxf_239");

	QsqlString.append(", :dxf_270, :dxf_271, :dxf_272, :dxf_273, :dxf_274, :dxf_275, :dxf_276, :dxf_277, :dxf_278, :dxf_279");
	QsqlString.append(", :dxf_280, :dxf_281, :dxf_282, :dxf_283, :dxf_284, :dxf_285, :dxf_286, :dxf_287, :dxf_288, :dxf_289");
	QsqlString.append(", :dxf_290, :dxf_291, :dxf_292, :dxf_293, :dxf_294, :dxf_295, :dxf_296, :dxf_297, :dxf_298, :dxf_299");
	QsqlString.append(", :dxf_300, :dxf_301, :dxf_302, :dxf_303, :dxf_304, :dxf_305, :dxf_306, :dxf_307, :dxf_308, :dxf_309");
	QsqlString.append(", :dxf_310, :dxf_311, :dxf_312, :dxf_313, :dxf_314, :dxf_315, :dxf_316, :dxf_317, :dxf_318, :dxf_319");
	QsqlString.append(", :dxf_320, :dxf_321, :dxf_322, :dxf_323, :dxf_324, :dxf_325, :dxf_326, :dxf_327, :dxf_328, :dxf_329");
	QsqlString.append(", :dxf_330, :dxf_331, :dxf_332, :dxf_333, :dxf_334, :dxf_335, :dxf_336, :dxf_337, :dxf_338, :dxf_339");
	QsqlString.append(", :dxf_340, :dxf_341, :dxf_342, :dxf_343, :dxf_344, :dxf_345, :dxf_346, :dxf_347, :dxf_348, :dxf_349");
	QsqlString.append(", :dxf_350, :dxf_351, :dxf_352, :dxf_353, :dxf_354, :dxf_355, :dxf_356, :dxf_357, :dxf_358, :dxf_359");
	QsqlString.append(", :dxf_360, :dxf_361, :dxf_362, :dxf_363, :dxf_364, :dxf_365, :dxf_366, :dxf_367, :dxf_368, :dxf_369");
	QsqlString.append(", :dxf_370, :dxf_371, :dxf_372, :dxf_373, :dxf_374, :dxf_375, :dxf_376, :dxf_377, :dxf_378, :dxf_379");
	QsqlString.append(", :dxf_380, :dxf_381, :dxf_382, :dxf_383, :dxf_384, :dxf_385, :dxf_386, :dxf_387, :dxf_388, :dxf_389");
	QsqlString.append(", :dxf_390, :dxf_391, :dxf_392, :dxf_393, :dxf_394, :dxf_395, :dxf_396, :dxf_397, :dxf_398, :dxf_399");
	QsqlString.append(", :dxf_400, :dxf_401, :dxf_402, :dxf_403, :dxf_404, :dxf_405, :dxf_406, :dxf_407, :dxf_408, :dxf_409");
	QsqlString.append(", :dxf_410, :dxf_411, :dxf_412, :dxf_413, :dxf_414, :dxf_415, :dxf_416, :dxf_417, :dxf_418, :dxf_419");
	QsqlString.append(", :dxf_420, :dxf_421, :dxf_422, :dxf_423, :dxf_424, :dxf_425, :dxf_426, :dxf_427, :dxf_428, :dxf_429");
	QsqlString.append(", :dxf_430, :dxf_431, :dxf_432, :dxf_433, :dxf_434, :dxf_435, :dxf_436, :dxf_437, :dxf_438, :dxf_439");
	QsqlString.append(", :dxf_440, :dxf_441, :dxf_442, :dxf_443, :dxf_444, :dxf_445, :dxf_446, :dxf_447, :dxf_448, :dxf_449");
	QsqlString.append(", :dxf_450, :dxf_451, :dxf_452, :dxf_453, :dxf_454, :dxf_455, :dxf_456, :dxf_457, :dxf_458, :dxf_459");
	QsqlString.append(", :dxf_460, :dxf_461, :dxf_462, :dxf_463, :dxf_464, :dxf_465, :dxf_466, :dxf_467, :dxf_468, :dxf_469");
	QsqlString.append(", :dxf_470, :dxf_471, :dxf_472, :dxf_473, :dxf_474, :dxf_475, :dxf_476, :dxf_477, :dxf_478, :dxf_479");
	QsqlString.append(", :dxf_480, :dxf_481, :dxf_482, :dxf_483, :dxf_484, :dxf_485, :dxf_486, :dxf_487, :dxf_488, :dxf_489");
	QsqlString.append(", :dxf_999");
	QsqlString.append(", :dxf_1000, :dxf_1001, :dxf_1002, :dxf_1003, :dxf_1004, :dxf_1005, :dxf_1006, :dxf_1007, :dxf_1008, :dxf_1009");
	QsqlString.append(", :dxf_1010, :dxf_1011, :dxf_1012, :dxf_1013, :dxf_1014, :dxf_1015, :dxf_1016, :dxf_1017, :dxf_1018, :dxf_1019");
	QsqlString.append(", :dxf_1020, :dxf_1021, :dxf_1022, :dxf_1023, :dxf_1024, :dxf_1025, :dxf_1026, :dxf_1027, :dxf_1028, :dxf_1029");
	QsqlString.append(", :dxf_1030, :dxf_1031, :dxf_1032, :dxf_1033, :dxf_1034, :dxf_1035, :dxf_1036, :dxf_1037, :dxf_1038, :dxf_1039");
	QsqlString.append(", :dxf_1040, :dxf_1041, :dxf_1042, :dxf_1043, :dxf_1044, :dxf_1045, :dxf_1046, :dxf_1047, :dxf_1048, :dxf_1049");
	QsqlString.append(", :dxf_1050, :dxf_1051, :dxf_1052, :dxf_1053, :dxf_1054, :dxf_1055, :dxf_1056, :dxf_1057, :dxf_1058, :dxf_1059");
	QsqlString.append(", :dxf_1060, :dxf_1061, :dxf_1062, :dxf_1063, :dxf_1064, :dxf_1065, :dxf_1066, :dxf_1067, :dxf_1068, :dxf_1069");
	QsqlString.append(", :dxf_1070, :dxf_1071");

	QsqlString.append(")");


	Query1.prepare(QsqlString);

	Command_Count=-1;
	Max_count_lines=*Max_lines;
	Record_count_lines=*Record_count;
	x1=0;

	while ((x1<Max_count_lines) and (x1<DXF_codes_set))
	{
		//DXF_code_tables[x1].ID_instruction=1;
		//Record_count_lines++;
		//x10++;
		if(Command_Count>=Max_count_lines)
		{
			Command_Count=-1;
		}

		Command_Count++;
		//Record_count_lines++;
		x2=0;

		//while (x10<Max_count_lines)
		//{

		//Record_count_lines++;

			//RecordNr=(QString::number(Record_count_lines));
			//Query1.bindValue(":Index_count",RecordNr);
			Query1.bindValue(":Index_count",Record_count_lines);
			Query1.bindValue(":Section",DXF_code_tables[0].Section);
			Query1.bindValue(":Command",DXF_code_tables[0].Command);


			Record_count_lines++;

			/*if (DXF_code_tables[0].dxf_5!="")
			{
				Query1.bindValue(":ID_instruction",DXF_code_tables[0].dxf_5);

			}
			else
			{
				Query1.bindValue(":ID_instruction",DXF_code_tables[0].ID_instruction);
			}*/

			Query1.bindValue(":ID_instruction",DXF_code_tables[0].ID_instruction);

			Query1.bindValue(":Command_count",QString::number(Command_Count));
			Query1.bindValue(":dxf_m1",DXF_code_tables[x1].dxf_m1);
			Query1.bindValue(":dxf_m2",DXF_code_tables[x1].dxf_m2);
			Query1.bindValue(":dxf_m3",DXF_code_tables[x1].dxf_m3);
			Query1.bindValue(":dxf_m4",DXF_code_tables[x1].dxf_m4);
			Query1.bindValue(":dxf_m1",DXF_code_tables[x1].dxf_m5);

			Query1.bindValue(":dxf_0",DXF_code_tables[x1].dxf_0);
			Query1.bindValue(":dxf_1",DXF_code_tables[x1].dxf_1);
			Query1.bindValue(":dxf_2",DXF_code_tables[x1].dxf_2);
			Query1.bindValue(":dxf_3",DXF_code_tables[x1].dxf_3);
			Query1.bindValue(":dxf_4",DXF_code_tables[x1].dxf_4);
			Query1.bindValue(":dxf_5",DXF_code_tables[0].dxf_5);
			Query1.bindValue(":dxf_6",DXF_code_tables[x1].dxf_6);
			Query1.bindValue(":dxf_7",DXF_code_tables[x1].dxf_7);
			Query1.bindValue(":dxf_8",DXF_code_tables[x1].dxf_8);
			Query1.bindValue(":dxf_9",DXF_code_tables[x1].dxf_9);
			Query1.bindValue(":dxf_10",DXF_code_tables[x1].dxf_10);
			Query1.bindValue(":dxf_10",DXF_code_tables[x1].dxf_10);
			Query1.bindValue(":dxf_11",DXF_code_tables[x1].dxf_11);
			Query1.bindValue(":dxf_12",DXF_code_tables[x1].dxf_12);
			Query1.bindValue(":dxf_13",DXF_code_tables[x1].dxf_13);
			Query1.bindValue(":dxf_14",DXF_code_tables[x1].dxf_14);
			Query1.bindValue(":dxf_15",DXF_code_tables[x1].dxf_15);
			Query1.bindValue(":dxf_16",DXF_code_tables[x1].dxf_16);
			Query1.bindValue(":dxf_17",DXF_code_tables[x1].dxf_17);
			Query1.bindValue(":dxf_18",DXF_code_tables[x1].dxf_18);
			Query1.bindValue(":dxf_19",DXF_code_tables[x1].dxf_19);
			Query1.bindValue(":dxf_20",DXF_code_tables[x1].dxf_20);
			Query1.bindValue(":dxf_21",DXF_code_tables[x1].dxf_21);
			Query1.bindValue(":dxf_22",DXF_code_tables[x1].dxf_22);
			Query1.bindValue(":dxf_23",DXF_code_tables[x1].dxf_23);
			Query1.bindValue(":dxf_24",DXF_code_tables[x1].dxf_24);
			Query1.bindValue(":dxf_25",DXF_code_tables[x1].dxf_25);
			Query1.bindValue(":dxf_26",DXF_code_tables[x1].dxf_26);
			Query1.bindValue(":dxf_27",DXF_code_tables[x1].dxf_27);
			Query1.bindValue(":dxf_28",DXF_code_tables[x1].dxf_28);
			Query1.bindValue(":dxf_29",DXF_code_tables[x1].dxf_29);
			Query1.bindValue(":dxf_30",DXF_code_tables[x1].dxf_30);
			Query1.bindValue(":dxf_31",DXF_code_tables[x1].dxf_31);
			Query1.bindValue(":dxf_32",DXF_code_tables[x1].dxf_32);
			Query1.bindValue(":dxf_33",DXF_code_tables[x1].dxf_33);
			Query1.bindValue(":dxf_34",DXF_code_tables[x1].dxf_34);
			Query1.bindValue(":dxf_35",DXF_code_tables[x1].dxf_35);
			Query1.bindValue(":dxf_36",DXF_code_tables[x1].dxf_36);
			Query1.bindValue(":dxf_37",DXF_code_tables[x1].dxf_37);
			Query1.bindValue(":dxf_38",DXF_code_tables[x1].dxf_38);
			Query1.bindValue(":dxf_39",DXF_code_tables[x1].dxf_39);
			Query1.bindValue(":dxf_40",DXF_code_tables[x1].dxf_40);
			Query1.bindValue(":dxf_41",DXF_code_tables[x1].dxf_41);
			Query1.bindValue(":dxf_42",DXF_code_tables[x1].dxf_42);
			Query1.bindValue(":dxf_43",DXF_code_tables[x1].dxf_43);
			Query1.bindValue(":dxf_44",DXF_code_tables[x1].dxf_44);
			Query1.bindValue(":dxf_45",DXF_code_tables[x1].dxf_45);
			Query1.bindValue(":dxf_46",DXF_code_tables[x1].dxf_46);
			Query1.bindValue(":dxf_47",DXF_code_tables[x1].dxf_47);
			Query1.bindValue(":dxf_48",DXF_code_tables[x1].dxf_48);
			Query1.bindValue(":dxf_49",DXF_code_tables[x1].dxf_49);
			Query1.bindValue(":dxf_50",DXF_code_tables[x1].dxf_50);
			Query1.bindValue(":dxf_51",DXF_code_tables[x1].dxf_51);
			Query1.bindValue(":dxf_52",DXF_code_tables[x1].dxf_52);
			Query1.bindValue(":dxf_53",DXF_code_tables[x1].dxf_53);
			Query1.bindValue(":dxf_54",DXF_code_tables[x1].dxf_54);
			Query1.bindValue(":dxf_55",DXF_code_tables[x1].dxf_55);
			Query1.bindValue(":dxf_56",DXF_code_tables[x1].dxf_56);
			Query1.bindValue(":dxf_57",DXF_code_tables[x1].dxf_57);
			Query1.bindValue(":dxf_58",DXF_code_tables[x1].dxf_58);
			Query1.bindValue(":dxf_59",DXF_code_tables[x1].dxf_59);
			Query1.bindValue(":dxf_60",DXF_code_tables[x1].dxf_60);
			Query1.bindValue(":dxf_61",DXF_code_tables[x1].dxf_61);
			Query1.bindValue(":dxf_62",DXF_code_tables[x1].dxf_62);
			Query1.bindValue(":dxf_63",DXF_code_tables[x1].dxf_63);
			Query1.bindValue(":dxf_64",DXF_code_tables[x1].dxf_64);
			Query1.bindValue(":dxf_65",DXF_code_tables[x1].dxf_65);
			Query1.bindValue(":dxf_66",DXF_code_tables[x1].dxf_66);
			Query1.bindValue(":dxf_67",DXF_code_tables[x1].dxf_67);
			Query1.bindValue(":dxf_68",DXF_code_tables[x1].dxf_68);
			Query1.bindValue(":dxf_69",DXF_code_tables[x1].dxf_69);
			Query1.bindValue(":dxf_70",DXF_code_tables[x1].dxf_70);
			Query1.bindValue(":dxf_71",DXF_code_tables[x1].dxf_71);
			Query1.bindValue(":dxf_72",DXF_code_tables[x1].dxf_72);
			Query1.bindValue(":dxf_73",DXF_code_tables[x1].dxf_73);
			Query1.bindValue(":dxf_74",DXF_code_tables[x1].dxf_74);
			Query1.bindValue(":dxf_75",DXF_code_tables[x1].dxf_75);
			Query1.bindValue(":dxf_76",DXF_code_tables[x1].dxf_76);
			Query1.bindValue(":dxf_77",DXF_code_tables[x1].dxf_77);
			Query1.bindValue(":dxf_78",DXF_code_tables[x1].dxf_78);
			Query1.bindValue(":dxf_79",DXF_code_tables[x1].dxf_79);


			Query1.bindValue(":dxf_90",DXF_code_tables[x1].dxf_90);
			Query1.bindValue(":dxf_91",DXF_code_tables[x1].dxf_91);
			Query1.bindValue(":dxf_92",DXF_code_tables[x1].dxf_92);
			Query1.bindValue(":dxf_93",DXF_code_tables[x1].dxf_93);
			Query1.bindValue(":dxf_94",DXF_code_tables[x1].dxf_94);
			Query1.bindValue(":dxf_95",DXF_code_tables[x1].dxf_95);
			Query1.bindValue(":dxf_96",DXF_code_tables[x1].dxf_96);
			Query1.bindValue(":dxf_97",DXF_code_tables[x1].dxf_97);
			Query1.bindValue(":dxf_98",DXF_code_tables[x1].dxf_98);
			Query1.bindValue(":dxf_99",DXF_code_tables[x1].dxf_99);
			Query1.bindValue(":dxf_100",DXF_code_tables[x1].dxf_100);

			Query1.bindValue(":dxf_102",DXF_code_tables[x1].dxf_102);


			Query1.bindValue(":dxf_105",DXF_code_tables[x1].dxf_105);


			Query1.bindValue(":dxf_110",DXF_code_tables[x1].dxf_110);
			Query1.bindValue(":dxf_111",DXF_code_tables[x1].dxf_111);
			Query1.bindValue(":dxf_112",DXF_code_tables[x1].dxf_112);
			Query1.bindValue(":dxf_113",DXF_code_tables[x1].dxf_113);
			Query1.bindValue(":dxf_114",DXF_code_tables[x1].dxf_114);
			Query1.bindValue(":dxf_115",DXF_code_tables[x1].dxf_115);
			Query1.bindValue(":dxf_116",DXF_code_tables[x1].dxf_116);
			Query1.bindValue(":dxf_117",DXF_code_tables[x1].dxf_117);
			Query1.bindValue(":dxf_118",DXF_code_tables[x1].dxf_118);
			Query1.bindValue(":dxf_119",DXF_code_tables[x1].dxf_119);
			Query1.bindValue(":dxf_120",DXF_code_tables[x1].dxf_120);
			Query1.bindValue(":dxf_121",DXF_code_tables[x1].dxf_121);
			Query1.bindValue(":dxf_122",DXF_code_tables[x1].dxf_122);
			Query1.bindValue(":dxf_123",DXF_code_tables[x1].dxf_123);
			Query1.bindValue(":dxf_124",DXF_code_tables[x1].dxf_124);
			Query1.bindValue(":dxf_125",DXF_code_tables[x1].dxf_125);
			Query1.bindValue(":dxf_126",DXF_code_tables[x1].dxf_126);
			Query1.bindValue(":dxf_127",DXF_code_tables[x1].dxf_127);
			Query1.bindValue(":dxf_128",DXF_code_tables[x1].dxf_128);
			Query1.bindValue(":dxf_129",DXF_code_tables[x1].dxf_129);
			Query1.bindValue(":dxf_130",DXF_code_tables[x1].dxf_130);
			Query1.bindValue(":dxf_131",DXF_code_tables[x1].dxf_131);
			Query1.bindValue(":dxf_132",DXF_code_tables[x1].dxf_132);
			Query1.bindValue(":dxf_133",DXF_code_tables[x1].dxf_133);
			Query1.bindValue(":dxf_134",DXF_code_tables[x1].dxf_134);
			Query1.bindValue(":dxf_135",DXF_code_tables[x1].dxf_135);
			Query1.bindValue(":dxf_136",DXF_code_tables[x1].dxf_136);
			Query1.bindValue(":dxf_137",DXF_code_tables[x1].dxf_137);
			Query1.bindValue(":dxf_138",DXF_code_tables[x1].dxf_138);
			Query1.bindValue(":dxf_139",DXF_code_tables[x1].dxf_139);
			Query1.bindValue(":dxf_140",DXF_code_tables[x1].dxf_140);
			Query1.bindValue(":dxf_141",DXF_code_tables[x1].dxf_141);
			Query1.bindValue(":dxf_142",DXF_code_tables[x1].dxf_142);
			Query1.bindValue(":dxf_143",DXF_code_tables[x1].dxf_143);
			Query1.bindValue(":dxf_144",DXF_code_tables[x1].dxf_144);
			Query1.bindValue(":dxf_145",DXF_code_tables[x1].dxf_145);
			Query1.bindValue(":dxf_146",DXF_code_tables[x1].dxf_146);
			Query1.bindValue(":dxf_147",DXF_code_tables[x1].dxf_147);
			Query1.bindValue(":dxf_148",DXF_code_tables[x1].dxf_148);
			Query1.bindValue(":dxf_149",DXF_code_tables[x1].dxf_149);


			Query1.bindValue(":dxf_160",DXF_code_tables[x1].dxf_160);
			Query1.bindValue(":dxf_161",DXF_code_tables[x1].dxf_161);
			Query1.bindValue(":dxf_162",DXF_code_tables[x1].dxf_162);
			Query1.bindValue(":dxf_163",DXF_code_tables[x1].dxf_163);
			Query1.bindValue(":dxf_164",DXF_code_tables[x1].dxf_164);
			Query1.bindValue(":dxf_165",DXF_code_tables[x1].dxf_165);
			Query1.bindValue(":dxf_166",DXF_code_tables[x1].dxf_166);
			Query1.bindValue(":dxf_167",DXF_code_tables[x1].dxf_167);
			Query1.bindValue(":dxf_168",DXF_code_tables[x1].dxf_168);
			Query1.bindValue(":dxf_169",DXF_code_tables[x1].dxf_169);
			Query1.bindValue(":dxf_170",DXF_code_tables[x1].dxf_170);
			Query1.bindValue(":dxf_171",DXF_code_tables[x1].dxf_171);
			Query1.bindValue(":dxf_172",DXF_code_tables[x1].dxf_172);
			Query1.bindValue(":dxf_173",DXF_code_tables[x1].dxf_173);
			Query1.bindValue(":dxf_174",DXF_code_tables[x1].dxf_174);
			Query1.bindValue(":dxf_175",DXF_code_tables[x1].dxf_175);
			Query1.bindValue(":dxf_176",DXF_code_tables[x1].dxf_176);
			Query1.bindValue(":dxf_177",DXF_code_tables[x1].dxf_177);
			Query1.bindValue(":dxf_178",DXF_code_tables[x1].dxf_178);
			Query1.bindValue(":dxf_179",DXF_code_tables[x1].dxf_179);


			Query1.bindValue(":dxf_210",DXF_code_tables[x1].dxf_210);
			Query1.bindValue(":dxf_211",DXF_code_tables[x1].dxf_211);
			Query1.bindValue(":dxf_212",DXF_code_tables[x1].dxf_212);
			Query1.bindValue(":dxf_213",DXF_code_tables[x1].dxf_213);
			Query1.bindValue(":dxf_214",DXF_code_tables[x1].dxf_214);
			Query1.bindValue(":dxf_215",DXF_code_tables[x1].dxf_215);
			Query1.bindValue(":dxf_216",DXF_code_tables[x1].dxf_216);
			Query1.bindValue(":dxf_217",DXF_code_tables[x1].dxf_217);
			Query1.bindValue(":dxf_218",DXF_code_tables[x1].dxf_218);
			Query1.bindValue(":dxf_219",DXF_code_tables[x1].dxf_219);
			Query1.bindValue(":dxf_220",DXF_code_tables[x1].dxf_220);
			Query1.bindValue(":dxf_221",DXF_code_tables[x1].dxf_221);
			Query1.bindValue(":dxf_222",DXF_code_tables[x1].dxf_222);
			Query1.bindValue(":dxf_223",DXF_code_tables[x1].dxf_223);
			Query1.bindValue(":dxf_224",DXF_code_tables[x1].dxf_224);
			Query1.bindValue(":dxf_225",DXF_code_tables[x1].dxf_225);
			Query1.bindValue(":dxf_226",DXF_code_tables[x1].dxf_226);
			Query1.bindValue(":dxf_227",DXF_code_tables[x1].dxf_227);
			Query1.bindValue(":dxf_228",DXF_code_tables[x1].dxf_228);
			Query1.bindValue(":dxf_229",DXF_code_tables[x1].dxf_229);
			Query1.bindValue(":dxf_230",DXF_code_tables[x1].dxf_230);
			Query1.bindValue(":dxf_231",DXF_code_tables[x1].dxf_231);
			Query1.bindValue(":dxf_232",DXF_code_tables[x1].dxf_232);
			Query1.bindValue(":dxf_233",DXF_code_tables[x1].dxf_233);
			Query1.bindValue(":dxf_234",DXF_code_tables[x1].dxf_234);
			Query1.bindValue(":dxf_235",DXF_code_tables[x1].dxf_235);
			Query1.bindValue(":dxf_236",DXF_code_tables[x1].dxf_236);
			Query1.bindValue(":dxf_237",DXF_code_tables[x1].dxf_237);
			Query1.bindValue(":dxf_238",DXF_code_tables[x1].dxf_238);
			Query1.bindValue(":dxf_239",DXF_code_tables[x1].dxf_239);


			Query1.bindValue(":dxf_270",DXF_code_tables[x1].dxf_270);
			Query1.bindValue(":dxf_271",DXF_code_tables[x1].dxf_271);
			Query1.bindValue(":dxf_272",DXF_code_tables[x1].dxf_272);
			Query1.bindValue(":dxf_273",DXF_code_tables[x1].dxf_273);
			Query1.bindValue(":dxf_274",DXF_code_tables[x1].dxf_274);
			Query1.bindValue(":dxf_275",DXF_code_tables[x1].dxf_275);
			Query1.bindValue(":dxf_276",DXF_code_tables[x1].dxf_276);
			Query1.bindValue(":dxf_277",DXF_code_tables[x1].dxf_277);
			Query1.bindValue(":dxf_278",DXF_code_tables[x1].dxf_278);
			Query1.bindValue(":dxf_279",DXF_code_tables[x1].dxf_279);
			Query1.bindValue(":dxf_280",DXF_code_tables[x1].dxf_280);
			Query1.bindValue(":dxf_281",DXF_code_tables[x1].dxf_281);
			Query1.bindValue(":dxf_282",DXF_code_tables[x1].dxf_282);
			Query1.bindValue(":dxf_283",DXF_code_tables[x1].dxf_283);
			Query1.bindValue(":dxf_284",DXF_code_tables[x1].dxf_284);
			Query1.bindValue(":dxf_285",DXF_code_tables[x1].dxf_285);
			Query1.bindValue(":dxf_286",DXF_code_tables[x1].dxf_286);
			Query1.bindValue(":dxf_287",DXF_code_tables[x1].dxf_287);
			Query1.bindValue(":dxf_288",DXF_code_tables[x1].dxf_288);
			Query1.bindValue(":dxf_289",DXF_code_tables[x1].dxf_289);
			Query1.bindValue(":dxf_290",DXF_code_tables[x1].dxf_290);
			Query1.bindValue(":dxf_291",DXF_code_tables[x1].dxf_291);
			Query1.bindValue(":dxf_292",DXF_code_tables[x1].dxf_292);
			Query1.bindValue(":dxf_293",DXF_code_tables[x1].dxf_293);
			Query1.bindValue(":dxf_294",DXF_code_tables[x1].dxf_294);
			Query1.bindValue(":dxf_295",DXF_code_tables[x1].dxf_295);
			Query1.bindValue(":dxf_296",DXF_code_tables[x1].dxf_296);
			Query1.bindValue(":dxf_297",DXF_code_tables[x1].dxf_297);
			Query1.bindValue(":dxf_298",DXF_code_tables[x1].dxf_298);
			Query1.bindValue(":dxf_299",DXF_code_tables[x1].dxf_299);
			Query1.bindValue(":dxf_300",DXF_code_tables[x1].dxf_300);
			Query1.bindValue(":dxf_301",DXF_code_tables[x1].dxf_301);
			Query1.bindValue(":dxf_302",DXF_code_tables[x1].dxf_302);
			Query1.bindValue(":dxf_303",DXF_code_tables[x1].dxf_303);
			Query1.bindValue(":dxf_304",DXF_code_tables[x1].dxf_304);
			Query1.bindValue(":dxf_305",DXF_code_tables[x1].dxf_305);
			Query1.bindValue(":dxf_306",DXF_code_tables[x1].dxf_306);
			Query1.bindValue(":dxf_307",DXF_code_tables[x1].dxf_307);
			Query1.bindValue(":dxf_308",DXF_code_tables[x1].dxf_308);
			Query1.bindValue(":dxf_309",DXF_code_tables[x1].dxf_309);
			Query1.bindValue(":dxf_310",DXF_code_tables[x1].dxf_310);
			Query1.bindValue(":dxf_311",DXF_code_tables[x1].dxf_311);
			Query1.bindValue(":dxf_312",DXF_code_tables[x1].dxf_312);
			Query1.bindValue(":dxf_313",DXF_code_tables[x1].dxf_313);
			Query1.bindValue(":dxf_314",DXF_code_tables[x1].dxf_314);
			Query1.bindValue(":dxf_315",DXF_code_tables[x1].dxf_315);
			Query1.bindValue(":dxf_316",DXF_code_tables[x1].dxf_316);
			Query1.bindValue(":dxf_317",DXF_code_tables[x1].dxf_317);
			Query1.bindValue(":dxf_318",DXF_code_tables[x1].dxf_318);
			Query1.bindValue(":dxf_319",DXF_code_tables[x1].dxf_319);
			Query1.bindValue(":dxf_320",DXF_code_tables[x1].dxf_320);
			Query1.bindValue(":dxf_321",DXF_code_tables[x1].dxf_321);
			Query1.bindValue(":dxf_322",DXF_code_tables[x1].dxf_322);
			Query1.bindValue(":dxf_323",DXF_code_tables[x1].dxf_323);
			Query1.bindValue(":dxf_324",DXF_code_tables[x1].dxf_324);
			Query1.bindValue(":dxf_325",DXF_code_tables[x1].dxf_325);
			Query1.bindValue(":dxf_326",DXF_code_tables[x1].dxf_326);
			Query1.bindValue(":dxf_327",DXF_code_tables[x1].dxf_327);
			Query1.bindValue(":dxf_328",DXF_code_tables[x1].dxf_328);
			Query1.bindValue(":dxf_329",DXF_code_tables[x1].dxf_329);
			Query1.bindValue(":dxf_330",DXF_code_tables[x1].dxf_330);
			Query1.bindValue(":dxf_331",DXF_code_tables[x1].dxf_331);
			Query1.bindValue(":dxf_332",DXF_code_tables[x1].dxf_332);
			Query1.bindValue(":dxf_333",DXF_code_tables[x1].dxf_333);
			Query1.bindValue(":dxf_334",DXF_code_tables[x1].dxf_334);
			Query1.bindValue(":dxf_335",DXF_code_tables[x1].dxf_335);
			Query1.bindValue(":dxf_336",DXF_code_tables[x1].dxf_336);
			Query1.bindValue(":dxf_337",DXF_code_tables[x1].dxf_337);
			Query1.bindValue(":dxf_338",DXF_code_tables[x1].dxf_338);
			Query1.bindValue(":dxf_339",DXF_code_tables[x1].dxf_339);
			Query1.bindValue(":dxf_340",DXF_code_tables[x1].dxf_340);
			Query1.bindValue(":dxf_341",DXF_code_tables[x1].dxf_341);
			Query1.bindValue(":dxf_342",DXF_code_tables[x1].dxf_342);
			Query1.bindValue(":dxf_343",DXF_code_tables[x1].dxf_343);
			Query1.bindValue(":dxf_344",DXF_code_tables[x1].dxf_344);
			Query1.bindValue(":dxf_345",DXF_code_tables[x1].dxf_345);
			Query1.bindValue(":dxf_346",DXF_code_tables[x1].dxf_346);
			Query1.bindValue(":dxf_347",DXF_code_tables[x1].dxf_347);
			Query1.bindValue(":dxf_348",DXF_code_tables[x1].dxf_348);
			Query1.bindValue(":dxf_349",DXF_code_tables[x1].dxf_349);
			Query1.bindValue(":dxf_350",DXF_code_tables[x1].dxf_350);
			Query1.bindValue(":dxf_351",DXF_code_tables[x1].dxf_351);
			Query1.bindValue(":dxf_352",DXF_code_tables[x1].dxf_352);
			Query1.bindValue(":dxf_353",DXF_code_tables[x1].dxf_353);
			Query1.bindValue(":dxf_354",DXF_code_tables[x1].dxf_354);
			Query1.bindValue(":dxf_355",DXF_code_tables[x1].dxf_355);
			Query1.bindValue(":dxf_356",DXF_code_tables[x1].dxf_356);
			Query1.bindValue(":dxf_357",DXF_code_tables[x1].dxf_357);
			Query1.bindValue(":dxf_358",DXF_code_tables[x1].dxf_358);
			Query1.bindValue(":dxf_359",DXF_code_tables[x1].dxf_359);
			Query1.bindValue(":dxf_360",DXF_code_tables[x1].dxf_360);
			Query1.bindValue(":dxf_361",DXF_code_tables[x1].dxf_361);
			Query1.bindValue(":dxf_362",DXF_code_tables[x1].dxf_362);
			Query1.bindValue(":dxf_363",DXF_code_tables[x1].dxf_363);
			Query1.bindValue(":dxf_364",DXF_code_tables[x1].dxf_364);
			Query1.bindValue(":dxf_365",DXF_code_tables[x1].dxf_365);
			Query1.bindValue(":dxf_366",DXF_code_tables[x1].dxf_366);
			Query1.bindValue(":dxf_367",DXF_code_tables[x1].dxf_367);
			Query1.bindValue(":dxf_368",DXF_code_tables[x1].dxf_368);
			Query1.bindValue(":dxf_369",DXF_code_tables[x1].dxf_369);
			Query1.bindValue(":dxf_370",DXF_code_tables[x1].dxf_370);
			Query1.bindValue(":dxf_371",DXF_code_tables[x1].dxf_371);
			Query1.bindValue(":dxf_372",DXF_code_tables[x1].dxf_372);
			Query1.bindValue(":dxf_373",DXF_code_tables[x1].dxf_373);
			Query1.bindValue(":dxf_374",DXF_code_tables[x1].dxf_374);
			Query1.bindValue(":dxf_375",DXF_code_tables[x1].dxf_375);
			Query1.bindValue(":dxf_376",DXF_code_tables[x1].dxf_376);
			Query1.bindValue(":dxf_377",DXF_code_tables[x1].dxf_377);
			Query1.bindValue(":dxf_378",DXF_code_tables[x1].dxf_378);
			Query1.bindValue(":dxf_379",DXF_code_tables[x1].dxf_379);
			Query1.bindValue(":dxf_380",DXF_code_tables[x1].dxf_380);
			Query1.bindValue(":dxf_381",DXF_code_tables[x1].dxf_381);
			Query1.bindValue(":dxf_382",DXF_code_tables[x1].dxf_382);
			Query1.bindValue(":dxf_383",DXF_code_tables[x1].dxf_383);
			Query1.bindValue(":dxf_384",DXF_code_tables[x1].dxf_384);
			Query1.bindValue(":dxf_385",DXF_code_tables[x1].dxf_385);
			Query1.bindValue(":dxf_386",DXF_code_tables[x1].dxf_386);
			Query1.bindValue(":dxf_387",DXF_code_tables[x1].dxf_387);
			Query1.bindValue(":dxf_388",DXF_code_tables[x1].dxf_388);
			Query1.bindValue(":dxf_389",DXF_code_tables[x1].dxf_389);
			Query1.bindValue(":dxf_390",DXF_code_tables[x1].dxf_390);
			Query1.bindValue(":dxf_391",DXF_code_tables[x1].dxf_391);
			Query1.bindValue(":dxf_392",DXF_code_tables[x1].dxf_392);
			Query1.bindValue(":dxf_393",DXF_code_tables[x1].dxf_393);
			Query1.bindValue(":dxf_394",DXF_code_tables[x1].dxf_394);
			Query1.bindValue(":dxf_395",DXF_code_tables[x1].dxf_395);
			Query1.bindValue(":dxf_396",DXF_code_tables[x1].dxf_396);
			Query1.bindValue(":dxf_397",DXF_code_tables[x1].dxf_397);
			Query1.bindValue(":dxf_398",DXF_code_tables[x1].dxf_398);
			Query1.bindValue(":dxf_399",DXF_code_tables[x1].dxf_399);
			Query1.bindValue(":dxf_400",DXF_code_tables[x1].dxf_400);
			Query1.bindValue(":dxf_401",DXF_code_tables[x1].dxf_401);
			Query1.bindValue(":dxf_402",DXF_code_tables[x1].dxf_402);
			Query1.bindValue(":dxf_403",DXF_code_tables[x1].dxf_403);
			Query1.bindValue(":dxf_404",DXF_code_tables[x1].dxf_404);
			Query1.bindValue(":dxf_405",DXF_code_tables[x1].dxf_405);
			Query1.bindValue(":dxf_406",DXF_code_tables[x1].dxf_406);
			Query1.bindValue(":dxf_407",DXF_code_tables[x1].dxf_407);
			Query1.bindValue(":dxf_408",DXF_code_tables[x1].dxf_408);
			Query1.bindValue(":dxf_409",DXF_code_tables[x1].dxf_409);
			Query1.bindValue(":dxf_410",DXF_code_tables[x1].dxf_410);
			Query1.bindValue(":dxf_411",DXF_code_tables[x1].dxf_411);
			Query1.bindValue(":dxf_412",DXF_code_tables[x1].dxf_412);
			Query1.bindValue(":dxf_413",DXF_code_tables[x1].dxf_413);
			Query1.bindValue(":dxf_414",DXF_code_tables[x1].dxf_414);
			Query1.bindValue(":dxf_415",DXF_code_tables[x1].dxf_415);
			Query1.bindValue(":dxf_416",DXF_code_tables[x1].dxf_416);
			Query1.bindValue(":dxf_417",DXF_code_tables[x1].dxf_417);
			Query1.bindValue(":dxf_418",DXF_code_tables[x1].dxf_418);
			Query1.bindValue(":dxf_419",DXF_code_tables[x1].dxf_419);
			Query1.bindValue(":dxf_420",DXF_code_tables[x1].dxf_420);
			Query1.bindValue(":dxf_421",DXF_code_tables[x1].dxf_421);
			Query1.bindValue(":dxf_422",DXF_code_tables[x1].dxf_422);
			Query1.bindValue(":dxf_423",DXF_code_tables[x1].dxf_423);
			Query1.bindValue(":dxf_424",DXF_code_tables[x1].dxf_424);
			Query1.bindValue(":dxf_425",DXF_code_tables[x1].dxf_425);
			Query1.bindValue(":dxf_426",DXF_code_tables[x1].dxf_426);
			Query1.bindValue(":dxf_427",DXF_code_tables[x1].dxf_427);
			Query1.bindValue(":dxf_428",DXF_code_tables[x1].dxf_428);
			Query1.bindValue(":dxf_429",DXF_code_tables[x1].dxf_429);
			Query1.bindValue(":dxf_430",DXF_code_tables[x1].dxf_430);
			Query1.bindValue(":dxf_431",DXF_code_tables[x1].dxf_431);
			Query1.bindValue(":dxf_432",DXF_code_tables[x1].dxf_432);
			Query1.bindValue(":dxf_433",DXF_code_tables[x1].dxf_433);
			Query1.bindValue(":dxf_434",DXF_code_tables[x1].dxf_434);
			Query1.bindValue(":dxf_435",DXF_code_tables[x1].dxf_435);
			Query1.bindValue(":dxf_436",DXF_code_tables[x1].dxf_436);
			Query1.bindValue(":dxf_437",DXF_code_tables[x1].dxf_437);
			Query1.bindValue(":dxf_438",DXF_code_tables[x1].dxf_438);
			Query1.bindValue(":dxf_439",DXF_code_tables[x1].dxf_439);
			Query1.bindValue(":dxf_440",DXF_code_tables[x1].dxf_440);
			Query1.bindValue(":dxf_441",DXF_code_tables[x1].dxf_441);
			Query1.bindValue(":dxf_442",DXF_code_tables[x1].dxf_442);
			Query1.bindValue(":dxf_443",DXF_code_tables[x1].dxf_443);
			Query1.bindValue(":dxf_444",DXF_code_tables[x1].dxf_444);
			Query1.bindValue(":dxf_445",DXF_code_tables[x1].dxf_445);
			Query1.bindValue(":dxf_446",DXF_code_tables[x1].dxf_446);
			Query1.bindValue(":dxf_447",DXF_code_tables[x1].dxf_447);
			Query1.bindValue(":dxf_448",DXF_code_tables[x1].dxf_448);
			Query1.bindValue(":dxf_449",DXF_code_tables[x1].dxf_449);
			Query1.bindValue(":dxf_450",DXF_code_tables[x1].dxf_450);
			Query1.bindValue(":dxf_451",DXF_code_tables[x1].dxf_451);
			Query1.bindValue(":dxf_452",DXF_code_tables[x1].dxf_452);
			Query1.bindValue(":dxf_453",DXF_code_tables[x1].dxf_453);
			Query1.bindValue(":dxf_454",DXF_code_tables[x1].dxf_454);
			Query1.bindValue(":dxf_455",DXF_code_tables[x1].dxf_455);
			Query1.bindValue(":dxf_456",DXF_code_tables[x1].dxf_456);
			Query1.bindValue(":dxf_457",DXF_code_tables[x1].dxf_457);
			Query1.bindValue(":dxf_458",DXF_code_tables[x1].dxf_458);
			Query1.bindValue(":dxf_459",DXF_code_tables[x1].dxf_459);


			Query1.bindValue(":dxf_460",DXF_code_tables[x1].dxf_460);
			Query1.bindValue(":dxf_461",DXF_code_tables[x1].dxf_461);
			Query1.bindValue(":dxf_462",DXF_code_tables[x1].dxf_462);
			Query1.bindValue(":dxf_463",DXF_code_tables[x1].dxf_463);
			Query1.bindValue(":dxf_464",DXF_code_tables[x1].dxf_464);
			Query1.bindValue(":dxf_465",DXF_code_tables[x1].dxf_465);
			Query1.bindValue(":dxf_466",DXF_code_tables[x1].dxf_466);
			Query1.bindValue(":dxf_467",DXF_code_tables[x1].dxf_467);
			Query1.bindValue(":dxf_468",DXF_code_tables[x1].dxf_468);
			Query1.bindValue(":dxf_469",DXF_code_tables[x1].dxf_469);
			Query1.bindValue(":dxf_470",DXF_code_tables[x1].dxf_470);
			Query1.bindValue(":dxf_471",DXF_code_tables[x1].dxf_471);
			Query1.bindValue(":dxf_472",DXF_code_tables[x1].dxf_472);
			Query1.bindValue(":dxf_473",DXF_code_tables[x1].dxf_473);
			Query1.bindValue(":dxf_474",DXF_code_tables[x1].dxf_474);
			Query1.bindValue(":dxf_475",DXF_code_tables[x1].dxf_475);
			Query1.bindValue(":dxf_476",DXF_code_tables[x1].dxf_476);
			Query1.bindValue(":dxf_477",DXF_code_tables[x1].dxf_477);
			Query1.bindValue(":dxf_478",DXF_code_tables[x1].dxf_478);
			Query1.bindValue(":dxf_479",DXF_code_tables[x1].dxf_479);
			Query1.bindValue(":dxf_480",DXF_code_tables[x1].dxf_480);
			Query1.bindValue(":dxf_481",DXF_code_tables[x1].dxf_481);
			Query1.bindValue(":dxf_482",DXF_code_tables[x1].dxf_482);
			Query1.bindValue(":dxf_483",DXF_code_tables[x1].dxf_483);
			Query1.bindValue(":dxf_484",DXF_code_tables[x1].dxf_484);
			Query1.bindValue(":dxf_485",DXF_code_tables[x1].dxf_485);
			Query1.bindValue(":dxf_486",DXF_code_tables[x1].dxf_486);
			Query1.bindValue(":dxf_487",DXF_code_tables[x1].dxf_487);
			Query1.bindValue(":dxf_488",DXF_code_tables[x1].dxf_488);
			Query1.bindValue(":dxf_489",DXF_code_tables[x1].dxf_489);


			Query1.bindValue(":dxf_999",DXF_code_tables[x1].dxf_999);


			Query1.bindValue(":dxf_1000",DXF_code_tables[x1].dxf_1000);
			Query1.bindValue(":dxf_1001",DXF_code_tables[x1].dxf_1001);
			Query1.bindValue(":dxf_1002",DXF_code_tables[x1].dxf_1002);
			Query1.bindValue(":dxf_1003",DXF_code_tables[x1].dxf_1003);
			Query1.bindValue(":dxf_1004",DXF_code_tables[x1].dxf_1004);
			Query1.bindValue(":dxf_1005",DXF_code_tables[x1].dxf_1005);
			Query1.bindValue(":dxf_1006",DXF_code_tables[x1].dxf_1006);
			Query1.bindValue(":dxf_1007",DXF_code_tables[x1].dxf_1007);
			Query1.bindValue(":dxf_1008",DXF_code_tables[x1].dxf_1008);
			Query1.bindValue(":dxf_1009",DXF_code_tables[x1].dxf_1009);
			Query1.bindValue(":dxf_1010",DXF_code_tables[x1].dxf_1010);
			Query1.bindValue(":dxf_1011",DXF_code_tables[x1].dxf_1011);
			Query1.bindValue(":dxf_1012",DXF_code_tables[x1].dxf_1012);
			Query1.bindValue(":dxf_1013",DXF_code_tables[x1].dxf_1013);
			Query1.bindValue(":dxf_1014",DXF_code_tables[x1].dxf_1014);
			Query1.bindValue(":dxf_1015",DXF_code_tables[x1].dxf_1015);
			Query1.bindValue(":dxf_1016",DXF_code_tables[x1].dxf_1016);
			Query1.bindValue(":dxf_1017",DXF_code_tables[x1].dxf_1017);
			Query1.bindValue(":dxf_1018",DXF_code_tables[x1].dxf_1018);
			Query1.bindValue(":dxf_1019",DXF_code_tables[x1].dxf_1019);
			Query1.bindValue(":dxf_1020",DXF_code_tables[x1].dxf_1020);
			Query1.bindValue(":dxf_1021",DXF_code_tables[x1].dxf_1021);
			Query1.bindValue(":dxf_1022",DXF_code_tables[x1].dxf_1022);
			Query1.bindValue(":dxf_1023",DXF_code_tables[x1].dxf_1023);
			Query1.bindValue(":dxf_1024",DXF_code_tables[x1].dxf_1024);
			Query1.bindValue(":dxf_1025",DXF_code_tables[x1].dxf_1025);
			Query1.bindValue(":dxf_1026",DXF_code_tables[x1].dxf_1026);
			Query1.bindValue(":dxf_1027",DXF_code_tables[x1].dxf_1027);
			Query1.bindValue(":dxf_1028",DXF_code_tables[x1].dxf_1028);
			Query1.bindValue(":dxf_1029",DXF_code_tables[x1].dxf_1029);
			Query1.bindValue(":dxf_1030",DXF_code_tables[x1].dxf_1030);
			Query1.bindValue(":dxf_1031",DXF_code_tables[x1].dxf_1031);
			Query1.bindValue(":dxf_1032",DXF_code_tables[x1].dxf_1032);
			Query1.bindValue(":dxf_1033",DXF_code_tables[x1].dxf_1033);
			Query1.bindValue(":dxf_1034",DXF_code_tables[x1].dxf_1034);
			Query1.bindValue(":dxf_1035",DXF_code_tables[x1].dxf_1035);
			Query1.bindValue(":dxf_1036",DXF_code_tables[x1].dxf_1036);
			Query1.bindValue(":dxf_1037",DXF_code_tables[x1].dxf_1037);
			Query1.bindValue(":dxf_1038",DXF_code_tables[x1].dxf_1038);
			Query1.bindValue(":dxf_1039",DXF_code_tables[x1].dxf_1039);
			Query1.bindValue(":dxf_1040",DXF_code_tables[x1].dxf_1040);
			Query1.bindValue(":dxf_1041",DXF_code_tables[x1].dxf_1041);
			Query1.bindValue(":dxf_1042",DXF_code_tables[x1].dxf_1042);
			Query1.bindValue(":dxf_1043",DXF_code_tables[x1].dxf_1043);
			Query1.bindValue(":dxf_1044",DXF_code_tables[x1].dxf_1044);
			Query1.bindValue(":dxf_1045",DXF_code_tables[x1].dxf_1045);
			Query1.bindValue(":dxf_1046",DXF_code_tables[x1].dxf_1046);
			Query1.bindValue(":dxf_1047",DXF_code_tables[x1].dxf_1047);
			Query1.bindValue(":dxf_1048",DXF_code_tables[x1].dxf_1048);
			Query1.bindValue(":dxf_1049",DXF_code_tables[x1].dxf_1049);
			Query1.bindValue(":dxf_1050",DXF_code_tables[x1].dxf_1050);
			Query1.bindValue(":dxf_1051",DXF_code_tables[x1].dxf_1051);
			Query1.bindValue(":dxf_1052",DXF_code_tables[x1].dxf_1052);
			Query1.bindValue(":dxf_1053",DXF_code_tables[x1].dxf_1053);
			Query1.bindValue(":dxf_1054",DXF_code_tables[x1].dxf_1054);
			Query1.bindValue(":dxf_1055",DXF_code_tables[x1].dxf_1055);
			Query1.bindValue(":dxf_1056",DXF_code_tables[x1].dxf_1056);
			Query1.bindValue(":dxf_1057",DXF_code_tables[x1].dxf_1057);
			Query1.bindValue(":dxf_1058",DXF_code_tables[x1].dxf_1058);
			Query1.bindValue(":dxf_1059",DXF_code_tables[x1].dxf_1059);
			Query1.bindValue(":dxf_1060",DXF_code_tables[x1].dxf_1060);
			Query1.bindValue(":dxf_1061",DXF_code_tables[x1].dxf_1061);
			Query1.bindValue(":dxf_1062",DXF_code_tables[x1].dxf_1062);
			Query1.bindValue(":dxf_1063",DXF_code_tables[x1].dxf_1063);
			Query1.bindValue(":dxf_1064",DXF_code_tables[x1].dxf_1064);
			Query1.bindValue(":dxf_1065",DXF_code_tables[x1].dxf_1065);
			Query1.bindValue(":dxf_1066",DXF_code_tables[x1].dxf_1066);
			Query1.bindValue(":dxf_1067",DXF_code_tables[x1].dxf_1067);
			Query1.bindValue(":dxf_1068",DXF_code_tables[x1].dxf_1068);
			Query1.bindValue(":dxf_1069",DXF_code_tables[x1].dxf_1069);
			Query1.bindValue(":dxf_1070",DXF_code_tables[x1].dxf_1070);
			Query1.bindValue(":dxf_1071",DXF_code_tables[x1].dxf_1071);

			//x10++;
			x2=Query1.exec();

		//x2=Query1.exec();
		x1++;

	}


	//m_db.exec(QsqlString);

	m_db.commit();
	return Record_count_lines;
}

void dbManager::dbManager_load_dxf(const QString &pathname)
{
	//m_db.database().transaction();
	m_db.transaction();

	QSqlTableModel dxf_tabel1;
	dxf_tabel1.setTable("dxf_file");
	dxf_tabel1.select();

	QTableView dxf_table_view;
	dxf_table_view.setModel(&dxf_tabel1);


	QSqlRecord dxf_lines=dxf_tabel1.record();

	dxf_line_count=0;
	count_input=0;
	dxf_line_count_max=DXF_main_base[0].dxf_input.count();

	dxf_list1.clear();
	dxf_list2.clear();
	dxf_list3.clear();
	dxf_list4.clear();

	//dxf_tabel1.database().transaction();

	while (dxf_line_count<dxf_line_count_max-1)
	{
		if ((QString(DXF_main_base[0].dxf_input[dxf_line_count]).toInt()==0) and (DXF_main_base[0].dxf_input[dxf_line_count+1]=="SECTION"))
		{
			dxf_section=DXF_main_base[0].dxf_input[dxf_line_count+3];
		}


		dxf_lines.setValue("Index_count", QString::number(count_input));
		//dxf_list1.append(QString::number(count_input));

		dxf_lines.setValue("Code",DXF_main_base[0].dxf_input[dxf_line_count]);
		//dxf_list2.append(DXF_main_base[0].dxf_input[dxf_line_count]);

		dxf_lines.setValue("Waarde",DXF_main_base[0].dxf_input[dxf_line_count+1]);
		//dxf_list3.append(DXF_main_base[0].dxf_input[dxf_line_count+1]);

		dxf_lines.setValue("Section",dxf_section);
		//dxf_list4.append(dxf_section);



		dxf_line_count++;

		dxf_line_count++;


		count_input++;

		//dxf_table_view<-dxf_lines;



		dxf_tabel1.insertRecord(-1,dxf_lines);
		//dxf_tabel1.submit();

	}
	//dxf_tabel1.submitAll();

	//m_db.database().commit();
	m_db.database().commit();


}

void dbManager::dbManager_create_elmt_entitie (const QString &pathname, int32_t Index_count_1,QString Block_naam_1, QString Block_value_1)
{

	QSqlQuery Query_entitie;

	Qsql_entitie = "INSERT INTO table_elmt_entities (Index_count, Block_Naam, Block_value";
	Qsql_entitie.append(")");
	Qsql_entitie.append(" VALUES (:Index_count, :Block_Naam, :Block_value");
	Qsql_entitie.append(")");

	Query_entitie.prepare(Qsql_entitie);

	Query_entitie.bindValue(":Index_count",Index_count_1);
	Query_entitie.bindValue("Block_Naam",Block_naam_1);
	Query_entitie.bindValue(":Block_value",Block_value_1);

	//Query_entitie.prepare(Qsql_entitie);

	Query_entitie.exec();


}

void dbManager::dbManager_create_elmt_block (const QString &pathname, int32_t Index_count_2,QString Block_naam_2, QString Block_value_2)
{
	QSqlQuery Query_block;

	Qsql_Block = "INSERT INTO table_elmt_entities (Index_count, Block_Naam, Block_value";
	Qsql_Block.append(")");
	Qsql_Block.append(" VALUES (:Index_count, :Block_Naam, :Block_value");
	Qsql_Block.append(")");

	Query_block.prepare(Qsql_Block);

	Query_block.bindValue(":Index_count",Index_count_2);
	Query_block.bindValue("Block_Naam",Block_naam_2);
	Query_block.bindValue(":Block_value",Block_value_2);

	//Query_block.prepare(Qsql_Block);

	Query_block.exec();
}


void dbManager::dbManager_load_dxf_list(const QString &pathname)
{
	QSqlQuery Query_List;

	Qsql_List="INSERT INTO table_list (Index_count primary key, Code) ";
	Qsql_List.append("VALUES (:Indec_count, :Code)");

	Query_List.prepare(Qsql_List);

	dxf_line_count_max=DXF_main_base[0].dxf_input.count();
	count_input=0;

	dxf_list1.clear();

	while (count_input<dxf_line_count_max-1)
	{

		dxf_list1.append(count_input);
		dxf_list1.append(DXF_main_base[0].dxf_input[count_input]);
		count_input++;




	}

	Query_List.addBindValue(dxf_list1);
	Query_List.exec();

}

QString dbManager::db_split_header(const QString &pathname)
{
	/*m_db.transaction();

	QSqlTableModel dxf_tabel1;
	dxf_tabel1.setTable("dxf_file");
	dxf_tabel1.setFilter(Section='HEADER');
	dxf_tabel1.select();

	QSqlRecord dxf_file_lines=dxf_tabel1.record();


	QSqlTableModel dxf_header1;
	dxf_header1.setTable("dxf_header");
	dxf_header1.select();

	dxf_header1.clear();

	QSqlRecord dxf_header_lines=dxfheader1.record();



	m_db.commit();*/
}
