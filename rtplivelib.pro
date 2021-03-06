#-------------------------------------------------
#
# Project created by QtCreator 2018-11-19T16:36:17
#
#-------------------------------------------------

QT  -=  gui
QT	-= core

TARGET = rtplive
TEMPLATE = lib
CONFIG += c++11 c++14

DEFINES += RTPLIVELIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(debug, debug|release): DEFINES += DEBUG
else:CONFIG(release, debug|release): DEFINES += NDEBUG

unix {
    target.path = /usr/lib
    INSTALLS += target

LIBS += -L$$PWD/SDK/UNIX/lib/ -lavdevice \
	-L$$PWD/SDK/UNIX/lib/ -lavcodec \
	-L$$PWD/SDK/UNIX/lib/ -lavformat \
	-L$$PWD/SDK/UNIX/lib/ -lavutil \
	-L$$PWD/SDK/UNIX/lib/ -lswscale \
	-L$$PWD/SDK/UNIX/lib/ -lavfilter \
	-L$$PWD/SDK/UNIX/lib/ -lswresample \
	-L$$PWD/SDK/UNIX/lib/ -lSDL2 \
	-L$$PWD/SDK/UNIX/lib/ -ljrtp \
	-L$$PWD/SDK/UNIX/lib/ -ljthread \
	-L$$PWD/SDK/UNIX/lib/ -lopenfec

INCLUDEPATH += $$PWD/SDK/UNIX/include
DEPENDPATH += $$PWD/SDK/UNIX/include

HEADERS += \
    src/device_manager/alsa.h
	
SOURCES += \
    src/device_manager/alsa.cpp
}

win32{
LIBS += -L$$PWD/SDK/win64/bin/ -lavdevice-58 \
	-L$$PWD/SDK/win64/bin/ -lavcodec-58 \
	-L$$PWD/SDK/win64/bin/ -lavformat-58 \
	-L$$PWD/SDK/win64/bin/ -lavutil-56 \
	-L$$PWD/SDK/win64/bin/ -lswscale-5 \
	-L$$PWD/SDK/win64/bin/ -lavfilter-7 \
	-L$$PWD/SDK/win64/bin/ -lswresample-3 \
	-L$$PWD/SDK/win64/bin/ -lSDL2 \
	-L$$PWD/SDK/win64/bin/ -llibjrtp \
	-L$$PWD/SDK/win64/bin/ -llibopenfec \
	-L$$PWD/SDK/win64/lib/ -lwirehair

LIBS += -lWs2_32 \
	-lAdvapi32 \
	-lOle32 \
	-lOleAut32 \
	-lStrmiids \
	-lDXGI \
	-lD3D11

INCLUDEPATH += $$PWD/SDK/win64/include
DEPENDPATH += $$PWD/SDK/win64/include

HEADERS += \
	src/device_manager/wasapi.h \
    src/device_manager/dxgicapture.h
	
SOURCES += \
	src/device_manager/wasapi.cpp \
    src/device_manager/dxgicapture.cpp
}

INCLUDEPATH += $$PWD/SDK/include
DEPENDPATH += $$PWD/SDK/include

HEADERS += \
    src/core/abstractqueue.h \
    src/core/abstractthread.h \
    src/core/config.h \
    src/core/multioutputqueue.h \
    src/core/releasefunction.h \
    src/core/singleioqueue.h \
    src/player/abstractplayer.h \
    src/core/format.h \
    src/device_manager/abstractcapture.h \
    src/device_manager/audioprocessingfactory.h \
    src/device_manager/cameracapture.h \
    src/device_manager/desktopcapture.h \
    src/device_manager/videoprocessingfactory.h \
    src/core/time.h \
    src/core/logger.h \
    src/core/error.h \
    src/codec/videodecoder.h \
    src/codec/videoencoder.h \
    src/rtp_network/rtpsession.h \
    src/liveengine.h \
    src/device_manager/devicemanager.h \
    src/rtp_network/rtpsendthread.h \
    src/rtp_network/rtprecvthread.h \
    src/rtp_network/rtppacket.h \
    src/rtp_network/rtpusermanager.h \
    src/rtp_network/rtpuser.h \
    src/rtp_network/rtpbandwidth.h \
    src/core/timer.h \
    src/core/abstractobject.h \
    src/codec/hardwaredevice.h \
    src/image_processing/crop.h \
    src/image_processing/scale.h \
    src/core/except.h \
    src/device_manager/microphonecapture.h \
    src/device_manager/soundcardcapture.h \
    src/core/stringformat.h \
    src/codec/audioencoder.h \
    src/core/globalcallback.h \
    src/audio_processing/resample.h \
    src/codec/audiodecoder.h \
    src/codec/encoder.h \
    src/player/videoplayer.h \
    src/player/audioplayer.h \  
    src/rtp_network/fec/codec/fecabstractcodec.h \
    src/rtp_network/fec/codec/wirehair.h \ 
    src/rtp_network/fec/fecdecoder.h \
    src/rtp_network/fec/fecencoder.h \
    src/device_manager/gpudevice.h

SOURCES += \
    src/core/abstractthread.cpp \
    src/player/abstractplayer.cpp \
    src/core/format.cpp \
    src/device_manager/abstractcapture.cpp \
    src/device_manager/audioprocessingfactory.cpp \
    src/device_manager/cameracapture.cpp \
    src/device_manager/desktopcapture.cpp \
    src/device_manager/videoprocessingfactory.cpp \
    src/core/time.cpp \
    src/core/logger.cpp \
    src/codec/videodecoder.cpp \
    src/codec/videoencoder.cpp \
    src/rtp_network/rtpsession.cpp \
    src/liveengine.cpp \
    src/device_manager/devicemanager.cpp \
    src/rtp_network/rtpsendthread.cpp \
    src/rtp_network/rtprecvthread.cpp \
    src/rtp_network/rtppacket.cpp \
    src/rtp_network/rtpusermanager.cpp \
    src/rtp_network/rtpuser.cpp \
    src/codec/hardwaredevice.cpp \
    src/image_processing/crop.cpp \
    src/image_processing/scale.cpp \
    src/core/except.cpp \
    src/device_manager/microphonecapture.cpp \
    src/device_manager/soundcardcapture.cpp \
    src/core/stringformat.cpp \
    src/codec/audioencoder.cpp \
    src/core/globalcallback.cpp \
    src/audio_processing/resample.cpp \
    src/codec/audiodecoder.cpp \
    src/codec/encoder.cpp \
    src/player/videoplayer.cpp \
    src/player/audioplayer.cpp \  
    src/rtp_network/fec/codec/wirehair.cpp \ 
    src/rtp_network/fec/fecdecoder.cpp \
    src/rtp_network/fec/fecencoder.cpp \
    src/rtp_network/fec/codec/fecabstractcodec.cpp \
    src/device_manager/gpudevice.cpp
