#-------------------------------------------------
#
# Project created by QtCreator 2016-04-30T12:13:04
#
#-------------------------------------------------

QT       += core gui\
         sql\

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DXFtoQET
TEMPLATE = app


SOURCES += main.cpp\
        dxftoqet3db.cpp \
    data.cpp \
    src/dxf_load.cpp \
    db/dbmanager.cpp \
    data2.cpp \
    src/ELMT_base_types/dxf_base_arc.cpp \
    src/ELMT_base_types/dxf_base_circle.cpp \
    src/ELMT_base_types/dxf_base_ellipse.cpp \
    src/ELMT_base_types/dxf_base_input.cpp \
    src/ELMT_base_types/dxf_base_line.cpp \
    src/ELMT_base_types/dxf_base_polyline.cpp \
    src/ELMT_base_types/dxf_base_rectangel.cpp \
    src/ELMT_base_types/dxf_base_terminal.cpp \
    src/ELMT_base_types/dxf_base_text.cpp \
    src/ELMT_base/baseelmt.cpp \
    src/DXF_control/dxf_layer_control.cpp \
    src/DXF_control/dxf_ltype_control.cpp \
    src/DXF_control/dxf_text_control.cpp \
    src/ELMT_steps/elmt_header_steps.cpp \
    src/ELMT_steps/elmt_tables.cpp \
    src/ELMT_steps/elmt_entities.cpp \
    src/DXF_control/dxf_corner_to_elmt.cpp \
    src/ELMT_steps/elmt_blocks.cpp \
    src/ELMT_steps/elmt_block_level2.cpp

HEADERS  += dxftoqet3db.h \
    data.h \
    src/dxf_load.h \
    db/dbmanager.h \
    data2.h \
    src/ELMT_base_types/dxf_base_arc.h \
    src/ELMT_base_types/dxf_base_circle.h \
    src/ELMT_base_types/dxf_base_ellipse.h \
    src/ELMT_base_types/dxf_base_input.h \
    src/ELMT_base_types/dxf_base_line.h \
    src/ELMT_base_types/dxf_base_polyline.h \
    src/ELMT_base_types/dxf_base_rectangel.h \
    src/ELMT_base_types/dxf_base_terminal.h \
    src/ELMT_base_types/dxf_base_text.h \
    src/ELMT_base/baseelmt.h \
    src/DXF_control/dxf_layer_control.h \
    src/DXF_control/dxf_ltype_control.h \
    src/DXF_control/dxf_text_control.h \
    src/ELMT_steps/elmt_header_steps.h \
    src/ELMT_steps/elmt_tables.h \
    src/ELMT_steps/elmt_entities.h \
    src/DXF_control/dxf_corner_to_elmt.h \
    src/ELMT_steps/elmt_blocks.h \
    src/ELMT_steps/elmt_block_level2.h

FORMS    += dxftoqet3db.ui

DISTFILES += \
    Convertion prestations.ods \
    Introductie dxftoqet converter V3
