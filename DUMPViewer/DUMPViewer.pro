#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T09:43:20
#
#-------------------------------------------------

QT       += core gui\
            xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DUMPViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewwindow.cpp \
    objectCompiller/parsers/ducParser/configitem.cpp \
    objectCompiller/parsers/ducParser/ducparser.cpp \
    objectCompiller/sceneObject/material.cpp \
    objectCompiller/parsers/parserobj.cpp \
    objectCompiller/sceneObject/sceneobject.cpp \
    mathPrimitives/vertex.cpp \
    mathPrimitives/vector3.cpp \
    mathPrimitives/vector2.cpp \
    gameObject/graphicobject.cpp \
    gameObject/phisycobject.cpp \
    objectCompiller/objectcompiller.cpp \
    gameObject/gameobject.cpp \
    gameObject/gameobjectmaterial.cpp \
    gameObject/gameobjecttexture.cpp \
    gameObject/meshobject.cpp \
    gameObject/rigidbody.cpp \
    gameObject/constraint.cpp \
    gameObject/editabelObjects/editabelgameobject.cpp \
    gameObject/lod.cpp \
    gameObject/editabelObjects/editabelphisycobject.cpp \
    application.cpp \
    objectCompiller/loader.cpp \
    gameObject/stream.cpp \
    gameObject/editabelObjects/editabelgraphicobject.cpp \
    gameObject/editabelObjects/editablelod.cpp \
    gameObject/editabelObjects/editabelrigidbody.cpp \
    GUI/serviceWindows/dfiledialog.cpp \
    GUI/serviceWindows/newgameobjectnamewindow.cpp \
    GUI/tabs/constraintstab.cpp \
    GUI/tabs/lodtab.cpp \
    GUI/tabs/meshtab.cpp \
    GUI/tabs/rigidbodyestab.cpp \
    GUI/tabs/tabbar.cpp \
    GUI/widgets/constraintPropertiesWidgets/conetwistwidget.cpp \
    GUI/widgets/constraintPropertiesWidgets/hingewidget.cpp \
    GUI/widgets/constraintPropertiesWidgets/pivotwidget.cpp \
    GUI/widgets/constraintPropertiesWidgets/pointtopointwidget.cpp \
    GUI/widgets/constraintPropertiesWidgets/transformwidget.cpp \
    GUI/widgets/distancewidget.cpp \
    GUI/widgets/dumpviewerwidget.cpp \
    GUI/widgets/ridgidbodypropertyeswidget.cpp \
    GUI/widgets/rigidbodieswidget.cpp \
    GUI/infobox.cpp \
    GUI/lodsbox.cpp \
    GUI/toolpanel.cpp \
    GUI/tooltabinfobox.cpp \
    GUI/tooltabshortinfobox.cpp \
    GUI/toolwidget.cpp \
    objectCompiller/parsers/parserdae.cpp \
    objectCompiller/parsers/abstractparser.cpp \

HEADERS  += mainwindow.h \
    viewwindow.h \
    objectCompiller/parsers/ducParser/configitem.h \
    objectCompiller/parsers/ducParser/ducparser.h \
    objectCompiller/sceneObject/material.h \
    objectCompiller/parsers/parserobj.h \
    objectCompiller/sceneObject/sceneobject.h \
    mathPrimitives/vertex.h \
    mathPrimitives/vector3.h \
    mathPrimitives/vector2.h \
    gameObject/graphicobject.h \
    gameObject/phisycobject.h \
    objectCompiller/objectcompiller.h \
    gameObject/gameobject.h \
    gameObject/gameobjectmaterial.h \
    gameObject/gameobjecttexture.h \
    gameObject/meshobject.h \
    gameObject/rigidbody.h \
    gameObject/constraint.h \
    gameObject/editabelObjects/editabelgameobject.h \
    gameObject/lod.h \
    gameObject/editabelObjects/editabelphisycobject.h \
    application.h \
    objectCompiller/loader.h \
    gameObject/stream.h \
    defines.h \
    gameObject/editabelObjects/editabelgraphicobject.h \
    gameObject/editabelObjects/editablelod.h \
    gameObject/editabelObjects/editabelrigidbody.h \
    GUI/serviceWindows/dfiledialog.h \
    GUI/serviceWindows/newgameobjectnamewindow.h \
    GUI/tabs/constraintstab.h \
    GUI/tabs/lodtab.h \
    GUI/tabs/meshtab.h \
    GUI/tabs/rigidbodyestab.h \
    GUI/tabs/tabbar.h \
    GUI/widgets/constraintPropertiesWidgets/conetwistwidget.h \
    GUI/widgets/constraintPropertiesWidgets/hingewidget.h \
    GUI/widgets/constraintPropertiesWidgets/pivotwidget.h \
    GUI/widgets/constraintPropertiesWidgets/pointtopointwidget.h \
    GUI/widgets/constraintPropertiesWidgets/transformwidget.h \
    GUI/widgets/distancewidget.h \
    GUI/widgets/dumpviewerwidget.h \
    GUI/widgets/ridgidbodypropertyeswidget.h \
    GUI/widgets/rigidbodieswidget.h \
    GUI/infobox.h \
    GUI/lodsbox.h \
    GUI/toolpanel.h \
    GUI/tooltabinfobox.h \
    GUI/tooltabshortinfobox.h \
    GUI/toolWidget.h \
    objectCompiller/parsers/parserdae.h \
    objectCompiller/parsers/abstractparser.h \
    gameObject/dArray.h

FORMS    += \
    mainwindow.ui \
    GUI/lodsbox.ui \
    GUI/tooltabinfobox.ui \
    GUI/tooltabshortinfobox.ui \
    GUI/toolwidget.ui \
    GUI/serviceWindows/newgameobjectnamewindow.ui \
    GUI/tabs/constraintstab.ui \
    GUI/tabs/lodtab.ui \
    GUI/tabs/meshtab.ui \
    GUI/tabs/rigidbodyestab.ui \
    GUI/widgets/distancewidget.ui \
    GUI/widgets/ridgidbodypropertyeswidget.ui \
    GUI/widgets/rigidbodieswidget.ui \
    GUI/widgets/constraintPropertiesWidgets/conetwistwidget.ui \
    GUI/widgets/constraintPropertiesWidgets/hingewidget.ui \
    GUI/widgets/constraintPropertiesWidgets/pivotwidget.ui \
    GUI/widgets/constraintPropertiesWidgets/pointtopointwidget.ui \
    GUI/widgets/constraintPropertiesWidgets/transformwidget.ui




INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include


win32: LIBS += -L$$PWD/include/ -lassimp_dll


