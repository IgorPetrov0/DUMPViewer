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
    mathPrimitives/vertex.cpp \
    mathPrimitives/vector3.cpp \
    mathPrimitives/vector2.cpp \
    gameObject/graphicobject.cpp \
    gameObject/phisycobject.cpp \
    gameObject/gameobject.cpp \
    gameObject/gameobjectmaterial.cpp \
    gameObject/gameobjecttexture.cpp \
    gameObject/meshobject.cpp \
    gameObject/rigidbody.cpp \
    gameObject/constraint.cpp \
    gameObject/editabelObjects/editabelgameobject.cpp \
    gameObject/lod.cpp \
    gameObject/editabelObjects/editabelphisycobject.cpp \
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
    GUI/toolwidget.cpp \
    editorCore.cpp \
    gameObject/gameindexobject.cpp \
    gameObject/slaveobject.cpp \
    mathPrimitives/boundbox.cpp \
    GUI/meshinfobox.cpp \
    GUI/meshbox.cpp

HEADERS  += mainwindow.h \
    viewwindow.h \
    mathPrimitives/vertex.h \
    mathPrimitives/vector3.h \
    mathPrimitives/vector2.h \
    gameObject/graphicobject.h \
    gameObject/phisycobject.h \
    gameObject/gameobject.h \
    gameObject/gameobjectmaterial.h \
    gameObject/gameobjecttexture.h \
    gameObject/meshobject.h \
    gameObject/rigidbody.h \
    gameObject/constraint.h \
    gameObject/editabelObjects/editabelgameobject.h \
    gameObject/lod.h \
    gameObject/editabelObjects/editabelphisycobject.h \
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
    GUI/toolWidget.h \
    gameObject/dArray.h \
    editorCore.h \
    gameObject/gameindexobject.h \
    gameObject/slaveobject.h \
    mathPrimitives/boundbox.h \
    GUI/meshinfobox.h \
    GUI/meshbox.h

FORMS    += \
    mainwindow.ui \
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
    GUI/widgets/constraintPropertiesWidgets/transformwidget.ui \
    GUI/meshinfobox.ui \
    GUI/meshbox.ui

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32: LIBS += -L$$PWD/include/ -lassimp_dll

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include


win32: LIBS += -L$$PWD/DevIL/ -lDevIL

INCLUDEPATH += $$PWD/DevIL
DEPENDPATH += $$PWD/DevIL

win32: LIBS += -L$$PWD/DevIL/ -lILU

INCLUDEPATH += $$PWD/DevIL
DEPENDPATH += $$PWD/DevIL


INCLUDEPATH += $$PWD/glm

DISTFILES += \
    shaders/defaultVertexShader.vert \
    shaders/defaultfragmentshader.fsh
