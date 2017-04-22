#-------------------------------------------------
#
# Project created by QtCreator 2017-02-03T21:44:02
#
#-------------------------------------------------

QT += core
QT += network

QT       -= gui

TARGET = domular
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    devent.cpp \
    dstate.cpp \
    dattribute.cpp \
    dendpoint.cpp \
    ddevice.cpp \
    dcore.cpp \
    ../qtkHttpServer/qtkHttpServer.cpp \
    ../qtkHttpServer/qtkJsRpcServer.cpp \    
    ../qtkHttpServer/qtkRtpCommand_.cpp \
    ../qtkApplicationParameters/qtkapplicationparameters.cpp \
    ../_qtkDebugLogger/qtkDebugLogger.cpp \
    ../_qtkJsonRpc/qtkjosnrpc.cpp

HEADERS += \
    devent.h \
    dstate.h \
    dattribute.h \
    dendpoint.h \
    ddevice.h \
    dcore.h \
    domular.h \
    ../qtkHttpServer/qtkHttpCommon.h \
    ../qtkHttpServer/qtkHttpServer.h \
    ../qtkHttpServer/qtkJsRpcServer.h \    
    ../qtkHttpServer/qtkRtpCommand_.h \    
    ./rpcCommands/qtkRtpCommand_headers.h \
    ./rpcCommands/qtkRtpCommand_id.h \    
    ./rpcCommands/qtkRtpCommand_Test.h \
    rpcCommands/qtkRtpCommandsInit.h \
    ../qtkApplicationParameters/qtkapplicationparameters.h \
    ../_qtkDebugLogger/qtkDebugLogger.h \
    ../_qtkJsonRpc/qtkjosnrpc.h

INCLUDEPATH += "../qtkApplicationParameters" \
               "../qtkHttpServer" \
               "./config" \
               "./rpcCommands"
